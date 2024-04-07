#include "encomendas.h"
#include "ui_encomendas.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QVariant>
#include <QMap>
#include <QDate>
#include <QDateTime>
#include <QTimer>
#include "QuantidadeDelegate.h"


Encomendas::Encomendas(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Encomendas)
{
    ui->setupUi(this);

    // inicializa na página 0 - lista de encomendas
    ui->stackedWidget->setCurrentIndex(0);

    // formatar o estilo dos botões
    QString buttonStyle = "QPushButton:enabled {background-color: #F09200; color: #004b23; "
                          "border: 1.5px solid #F09200;border-style: outset;border-radius: 5px;}"
                          "QPushButton:disabled {background-color: #FFC374;}";

    ui->btnVoltar_encomendas->setStyleSheet(buttonStyle);
    ui->btnEliminar->setStyleSheet(buttonStyle);
    ui->btnGuardar->setStyleSheet(buttonStyle);
    ui->btnCancelar->setStyleSheet(buttonStyle);
    ui->btnModificar->setStyleSheet(buttonStyle);

    // formatar a tabela dos produtos encomendados
    ui->tableWidget_ProdutosEnc->setColumnCount(5);
    preencherComboboxCodigoProduto();
    atualizarComboboxProdutos();
    QStringList titulos;
    titulos = {"Código", "Produto", "Quantidade", "Valor untitário", "Valor total"};
    ui->tableWidget_ProdutosEnc->setHorizontalHeaderLabels(titulos);
    // formatar título
    ui->tableWidget_ProdutosEnc->horizontalHeader()->setStyleSheet("QHeaderView::section {color: white; background-color: #004b23; font: bold 10px}");
    ui->tableWidget_ProdutosEnc->setStyleSheet("QTableWidget::item {background-color: #f0f0f0; color: black;}");
    // exibir os números das linhas
    ui->tableWidget_ProdutosEnc->verticalHeader()->setVisible(true);
    // ajustar a altura das colunas
    ui->tableWidget_ProdutosEnc->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
    //definir a largura da coluna
    ui->tableWidget_ProdutosEnc->setColumnWidth(0, 100);
    ui->tableWidget_ProdutosEnc->setColumnWidth(1, 250);
    ui->tableWidget_ProdutosEnc->setColumnWidth(2, 140);
    ui->tableWidget_ProdutosEnc->setColumnWidth(3, 140);
    ui->tableWidget_ProdutosEnc->setColumnWidth(4, 140);
    ui->tableWidget_ProdutosEnc->setStyleSheet("QTableWidget {border: 2px solid #004b23;}");
    // aplicar um QIntValidator à quantidade e desabilitar a edição dos dados para as restantes colunas
    ui->tableWidget_ProdutosEnc->setItemDelegate(new QuantidadDelegate(ui->tableWidget_ProdutosEnc));

    ui->cmbClientes->setCurrentIndex(0);
    ui->txtDataEntrega->setInputMask("99-99-9999;_");
    ui->txtNome->setReadOnly(true);
    carregarDadosEncomendas();

    connect(ui->tableWidget_ProdutosEnc, &QTableWidget::cellChanged, this, &Encomendas::calcularValorTotalLinha);
    calcularValorTotalCabecalho();
}

Encomendas::~Encomendas()
{
    delete ui;
}

void Encomendas::on_btnInicio_encomendas_clicked()
{
    emit InicioClicked();
}

void Encomendas::on_btnNovo_encomenda_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    limparCampos();
    habilitarCampos();
    ui->btnVoltar_encomendas->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    ui->btnAdLinha->setHidden(false);
    ui->btnEliminaLinha->setHidden(false);
    preencherComboboxCliente();
    preencherComboboxCodigoProduto();
}

void Encomendas::on_btnVoltar_encomendas_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//adicionar linhas à tabela 'tableWidget_ProdutosEnc'
void Encomendas::on_btnAdLinha_clicked()
{
    preencherComboboxCodigoProduto();
    calcularValorTotalCabecalho();
}

//remover linhas da tabela 'tableWidget_ProdutosEnc'
void Encomendas::on_btnEliminaLinha_clicked()
{
    auto selectedItems = ui->tableWidget_ProdutosEnc->selectedItems();
    if (!selectedItems.isEmpty()) {
        int selectedRow = ui->tableWidget_ProdutosEnc->row(selectedItems.first());
        ui->tableWidget_ProdutosEnc->removeRow(selectedRow);
    } else {
        QMessageBox::warning(this, "Seleção", "Por favor, selecione uma linha para eliminar.");
    }
    calcularValorTotalCabecalho();
}

// apresentar na combobox 'cmbClientes' os nifs de todos os clientes
void Encomendas::preencherComboboxCliente()
{
    ui->cmbClientes->clear();
    ui->cmbClientes->addItem("");
    QSqlQuery obterNifCliente;
    obterNifCliente.prepare("SELECT NIF FROM cliente;");

    if(obterNifCliente.exec())
    {
        while(obterNifCliente.next())
        {
            ui->cmbClientes->addItem(obterNifCliente.value("NIF").toString());
        }
    }
    else
    {
        QMessageBox::critical(this, "Atenção", "Erro ao carregar dados do cliente!");
        qDebug() << "Erro ao carregar dados do cliente:" << obterNifCliente.lastError().text();
    }
}

void Encomendas::on_cmbClientes_currentTextChanged(const QString &nif)
{
    if (nif.isEmpty()) {
        ui->txtNome->clear();
        limparTableWidget(ui->tableWidget_ProdutosEnc);
        calcularValorTotalCabecalho();
        return;
    }

    QSqlQuery obterNome;
    obterNome.prepare("SELECT Cliente FROM cliente WHERE NIF = :nif");
    obterNome.bindValue(":nif", nif);

    if (obterNome.exec() && obterNome.next()) {
        QString nomeCliente = obterNome.value("Cliente").toString();
        ui->txtNome->setText(nomeCliente);
    } else {
        QMessageBox::warning(this, "Atenção", "Erro ao obter o nome do cliente!");
        qDebug() << "Erro ao obter o nome do cliente:" << obterNome.lastError().text();
        ui->txtNome->clear();
    }

    limparTableWidget(ui->tableWidget_ProdutosEnc);
    calcularValorTotalCabecalho();
    preencherComboboxCodigoProduto();
}

// obter a informação dos produtos da base de dados e armazenar num "dicionário" em que
// a chave é o código do produto
QMap<QString,  QPair<QString, QString>> Encomendas::listaProdutosDisponiveis()
{
    QMap<QString, QPair<QString, QString>> produtos;
    QSqlQuery obterProdutos;
    obterProdutos.prepare("SELECT Codigo_Produto, Produto, Preco_venda FROM produto;");

    if (obterProdutos.exec()) {
        while (obterProdutos.next()) {
            QString codigo = obterProdutos.value("Codigo_Produto").toString();
            QString nome = obterProdutos.value("Produto").toString();
            QString preco = obterProdutos.value("Preco_venda").toString();
            produtos[codigo] = qMakePair(nome, preco);;
        }
    } else {
        qDebug() << "Erro ao obter produtos:" << obterProdutos.lastError().text();
    }

    return produtos;
}

// criar uma combobox na primeira coluna da tabela 'tableWidget_ProdutosEnc'
// e preencher com os códigos dos produtos
void Encomendas::preencherComboboxCodigoProduto()
{
    // Desconecta temporariamente o sinal para evitar chamadas recursivas
    disconnect(ui->tableWidget_ProdutosEnc, &QTableWidget::cellChanged, this, &Encomendas::calcularValorTotalLinha);

    QMap<QString, QPair<QString, QString>> produtos = listaProdutosDisponiveis();
    QComboBox* cmbProdutos = new QComboBox(ui->tableWidget_ProdutosEnc);

    cmbProdutos->addItem("", QVariant());
    // preencher a combobox com o código
    for(auto item = produtos.begin(); item != produtos.end(); item++) {
        QString itemData = item.value().first + ";" + item.value().second;
        cmbProdutos->addItem(item.key(), QVariant(itemData));
    }

    int novaLinha = ui->tableWidget_ProdutosEnc->rowCount();
    ui->tableWidget_ProdutosEnc->insertRow(novaLinha);
    ui->tableWidget_ProdutosEnc->setCellWidget(novaLinha, 0, cmbProdutos);
    cmbProdutos->setProperty("linha", novaLinha);

    // conectar o sinal de mudança de item da combobox ao slot para atualizar o nome do produto e o seu preço
    connect(cmbProdutos, SIGNAL(currentIndexChanged(int)), this, SLOT(atualizarProdutoEPreco(int)));

    // inicializar as restantes colunas com valores vazios
    ui->tableWidget_ProdutosEnc->setItem(novaLinha, 1, new QTableWidgetItem("")); // produto
    ui->tableWidget_ProdutosEnc->setItem(novaLinha, 2, new QTableWidgetItem("")); // quantidade
    ui->tableWidget_ProdutosEnc->setItem(novaLinha, 3, new QTableWidgetItem("")); // valor unitário
    ui->tableWidget_ProdutosEnc->setItem(novaLinha, 4, new QTableWidgetItem("")); // valor total

    // Reconecta o sinal após adicionar uma nova linha
    connect(ui->tableWidget_ProdutosEnc, &QTableWidget::cellChanged, this, &Encomendas::calcularValorTotalLinha);
}

// atualizar a combobox da tabela 'tableWidget_ProdutosEnc' com a lista de produtos disponíveis
// para o caso de serem adicionados mais produtos à base de dados e pretender alterar uma encomenda existente
void Encomendas::atualizarComboboxProdutos() {
    QMap<QString, QPair<QString, QString>> produtos = listaProdutosDisponiveis();

    for (int i = 0; i < ui->tableWidget_ProdutosEnc->rowCount(); i++) {
        QComboBox* cmbProdutos = qobject_cast<QComboBox*>(ui->tableWidget_ProdutosEnc->cellWidget(i, 0));
        if (cmbProdutos) {
            QString produtoAtual = cmbProdutos->currentData().toString();
            cmbProdutos->clear();
            cmbProdutos->addItem("", QVariant());

            for (auto item = produtos.begin(); item != produtos.end(); item++) {
                QString itemData = item.value().first + ";" + item.value().second;
                cmbProdutos->addItem(item.key(), QVariant(itemData));
            }

            int index = cmbProdutos->findData(produtoAtual);
            if (index != -1) {
                cmbProdutos->setCurrentIndex(index);
            }
        }
    }
}

// preencher automáticamente as colunas nome do produto e preço do produto da tabela 'tableWidget_ProdutosEnc'
// ao selecionar o código do produto na combobox
void Encomendas::atualizarProdutoEPreco(int index) {
    QComboBox* cmbProdutos = qobject_cast<QComboBox*>(sender());
    if(!cmbProdutos) return;

    // Recupera a linha da QComboBox
    int linha = cmbProdutos->property("linha").toInt();

    if(index == 0)
    {
        ui->tableWidget_ProdutosEnc->setItem(linha, 1, new QTableWidgetItem("")); // produto
        ui->tableWidget_ProdutosEnc->setItem(linha, 2, new QTableWidgetItem("")); // quantidade
        ui->tableWidget_ProdutosEnc->setItem(linha, 3, new QTableWidgetItem("")); // valor unitário
        ui->tableWidget_ProdutosEnc->setItem(linha, 4, new QTableWidgetItem("")); // valor total
    }

    else if (index > 0) {
        QString codigoProduto = cmbProdutos->itemData(index).toString();
        // Separa o nome do produto e o preço usando o delimitador definido
        QStringList produtoInfo = codigoProduto.split(";");
        if (produtoInfo.size() >= 2) {
            QString nomeProduto = produtoInfo.at(0);
            QString precoProduto = produtoInfo.at(1);

            //substituir o ponto pela vírgula e definir 2 casas decimais
            double precoVenda = precoProduto.toDouble();
            QString precoVendaSemPonto =  QString::number(precoVenda, 'f', 2);
            precoVendaSemPonto = precoVendaSemPonto.replace('.', ',');
            // Atualiza a tabela com o nome do produto e o preço
            ui->tableWidget_ProdutosEnc->setItem(linha, 1, new QTableWidgetItem(nomeProduto));
            ui->tableWidget_ProdutosEnc->setItem(linha, 3, new QTableWidgetItem(precoVendaSemPonto));
        }
    }
}

// calcular o valor total do produto da encomenda
void Encomendas::calcularValorTotalLinha(int row, int column)
{
    // verificar se a célula alterada está na coluna da quantidade (2) ou do valor unitário (3)
    if (column == 2 || column == 3) {
        bool okQuantidade, okValorUnitario;
        int quantidade = ui->tableWidget_ProdutosEnc->item(row, 2)->text().toInt(&okQuantidade);
        double valorUnitario = ui->tableWidget_ProdutosEnc->item(row, 3)->text().replace(',', '.').toDouble(&okValorUnitario);
        // Verificar se a conversão foi bem-sucedida
        if (okQuantidade && okValorUnitario) {
            double valorTotal = quantidade * valorUnitario;
            QString valorTotalStr = QString::number(valorTotal, 'f', 2).replace('.', ',');
            QTableWidgetItem* itemValorTotal = new QTableWidgetItem(valorTotalStr);
            ui->tableWidget_ProdutosEnc->setItem(row, 4, itemValorTotal);
        }
    }
    calcularValorTotalCabecalho();
}

// calcular o valor total de produtos da encomenda
void Encomendas::calcularValorTotalCabecalho() {
    int qtdTotal = 0;
    double totalVendas = 0;

    for (int i = 0; i < ui->tableWidget_ProdutosEnc->rowCount(); i++) {
        // somatório das quantidades
        QTableWidgetItem* itemQuantidade = ui->tableWidget_ProdutosEnc->item(i, 2);
        if (itemQuantidade && !itemQuantidade->text().isEmpty()) {
            qtdTotal += itemQuantidade->text().toInt();
        }

        // somatório do valor total
        QTableWidgetItem* itemValorTotal = ui->tableWidget_ProdutosEnc->item(i, 4);
        if (itemValorTotal && !itemValorTotal->text().isEmpty()) {
            totalVendas += itemValorTotal->text().replace(',', '.').toDouble();
        }
    }
    // atualiza os valores nos campos
    ui->txtQtdTotal->setText(QString::number(qtdTotal));
    ui->txtTotalVendas->setText(QString::number(totalVendas, 'f', 2).replace('.', ','));
}

// Guardar o registo da encomenda na base de dados
void Encomendas::on_btnGuardar_clicked()
{
    int nif = ui->cmbClientes->currentText().toInt();
    //formatar a data para guardar na base de dados
    QString dataEntregaStr = ui->txtDataEntrega->text();
    QDate dataEntrega = QDate::fromString(dataEntregaStr, "dd-MM-yyyy");
    QString dataEntregaFormatada = dataEntrega.toString("yyyy-MM-dd");
    int qtdTotal = ui->txtQtdTotal->text().toInt();
    double totalVendas = ui->txtTotalVendas->text().replace(',', '.').toDouble();

    if(!ui->txtRegisto->text().isEmpty()) //Encomenda já existe na base de dados
    {
        atualizarEncomenda();
    }
    else  // nova encomenda a ser guardado na base de dados
    {
        if (!verificarCamposCabecalho()) {
            qDebug() << "Falha na verificação dos campos do cabeçalho.";
            return;
        }

        QSqlDatabase bd = QSqlDatabase::database();
        bd.transaction();

        // Primeiro, obter o ID_Cliente
        QSqlQuery obterIdCliente;
        obterIdCliente.prepare("SELECT ID_Cliente FROM cliente WHERE NIF = :nif");
        obterIdCliente.bindValue(":nif", nif);

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
        // Guardar o registo  na tabela Encomenda
        guardarDados.prepare("INSERT INTO encomenda (ID_Cliente, Data_entrega, Qtd_encomenda, Valor) VALUES "
                             "(:ID_Cliente, :Data_entrega, :Qtd_encomenda, :Valor)");
        guardarDados.bindValue(":ID_Cliente", idCliente);
        guardarDados.bindValue(":Data_entrega", dataEntregaFormatada);
        guardarDados.bindValue(":Qtd_encomenda", qtdTotal);
        guardarDados.bindValue(":Valor", totalVendas);

        if (!guardarDados.exec()) {
            qDebug() << "Falha ao inserir na tabela Encomenda:" << guardarDados.lastError().text();
            bd.rollback(); // Desfaz a transação
            return;
        }

        // Recuperar o ID_Encomenda gerado
        int idEncomendaGerado = guardarDados.lastInsertId().toInt();

        // dependendo do número linhas que a tabela tiver
        // obter do ID_Produto e guardar as informações na base de dados na tabela encomendaDetalhe
        // atualizar a tabela stock com a Qtd_reservada (somar à existente)
        int linhas = ui->tableWidget_ProdutosEnc->rowCount();
        for (int linha = 0; linha < linhas; linha++)
        {
            QComboBox* comboBox = qobject_cast<QComboBox*>(ui->tableWidget_ProdutosEnc->cellWidget(linha, 0)); //combobox existente
            // obter o código do item selecionado
            QString codigo = "";
            if (comboBox) {
                codigo = comboBox->currentText();
            }

            QSqlQuery obterIdProduto;
            obterIdProduto.prepare("SELECT ID_Produto FROM produto WHERE Codigo_Produto = :Codigo_Produto");
            obterIdProduto.bindValue(":Codigo_Produto", codigo);

            if (!obterIdProduto.exec()) {
                qDebug() << "Falha ao obter o ID_Produto:" << obterIdProduto.lastError().text();
                return;
            }
            if (!obterIdProduto.next()) {
                qDebug() << "Produto não encontrado.";
                return;
            }

            int idProduto = obterIdProduto.value("ID_Produto").toInt();
            int quantidade = ui->tableWidget_ProdutosEnc->item(linha, 2)->text().toInt();
            double valorTotal = ui->tableWidget_ProdutosEnc->item(linha, 4)->text().replace(',', '.').toDouble();

            // Inserir na tabela 'encomendaDetalhe'
            guardarDados.prepare("INSERT INTO encomendaDetalhe (ID_Encomenda, ID_Produto, Qtd_produto, Valor) VALUES "
                                 "(:ID_Encomenda, :ID_Produto, :Qtd_produto, :Valor)");
            guardarDados.bindValue(":ID_Encomenda", idEncomendaGerado);
            guardarDados.bindValue(":ID_Produto", idProduto);
            guardarDados.bindValue(":Qtd_produto", quantidade);
            guardarDados.bindValue(":Valor", valorTotal);

            if (!guardarDados.exec()) {
                qDebug() << "Falha ao inserir na tabela encomendaDetalhe:" << guardarDados.lastError().text();
                // Remove a encomenda inserida anteriormente
                guardarDados.prepare("DELETE FROM encomenda WHERE ID_Encomenda = :ID_Encomenda");
                guardarDados.bindValue(":ID_Encomenda", idEncomendaGerado);
                if (!guardarDados.exec()) {
                    qDebug() << "Erro ao remover o registo da encomenda:" << guardarDados.lastError().text();
                }
                bd.rollback(); // Desfaz a transação incluindo a tentativa de remoção
                return;
            }

            // Atualizar na tabela 'stock' a quantidade reservada de produto
            guardarDados.prepare("UPDATE stock SET Qtd_reservada = Qtd_reservada + :novaQuantidade WHERE ID_Produto = :ID_Produto");
            guardarDados.bindValue(":novaQuantidade", quantidade);
            guardarDados.bindValue(":ID_Produto", idProduto);

            if (!guardarDados.exec()) {
                qDebug() << "Falha ao atualizar dados na tabela stock:" << guardarDados.lastError().text();

                QSqlQuery queryApagar;
                // Remover da tabela 'encomendaDetalhe' o produto inserido anteriormente
                queryApagar.prepare("DELETE FROM encomendaDetalhe WHERE ID_Produto = :ID_Produto AND "
                                    "ID_Encomenda = :ID_Encomenda");
                queryApagar.bindValue(":ID_Produto", idProduto);
                guardarDados.bindValue(":ID_Encomenda", idEncomendaGerado);
                if (!queryApagar.exec()) {
                    qDebug() << "Erro ao remover o produto da tabela encomendaDetalhe:" << queryApagar.lastError().text();
                }

                // Remove a encomenda inserida anteriormente
                queryApagar.prepare("DELETE FROM encomenda WHERE ID_Encomenda = :ID_Encomenda");
                queryApagar.bindValue(":ID_Encomenda", idEncomendaGerado);
                if (!queryApagar.exec()) {
                    qDebug() << "Erro ao remover o registo da encomenda:" << queryApagar.lastError().text();
                }
                bd.rollback(); // Desfaz a transação
                return;
            }
        } //fim do ciclo for

        if (!bd.commit()) {
            QMessageBox::critical(this, "Erro na base de dados", "Falha ao guardar as informações do encomenda na base de dados."
                                                                 "\nPor favor, contacte o suporte!");
            return;
        }

        qDebug() << "Encomenda registada com sucesso.";
        QMessageBox::information(this, "Aviso", "Encomenda registada com sucesso!");

        limparCampos();
        habilitarCampos();
    }

    ui->btnVoltar_encomendas->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    carregarDadosEncomendas();
    emit encomendasAtualizadas();
}

void Encomendas::on_btnCancelar_clicked()
{
    limparCampos();
    desabilitarCampos();
    ui->btnVoltar_encomendas->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(true);
    preencherComboboxCodigoProduto();
}

// Apresentar todas as encomendas na tabela da lista de encomendas
void Encomendas::carregarDadosEncomendas()
{
    limparTableWidget(ui->tableWidget_encomendas);

    QSqlQuery obterDados;
    obterDados.prepare("SELECT encomenda.ID_Encomenda, encomenda.Num_Encomenda, cliente.Cliente, encomenda.Qtd_encomenda, encomenda.Valor, "
                       "encomenda.Expedida, encomenda.Data_encomenda "
                       "FROM encomenda LEFT JOIN  cliente ON encomenda.ID_Cliente = cliente.ID_Cliente;");

    //verificar o acesso à BD
    if(obterDados.exec())
    {
        int linha = 0;
        ui->tableWidget_encomendas->setColumnCount(7);

        while(obterDados.next())
        {
            ui->tableWidget_encomendas->insertRow(linha);
            for(int coluna = 0; coluna < 7; coluna++)
            {
                QTableWidgetItem* novoItem = new QTableWidgetItem(obterDados.value(coluna).toString());
                ui->tableWidget_encomendas->setItem(linha, coluna, novoItem);

                //substituir o ponto pela vírgula e definir 2 casas decimais
                double valorTotal = obterDados.value("Valor").toDouble();
                QString valorTotalSemPonto =  QString::number(valorTotal, 'f', 2);
                valorTotalSemPonto = valorTotalSemPonto.replace('.', ',');
                ui->tableWidget_encomendas->setItem(linha, 4, new QTableWidgetItem(valorTotalSemPonto));
            }

            linha++;
        }

        ui->lblTotalEncomedas->setText("Encomendas: " + QString::number(linha));

        //colocar os títulos das colunas igual à ordem da query 'obterDados'
        QStringList titulos;
        titulos = {"Registo", "Nr. Encomenda", "Cliente", "Qtd Total (un)", "Valor Total (euros)", "Expedida", "Data Encomenda"};
        ui->tableWidget_encomendas->setHorizontalHeaderLabels(titulos);
        // formatar título
        ui->tableWidget_encomendas->horizontalHeader()->setStyleSheet("QHeaderView::section {color: white; background-color: #004b23; font: bold 10px}");
        ui->tableWidget_encomendas->setStyleSheet("QTableWidget::item {background-color: #f0f0f0; color: black;}");
        // ocultar os números das linhas
        ui->tableWidget_encomendas->verticalHeader()->setVisible(false);
        // ajustar a largura e altura das colunas
        //ui->tableWidget_encomendas->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
        ui->tableWidget_encomendas->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
        //definir a largura da coluna
        ui->tableWidget_encomendas->setColumnWidth(0, 80);
        ui->tableWidget_encomendas->setColumnWidth(1, 100);
        ui->tableWidget_encomendas->setColumnWidth(2, 200);
        ui->tableWidget_encomendas->setColumnWidth(3, 160);
        ui->tableWidget_encomendas->setColumnWidth(4, 180);
        ui->tableWidget_encomendas->setColumnWidth(5, 120);
        ui->tableWidget_encomendas->setColumnWidth(6, 100);
        // desabilitar a edição dos dados
        ui->tableWidget_encomendas->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // selecionar a linha inteira da tabela
        ui->tableWidget_encomendas->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_encomendas->setStyleSheet("QTableWidget {border: 2px solid #004b23;}");
    }
    else
    {
        QMessageBox::critical(this, "Atenção", "Erro ao carregar a informação das Encomendas na tabela.");
        qDebug() << "Erro ao carregar a informação dos Encomendas na tabela:" << obterDados.lastError().text();
        qDebug() << "Consulta SQL Encomendas:" << obterDados.lastQuery();
    }
}

// limpar os dados da tabela
void Encomendas::limparTableWidget(QTableWidget *limpaTW)
{
    while(limpaTW->rowCount() > 0)
    {
        limpaTW->removeRow(0);
    }
}

// apresentar a informação detalhada da encomenda na página de registo de encomendas
void Encomendas::on_tableWidget_encomendas_cellDoubleClicked()
{
    ui->btnVoltar_encomendas->setEnabled(true);
    ui->btnEliminar->setEnabled(true);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(true);
    ui->btnAdLinha->setHidden(true);
    ui->btnEliminaLinha->setHidden(true);
    limparCampos();
    desabilitarCampos();

    int idEncomenda =0;
    int linhaAtual = 0;

    linhaAtual = ui->tableWidget_encomendas->currentRow();
    idEncomendaSelecionada = ui->tableWidget_encomendas->item(linhaAtual, 0)->text();
    idEncomenda = idEncomendaSelecionada.toInt();

    ui->stackedWidget->setCurrentIndex(1); // página de registo de encomendas
    QSqlQuery obterDados;
    obterDados.prepare("SELECT encomenda.ID_Encomenda, encomenda.Num_Encomenda, encomenda.Qtd_encomenda, encomenda.Data_encomenda, "
                       "encomenda.Valor, encomenda.Data_entrega, encomenda.Expedida, cliente.NIF, cliente.Cliente "
                       "FROM encomenda LEFT JOIN cliente ON encomenda.ID_Cliente = cliente.ID_Cliente "
                       "WHERE encomenda.ID_Encomenda = :ID_Encomenda;");
    obterDados.bindValue(":ID_Encomenda", idEncomenda);

    if(obterDados.exec() && obterDados.first())
    {
        // preencher o cabeçalho
        ui->txtRegisto->setText(obterDados.value("ID_Encomenda").toString());
        ui->txtCodigo->setText(obterDados.value("Num_Encomenda").toString());
        ui->txtNome->setText(obterDados.value("Cliente").toString());
        ui->txtQtdTotal->setText(obterDados.value("Qtd_encomenda").toString());
        ui->txtExpedida->setText(obterDados.value("Expedida").toString());
        //substituir o ponto pela vírgula
        double valorTotal = obterDados.value("Valor").toDouble();
        QString valorTotalSemPonto = QString::number(valorTotal, 'f', 2).replace('.', ',');
        ui->txtTotalVendas->setText(valorTotalSemPonto);
        // formatar data do registo da encomenda
        QString dataStr = obterDados.value("Data_encomenda").toString();
        QDateTime dataHora = QDateTime::fromString(dataStr, Qt::ISODate);
        QString dataFormatada = dataHora.toString("dd-MM-yyyy");
        ui->txtDataCriacao->setText(dataFormatada);
        // formatar data de entrega
        QString dataEntregaStr = obterDados.value("Data_entrega").toString();
        if(dataEntregaStr != ""){
            QDate dataEntrega = QDate::fromString(dataEntregaStr, "yyyy-MM-dd");
            QString dataEntregaFormatada = dataEntrega.toString("dd-MM-yyyy");
            ui->txtDataEntrega->setText(dataEntregaFormatada);
        }
        else{
            ui->txtDataEntrega->setText("");
        }

        // apresentar o nif do cliente no campo 'cmbClientes'
        QString nifCliente = obterDados.value("NIF").toString();
        ui->cmbClientes->setCurrentText(nifCliente);

        // preencher as linhas com os detalhes da encomenda
        QSqlQuery obterDetalhesEncomenda;
        obterDetalhesEncomenda.prepare("SELECT encomendaDetalhe.ID_EncomendaDetalhe, encomendaDetalhe.Qtd_produto, encomendaDetalhe.Valor, produto.Preco_venda, "
                                       "produto.Codigo_Produto, produto.Produto "
                                       "FROM encomendaDetalhe LEFT JOIN produto ON encomendaDetalhe.ID_Produto = produto.ID_Produto "
                                       "WHERE encomendaDetalhe.ID_Encomenda = :ID_Encomenda");
        obterDetalhesEncomenda.bindValue(":ID_Encomenda", idEncomenda);

        if (obterDetalhesEncomenda.exec()) {
            int novaLinha = 0;
            ui->tableWidget_ProdutosEnc->setRowCount(novaLinha);
            while(obterDetalhesEncomenda.next())
            {
                ui->tableWidget_ProdutosEnc->insertRow(novaLinha);

                //armazenar o ID_EncomendaDetalhe de cada linha da 'tableWidget_ProdutosEnc'
                int idEncomendaDetalhe = obterDetalhesEncomenda.value("ID_EncomendaDetalhe").toInt();
                itemIDEncDetalhe = new QTableWidgetItem(obterDetalhesEncomenda.value("ID_EncomendaDetalhe").toString());
                // armazenar o ID_EncomendaDetalhe usando Qt::UserRole
                itemIDEncDetalhe->setData(Qt::UserRole + 1, idEncomendaDetalhe);
                // adicionar o item à primeira coluna da nova linha
                ui->tableWidget_ProdutosEnc->setItem(novaLinha, 0, itemIDEncDetalhe);
                //qDebug() << "ID_EncomendaDetalhe linha " << novaLinha <<": " << itemIDEncDetalhe->data(Qt::UserRole + 1).toInt();

                QString codigoProduto = obterDetalhesEncomenda.value("Codigo_Produto").toString();
                QComboBox* cmbProdutos = new QComboBox(ui->tableWidget_ProdutosEnc);
                cmbProdutos->addItem(codigoProduto);
                cmbProdutos->setCurrentIndex(0);
                ui->tableWidget_ProdutosEnc->setCellWidget(novaLinha, 0, cmbProdutos);
                cmbProdutos->setProperty("linha", novaLinha);

                disconnect(ui->tableWidget_ProdutosEnc, &QTableWidget::cellChanged, this, &Encomendas::calcularValorTotalLinha);
                ui->tableWidget_ProdutosEnc->setItem(novaLinha, 1, new QTableWidgetItem(obterDetalhesEncomenda.value("Produto").toString())); // produto
                ui->tableWidget_ProdutosEnc->setItem(novaLinha, 2, new QTableWidgetItem(obterDetalhesEncomenda.value("Qtd_produto").toString())); // quantidade
                //substituir o ponto pela vírgula
                double valorUnitario = obterDetalhesEncomenda.value("Preco_venda").toDouble();
                QString valorUnitarioSemPonto = QString::number(valorUnitario, 'f', 2).replace('.', ',');
                ui->tableWidget_ProdutosEnc->setItem(novaLinha, 3, new QTableWidgetItem(valorUnitarioSemPonto)); // valor unitário
                double valorTotal = obterDetalhesEncomenda.value("Valor").toDouble();
                QString valorTotalSemPonto = QString::number(valorTotal, 'f', 2).replace('.', ',');
                ui->tableWidget_ProdutosEnc->setItem(novaLinha, 4, new QTableWidgetItem(valorTotalSemPonto)); // valor total

                //armazenar a quantidade de produto de cada linha da 'tableWidget_ProdutosEnc'
                int quantidadeInicial = obterDetalhesEncomenda.value("Qtd_produto").toInt();
                itemQuantidade = new QTableWidgetItem(obterDetalhesEncomenda.value("Qtd_produto").toString());
                itemQuantidade->setData(Qt::UserRole + 2, quantidadeInicial);
                ui->tableWidget_ProdutosEnc->setItem(novaLinha, 2, itemQuantidade);
                //qDebug() << "Quantidade inicial armazenada linha " << novaLinha <<": " << itemQuantidade->data(Qt::UserRole + 2).toInt();
                //qDebug() << "ID_EncomendaDetalhe PONTO 2 linha " << novaLinha <<": " << itemIDEncDetalhe->data(Qt::UserRole + 1).toInt();
                novaLinha++;
                calcularValorTotalCabecalho();
            }
        } else {
            qDebug() << "Erro ao obter os detalhes da encomenda: " << obterDetalhesEncomenda.lastError().text();
        }
    }
    else
    {
        QMessageBox::critical(this, "Atenção", "Erro ao carregar dados da encomenda!");
    }
    connect(ui->tableWidget_ProdutosEnc, &QTableWidget::cellChanged, this, &Encomendas::calcularValorTotalLinha);
}

void Encomendas::on_btnModificar_clicked()
{
    ui->btnVoltar_encomendas->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    habilitarCampos();

    if(!ui->txtRegisto->text().isEmpty()) //Encomenda já existe na base de dados
    {
        ui->cmbClientes->setEnabled(false);
    }
    else{
        ui->btnAdLinha->setHidden(false);
        ui->btnEliminaLinha->setHidden(false);
    }
}

// atualizar o registo da encomenda na base de dados
//NOTA: só é possível alterar encomendas não expedidas, parcialmente ou totalmente e que não contenham produtos em produção - CORRIGIR
// neste momento só é possível atualizar as quantidades de produto
void Encomendas::atualizarEncomenda()
{
    int idEncomenda = idEncomendaSelecionada.toInt();
    // obter a informação do cabeçalho
    QString dataEntregaStr = ui->txtDataEntrega->text();
    QDate dataEntrega = QDate::fromString(dataEntregaStr, "dd-MM-yyyy");
    QString dataEntregaFormatada = dataEntrega.toString("yyyy-MM-dd");
    int qtdTotal = ui->txtQtdTotal->text().toInt();
    double totalVendas = ui->txtTotalVendas->text().replace(',', '.').toDouble();

    // Antes de proceder com a atualização, verificar os campos
    if (!verificarCamposCabecalho()) {
        qDebug() << "Falha na verificação dos campos do cabeçalho.";
        return;
    }

    // ligação à base de dados
    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction(); // Inicia uma transação

    QSqlQuery atualizarEncomenda;

    // Alterar na tabela 'Encomenda'
    atualizarEncomenda.prepare("UPDATE encomenda SET Data_entrega = :Data_entrega, "
                               "Valor = :Valor, Qtd_encomenda = :Qtd_encomenda "
                               "WHERE ID_Encomenda = :ID_Encomenda");
    atualizarEncomenda.bindValue(":ID_Encomenda", idEncomenda);
    atualizarEncomenda.bindValue(":Data_entrega", dataEntregaFormatada);
    atualizarEncomenda.bindValue(":Valor", totalVendas);
    atualizarEncomenda.bindValue(":Qtd_encomenda", qtdTotal);

    if (!atualizarEncomenda.exec()) {
        qDebug() << "Falha ao atualizar dados na tabela Encomenda:" << atualizarEncomenda.lastError().text();
        bd.rollback();
        return;
    }

    // obter a informação das linhas
    int linhas = ui->tableWidget_ProdutosEnc->rowCount();
    for (int linha = 0; linha < linhas; linha++)
    {
        // Primeiro, recuperar o ID_EncomendaDetalhe de cada linha
        int idEncomendaDetalhe = 0;
        // recuperar o item da primeira coluna (aonde foi armazenado o ID_EncomendaDetalhe)
        itemIDEncDetalhe = ui->tableWidget_ProdutosEnc->item(linha, 0);
        idEncomendaDetalhe = itemIDEncDetalhe->data(Qt::UserRole + 1).toInt();

        // recuperar a quantProdutoInicial de cada linha
        int quantProdutoInicial = 0;
        itemQuantidade = ui->tableWidget_ProdutosEnc->item(linha, 2);
        quantProdutoInicial = itemQuantidade->data(Qt::UserRole + 2).toInt();


        QComboBox* cmbProdutos = qobject_cast<QComboBox*>(ui->tableWidget_ProdutosEnc->cellWidget(linha, 0)); //combobox existente
        // obter o código do item selecionado
        QString codigo = "";
        if (cmbProdutos) {
            codigo = cmbProdutos->currentText();
        }

        QSqlQuery obterIdProduto;
        obterIdProduto.prepare("SELECT ID_Produto FROM produto WHERE Codigo_Produto = :Codigo_Produto");
        obterIdProduto.bindValue(":Codigo_Produto", codigo);

        if (!obterIdProduto.exec()) {
            qDebug() << "Falha ao obter o ID_Produto:" << obterIdProduto.lastError().text();
            return;
        }
        if (!obterIdProduto.next()) {
            qDebug() << "Produto não encontrado.";
            return;
        }

        int idProduto = obterIdProduto.value("ID_Produto").toInt();


        int quantProdutoAtual = ui->tableWidget_ProdutosEnc->item(linha, 2)->text().toInt();
        double valorProduto = ui->tableWidget_ProdutosEnc->item(linha, 4)->text().replace(',', '.').toDouble();

        int diferencaQuantidade = quantProdutoAtual - quantProdutoInicial;
        /*
        qDebug() << "ID_EncomendaDetalhe: " << idEncomendaDetalhe;
        qDebug() << "Quantidade Inicial: " << quantProdutoInicial;
        qDebug() << "Quantidade Atual: " << quantProdutoAtual;
        qDebug() << "Diferença de Quantidade: " << diferencaQuantidade;
        */

        /*
        // Antes de proceder com a atualização, verificar os campos
        if (!verificarCamposLinhas()) {
            qDebug() << "Falha na verificação dos campos das linhas.";
            return;
        }*/


        /*
        QSqlQuery atualizarEncomendaDetalhe;
        // Alterar na tabela 'encomendaDetalhe'
        atualizarEncomendaDetalhe.prepare("UPDATE encomendaDetalhe SET ID_Produto = :ID_Produto, "
                                       "Valor = :Valor, Qtd_produto = :Qtd_produto "
                                       "WHERE ID_EncomendaDetalhe = :ID_EncomendaDetalhe ");
        atualizarEncomendaDetalhe.bindValue(":ID_EncomendaDetalhe", idEncomendaDetalhe);
        atualizarEncomendaDetalhe.bindValue(":ID_Produto", idProduto);
        atualizarEncomendaDetalhe.bindValue(":Valor", valorProduto);
        atualizarEncomendaDetalhe.bindValue(":Qtd_produto", quantProdutoAtual);
        */


        QSqlQuery atualizarEncomendaDetalhe;
        // Alterar na tabela 'encomendaDetalhe'
        atualizarEncomendaDetalhe.prepare("UPDATE encomendaDetalhe SET "
                                          "Valor = :Valor, Qtd_produto = :Qtd_produto "
                                          "WHERE ID_EncomendaDetalhe = :ID_EncomendaDetalhe ");
        atualizarEncomendaDetalhe.bindValue(":ID_EncomendaDetalhe", idEncomendaDetalhe);
        atualizarEncomendaDetalhe.bindValue(":Valor", valorProduto);
        atualizarEncomendaDetalhe.bindValue(":Qtd_produto", quantProdutoAtual);

        if (!atualizarEncomendaDetalhe.exec()) {
            qDebug() << "Falha ao atualizar dados na tabela EncomendaDetalhe:" << atualizarEncomenda.lastError().text();
            bd.rollback();
            return;
        }

        QSqlQuery atualizarStock;
        // atualizar na tabela 'stock' a quantidade reservada de produto
        atualizarStock.prepare("UPDATE stock SET Qtd_reservada = Qtd_reservada + :novaQuantidade WHERE ID_Produto = :ID_Produto");
        atualizarStock.bindValue(":novaQuantidade", diferencaQuantidade);
        atualizarStock.bindValue(":ID_Produto", idProduto);


        if (!atualizarStock.exec()) {
            qDebug() << "Falha ao atualizar dados na tabela stock:" << atualizarStock.lastError().text();
            bd.rollback(); // Desfaz a transação
            return;
        }
    } //fim do ciclo for

    if (!bd.commit()) {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao guardar as alterações da encomenda na base de dados."
                                                             "\nPor favor, contacte o suporte!");
        return;
    }
    qDebug() << "Encomenda alterada com sucesso.";
    QMessageBox::information(this, "Aviso", "Alterações guardadas com sucesso!");

    limparCampos();
    habilitarCampos();
}

// NOTA: só é possível eliminar encomendas não expedidas, parcialmente ou totalmente, e que não contenham produtos em produção - CORRIGIR
void Encomendas::on_btnEliminar_clicked()
{
    if (ui->txtRegisto->text().isEmpty()){
        QMessageBox::warning(this, "Registo vazio", "Não é possível eliminar registos vazios.");
        return;
    }
    else{
        QMessageBox::StandardButton confirmar;
        confirmar = QMessageBox::question(this, "Confirmar",
                                          "Pretende eliminar a encomenda " + ui->txtCodigo->text() + "?",
                                          QMessageBox::Yes|QMessageBox::No);

        if (confirmar == QMessageBox::Yes)
        {
            int idEncomenda = idEncomendaSelecionada.toInt();

            QSqlDatabase bd = QSqlDatabase::database();
            bd.transaction();

            QSqlQuery obterInfoProduto;
            obterInfoProduto.prepare("SELECT ID_Produto, Qtd_produto FROM encomendaDetalhe WHERE ID_Encomenda = :idSelecionado");
            obterInfoProduto.bindValue(":idSelecionado", idEncomenda);

            if (obterInfoProduto.exec()) {
                while (obterInfoProduto.next()) {
                    int idProduto = obterInfoProduto.value("ID_Produto").toInt();
                    int quantProduto = obterInfoProduto.value("Qtd_produto").toInt();

                    // atualizar na tabela 'stock' a quantidade reservada de produto
                    QSqlQuery atualizarStock;
                    atualizarStock.prepare("UPDATE stock SET Qtd_reservada = Qtd_reservada - :novaQuantidade WHERE ID_Produto = :ID_Produto");
                    atualizarStock.bindValue(":novaQuantidade", quantProduto);
                    atualizarStock.bindValue(":ID_Produto", idProduto);
                    if (!atualizarStock.exec()) {
                        qDebug() << "Falha ao atualizar dados na tabela stock:" << atualizarStock.lastError().text();
                        bd.rollback(); // Desfaz a transação
                        return;
                    }
                }
            } else {
                qDebug() << "Erro ao obter produtos:" << obterInfoProduto.lastError().text();
            }

            // elimnar o(s) registo(s) da encomenda da tabela 'encomendaDetalhe'
            QSqlQuery eliminarEncomendaDetalhe;
            eliminarEncomendaDetalhe.prepare("DELETE FROM encomendaDetalhe WHERE ID_Encomenda = :idSelecionado");
            eliminarEncomendaDetalhe.bindValue(":idSelecionado", idEncomenda);
            if (!eliminarEncomendaDetalhe.exec()) {
                bd.rollback(); // Reverte a transação se ocorrer um erro
                qDebug() << "Erro ao excluir o registo da tabela encomenda:" << eliminarEncomendaDetalhe.lastError().text();
                return;
            }

            // elimnar o registo da encomenda da tabela 'encomenda'
            QSqlQuery eliminarEncomenda;
            eliminarEncomenda.prepare("DELETE FROM encomenda WHERE ID_Encomenda = :idSelecionado");
            eliminarEncomenda.bindValue(":idSelecionado", idEncomenda);
            if (!eliminarEncomenda.exec()) {
                bd.rollback(); // Reverte a transação se ocorrer um erro
                qDebug() << "Erro ao excluir o registo da tabela encomenda:" << eliminarEncomenda.lastError().text();
                return;
            }

            if (!bd.commit()) {
                QMessageBox::critical(this, "Erro na base de dados", "Falha ao eliminar o registo da encomenda da base de dados."
                                                                     "\nPor favor, contacte o suporte!");
                return;
            }

            QMessageBox::information(this, "Aviso", "Encomenda eliminada com sucesso!");

            ui->btnVoltar_encomendas->setEnabled(true);
            ui->btnEliminar->setEnabled(false);
            ui->btnGuardar->setEnabled(false);
            ui->btnCancelar->setEnabled(false);
            ui->btnModificar->setEnabled(false);

            limparCampos();
            desabilitarCampos();
            carregarDadosEncomendas();
            emit encomendasAtualizadas();
        }
    }
}

void Encomendas::on_btnPesquisar_clicked()
{
    QString codigo = ui->txtCodigo_2->text();
    QString cliente = ui->txtCliente->text();
    QString expedida = ui->cmbPesquisar->currentText();

    // construir a consulta SQL
    QString pesquisa = "SELECT encomenda.ID_Encomenda, encomenda.Num_Encomenda, cliente.Cliente, encomenda.Qtd_encomenda, encomenda.Valor, "
                       "encomenda.Expedida, encomenda.Data_encomenda "
                       "FROM encomenda LEFT JOIN  cliente ON encomenda.ID_Cliente = cliente.ID_Cliente WHERE 1=1 ";

    if (!codigo.isEmpty()) {
        pesquisa += " AND Num_Encomenda = :codigo";
    }

    if (!cliente.isEmpty()) {
        pesquisa += " AND Cliente LIKE :cliente";
        cliente = "%" + cliente + "%";
    }

    if (!expedida.isEmpty()) {
        pesquisa += " AND Expedida = :expedida";
    }

    // executar a consulta
    QSqlQuery queryPesquisa;
    queryPesquisa.prepare(pesquisa);
    queryPesquisa.bindValue(":codigo", codigo);
    queryPesquisa.bindValue(":cliente", cliente);
    queryPesquisa.bindValue(":expedida", expedida);

    if (queryPesquisa.exec()) {
        limparTableWidget(ui->tableWidget_encomendas);
        int linha = 0;

        while (queryPesquisa.next()) {
            ui->tableWidget_encomendas->insertRow(linha);
            for(int coluna = 0; coluna < 7; coluna++)
            {
                QTableWidgetItem* novoItem = new QTableWidgetItem(queryPesquisa.value(coluna).toString());
                ui->tableWidget_encomendas->setItem(linha, coluna, novoItem);

                //substituir o ponto pela vírgula e definir 2 casas decimais
                double valorTotal = queryPesquisa.value("Valor").toDouble();
                QString valorTotalSemPonto =  QString::number(valorTotal, 'f', 2);
                valorTotalSemPonto = valorTotalSemPonto.replace('.', ',');
                ui->tableWidget_encomendas->setItem(linha, 4, new QTableWidgetItem(valorTotalSemPonto));
            }

            linha++;
        }
        ui->lblTotalEncomedas->setText("Encomendas: " + QString::number(linha));
    } else {
        qDebug() << "Erro ao executar a consulta:" << queryPesquisa.lastError().text();
    }
}

void Encomendas::on_btnLimparPesquisa_clicked()
{
    ui->txtCodigo_2->clear();
    ui->txtCliente->clear();
    ui->cmbPesquisar->setCurrentIndex(0);
    carregarDadosEncomendas();
}

bool Encomendas::verificarCamposCabecalho()
{
    if(ui->cmbClientes->currentIndex() == 0){
        ui->lblErro->setText("Atenção! O campo NIF é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->cmbClientes->setFocus();
        return false;
    }

    QString dataEntregaStr = ui->txtDataEntrega->text();
    QDate dataEntrega = QDate::fromString(dataEntregaStr, "dd-MM-yyyy");

    if(!dataEntrega.isNull() && dataEntrega < QDate::currentDate()){
        ui->lblErro->setText("Atenção! A Data de Entrega não pode ser inferior à data atual.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtDataEntrega->setFocus();
        return false;
    }

    return true;
}

// CORRIGIR
bool Encomendas::verificarCamposLinhas()
{
    // verificar se os campos estão todos preenchidos e verificar se tem produtos repetidos

    return true;
}

void Encomendas::on_calendarWidget_selectionChanged()
{
    QDate date = ui->calendarWidget->selectedDate();
    QString dataFormato = date.toString("dd-MM-yyyy");
    ui->txtDataEntrega->setText(dataFormato);
}

void Encomendas::on_txtDataEntrega_editingFinished()
{
    QString data = ui->txtDataEntrega->text();
    QDate date = QDate::fromString(data, "dd-MM-yyyy");

    if (date.isValid()) {
        ui->calendarWidget->setSelectedDate(date);
    } else {
        qDebug() << "A Data fornecida é inválida.";
    }
}

void Encomendas::limparCampos()
{
    ui->txtDataEntrega->clear();
    ui->cmbClientes->setCurrentIndex(0);
    preencherComboboxCliente();
    ui->txtNome->clear();
    ui->txtRegisto->clear();
    ui->txtCodigo->clear();
    ui->txtDataCriacao->clear();
    ui->txtQtdTotal->clear();
    ui->txtTotalVendas->clear();
    ui->txtExpedida->clear();
    limparTableWidget(ui->tableWidget_ProdutosEnc);
}

void Encomendas::desabilitarCampos()
{
    ui->txtDataEntrega->setReadOnly(true);
    ui->cmbClientes->setEnabled(false);
    ui->txtNome->setReadOnly(true);
    ui->calendarWidget->setEnabled(false);
    ui->tableWidget_ProdutosEnc->setEnabled(false);
    ui->btnAdLinha->setEnabled(false);
    ui->btnEliminaLinha->setEnabled(false);
}

void Encomendas::habilitarCampos()
{
    ui->txtDataEntrega->setReadOnly(false);
    ui->cmbClientes->setEnabled(true);
    ui->txtNome->setReadOnly(true);
    ui->calendarWidget->setEnabled(true);
    ui->tableWidget_ProdutosEnc->setEnabled(true);
    ui->btnAdLinha->setEnabled(true);
    ui->btnEliminaLinha->setEnabled(true);
}
