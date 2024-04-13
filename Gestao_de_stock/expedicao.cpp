#include "expedicao.h"
#include "ui_expedicao.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QVariant>
#include <QMap>
#include <QDate>
#include <QDateTime>
#include <QTimer>
#include "ReportDialog.h"


Expedicao::Expedicao(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Expedicao)
{
    ui->setupUi(this);
    // inicializa na página 0 - lista de expedições
    ui->stackedWidget->setCurrentIndex(0);

    // formatar o estilo dos botões
    QString buttonStyle = "QPushButton:enabled {background-color: #F09200; color: #004b23; "
                          "border: 1.5px solid #F09200;border-style: outset; border-radius: 5px;}"
                          "QPushButton:disabled {background-color: #FFC374;}";

    ui->btnVoltar_expedicao->setStyleSheet(buttonStyle);
    ui->btnEliminar->setStyleSheet(buttonStyle);
    ui->btnGuardar->setStyleSheet(buttonStyle);
    ui->btnCancelar->setStyleSheet(buttonStyle);
    ui->btnModificar->setStyleSheet(buttonStyle);

    // formatar o estilo dos botões
    QString buttonStyle2 = "QPushButton:enabled {background-color: #A4CE95; color: #004b23; "
                           "border: 1px solid #004b23;border-style: outset; border-radius: 1px;}"
                           "QPushButton:disabled {background-color: rgb(208, 208, 208);}";

    ui->btnExpedicao->setStyleSheet(buttonStyle2);
    ui->btnExpedicao->setEnabled(false);

    ui->cmbNif->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->txtDataExpedicao->setInputMask("99-99-9999;_");
    ui->txtNome->setReadOnly(true);
    carregarDadosExpedicao();
}

Expedicao::~Expedicao()
{
    delete ui;

    if (modeloTreeView != nullptr) {
        delete modeloTreeView;
    }
    if (modeloTableView != nullptr) {
        delete modeloTableView;
    }
}

void Expedicao::on_btnInicio_expedicao_clicked()
{
    emit InicioClicked();
}

void Expedicao::on_btnNovo_expedicao_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    limparCampos();
    habilitarCampos();
    ui->btnVoltar_expedicao->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    ui->btnExpedicao->setEnabled(false);
    preencherComboboxNif(false);

    // Limpar o modelo 'modeloTableView'
    if (modeloTableView != nullptr) {
        tableViewProdutos->setVisible(false);
        delete modeloTableView;
        modeloTableView = nullptr;
    }

    atualizarModeloTreeView();
}

void Expedicao::on_btnVoltar_expedicao_clicked()
{
    limparCampos();
    ui->stackedWidget->setCurrentIndex(0);
}

// preencher a combobox com os NIF dos clientes
void Expedicao::preencherComboboxNif(bool mostrarTodosNifs = false)
{
    ui->cmbNif->clear();
    ui->cmbNif->addItem("");  

    QString queryString = "SELECT NIF FROM cliente ";
    if (!mostrarTodosNifs)
    {   //obter o nif dos clientes que têm encomendas e ordens de produção associadas a essas encomendas
        //e que ainda não tenham nehum registo de expedicão
        queryString += "INNER JOIN encomenda ON cliente.ID_Cliente = encomenda.ID_Cliente "
                       "INNER JOIN encomendaDetalhe ON encomenda.ID_Encomenda = encomendaDetalhe.ID_Encomenda "
                       "WHERE encomendaDetalhe.Expedido <> 1 AND encomendaDetalhe.Produzido = 1 "
                       "GROUP BY NIF;";
    }
    else
    {
        queryString += ";";
    }

    QSqlQuery obterNifCliente;
    obterNifCliente.prepare(queryString);
    if(obterNifCliente.exec())
    {
        while(obterNifCliente.next())
        {
            ui->cmbNif->addItem(obterNifCliente.value("NIF").toString());
        }
    }
    else
    {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao carregar dados do cliente."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Erro ao carregar dados do cliente:" << obterNifCliente.lastError().text();
    }
}

void Expedicao::atualizarModeloTreeView()
{
    if (modeloTreeView == nullptr) {
        modeloTreeView = new QStandardItemModel(ui->page2_RegistarExpedicoes);
    } else {
        modeloTreeView->clear();
    }

    // formatar a QTreeView da página de registo de Expedições
    //definir o título das colunas
    QStringList titulos;
    titulos = {"        Nr. Encomenda", "        Cód. Produto", "        Produto", "        Quantidade"};
    modeloTreeView->setHorizontalHeaderLabels(titulos);
    //definir o estilo
    ui->treeViewProdutos->setStyleSheet(
        "QTreeView::item {background-color: #DAF7D9; color: black;}"
        "QHeaderView::section {color: white; background-color: #004b23; font: bold 10px;}"
        "QTreeView {border: 2px solid #004b23;}"
        );
    // aplicar o modelo à treeView
    ui->treeViewProdutos->setModel(modeloTreeView);
    // redimensionar as colunas
    ui->treeViewProdutos->header()->resizeSection(0, 180);
    ui->treeViewProdutos->header()->resizeSection(1, 190);
    ui->treeViewProdutos->header()->resizeSection(2, 230);
    ui->treeViewProdutos->header()->resizeSection(3, 190);
    ui->treeViewProdutos->setVisible(true);
    // atualização da treeView
    ui->treeViewProdutos->update();
}

void Expedicao::on_cmbNif_currentTextChanged(const QString &nif)
{
    if (modeloTreeView != nullptr) {
        // sempre que existir uma alteração na QTreeView a quantidade total cabeçalho será calculada
        connect(modeloTreeView, &QStandardItemModel::itemChanged, this, &Expedicao::calcularQuantidadeTotalCabecalho);
    }

    if (nif.isEmpty()) {
        ui->txtNome->clear();
        atualizarModeloTreeView();
        return;
    }

    QSqlQuery obterNome;
    obterNome.prepare("SELECT Cliente FROM cliente WHERE NIF = :NIF");
    obterNome.bindValue(":NIF", nif);

    if (obterNome.exec() && obterNome.next()) {
        QString nomeCliente = obterNome.value("Cliente").toString();
        ui->txtNome->setText(nomeCliente);
    } else {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao apresentar o nome do cliente."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Erro ao obter o nome do cliente:" << obterNome.lastError().text();
        ui->txtNome->clear();
    }
    apresentarEncomendasDisponiveis(nif);
   // disconnect(modeloTreeView, &QStandardItemModel::itemChanged, this, &Expedicao::calcularQuantidadeTotalCabecalho);
}

// apresentar as ecomendas disponíveis para o NIF selecionado na combobox
void Expedicao::apresentarEncomendasDisponiveis(const QString &nif)
{
    atualizarModeloTreeView();
    // apresentar as encomendas do cliente para o nif escolhido
   // apenas ecomendas que tenham OPs associadas e que não estejam em expedição
    QSqlQuery obterEncomendas;
    obterEncomendas.prepare("SELECT Num_Encomenda FROM encomenda "
                            "INNER JOIN cliente ON encomenda.ID_Cliente = cliente.ID_Cliente "
                            "INNER JOIN encomendaDetalhe ON encomenda.ID_Encomenda = encomendaDetalhe.ID_Encomenda "
                            "WHERE cliente.NIF = :NIF AND encomendaDetalhe.Expedido <> 1 AND encomendaDetalhe.Produzido = 1 GROUP BY Num_Encomenda;");
    obterEncomendas.bindValue(":NIF", nif);

    if(obterEncomendas.exec())
    {
        modeloTreeView->setRowCount(0); // limpa o modelo
        while (obterEncomendas.next())
        {
            QString numeroEncomenda = obterEncomendas.value("Num_Encomenda").toString();
            //qDebug() << "Encomenda:" << numeroEncomenda;

            QStandardItem *itemEncomenda = new QStandardItem(numeroEncomenda);
            // não permitir a edição do campo
            itemEncomenda->setEditable(false);

            // definir as células vazias como não editáveis
            // para isso criaram-se itens vazios para preencher as colunas
            QList<QStandardItem*> itemsRow;
            itemsRow.append(itemEncomenda);
            for (int coluna = 1; coluna < 4; coluna++) {
                QStandardItem *emptyItem = new QStandardItem();
                emptyItem->setEditable(false);
                itemsRow.append(emptyItem);
            }

            modeloTreeView->appendRow(itemsRow);

            // apresentar os produtos de cada encomenda
            // apenas produtos da encomenda não expedidos e que se encontram em produção
            QSqlQuery obterProdutos;
            obterProdutos.prepare("SELECT produto.Codigo_Produto, produto.Produto, encomendaDetalhe.Qtd_produto FROM produto "
                                  "INNER JOIN encomendaDetalhe ON produto.ID_Produto = encomendaDetalhe.ID_Produto "
                                  "INNER JOIN encomenda ON encomendaDetalhe.ID_Encomenda = encomenda.ID_Encomenda "
                                  "WHERE Num_Encomenda = :Num_Encomenda AND encomendaDetalhe.Expedido = 0 "
                                  "AND encomendaDetalhe.Produzido = 1;");
            obterProdutos.bindValue(":Num_Encomenda", numeroEncomenda);
            obterProdutos.exec();

            while (obterProdutos.next()) {
                QString codigoProduto = obterProdutos.value("Codigo_Produto").toString();
                QString nomeProduto = obterProdutos.value("Produto").toString();
                int quantidade = obterProdutos.value("Qtd_produto").toInt();
                //qDebug() << "Produto:" << codigoProduto << nomeProduto << quantidade;

                QList<QStandardItem*> row;

                // criar uma checkBox no inicio de cada linha de produtos
                QStandardItem *checkBoxItem = new QStandardItem();
                checkBoxItem->setCheckable(true);
                checkBoxItem->setData(Qt::Unchecked, Qt::CheckStateRole);
                checkBoxItem->setEditable(false);  // definir a célula  como não editável

                // adicionar os detalhes do produto
                QStandardItem *itemCodigoProduto = new QStandardItem(codigoProduto);
                QStandardItem *itemNomeProduto = new QStandardItem(nomeProduto);
                QStandardItem *itemQuantidade = new QStandardItem(QString::number(quantidade));
                // não permitir a edição dos campos
                itemCodigoProduto->setEditable(false);
                itemNomeProduto->setEditable(false);
                itemQuantidade->setEditable(false);

                row << checkBoxItem << itemCodigoProduto << itemNomeProduto << itemQuantidade;
                itemEncomenda->appendRow(row);
            }
        }
    }
    else {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao apresentar informação das Encomendas."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Erro ao carregar informação das Encomendas:" << obterEncomendas.lastError().text();
    }
}

// verificar qual checkbox está selecionada, para saber qual é ou são os produtos a expedir
void Expedicao::verificarProdutosSelecionados()
{
    // percorrer as encomendas do cliente selecionado
    for (int i = 0; i < modeloTreeView->rowCount(); i++) {
        QStandardItem *itemEncomenda = modeloTreeView->item(i, 0);

        QString numeroEncomenda = modeloTreeView->item(i, 0)->text();
        qDebug() << "Nr. Encomenda:" << numeroEncomenda;

        // Obter o ID_Encomenda
        QSqlQuery obterIdEncomenda;
        obterIdEncomenda.prepare("SELECT ID_Encomenda FROM encomenda WHERE Num_Encomenda = :Num_Encomenda");
        obterIdEncomenda.bindValue(":Num_Encomenda", numeroEncomenda);

        if (!obterIdEncomenda.exec()) {
            qDebug() << "Falha ao obter o ID_Encomenda:" << obterIdEncomenda.lastError().text();
            return;
        }
        if (!obterIdEncomenda.next()) {
            qDebug() << "Encomenda não encontrada.";
            return;
        }

        int idEncomenda = obterIdEncomenda.value("ID_Encomenda").toInt();

        // percorrer os produtos de cada encomenda e verificar qual está selecionado
        for (int j = 0; j < itemEncomenda->rowCount(); j++) {
            QStandardItem *itemProduto = itemEncomenda->child(j, 0);
            if (itemProduto->checkState() == Qt::Checked) {
                QString codigoProduto = itemEncomenda->child(j, 1)->text();
                QString nomeProduto = itemEncomenda->child(j, 2)->text();
                int quantidade = itemEncomenda->child(j, 3)->text().toInt();

                qDebug() << "Produto selecionado:" << codigoProduto << nomeProduto << quantidade;

                // Obter o ID_Produto
                QSqlQuery obterIdProduto;
                obterIdProduto.prepare("SELECT ID_Produto FROM produto WHERE Codigo_Produto = :Codigo_Produto");
                obterIdProduto.bindValue(":Codigo_Produto", codigoProduto);

                if (!obterIdProduto.exec()) {
                    qDebug() << "Falha ao obter o ID_Produto:" << obterIdProduto.lastError().text();
                    return;
                }
                if (!obterIdProduto.next()) {
                    qDebug() << "Produto não encontrado.";
                    return;
                }

                int idProduto = obterIdProduto.value("ID_Produto").toInt();

                QSqlDatabase bd = QSqlDatabase::database();
                bd.transaction();

                // Guardar o registo  na tabela expedicaoDetalhe
                QSqlQuery guardarDados;
                guardarDados.prepare("INSERT INTO expedicaoDetalhe (ID_Expedicao, ID_Encomenda, ID_Produto, Qtd_produto) VALUES "
                                     "(:ID_Expedicao, :ID_Encomenda, :ID_Produto, :Qtd_produto)");
                guardarDados.bindValue(":ID_Expedicao", idExpedicaoSelecionado);
                guardarDados.bindValue(":ID_Encomenda", idEncomenda);
                guardarDados.bindValue(":ID_Produto", idProduto);
                guardarDados.bindValue(":Qtd_produto", quantidade);

                if (!guardarDados.exec()) {
                    qDebug() << "Falha ao inserir na tabela expedicaoDetalhe:" << guardarDados.lastError().text();
                    // Remove o registo de expedicao inserido anteriormente
                    guardarDados.prepare("DELETE FROM expedicao WHERE ID_Expedicao = :ID_Expedicao");
                    guardarDados.bindValue(":ID_Expedicao", idExpedicaoSelecionado);
                    if (!guardarDados.exec()) {
                        qDebug() << "Erro ao remover o registo da Expediçãoo:" << guardarDados.lastError().text();
                    }
                    bd.rollback(); // Desfaz a transação incluindo a tentativa de remoção
                    return;
                }

                // Atualizar a tabela 'encomendaDetalhe'
                QSqlQuery updateExpedido;
                updateExpedido.prepare("UPDATE encomendadetalhe SET Expedido = 1 "
                                        "WHERE ID_Encomenda = :ID_Encomenda AND ID_Produto = :ID_Produto;");
                updateExpedido.bindValue(":ID_Encomenda", idEncomenda);
                updateExpedido.bindValue(":ID_Produto", idProduto);

                if (!updateExpedido.exec()) {
                    qDebug() << "Falha ao atualizar a tabela encomendaDetalhe:" << updateExpedido.lastError().text();

                    QSqlQuery queryApagar;
                    // Remover da tabela 'expedicaoDetalhe' o produto inserido anteriormente
                    queryApagar.prepare("DELETE FROM expedicaoDetalhe WHERE ID_Produto = :ID_Produto AND "
                                        "ID_Encomenda = :ID_Encomenda;");
                    queryApagar.bindValue(":ID_Produto", idProduto);
                    queryApagar.bindValue(":ID_Encomenda", idEncomenda);
                    if (!queryApagar.exec()) {
                        qDebug() << "Erro ao remover o produto tabela expedicaoDetalhe:" << queryApagar.lastError().text();
                    }

                    // Remove o registo de expedicao inserido anteriormente
                    queryApagar.prepare("DELETE FROM expedicao WHERE ID_Expedicao = :ID_Expedicao");
                    queryApagar.bindValue(":ID_Expedicao", idExpedicaoSelecionado);
                    if (!queryApagar.exec()) {
                        qDebug() << "Erro ao remover o registo da Expediçãoo:" << queryApagar.lastError().text();
                    }
                    bd.rollback();
                    return;
                }
            }
        }
    }
}

// calcular a quantidade total de produtos a expedir
void Expedicao::calcularQuantidadeTotalCabecalho()
{
    int qtdTotal = 0;

    // percorrer as encomendas do cliente selecionado
    for (int i = 0; i < modeloTreeView->rowCount(); i++) {
        QStandardItem *itemEncomenda = modeloTreeView->item(i);

        // percorrer os produtos de cada encomenda e verificar qual está selecionado
        for (int j = 0; j < itemEncomenda->rowCount(); j++) {
            QStandardItem *itemProduto = itemEncomenda->child(j, 0);
            if (itemProduto->checkState() == Qt::Checked) {
                int qtdProduto = itemEncomenda->child(j, 3)->text().toInt();
                qtdTotal += qtdProduto;
                //qDebug() << "Quantidade produto:" << qtdProduto;
                //qDebug() << "Estado da Checkbox:" << itemProduto->checkState();
            }            
        }
    }

    //qDebug() << "Quantidade Total:" << qtdTotal;
    ui->txtQtdTotal->setText(QString::number(qtdTotal));
}

// confirmar se pelo menos uma checkbox está selecionada
bool Expedicao::verificarSelecaoProdutos()
{
    for (int i = 0; i < modeloTreeView->rowCount(); i++) {
        QStandardItem *itemEncomenda = modeloTreeView->item(i);

        // verifica os produtos de cada encomenda
        for (int j = 0; j < itemEncomenda->rowCount(); j++) {
            QStandardItem *itemProduto = itemEncomenda->child(j, 0);
            if (itemProduto->checkState() == Qt::Checked) {

                qDebug() << "Checkbox selecionada linha" << j;
                return true; // retorna true assim que encontrar a primeira checkbox marcada
            }
        }
    }
    qDebug() << "Nenhuma checkbox selecionada";
    return false; // retorna false se não encontrar nenhuma checkbox marcada
}

// Guardar a informação do registo da expedição na base de dados
void Expedicao::on_btnGuardar_clicked()
{
    QString nif = ui->cmbNif->currentText();
    //formatar a data para guardar na base de dados
    QString dataExpedicaoStr = ui->txtDataExpedicao->text();
    QDate dataExpedicao = QDate::fromString(dataExpedicaoStr, "dd-MM-yyyy");
    QString dataExpedicaoFormatada = dataExpedicao.toString("yyyy-MM-dd");
    int qtdTotal = ui->txtQtdTotal->text().toInt();

    if (!verificarCamposCabecalho()) {
        qDebug() << "Falha na verificação dos campos do cabeçalho.";
        return;
    }

    if (!verificarSelecaoProdutos()) {
        ui->lblErro->setText("Atenção! Por favor, selecione pelo menos um produto para expedir.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        return;
    }

    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction();

    // Primeiro, obter o ID_Cliente
    QSqlQuery obterIdCliente;
    obterIdCliente.prepare("SELECT ID_Cliente FROM cliente WHERE NIF = :NIF");
    obterIdCliente.bindValue(":NIF", nif);

    if (!obterIdCliente.exec()) {
        qDebug() << "Falha ao obter o ID_Cliente:" << obterIdCliente.lastError().text();
        return;
    }
    if (!obterIdCliente.next()) {
        qDebug() << "Cliente não encontrado.";
        return;
    }

    int idCliente = obterIdCliente.value("ID_Cliente").toInt();

    QSqlQuery guardarDados;
    // Guardar o registo  na tabela Expedição
    guardarDados.prepare("INSERT INTO expedicao (ID_Cliente, Data_expedicaoPrevista, Qtd_expedicao) VALUES "
                         "(:ID_Cliente, :Data_expedicaoPrevista, :Qtd_expedicao)");
    guardarDados.bindValue(":ID_Cliente", idCliente);
    guardarDados.bindValue(":Data_expedicaoPrevista", dataExpedicaoFormatada);
    guardarDados.bindValue(":Qtd_expedicao", qtdTotal);

    //confirmar a transação
    if (!guardarDados.exec()) {
        qDebug() << "Falha ao inserir na tabela Expedição:" << guardarDados.lastError().text();
        bd.rollback(); // Desfaz a transação
        return;
    }
    else{
        bd.commit();
    }

    // Recuperar o ID_Expedicao gerado
    int idExpedicaoGerado = guardarDados.lastInsertId().toInt();
    idExpedicaoSelecionado = QString::number(idExpedicaoGerado);

    verificarProdutosSelecionados();

    if (!bd.commit()) {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao guardar as informações da Expedição na base de dados."
                                                             "\nPor favor, contacte o suporte!");
        return;
    }

    qDebug() << "Expedição registada com sucesso.";
    QMessageBox::information(this, "Aviso", "Expedição registada com sucesso!");

    //apresentar a ficha da expedição atualizada
    apresentarInfoExpedicao(idExpedicaoGerado);
    //habilitar o botão
    ui->btnExpedicao->setEnabled(true);
    desabilitarCampos();
    ui->btnVoltar_expedicao->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    carregarDadosExpedicao();
}

void Expedicao::atualizarModeloTableView()
{
    ui->treeViewProdutos->setVisible(false);

    if (modeloTableView == nullptr) {
        modeloTableView = new QStandardItemModel(ui->page2_RegistarExpedicoes);
    } else {
        modeloTableView->clear();
    }

    //criar uma tabela e preencher com a informação dos produtos a expedir
    QStringList titulos;
    titulos = {"Cód. Produto", "Produto", "Nr. Encomenda", "Quantidade"};
    modeloTableView->setHorizontalHeaderLabels(titulos);

    if(tableViewProdutos == nullptr){
        // criar a QTableView
        tableViewProdutos = new QTableView(ui->page2_RegistarExpedicoes);
        tableViewProdutos->setStyleSheet(
            "QTableView::item {background-color: #DAF7D9; color: black;}"
            "QHeaderView::section {color: white; background-color: #004b23; font: bold 10px;}"
            "QTableView {border: 2px solid #004b23; background-color: #ADCE74;}"
            );
        tableViewProdutos->setModel(modeloTableView);
        tableViewProdutos->verticalHeader()->setVisible(true); // exibir os números das linhas
        tableViewProdutos->horizontalHeader()->resizeSection(0, 180);
        tableViewProdutos->horizontalHeader()->resizeSection(1, 240);
        tableViewProdutos->horizontalHeader()->resizeSection(2, 180);
        tableViewProdutos->horizontalHeader()->resizeSection(3, 180);
        tableViewProdutos->setEditTriggers(QAbstractItemView::NoEditTriggers); // desativar a edição
        tableViewProdutos->horizontalHeader()->setHighlightSections(false);
        tableViewProdutos->verticalHeader()->setHighlightSections(false);
        tableViewProdutos->horizontalHeader()->setStretchLastSection(true);
        tableViewProdutos->setGeometry(QRect(30, 390, 801, 260)); // definir a posição e o tamanho da QTableView
        tableViewProdutos->setVisible(true);
    }
    tableViewProdutos->setModel(modeloTableView);
    tableViewProdutos->horizontalHeader()->resizeSection(0, 180);
    tableViewProdutos->horizontalHeader()->resizeSection(1, 240);
    tableViewProdutos->horizontalHeader()->resizeSection(2, 180);
    tableViewProdutos->horizontalHeader()->resizeSection(3, 180);
    tableViewProdutos->setGeometry(QRect(30, 390, 801, 260));
    tableViewProdutos->setVisible(true);
}

// Após guardar o registo da expedição, apresentar a página de 'Registos de expedições' com toda a informação do registo
void Expedicao::apresentarInfoExpedicao(const int &idExpedicaoGerado)
{
    // Limpar o modelo 'modeloTreeView'
    if (modeloTreeView != nullptr) {
        ui->treeViewProdutos->setVisible(false);
        delete modeloTreeView;
        modeloTreeView = nullptr;
    }

    QSqlQuery obterDados;
    obterDados.prepare("SELECT expedicao.ID_Expedicao, expedicao.Num_Expedicao, cliente.NIF, cliente.Cliente, expedicao.Qtd_expedicao, "
                       "expedicao.Data_registo, expedicao.Data_expedicaoPrevista, expedicao.Expedida "
                       "FROM expedicao "
                       "INNER JOIN cliente ON expedicao.ID_Cliente = cliente.ID_Cliente "
                       "WHERE expedicao.ID_Expedicao = :ID_Expedicao;");

    obterDados.bindValue(":ID_Expedicao", idExpedicaoGerado);

    if(obterDados.exec() && obterDados.first())
    {  
        // preencher o cabeçalho
        ui->txtRegisto->setText(obterDados.value("ID_Expedicao").toString());
        ui->txtCodigo->setText(obterDados.value("Num_Expedicao").toString());
        // apresentar o nif do cliente no campo 'cmbNif'
        QString nifCliente = obterDados.value("NIF").toString();
        ui->cmbNif->setCurrentText(nifCliente);
        ui->txtNome->setText(obterDados.value("Cliente").toString());         
        ui->txtQtdTotal->setText(obterDados.value("Qtd_expedicao").toString());        
        ui->txtStatusExpedicao->setText(obterDados.value("Expedida").toString());
        // alterar o texto da label 'lblQtdTotalExpedir'
        QString estado = "";
        estado = obterDados.value("Expedida").toString();
        if(estado == "Sim")
        {
            ui->lblQtdTotalExpedir->setText("Quant. Total Expedida");
        }
        else{
            ui->lblQtdTotalExpedir->setText("Quant. Total a Expedir");
        }

        // formatar data do registo da expedicao
        QString dataStr = obterDados.value("Data_registo").toString();
        QDateTime dataHora = QDateTime::fromString(dataStr, Qt::ISODate);
        QString dataFormatada = dataHora.toString("dd-MM-yyyy");
        ui->txtDataCriacao->setText(dataFormatada);
        // formatar data de expedição prevista
        QString dataExpedicaoStr = obterDados.value("Data_expedicaoPrevista").toString();
        if(dataExpedicaoStr != ""){
            QDate dataExpedicao = QDate::fromString(dataExpedicaoStr, "yyyy-MM-dd");
            QString dataExpedicaoFormatada = dataExpedicao.toString("dd-MM-yyyy");
            ui->txtDataExpedicao->setText(dataExpedicaoFormatada);
        }
        else{
            ui->txtDataExpedicao->setText("");
        }

        atualizarModeloTableView();

        // obter a informação da base de dados
        QSqlQuery obterDetalhesExpedicao;
        obterDetalhesExpedicao.prepare("SELECT expedicaodetalhe.Qtd_produto, produto.Codigo_Produto, produto.Produto, encomenda.Num_Encomenda "
                                       "FROM expedicaodetalhe "
                                       "INNER JOIN produto ON expedicaodetalhe.ID_Produto = produto.ID_Produto "
                                       "INNER JOIN encomenda ON expedicaodetalhe.ID_Encomenda = encomenda.ID_Encomenda "
                                       "WHERE expedicaodetalhe.ID_Expedicao = :ID_Expedicao;");
        obterDetalhesExpedicao.bindValue(":ID_Expedicao", idExpedicaoGerado);

        if (obterDetalhesExpedicao.exec()) {
            while(obterDetalhesExpedicao.next())
            {
                QList<QStandardItem *> novaLinha;
                novaLinha.append(new QStandardItem(obterDetalhesExpedicao.value("Codigo_Produto").toString()));
                novaLinha.append(new QStandardItem(obterDetalhesExpedicao.value("Produto").toString()));
                novaLinha.append(new QStandardItem(obterDetalhesExpedicao.value("Num_Encomenda").toString()));
                novaLinha.append(new QStandardItem(obterDetalhesExpedicao.value("Qtd_produto").toString()));
                modeloTableView->appendRow(novaLinha);
            }
        } else {
            qDebug() << "Erro ao obter os detalhes da expedição: " << obterDetalhesExpedicao.lastError().text();
        }
    }
    else
    {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao carregar a informação da Expedição."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Erro ao carregar a informação da Expedição!:" << obterDados.lastError().text();
    }
}

void Expedicao::on_btnCancelar_clicked()
{
    limparCampos();
    desabilitarCampos();
    ui->btnVoltar_expedicao->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(true);
    ui->btnExpedicao->setEnabled(false);
}

void Expedicao::on_btnModificar_clicked()
{
    ui->btnVoltar_expedicao->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    ui->btnExpedicao->setEnabled(false);
    habilitarCampos();
    atualizarModeloTreeView();
}

// Muda o status da Expedição de 'Não' para 'Sim'.
// Apenas posso carregar no botão expedição quando a OP estiver no estado fechada (o produto já deu entrada em stock).
// Saída do produto do stock - atualiza a quantidade do produto em stock (total, reservada e disponível).
void Expedicao::on_btnExpedicao_clicked()
{
    int idExpedicao = idExpedicaoSelecionado.toInt();

    //1. Verifcar se existem produtos que ainda não deram entrada em Stock, ou seja, produtos com producao.Status_OP <> 'Fechada'
    QSqlQuery verificarStatusOP;
    verificarStatusOP.prepare("SELECT produto.Codigo_Produto, encomenda.Num_Encomenda "
                              "FROM producao "
                              "INNER JOIN encomenda ON producao.ID_Encomenda = encomenda.ID_Encomenda "
                              "INNER JOIN producaoDetalhe ON producao.ID_Producao = producaoDetalhe.ID_Producao "
                              "INNER JOIN produto ON producaoDetalhe.ID_Produto = produto.ID_Produto "
                              "INNER JOIN expedicaoDetalhe ON producaoDetalhe.ID_Produto = expedicaoDetalhe.ID_Produto "
                              "WHERE expedicaoDetalhe.ID_Expedicao = :ID_Expedicao AND producao.ID_Encomenda =  expedicaoDetalhe.ID_Encomenda "
                              "AND producao.Status_OP <> 'Fechada'");
    verificarStatusOP.bindValue(":ID_Expedicao", idExpedicao);

    if (verificarStatusOP.exec()) {
        QString mensagem = "Produtos que ainda não deram entrada em stock:\n";
        bool temProdutosPendentes = false;

        while (verificarStatusOP.next()) {
            temProdutosPendentes = true;
            QString codigoProduto = verificarStatusOP.value("Codigo_Produto").toString();
            QString numEncomenda = verificarStatusOP.value("Num_Encomenda").toString();
            mensagem += " -> Produto: " + codigoProduto + ", Encomenda: " + numEncomenda + "\n";
        }

        // se existirem produtos pendentes, exibe a mensagem
        if (temProdutosPendentes) {
            QMessageBox::warning(this, "Produtos Pendentes", mensagem);
            return;
        }
    } else {
        qDebug() << "Erro ao verificar status das ordens de produção: " << verificarStatusOP.lastError().text();
    }

    // ligação à base de dados
    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction(); // Inicia uma transação

    // 2. Alterar o status da Expedição e registar a data da expedição = data corrente
    QSqlQuery updateStatusExpedicao;
    // Alterar na tabela 'expedicao'
    updateStatusExpedicao.prepare("UPDATE expedicao SET Expedida = 'Sim', Data_expedicao = CURRENT_TIMESTAMP "
                                  "WHERE  ID_Expedicao = :ID_Expedicao;");
    updateStatusExpedicao.bindValue(":ID_Expedicao", idExpedicao);

    if (!updateStatusExpedicao.exec()) {
        qDebug() << "Falha ao atualizar dados na tabela Expedicao:" << updateStatusExpedicao.lastError().text();
        bd.rollback();
        return;
    }

    //Enquanto existirem produtos na tabela expedicaoDetalhe, associados à expedição atual, atualizar o stock do produto
    QSqlQuery obterProdutos;
    obterProdutos.prepare("SELECT expedicaoDetalhe.ID_Produto, expedicaoDetalhe.Qtd_produto "
                          "FROM expedicaoDetalhe "
                          "WHERE expedicaoDetalhe.ID_Expedicao = :ID_Expedicao;");
    obterProdutos.bindValue(":ID_Expedicao", idExpedicao);
    if (!obterProdutos.exec())
    {
        qDebug() << "Erro ao obter a informação dos produtos da tabela expedicaoDetalhe: " << obterProdutos.lastError().text();
        return;
    }
    while (obterProdutos.next()) {
        int idProduto = obterProdutos.value("ID_Produto").toInt();
        int quantidade = obterProdutos.value("Qtd_produto").toInt();
        // 3. Saída do produto do stock - atualizar a quantidade do produto em stock (total, reservada e disponível).
        QSqlQuery atualizarStock;
        // atualizar na tabela 'stock'
        atualizarStock.prepare("UPDATE stock SET Qtd_reservada = Qtd_reservada - :novaQuantidade, "
                               "Qtd_total = Qtd_total - :novaQuantidade "
                               "WHERE ID_Produto = :ID_Produto");
        atualizarStock.bindValue(":novaQuantidade", quantidade);
        atualizarStock.bindValue(":ID_Produto", idProduto);
        // se a atualização do stock falhar
        if (!atualizarStock.exec()) {
            qDebug() << "Falha ao atualizar dados na tabela stock:" << atualizarStock.lastError().text();
            // aterar  novamente o status da expedição para 'Não'
            QSqlQuery updateStatusExpedicao;
            updateStatusExpedicao.prepare("UPDATE expedicao SET Expedida = 'Não', Data_expedicao = NULL "
                                          "WHERE  ID_Expedicao = :ID_Expedicao;");
            updateStatusExpedicao.bindValue(":ID_Expedicao", idExpedicao);

            if (!updateStatusExpedicao.exec()) {
                qDebug() << "Falha ao atualizar dados na tabela Expedicao:" << updateStatusExpedicao.lastError().text();
            }
            bd.rollback(); // Desfaz a transação
            return;
        }
    }

    // verificar se o estado da encomenda foi atualizado com sucesso
    bool sucesso = atualizarStatusEncomenda();
    if (!sucesso) {
        bd.rollback();
        return;
    }

    if (!bd.commit()) {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao realizar a Expedição."
                                                             "\nPor favor, contacte o suporte!");
        return;
    }

    qDebug() << "Alterações guardadas com sucesso";

    relatorioExpedicao();

    ui->btnExpedicao->setEnabled(false);
    apresentarInfoExpedicao(idExpedicao);
    carregarDadosExpedicao();
}

// Atualizar o estado da encomenda.Expedida de 'Não' para 'Parcial' ou 'Total'
bool Expedicao::atualizarStatusEncomenda()
{
    int idExpedicao = idExpedicaoSelecionado.toInt();
    // ligação à base de dados
    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction(); // Inicia uma transação

    // obter as encomendas presentes na ficha atual de expedição
    QSqlQuery obterEncomendas;
    obterEncomendas.prepare("SELECT DISTINCT ID_Encomenda FROM expedicaoDetalhe "
                            "WHERE ID_Expedicao = :ID_Expedicao");
    obterEncomendas.bindValue(":ID_Expedicao", idExpedicao);

    if (!obterEncomendas.exec()) {
        qDebug() << "Erro ao obter encomendas da expedicão: " << obterEncomendas.lastError().text();
        return false;
    }

    int totalProdutos = 0, totalExpedidos = 0;
    while (obterEncomendas.next()) {
        int idEncomenda = obterEncomendas.value("ID_Encomenda").toInt();
        // contar o total de produtos de cada encomenda
        QSqlQuery totalProdutosEncomenda;
        totalProdutosEncomenda.prepare("SELECT COUNT(*) as totalProdutos  FROM encomendaDetalhe "
                                       "WHERE ID_Encomenda = :ID_Encomenda");
        totalProdutosEncomenda.bindValue(":ID_Encomenda", idEncomenda);

        if(totalProdutosEncomenda.exec() && totalProdutosEncomenda.next()){
            totalProdutos = totalProdutosEncomenda.value("totalProdutos").toInt();
        }

        else{
            qDebug() << "Falha ao contar o total de produtos da encomenda:" << totalProdutosEncomenda.lastError().text();
            return false;
        }

        // contar o total de produtos expedidos da encomenda
        // considera-se a encomenda como expedida quando o expedicao.Expedida = 'Sim'
        QSqlQuery totalProdutosExpedidos;
        totalProdutosExpedidos.prepare("SELECT COUNT(*) as totalProdutosExpedidos FROM expedicaoDetalhe "
                                       "INNER JOIN expedicao ON expedicaoDetalhe.ID_Expedicao = expedicao.ID_Expedicao "
                                       "WHERE expedicaoDetalhe.ID_Encomenda = :ID_Encomenda AND expedicao.Expedida = 'Sim'");
        totalProdutosExpedidos.bindValue(":ID_Encomenda", idEncomenda);
        if(totalProdutosExpedidos.exec() && totalProdutosExpedidos.next())
        {
            totalExpedidos = totalProdutosExpedidos.value("totalProdutosExpedidos").toInt();
        }
        else{
            qDebug() << "Falha ao contar o total de produtos expedidos da encomenda:" << totalProdutosExpedidos.lastError().text();
            return false;
        }

        // atualizar o estado da encomenda
        QString estado = "";
        if (totalExpedidos == 0) {
            estado = "Não";
        } else if (totalExpedidos < totalProdutos) {
            estado = "Parcial";
        } else {
            estado = "Total";
        }

        QSqlQuery atualizarEstado;
        atualizarEstado.prepare("UPDATE encomenda SET Expedida = :Expedida "
                                "WHERE ID_Encomenda = :ID_Encomenda");
        atualizarEstado.bindValue(":Expedida", estado);
        atualizarEstado.bindValue(":ID_Encomenda", idEncomenda);

        if (!atualizarEstado.exec()) {
            qDebug() << "Erro ao atualizar o estado da encomenda: " << atualizarEstado.lastError().text();
            bd.rollback();
            return false;
        }
    }

    if (!bd.commit()) {
        qDebug() << "Erro ao atualizar o estado da encomenda.";
        return false;
    }

    qDebug() << "Estado da encomenda atualizado com sucesso";
    return true;
}

// Exibir um relatório no ecrã com a informação da expedição
void Expedicao::relatorioExpedicao()
{
    int idExpedicao = idExpedicaoSelecionado.toInt();
    QString reportHtml = "";

    QSqlQuery obterInfoExpedicao;
    obterInfoExpedicao.prepare("SELECT expedicao.Num_Expedicao, cliente.Cliente "
                               "FROM expedicao "
                               "INNER JOIN cliente ON expedicao.ID_Cliente = cliente.ID_Cliente "
                               "WHERE expedicao.ID_Expedicao = :ID_Expedicao;");
    obterInfoExpedicao.bindValue(":ID_Expedicao", idExpedicao);

    if(obterInfoExpedicao.exec() && obterInfoExpedicao.first())
    {
        QString numExpedicao = obterInfoExpedicao.value("Num_Expedicao").toString();
        QString nomeCliente = obterInfoExpedicao.value("Cliente").toString();

        reportHtml = "<h2>Expedição validada</h2>"
                     + QString( "<p><b>Número da Expedição:</b> %1</p>").arg(numExpedicao)
                     + QString( "<p><b>Cliente:</b> %1</p>").arg(nomeCliente) +
                     "<p><b>Stock:</b></p>";

        QSqlQuery obterDetalhesExpedicao;
        obterDetalhesExpedicao.prepare("SELECT expedicaodetalhe.Qtd_produto, produto.Codigo_Produto "
                                       "FROM expedicaodetalhe "
                                       "INNER JOIN produto ON expedicaodetalhe.ID_Produto = produto.ID_Produto "
                                       "WHERE expedicaodetalhe.ID_Expedicao = :ID_Expedicao;");
        obterDetalhesExpedicao.bindValue(":ID_Expedicao", idExpedicao);

        if (obterDetalhesExpedicao.exec()) {
            while(obterDetalhesExpedicao.next())
            {
                QString quantProduto = obterDetalhesExpedicao.value("Qtd_produto").toString();
                QString codProduto = obterDetalhesExpedicao.value("Codigo_Produto").toString();
                reportHtml += QString("<p>  - Saída de %1 unidades do Produto %2</p>").arg(quantProduto, codProduto);
            }
        } else {
            qDebug() << "Erro ao obter os detalhes da expedição: " << obterDetalhesExpedicao.lastError().text();
        }
    }
    else
    {
        qDebug() << "Erro ao obter a informação da Expedição!:" << obterInfoExpedicao.lastError().text();
    }

    reportHtml += QString("<p><b>Data:</b> %1</p>").arg(QDate::currentDate().toString("dd-MM-yyyy")) ;

    ReportDialog dialog(reportHtml);
    dialog.exec();
}

void Expedicao::on_tableWidget_expedicoes_cellDoubleClicked()
{
    desabilitarCampos();
    ui->btnVoltar_expedicao->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(false);

    preencherComboboxNif(true);

    int idExpedicao = 0;
    int linhaAtual = 0;

    linhaAtual = ui->tableWidget_expedicoes->currentRow();
    idExpedicaoSelecionado = ui->tableWidget_expedicoes->item(linhaAtual, 0)->text();
    idExpedicao = idExpedicaoSelecionado.toInt();

    ui->stackedWidget->setCurrentIndex(1); // página de registo de Expedições
    apresentarInfoExpedicao(idExpedicao);

    // obter o status da Expedição
    QString statusExpedicao = "";
    statusExpedicao = ui->tableWidget_expedicoes->item(linhaAtual, 4)->text();
    if(statusExpedicao == "Não"){
        ui->btnExpedicao->setEnabled(true);
    }
    else{
        ui->btnExpedicao->setEnabled(false);
    }
}

// Apresentar todas as expedições na tabela da lista de expedições
void Expedicao::carregarDadosExpedicao()
{
    limparTableWidget(ui->tableWidget_expedicoes);

    QSqlQuery obterDados;
    obterDados.prepare("SELECT expedicao.ID_Expedicao, expedicao.Num_Expedicao, cliente.Cliente, "
                       "expedicao.Qtd_expedicao, expedicao.Expedida, expedicao.Data_expedicao "
                       "FROM expedicao INNER JOIN cliente ON expedicao.ID_Cliente = cliente.ID_Cliente ORDER BY expedicao.ID_Expedicao;");

    //verificar o acesso à BD
    if(obterDados.exec())
    {
        int linha = 0;
        ui->tableWidget_expedicoes->setColumnCount(6);

        while(obterDados.next())
        {
            ui->tableWidget_expedicoes->insertRow(linha);
            for(int coluna = 0; coluna < 6; coluna++)
            {
                QTableWidgetItem* novoItem = new QTableWidgetItem(obterDados.value(coluna).toString());
                ui->tableWidget_expedicoes->setItem(linha, coluna, novoItem);

                // formatar data
                QString dataStr = obterDados.value("Data_expedicao").toString();
                QDateTime dataHora = QDateTime::fromString(dataStr, Qt::ISODate);
                QString dataFormatada = dataHora.toString("dd-MM-yyyy HH:mm");
                ui->tableWidget_expedicoes->setItem(linha, 5, new QTableWidgetItem(dataFormatada));
            }
            linha++;
        }

        ui->lblTotalExpedicoes->setText("Expedições: " + QString::number(linha));

        //colocar os títulos das colunas igual à ordem da query 'obterDados'
        QStringList titulos;
        titulos = {"Registo", "Nr. Expedição", "Cliente", "Quantidade (un)", "Expedida", "Data Expedição"};
        ui->tableWidget_expedicoes->setHorizontalHeaderLabels(titulos);
        // formatar título
        ui->tableWidget_expedicoes->horizontalHeader()->setStyleSheet("QHeaderView::section {color: white; background-color: #004b23; font: bold 10px}");
        ui->tableWidget_expedicoes->setStyleSheet("QTableWidget::item {background-color: #f0f0f0; color: black;}");
        // ocultar os números das linhas
        ui->tableWidget_expedicoes->verticalHeader()->setVisible(false);
        // ajustar a largura e altura das colunas
        //ui->tableWidget_expedicoes->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
        ui->tableWidget_expedicoes->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
        //definir a largura da coluna
        ui->tableWidget_expedicoes->setColumnWidth(0, 140);
        ui->tableWidget_expedicoes->setColumnWidth(1, 140);
        ui->tableWidget_expedicoes->setColumnWidth(2, 230);
        ui->tableWidget_expedicoes->setColumnWidth(3, 140);
        ui->tableWidget_expedicoes->setColumnWidth(4, 140);
        ui->tableWidget_expedicoes->setColumnWidth(5, 140);
        // desabilitar a edição dos dados
        ui->tableWidget_expedicoes->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // selecionar a linha inteira da tabela
        ui->tableWidget_expedicoes->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_expedicoes->setStyleSheet("QTableWidget {border: 2px solid #004b23;}");
    }
    else
    {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao carregar a informação das Expedições na tabela Lista de Expedições."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Erro ao carregar a informação das Expedições na tabela:" << obterDados.lastError().text();
        qDebug() << "Consulta SQL Expedições:" << obterDados.lastQuery();
    }
}

// limpar os dados da tabela
void Expedicao::limparTableWidget(QTableWidget *limpaTW)
{
    while(limpaTW->rowCount() > 0)
    {
        limpaTW->removeRow(0);
    }
}

void Expedicao::on_btnPesquisar_clicked()
{
    QString numExpedicao = ui->txtNrExpedicao->text();
    QString cliente = ui->txtCliente->text();
    QString expedida = ui->cmbExpedida->currentText();

    // construir a consulta SQL
    QString pesquisa = "SELECT expedicao.ID_Expedicao, expedicao.Num_Expedicao, cliente.Cliente, "
                       "expedicao.Qtd_expedicao, expedicao.Expedida, expedicao.Data_expedicao "
                       "FROM expedicao INNER JOIN cliente ON expedicao.ID_Cliente = cliente.ID_Cliente "
                       "WHERE 1 = 1 ";

    if (!numExpedicao.isEmpty()) {
        pesquisa += " AND Num_Expedicao = :Num_Expedicao";
    }

    if (!cliente.isEmpty()) {
        pesquisa += " AND Cliente LIKE :Cliente";
        cliente = "%" + cliente + "%";
    }

    if (!expedida.isEmpty()) {
        pesquisa += " AND Expedida = :Expedida";
    }

    // executar a consulta
    QSqlQuery queryPesquisa;
    queryPesquisa.prepare(pesquisa);
    queryPesquisa.bindValue(":Num_Expedicao", numExpedicao);
    queryPesquisa.bindValue(":Cliente", cliente);
    queryPesquisa.bindValue(":Expedida", expedida);

    if (queryPesquisa.exec()) {
        limparTableWidget(ui->tableWidget_expedicoes);
        int linha = 0;

        while (queryPesquisa.next()) {
            ui->tableWidget_expedicoes->insertRow(linha);
            for(int coluna = 0; coluna < 6; coluna++)
            {
                QTableWidgetItem* novoItem = new QTableWidgetItem(queryPesquisa.value(coluna).toString());
                ui->tableWidget_expedicoes->setItem(linha, coluna, novoItem);
            }

            linha++;
        }
        ui->lblTotalExpedicoes->setText("Expedições: " + QString::number(linha));
    } else {
        qDebug() << "Erro ao executar a consulta:" << queryPesquisa.lastError().text();
    }
}

void Expedicao::on_btnLimparPesquisa_clicked()
{
    ui->txtNrExpedicao->clear();
    ui->txtCliente->clear();
    ui->cmbExpedida->setCurrentIndex(0);
    carregarDadosExpedicao();
}

void Expedicao::on_dateEdit_userDateChanged()
{
    QDate dataSelecionada = ui->dateEdit->date();
    QString dataFormato = dataSelecionada.toString("dd-MM-yyyy");
    ui->txtDataExpedicao->setText(dataFormato);
}

void Expedicao::on_txtDataExpedicao_editingFinished()
{
    QString data = ui->txtDataExpedicao->text();
    QDate dataSelecionada = QDate::fromString(data, "dd-MM-yyyy");

    if (dataSelecionada.isValid()) {
        ui->dateEdit->setDate(dataSelecionada);
    } else {
        qDebug() << "A Data fornecida é inválida.";
    }
}

bool Expedicao::verificarCamposCabecalho()
{
    if(ui->cmbNif->currentIndex() == 0){
        ui->lblErro->setText("Atenção! O campo NIF é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->cmbNif->setFocus();
        return false;
    }

    QString dataExpedicaoStr = ui->txtDataExpedicao->text();
    QDate dataExpedicao = QDate::fromString(dataExpedicaoStr, "dd-MM-yyyy");

    if(!dataExpedicao.isNull() && dataExpedicao < QDate::currentDate()){
        ui->lblErro->setText("Atenção! A Data de Expedição não pode ser inferior à data atual.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtDataExpedicao->setFocus();
        return false;
    }
    return true;
}

void Expedicao::limparCampos()
{
    ui->txtDataExpedicao->clear();
    ui->cmbNif->setCurrentIndex(0);
    preencherComboboxNif();
    ui->txtNome->clear();
    ui->txtStatusExpedicao->clear();
    ui->txtRegisto->clear();
    ui->txtCodigo->clear();
    ui->txtDataCriacao->clear();
    ui->txtQtdTotal->clear();
}

void Expedicao::desabilitarCampos()
{
    ui->txtDataExpedicao->setReadOnly(true);
    ui->cmbNif->setEnabled(false);
    ui->txtNome->setReadOnly(true);
    ui->dateEdit->setReadOnly(true);
}

void Expedicao::habilitarCampos()
{
    ui->txtDataExpedicao->setReadOnly(false);
    ui->cmbNif->setEnabled(true);
    ui->txtNome->setReadOnly(true);
    ui->dateEdit->setReadOnly(false);
}
