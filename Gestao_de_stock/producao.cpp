#include "producao.h"
#include "ui_producao.h"
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


Producao::Producao(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Producao)
{
    ui->setupUi(this);
    // inicializa na página 0 - lista de ordens de produção
    ui->stackedWidget->setCurrentIndex(0);

    // formatar o estilo dos botões
    QString buttonStyle = "QPushButton:enabled {background-color: #F09200; color: #004b23; "
                          "border: 1.5px solid #F09200;border-style: outset; border-radius: 5px;}"
                          "QPushButton:disabled {background-color: #FFC374;}";

    ui->btnVoltar_producao->setStyleSheet(buttonStyle);
    ui->btnEliminar->setStyleSheet(buttonStyle);
    ui->btnGuardar->setStyleSheet(buttonStyle);
    ui->btnCancelar->setStyleSheet(buttonStyle);
    ui->btnModificar->setStyleSheet(buttonStyle);

    // formatar o estilo dos botões
    QString buttonStyle2 = "QPushButton:enabled {background-color: #A4CE95; color: #004b23; "
                           "border: 1px solid #004b23;border-style: outset; border-radius: 1px;}"
                           "QPushButton:disabled {background-color: rgb(208, 208, 208);}";

    ui->btnProducao->setStyleSheet(buttonStyle2);
    ui->btnFechar->setStyleSheet(buttonStyle2);
    ui->btnProducao->setEnabled(false);
    ui->btnFechar->setEnabled(false);
    ui->btnAdLinha->setHidden(true);
    ui->btnEliminaLinha->setHidden(true);

    // formatar a tabela dos produtos a produzir
    ui->tableWidget_Produtos->setColumnCount(5);
    QStringList titulos;
    titulos = {"Cód. Produto", "Produto", "Gama", "Cor", "Quant. a produzir"};
    ui->tableWidget_Produtos->setHorizontalHeaderLabels(titulos);
    // formatar título
    ui->tableWidget_Produtos->horizontalHeader()->setStyleSheet("QHeaderView::section {color: white; background-color: #004b23; font: bold 10px}");
    ui->tableWidget_Produtos->setStyleSheet("QTableWidget::item {background-color: #f0f0f0; color: black;}");
    // exibir os números das linhas
    ui->tableWidget_Produtos->verticalHeader()->setVisible(true);
    // ajustar a altura das colunas
    ui->tableWidget_Produtos->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
    // desabilitar a edição dos dados
    ui->tableWidget_Produtos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //definir a largura da coluna
    ui->tableWidget_Produtos->setColumnWidth(0, 100);
    ui->tableWidget_Produtos->setColumnWidth(1, 180);
    ui->tableWidget_Produtos->setColumnWidth(2, 160);
    ui->tableWidget_Produtos->setColumnWidth(3, 140);
    ui->tableWidget_Produtos->setColumnWidth(4, 140);
    ui->tableWidget_Produtos->setStyleSheet("QTableWidget {border: 2px solid #004b23;}");

    ui->cmbNrEncomenda->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->txtDataProducao->setInputMask("99-99-9999;_");
    ui->txtCliente->setReadOnly(true);
    carregarDadosProducao();
}

Producao::~Producao()
{
    delete ui;
}

void Producao::on_btnInicio_producao_clicked()
{
    emit InicioClicked();
}

void Producao::on_btnVoltar_producao_clicked()
{
    limparCampos();
    ui->stackedWidget->setCurrentIndex(0);
}

void Producao::on_btnNovo_OP_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    limparCampos();
    habilitarCampos();
    ui->btnVoltar_producao->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    ui->btnProducao->setEnabled(false);
    ui->btnFechar->setEnabled(false);
    preencherComboboxNrEncomenda(false);

    QStringList titulos;
    titulos = {"Cód. Produto", "Produto", "Gama", "Cor", "Quant. a produzir"};
    ui->tableWidget_Produtos->setHorizontalHeaderLabels(titulos);
    ui->lblQuantidade->setText("Quant. Total a produzir");
}

// preencher a combobox com os Números de Encomendas existentes
void Producao::preencherComboboxNrEncomenda(bool mostrarTodasEncomendas = false)
{
    ui->cmbNrEncomenda->clear();
    ui->cmbNrEncomenda->addItem("");

    QString queryString = "SELECT encomenda.Num_Encomenda FROM encomenda ";

    if (!mostrarTodasEncomendas) {
        queryString += "INNER JOIN encomendaDetalhe ON encomenda.ID_Encomenda = encomendaDetalhe.ID_Encomenda "
                       "WHERE encomenda.Expedida <> 'Total' AND encomendaDetalhe.Produzido <> 1 GROUP BY encomenda.Num_Encomenda;";
    } else {
        queryString += "GROUP BY encomenda.Num_Encomenda;";
    }

    QSqlQuery obterNrEncomenda;
    obterNrEncomenda.prepare(queryString);

    if(obterNrEncomenda.exec())
    {
        while(obterNrEncomenda.next())
        {
            ui->cmbNrEncomenda->addItem(obterNrEncomenda.value("Num_Encomenda").toString());
        }
    }
    else
    {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao carregar Nr. da Encomenda."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Erro ao carregar Nr. da Encomenda:" << obterNrEncomenda.lastError().text();
    }
}

void Producao::on_cmbNrEncomenda_currentTextChanged(const QString &nrEncomenda)
{
    if (nrEncomenda.isEmpty()) {
        ui->txtCliente->clear();
        limparTableWidget(ui->tableWidget_Produtos);
        calcularQuantidadeTotalCabecalho();
        return;
    }

    QSqlQuery obterNomeCliente;
    obterNomeCliente.prepare("SELECT cliente.Cliente FROM cliente INNER JOIN encomenda ON cliente.ID_Cliente = encomenda.ID_Cliente "
                             "WHERE encomenda.Num_Encomenda = :Num_Encomenda");
    obterNomeCliente.bindValue(":Num_Encomenda", nrEncomenda);

    if (obterNomeCliente.exec() && obterNomeCliente.next()) {
        QString nomeCliente = obterNomeCliente.value("Cliente").toString();
        ui->txtCliente->setText(nomeCliente);
    } else {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao obter o nome do cliente."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Erro ao obter o nome do cliente:" << obterNomeCliente.lastError().text();
        ui->txtCliente->clear();
    }

    limparTableWidget(ui->tableWidget_Produtos);
    preencherComboboxCodigoProduto(nrEncomenda);
    calcularQuantidadeTotalCabecalho();
}

// Obter os produtos existentes da encomenda selecionada
QMap<QString, QList<QString>> Producao::produtosEncomendaSelecionada(const QString &nrEncomenda, bool mostrarTodosProdutos = false) {
    QMap<QString, QList<QString>> infoProdutos;

    QString queryString = "SELECT produto.Codigo_Produto, produto.Produto, produtodetalhe.Gama, produtodetalhe.Cor, encomendadetalhe.Qtd_produto "
                          "FROM produto INNER JOIN produtodetalhe ON produto.ID_Produto = produtodetalhe.ID_Produto "
                          "INNER JOIN encomendadetalhe ON produto.ID_Produto = encomendadetalhe.ID_Produto "
                          "INNER JOIN encomenda ON encomendadetalhe.ID_Encomenda = encomenda.ID_Encomenda "
                          "WHERE encomenda.Num_Encomenda = :Num_Encomenda ";

    if (!mostrarTodosProdutos) {
        queryString += "AND encomendadetalhe.Produzido = 0;";
    } else {
        queryString += ";";
    }

    QSqlQuery obterInfoProdutos;
    obterInfoProdutos.prepare(queryString);
    obterInfoProdutos.bindValue(":Num_Encomenda", nrEncomenda);

    if (obterInfoProdutos.exec()) {
        while (obterInfoProdutos.next()) {
            QString codigo = obterInfoProdutos.value("Codigo_Produto").toString();
            QList<QString> info = { obterInfoProdutos.value("Produto").toString(),
                obterInfoProdutos.value("Gama").toString(),
                obterInfoProdutos.value("Cor").toString(),
                obterInfoProdutos.value("Qtd_produto").toString()
            };
            infoProdutos.insert(codigo, info);

        }
    } else {
        qDebug() << "Erro ao obter produtos:" << obterInfoProdutos.lastError().text();
    }
    return infoProdutos;
}

// preencher a combobox como o código dos produtos da encomenda selecionada
void Producao::preencherComboboxCodigoProduto(const QString &nrEncomenda)
{
    QComboBox* cmbProdutos = new QComboBox(ui->tableWidget_Produtos);
    QMap<QString, QList<QString>>  produtos = produtosEncomendaSelecionada(nrEncomenda);

    cmbProdutos->clear();
    cmbProdutos->addItem("", QVariant());

    for(auto codigo = produtos.begin(); codigo != produtos.end(); codigo++) {
        // serializa a lista de informações do produto numa única string, usando ";" como separador.
        QString codigoInfo = codigo.value().join(";");
        // adiciona o código do produto como texto visível e a string como dados do item.
        cmbProdutos->addItem(codigo.key(), QVariant(codigoInfo));
    }

    int novaLinha = ui->tableWidget_Produtos->rowCount();
    ui->tableWidget_Produtos->insertRow(novaLinha);
    ui->tableWidget_Produtos->setCellWidget(novaLinha, 0, cmbProdutos);
    cmbProdutos->setProperty("linha", novaLinha);

    // conectar o sinal de mudança de item da combobox ao slot para atualizar os restantes campos
    connect(cmbProdutos, SIGNAL(currentIndexChanged(int)), this, SLOT(atualizarInfoProduto(int)));

    // inicializar as restantes colunas com valores vazios
    ui->tableWidget_Produtos->setItem(novaLinha, 1, new QTableWidgetItem("")); // produto
    ui->tableWidget_Produtos->setItem(novaLinha, 2, new QTableWidgetItem("")); // Gama
    ui->tableWidget_Produtos->setItem(novaLinha, 3, new QTableWidgetItem("")); // Cor
    ui->tableWidget_Produtos->setItem(novaLinha, 4, new QTableWidgetItem("")); // Quantidade a produzir
}

// ao selecionar um produto na combobox preencher os valores das restantes colunas da tabela automaticamente
void Producao::atualizarInfoProduto(int index)
{
    QComboBox* cmbProdutos = qobject_cast<QComboBox*>(sender());
    if(!cmbProdutos) return;

    // Recupera a linha da QComboBox
    int linha = cmbProdutos->property("linha").toInt();

    if(index == 0)
    {
        ui->tableWidget_Produtos->setItem(linha, 1, new QTableWidgetItem(""));
        ui->tableWidget_Produtos->setItem(linha, 2, new QTableWidgetItem(""));
        ui->tableWidget_Produtos->setItem(linha, 3, new QTableWidgetItem(""));
        ui->tableWidget_Produtos->setItem(linha, 4, new QTableWidgetItem(""));
    }

    else if (index > 0) {
        QString codigoProduto = cmbProdutos->itemData(index).toString();
        QStringList produtoInfo = codigoProduto.split(";");
        if (produtoInfo.size() >= 4) {
            QString nomeProduto = produtoInfo.at(0);
            QString gama = produtoInfo.at(1);
            QString cor = produtoInfo.at(2);
            QString quantidade = produtoInfo.at(3);

            ui->tableWidget_Produtos->setItem(linha, 1, new QTableWidgetItem(nomeProduto));
            ui->tableWidget_Produtos->setItem(linha, 2, new QTableWidgetItem(gama));
            ui->tableWidget_Produtos->setItem(linha, 3, new QTableWidgetItem(cor));
            ui->tableWidget_Produtos->setItem(linha, 4, new QTableWidgetItem(quantidade));
        }
    }
    calcularQuantidadeTotalCabecalho();
}

void Producao::calcularQuantidadeTotalCabecalho() {
    int qtdTotal = 0;
    for (int linha = 0; linha < ui->tableWidget_Produtos->rowCount(); linha++) {
        // somatório das quantidades
        QTableWidgetItem* itemQuantidade = ui->tableWidget_Produtos->item(linha, 4);
        if (itemQuantidade && !itemQuantidade->text().isEmpty()) {
            qtdTotal += itemQuantidade->text().toInt();
        }
    }
    ui->txtQtdTotal->setText(QString::number(qtdTotal));
}

// Guardar o registo da OP na base de dados
void Producao::on_btnGuardar_clicked()
{
    QString numEncomenda = ui->cmbNrEncomenda->currentText();
    //formatar a data para guardar na base de dados
    QString dataProducaoStr = ui->txtDataProducao->text();
    QDate dataProducao = QDate::fromString(dataProducaoStr, "dd-MM-yyyy");
    QString dataProducaoFormatada = dataProducao.toString("yyyy-MM-dd");
    int qtdTotal = ui->txtQtdTotal->text().toInt();

    if(!ui->txtRegisto->text().isEmpty()) //OP já existe na base de dados
    {
        if (!verificarCamposCabecalho()) {
            qDebug() << "Falha na verificação dos campos do cabeçalho.";
            return;
        }
        atualizarOrdemProducao(dataProducaoFormatada);
    }
    else  // novo registo a ser guardado na base de dados
    {
        if (!verificarCamposCabecalho()) {
            qDebug() << "Falha na verificação dos campos do cabeçalho.";
            return;
        }

        if(!verificarCamposLinhas()) {
            qDebug() << "Falha na verificação dos campos das linhas.";
            return;
        }

        QSqlDatabase bd = QSqlDatabase::database();
        bd.transaction();

        // Primeiro, obter o ID_Encomenda
        QSqlQuery obterIdEncomenda;
        obterIdEncomenda.prepare("SELECT ID_Encomenda FROM encomenda WHERE Num_Encomenda = :Num_Encomenda");
        obterIdEncomenda.bindValue(":Num_Encomenda", numEncomenda);

        if (!obterIdEncomenda.exec()) {
            qDebug() << "Falha ao obter o ID_Encomenda:" << obterIdEncomenda.lastError().text();
            return;
        }
        if (!obterIdEncomenda.next()) {
            qDebug() << "Encomenda não encontrada.";
            return;
        }

        int idEncomenda = obterIdEncomenda.value("ID_Encomenda").toInt();

        QSqlQuery guardarDados;
        // Guardar o registo  na tabela Producao
        guardarDados.prepare("INSERT INTO producao (ID_Encomenda, Data_Producao, Qtd_produzida) VALUES "
                             "(:ID_Encomenda, :Data_Producao, :Qtd_produzida)");
        guardarDados.bindValue(":ID_Encomenda", idEncomenda);
        guardarDados.bindValue(":Data_Producao", dataProducaoFormatada);
        guardarDados.bindValue(":Qtd_produzida", qtdTotal);

        if (!guardarDados.exec()) {
            qDebug() << "Falha ao inserir na tabela Produção:" << guardarDados.lastError().text();
            bd.rollback(); // Desfaz a transação
            return;
        }

        // Recuperar o ID_Producao gerado
        int idProducaoGerado = guardarDados.lastInsertId().toInt();

        // obter do ID_Produto e guardar as informações na base de dados na tabela producaoDetalhe
        QComboBox* comboBox = qobject_cast<QComboBox*>(ui->tableWidget_Produtos->cellWidget(0, 0));
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
        int quantidade = ui->tableWidget_Produtos->item(0, 4)->text().toInt();

        // Inserir na tabela 'producaoDetalhe'
        guardarDados.prepare("INSERT INTO producaoDetalhe (ID_Producao, ID_Produto, Qtd_produto) VALUES "
                             "(:ID_Producao, :ID_Produto, :Qtd_produto)");
        guardarDados.bindValue(":ID_Producao", idProducaoGerado);
        guardarDados.bindValue(":ID_Produto", idProduto);
        guardarDados.bindValue(":Qtd_produto", quantidade);

        if (!guardarDados.exec()) {
            qDebug() << "Falha ao inserir na tabela producaoDetalhe:" << guardarDados.lastError().text();
            // Remove a OP inserida anteriormente
            QSqlQuery apagarDados;
            apagarDados.prepare("DELETE FROM producao WHERE ID_Producao = :ID_Producao");
            apagarDados.bindValue(":ID_Producao", idProducaoGerado);
            if (!apagarDados.exec()) {
                qDebug() << "Erro ao remover o registo da OP:" << apagarDados.lastError().text();
            }
            bd.rollback(); // Desfaz a transação incluindo a tentativa de remoção
            return;
        }

        // Atualizar a tabela 'encomendaDetalhe'
        QSqlQuery updateProduzido;
        updateProduzido.prepare("UPDATE encomendadetalhe SET Produzido = 1 "
                                "WHERE ID_Encomenda = :ID_Encomenda AND ID_Produto = :ID_Produto;");
        updateProduzido.bindValue(":ID_Encomenda", idEncomenda);
        updateProduzido.bindValue(":ID_Produto", idProduto);

        if (!updateProduzido.exec()) {
            qDebug() << "Falha ao atualizar a tabela encomendaDetalhe:" << updateProduzido.lastError().text();

            QSqlQuery apagarDados;
            // Remover da tabela 'producaoDetalhe' o produto inserido anteriormente
            apagarDados.prepare("DELETE FROM producaoDetalhe WHERE ID_Produto = :ID_Produto AND "
                                "ID_Producao = :ID_Producao");
            apagarDados.bindValue(":ID_Produto", idProduto);
            guardarDados.bindValue(":ID_Producao", idProducaoGerado);
            if (!apagarDados.exec()) {
                qDebug() << "Erro ao remover o produto tabela producaoDetalhe:" << apagarDados.lastError().text();
            }

            // Remove a OP inserida anteriormente
            apagarDados.prepare("DELETE FROM producao WHERE ID_Producao = :ID_Producao");
            apagarDados.bindValue(":ID_Producao", idProducaoGerado);
            if (!apagarDados.exec()) {
                qDebug() << "Erro ao remover o registo da OP:" << apagarDados.lastError().text();
            }
            bd.rollback(); // Desfaz a transação incluindo a tentativa de remoção
            return;
        }

        if (!bd.commit()) {
            QMessageBox::critical(this, "Erro na base de dados", "Falha ao guardar as informações da Ordem de produção na base de dados."
                                                                 "\nPor favor, contacte o suporte!");
            return;
        }

        qDebug() << "Ordem de produção registada com sucesso.";
        QMessageBox::information(this, "Aviso", "Ordem de produção registada com sucesso!");

        //apresentar a ficha do produto atualizada
        apresentarInfoOP(idProducaoGerado);
        //habilitar o botão
        ui->btnProducao->setEnabled(true);
        desabilitarCampos();
        idProducaoSelecionado = QString::number(idProducaoGerado);
    }

    ui->btnVoltar_producao->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    carregarDadosProducao();
}

// Após guardar o registo da OP, apresentar a página de 'Registos de Ordens de Produção' com toda a informação do registo
void Producao::apresentarInfoOP(const int &idProducaoGerado)
{
    QSqlQuery obterDados;
    obterDados.prepare("SELECT producao.ID_Producao, producao.Num_OP, encomenda.Num_Encomenda, cliente.Cliente, producao.Qtd_produzida, "
                       "producao.Status_OP, producao.Data_Producao, producao.Data_ordemProducao, produto.Codigo_Produto, produto.Produto, "
                       "produtodetalhe.Gama, produtodetalhe.Cor, producaodetalhe.Qtd_produto FROM producao "
                       "INNER JOIN producaodetalhe ON producao.ID_Producao = producaodetalhe.ID_Producao "
                       "INNER JOIN encomenda ON producao.ID_Encomenda = encomenda.ID_Encomenda "
                       "INNER JOIN produto ON producaodetalhe.ID_Produto = produto.ID_Produto "
                       "INNER JOIN cliente ON encomenda.ID_Cliente = cliente.ID_Cliente "
                       "INNER JOIN produtodetalhe ON produto.ID_Produto = produtodetalhe.ID_Produto "
                       "WHERE producao.ID_Producao = :ID_Producao;");

    obterDados.bindValue(":ID_Producao", idProducaoGerado);
    ui->tableWidget_Produtos->setRowCount(0); //limpa a tabela
    if(obterDados.exec() && obterDados.first())
    {
        ui->tableWidget_Produtos->insertRow(0); //adiciona uma linha à tabela
        // retirar a informação da base de dados
        ui->txtRegisto->setText(obterDados.value("ID_Producao").toString());
        ui->txtCodigo->setText(obterDados.value("Num_OP").toString());

        QString numEncomenda = obterDados.value("Num_Encomenda").toString();
        ui->cmbNrEncomenda->setCurrentText(numEncomenda);
        produtosEncomendaSelecionada(numEncomenda, true);

        ui->txtCliente->setText(obterDados.value("Cliente").toString());
        ui->txtQtdTotal->setText(obterDados.value("Qtd_produzida").toString());
        ui->txtStatusOP->setText(obterDados.value("Status_OP").toString());

        // alterar o texto da label 'lblQuantidade'
        QString estado = "";
        estado = obterDados.value("Status_OP").toString();
        if(estado == "Fechada")
        {
            ui->lblQuantidade->setText("Quant. Total Produzida");
            QStringList titulos;
            titulos = {"Cód. Produto", "Produto", "Gama", "Cor", "Quant. produzida"};
            ui->tableWidget_Produtos->setHorizontalHeaderLabels(titulos);
        }
        else{
            ui->lblQuantidade->setText("Quant. Total a Produzir");
            QStringList titulos;
            titulos = {"Cód. Produto", "Produto", "Gama", "Cor", "Quant. a produzir"};
            ui->tableWidget_Produtos->setHorizontalHeaderLabels(titulos);
        }

        // formatar data
        QString dataOPStr = obterDados.value("Data_ordemProducao").toString();
        QDateTime dataHoraOP = QDateTime::fromString(dataOPStr, Qt::ISODate);
        QString dataOPFormatada = dataHoraOP.toString("dd-MM-yyyy");
        ui->txtDataCriacao->setText(dataOPFormatada);

        QString dataProducaoStr = obterDados.value("Data_Producao").toString();
        if(dataProducaoStr != ""){
            QDate dataProducao = QDate::fromString(dataProducaoStr, "yyyy-MM-dd");
            QString dataProducaoFormatada = dataProducao.toString("dd-MM-yyyy");
            ui->txtDataProducao->setText(dataProducaoFormatada);
        }
        else{
            ui->txtDataProducao->setText("");
        }

        //preencher a tabela
        QComboBox* cmbProdutos = new QComboBox(ui->tableWidget_Produtos);
        QString codProduto = obterDados.value("Codigo_Produto").toString();
        cmbProdutos->addItem(codProduto);
        cmbProdutos->setCurrentText(codProduto);
        QString produto = obterDados.value("Produto").toString();
        QString gama = obterDados.value("Gama").toString();
        QString cor = obterDados.value("Cor").toString();
        QString quantidade = obterDados.value("Qtd_produto").toString();

        ui->tableWidget_Produtos->setCellWidget(0, 0, cmbProdutos); // código produto
        ui->tableWidget_Produtos->setItem(0, 1, new QTableWidgetItem(produto)); // produto
        ui->tableWidget_Produtos->setItem(0, 2, new QTableWidgetItem(gama)); // Gama
        ui->tableWidget_Produtos->setItem(0, 3, new QTableWidgetItem(cor)); // Cor
        ui->tableWidget_Produtos->setItem(0, 4, new QTableWidgetItem(quantidade)); // Quantidade a produzir
    }
    else
    {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao carregar a informação da Ordem de Produção."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Erro ao carregar a informação da Ordem de Produção!:" << obterDados.lastError().text();
    }
}

void Producao::on_btnCancelar_clicked()
{
    limparCampos();
    desabilitarCampos();
    ui->btnVoltar_producao->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(true);
    ui->btnProducao->setEnabled(false);
    ui->btnFechar->setEnabled(false);
}

void Producao::on_tableWidget_OrdemProd_cellDoubleClicked()
{
    desabilitarCampos();

    preencherComboboxNrEncomenda(true);

    int idProducao = 0;
    int linhaAtual = 0;

    linhaAtual = ui->tableWidget_OrdemProd->currentRow();
    idProducaoSelecionado = ui->tableWidget_OrdemProd->item(linhaAtual, 0)->text();
    idProducao = idProducaoSelecionado.toInt();

    ui->stackedWidget->setCurrentIndex(1); // página de registo de OPs
    apresentarInfoOP(idProducao);

    // obter o saber o status da op
    QString statusOP = "";
    statusOP = ui->tableWidget_OrdemProd->item(linhaAtual, 6)->text();
    if(statusOP == "Planeada"){
        ui->btnProducao->setEnabled(true);
        ui->btnFechar->setEnabled(false);
        ui->btnVoltar_producao->setEnabled(true);
        ui->btnEliminar->setEnabled(true);
        ui->btnGuardar->setEnabled(false);
        ui->btnCancelar->setEnabled(false);
        ui->btnModificar->setEnabled(true);
    }
    else if(statusOP == "Em progresso"){
        ui->btnFechar->setEnabled(true);
        ui->btnProducao->setEnabled(false);
        ui->btnVoltar_producao->setEnabled(true);
        ui->btnEliminar->setEnabled(false);
        ui->btnGuardar->setEnabled(false);
        ui->btnCancelar->setEnabled(false);
        ui->btnModificar->setEnabled(false);
    }
    else{
        ui->btnFechar->setEnabled(false);
        ui->btnProducao->setEnabled(false);
        ui->btnVoltar_producao->setEnabled(true);
        ui->btnEliminar->setEnabled(false);
        ui->btnGuardar->setEnabled(false);
        ui->btnCancelar->setEnabled(false);
        ui->btnModificar->setEnabled(false);
    }
}

void Producao::on_btnModificar_clicked()
{
    ui->btnVoltar_producao->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    habilitarCampos();
    ui->btnProducao->setEnabled(false);

    if(!ui->txtRegisto->text().isEmpty()) //OP já existe na base de dados
    {
        ui->cmbNrEncomenda->setEnabled(false);
    }
}

// atualizar o registo da OP da base de dados apenas se estiver no estado Planeada
// Só é possível alterar a data de produção prevista
void Producao::atualizarOrdemProducao(QString dataProducao)
{
    int idProducao = idProducaoSelecionado.toInt();

    // ligação à base de dados para guardar/atualizar os valores
    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction(); // Inicia uma transação

    QSqlQuery dados;

    // Alterar na tabela 'produto'
    dados.prepare("UPDATE producao SET Data_Producao = :Data_Producao "
                  "WHERE ID_Producao = :ID_Producao");
    dados.bindValue(":ID_Producao", idProducao);
    dados.bindValue(":Data_Producao", dataProducao);

    if (!dados.exec()) {
        qDebug() << "Falha ao atualizar dados na tabela Producao:" << dados.lastError().text();
        bd.rollback();
        return;
    }

    if (!bd.commit()) {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao guardar as alterações na OP na base de dados."
                                                             "\nPor favor, contacte o suporte!");
        return;
    }

    qDebug() << "Alterações guardadas com sucesso";
    QMessageBox::information(this, "Aviso", "Alterações guardadas com sucesso!");

    apresentarInfoOP(idProducao);
    carregarDadosProducao();
    desabilitarCampos();
    ui->btnProducao->setEnabled(true);
}

// eliminar o registo da OP da base de dados apenas se estiver no estado Planeada
void Producao::on_btnEliminar_clicked()
{
    if (ui->txtRegisto->text().isEmpty()){
        QMessageBox::warning(this, "Registo vazio", "Não é possível eliminar registos vazios.");
        return;
    }

    QMessageBox::StandardButton confirmar;
    confirmar = QMessageBox::question(this, "Confirmar",
                                      "Pretende eliminar a Ordem de Produção " + ui->txtCodigo->text() + "?",
                                      QMessageBox::Yes|QMessageBox::No);

    if (confirmar == QMessageBox::Yes)
    {
        int idProducao = idProducaoSelecionado.toInt();

        QSqlDatabase bd = QSqlDatabase::database();
        bd.transaction();

        // obter o ID_Encomenda
        QSqlQuery obterIdEncomenda;
        obterIdEncomenda.prepare("SELECT ID_Encomenda FROM producao WHERE producao.ID_Producao = :ID_Producao;");
        obterIdEncomenda.bindValue(":ID_Producao", idProducao);

        if (!obterIdEncomenda.exec()) {
            qDebug() << "Falha ao obter o ID_Encomenda:" << obterIdEncomenda.lastError().text();
            return;
        }
        if (!obterIdEncomenda.next()) {
            qDebug() << "Encomenda não encontrada.";
            return;
        }

        int idEncomenda = obterIdEncomenda.value("ID_Encomenda").toInt();

        QSqlQuery obterIdProduto;
        obterIdProduto.prepare("SELECT ID_Produto FROM producaodetalhe WHERE ID_Producao = :ID_Producao;");
        obterIdProduto.bindValue(":ID_Producao", idProducao);

        if (!obterIdProduto.exec()) {
            qDebug() << "Falha ao obter o ID_Produto:" << obterIdProduto.lastError().text();
            return;
        }
        if (!obterIdProduto.next()) {
            qDebug() << "Produto não encontrado.";
            return;
        }

        int idProduto = obterIdProduto.value("ID_Produto").toInt();

        // Atualizar o campo Produzido na tabela 'encomendaDetalhe'
        QSqlQuery updateProduzido;
        updateProduzido.prepare("UPDATE encomendadetalhe SET Produzido = 0 "
                                "WHERE ID_Encomenda = :ID_Encomenda AND ID_Produto = :ID_Produto;");
        updateProduzido.bindValue(":ID_Encomenda", idEncomenda);
        updateProduzido.bindValue(":ID_Produto", idProduto);

        if (!updateProduzido.exec()) {
            qDebug() << "Falha ao atualizar a coluna Produzido na tabela encomendaDetalhe:" << updateProduzido.lastError().text();
            bd.rollback(); // Desfaz a transação
            return;
        }

        QSqlQuery eliminar;
        // Excluir registos da tabela 'producaoDetalhe', que contem a chave secundária
        eliminar.prepare("DELETE FROM producaoDetalhe WHERE ID_Producao = :ID_Producao");
        eliminar.bindValue(":ID_Producao", idProducao);
        if (!eliminar.exec()) {
            bd.rollback(); // Reverte a transação se ocorrer um erro
            qDebug() << "Erro ao excluir o registo da tabela producaoDetalhe:" << eliminar.lastError().text();
            return;
        }

        // Excluir registos da tabela 'producao', que contem a chave primária
        eliminar.prepare("DELETE FROM producao WHERE ID_Producao = :ID_Producao");
        eliminar.bindValue(":ID_Producao", idProducao);
        if (!eliminar.exec()) {
            bd.rollback(); // Reverte a transação se ocorrer um erro
            qDebug() << "Erro ao excluir o registo da tabela producao:" << eliminar.lastError().text();
            return;
        }

        if (!bd.commit()) {
            QMessageBox::critical(this, "Erro na base de dados", "Falha ao eliminar o registo da Ordem de Produção da base de dados."
                                                                 "\nPor favor, contacte o suporte!");
            return;
        }
        QMessageBox::information(this, "Aviso", "Registo eliminado com sucesso!");

        ui->btnVoltar_producao->setEnabled(true);
        ui->btnEliminar->setEnabled(false);
        ui->btnGuardar->setEnabled(false);
        ui->btnCancelar->setEnabled(false);
        ui->btnModificar->setEnabled(false);
        ui->btnFechar->setEnabled(false);
        ui->btnProducao->setEnabled(false);

        limparCampos();
        desabilitarCampos();
        carregarDadosProducao();
    }
}

// Muda o Status da OP de 'Planeada' para 'Em progresso'
void Producao::on_btnProducao_clicked()
{
    int idProducao = idProducaoSelecionado.toInt();

    // ligação à base de dados
    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction(); // Inicia uma transação

    // obter o Numero da OP
    QSqlQuery obterNumProducao;
    obterNumProducao.prepare("SELECT Num_OP FROM producao WHERE producao.ID_Producao = :ID_Producao;");
    obterNumProducao.bindValue(":ID_Producao", idProducao);

    if (!obterNumProducao.exec()) {
        qDebug() << "Falha ao obter o Numero da OP:" << obterNumProducao.lastError().text();
        return;
    }
    if (!obterNumProducao.next()) {
        qDebug() << "OP não encontrada.";
        return;
    }

    QString numOP = obterNumProducao.value("Num_OP").toString();

    // alterar o status da OP
    QSqlQuery updateStatusOP;
    // Alterar na tabela 'producao'
    updateStatusOP.prepare("UPDATE producao SET Status_OP = 'Em progresso' WHERE  ID_Producao = :ID_Producao;");
    updateStatusOP.bindValue(":ID_Producao", idProducao);

    if (!updateStatusOP.exec()) {
        qDebug() << "Falha ao atualizar dados na tabela Producao:" << updateStatusOP.lastError().text();
        bd.rollback();
        return;
    }

    if (!bd.commit()) {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao alterar o Status da OP."
                                                             "\nPor favor, contacte o suporte!");
        return;
    }

    qDebug() << "Alterações guardadas com sucesso";

    // exibir um relatório no ecrã
    QString reportHtml = "<h2>Processo de produção iniciado</h2>"
                         + QString( "<p><b>Número da Ordem de Produção:</b> %1</p>").arg(numOP) +
                         "<p><b>Status:</b> Em progresso</p>"
                         + QString("<p><b>Data:</b> %1</p>").arg(QDate::currentDate().toString("dd-MM-yyyy"));

    ReportDialog dialog(reportHtml);
    dialog.exec();

    apresentarInfoOP(idProducao);
    carregarDadosProducao();
    ui->btnProducao->setEnabled(false);
    ui->btnFechar->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
}

// Muda o Status da OP de 'Em progresso' para "Fechada"
// atualiza a quantidade de produto em stock
void Producao::on_btnFechar_clicked()
{
    int idProducao = idProducaoSelecionado.toInt();

    // ligação à base de dados
    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction(); // Inicia uma transação

    // obter o Numero da OP
    QSqlQuery obterNumProducao;
    obterNumProducao.prepare("SELECT Num_OP FROM producao WHERE producao.ID_Producao = :ID_Producao;");
    obterNumProducao.bindValue(":ID_Producao", idProducao);

    if (!obterNumProducao.exec()) {
        qDebug() << "Falha ao obter o Numero da OP:" << obterNumProducao.lastError().text();
        return;
    }
    if (!obterNumProducao.next()) {
        qDebug() << "OP não encontrada.";
        return;
    }

    QString numOP = obterNumProducao.value("Num_OP").toString();

    // alterar o status da OP
    QSqlQuery updateStatusOP;
    // Alterar na tabela 'producao'
    updateStatusOP.prepare("UPDATE producao SET Status_OP = 'Fechada' WHERE  ID_Producao = :ID_Producao;");
    updateStatusOP.bindValue(":ID_Producao", idProducao);

    if (!updateStatusOP.exec()) {
        qDebug() << "Falha ao atualizar dados na tabela Producao:" << updateStatusOP.lastError().text();
        bd.rollback();
        return;
    }

    QSqlQuery obterInfoProduto;
    obterInfoProduto.prepare("SELECT producaoDetalhe.ID_Produto, producaoDetalhe.Qtd_produto, produto.Codigo_Produto "
                             "FROM producaoDetalhe INNER JOIN produto ON producaoDetalhe.ID_Produto = produto.ID_Produto "
                             "WHERE ID_Producao = :ID_Producao");
    obterInfoProduto.bindValue(":ID_Producao", idProducao);
    int idProduto = 0, quantProduto = 0;
    QString codProduto = "";
    if (obterInfoProduto.exec() && obterInfoProduto.next()) {
        idProduto = obterInfoProduto.value("ID_Produto").toInt();
        quantProduto = obterInfoProduto.value("Qtd_produto").toInt();
        codProduto = obterInfoProduto.value("Codigo_Produto").toString();
    } else {
        qDebug() << "Erro ao obter info produto:" << obterInfoProduto.lastError().text();
    }

    // aumentar a quantidade total de produto em stock e recalcular a quantidade de stock disponível
    QSqlQuery atualizaStock;
    // Atualizar na tabela 'stock'
    atualizaStock.prepare("UPDATE stock SET Qtd_total = Qtd_total + :novaQuantidade "
                          "WHERE ID_Produto = :idProduto");
    atualizaStock.bindValue(":novaQuantidade", quantProduto);
    atualizaStock.bindValue(":idProduto", idProduto);

    if (!atualizaStock.exec()) {
        qDebug() << "Falha ao atualizar dados na tabela stock:" << atualizaStock.lastError().text();
        bd.rollback(); // Desfaz a transação
        return;
    }

    if (!bd.commit()) {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao alterar o Status da OP."
                                                             "\nPor favor, contacte o suporte!");
        return;
    }

    qDebug() << "Alterações guardadas com sucesso";

    // exibir um relatório no ecrã
    QString reportHtml = "<h2>Processo de produção finalizado</h2>"
                         + QString( "<p><b>Número da Ordem de Produção:</b> %1</p>").arg(numOP) +
                         "<p><b>Status:</b> Fechada</p>"
                         + QString("<p><b>Stock:</b> Entrada de %1 unidades do Produto %2</p>").arg(quantProduto).arg(codProduto)
                         + QString("<p><b>Data:</b> %1</p>").arg(QDate::currentDate().toString("dd-MM-yyyy"));

    ReportDialog dialog(reportHtml);
    dialog.exec();

    apresentarInfoOP(idProducao);
    carregarDadosProducao();
    ui->btnProducao->setEnabled(false);
    ui->btnFechar->setEnabled(false);
}

bool Producao::verificarCamposCabecalho()
{
    if(ui->cmbNrEncomenda->currentIndex() == 0){
        ui->lblErro->setText("Atenção! O campo Nr. Encomenda é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->cmbNrEncomenda->setFocus();
        return false;
    }

    QString dataProducaoStr = ui->txtDataProducao->text();
    QDate dataProducao = QDate::fromString(dataProducaoStr, "dd-MM-yyyy");

    if(!dataProducao.isNull() && dataProducao < QDate::currentDate()){
        ui->lblErro->setText("Atenção! A Data de Produção não pode ser inferior à data atual.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtDataProducao->setFocus();
        return false;
    }

    return true;
}

bool Producao::verificarCamposLinhas()
{
    QComboBox* cmbProdutos = qobject_cast<QComboBox*>(ui->tableWidget_Produtos->cellWidget(0, 0));
    if(cmbProdutos->currentIndex() == 0){
        ui->lblErro->setText("Atenção! Selecione o código do produto.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        cmbProdutos->setFocus();
        return false;
    }
    return true;
}

void Producao::limparCampos()
{
    ui->txtDataProducao->clear();
    ui->cmbNrEncomenda->setCurrentIndex(0);
    preencherComboboxNrEncomenda();
    ui->txtCliente->clear();
    ui->txtStatusOP->clear();
    ui->txtRegisto->clear();
    ui->txtCodigo->clear();
    ui->txtDataCriacao->clear();
    ui->txtQtdTotal->clear();
    limparTableWidget(ui->tableWidget_Produtos);
}

void Producao::desabilitarCampos()
{
    ui->txtDataProducao->setReadOnly(true);
    ui->cmbNrEncomenda->setEnabled(false);
    //ui->txtCliente->setReadOnly(true);
    ui->dateEdit->setReadOnly(true);
    //ui->btnAdLinha->setEnabled(false);
    //ui->btnEliminaLinha->setEnabled(false);
}

void Producao::habilitarCampos()
{
    ui->txtDataProducao->setReadOnly(false);
    ui->cmbNrEncomenda->setEnabled(true);
    //ui->txtCliente->setReadOnly(true);
    ui->tableWidget_Produtos->setEnabled(true);
    ui->dateEdit->setReadOnly(false);
    //ui->btnAdLinha->setEnabled(true);
    //ui->btnEliminaLinha->setEnabled(true);
}

void Producao::on_dateEdit_userDateChanged()
{
    QDate dataSelecionada = ui->dateEdit->date();
    QString dataFormato = dataSelecionada.toString("dd-MM-yyyy");
    ui->txtDataProducao->setText(dataFormato);
}

void Producao::on_txtDataProducao_editingFinished()
{
    QString data = ui->txtDataProducao->text();
    QDate dataSelecionada = QDate::fromString(data, "dd-MM-yyyy");

    if (dataSelecionada.isValid()) {
        ui->dateEdit->setDate(dataSelecionada);
    } else {
        qDebug() << "A Data fornecida é inválida.";
    }
}

// Apresentar todas as Ordens de produção na tabela da lista de OPs
void Producao::carregarDadosProducao()
{
    limparTableWidget(ui->tableWidget_OrdemProd);

    QSqlQuery obterDados;

    obterDados.prepare("SELECT producao.ID_Producao, producao.Num_OP, encomenda.Num_Encomenda, produto.Codigo_Produto, "
                       "produto.Produto, producao.Qtd_produzida, producao.Status_OP, producao.Data_ordemProducao "
                       "FROM producao INNER JOIN  encomenda ON producao.ID_Encomenda = encomenda.ID_Encomenda "
                       "INNER JOIN  producaodetalhe ON producao.ID_Producao = producaodetalhe.ID_Producao "
                       "INNER JOIN  produto ON producaodetalhe.ID_Produto = produto.ID_Produto ORDER BY producao.ID_Producao;");

    //verificar o acesso à BD
    if(obterDados.exec())
    {
        int linha = 0;
        ui->tableWidget_OrdemProd->setColumnCount(8);

        while(obterDados.next())
        {
            ui->tableWidget_OrdemProd->insertRow(linha);
            for(int coluna = 0; coluna < 8; coluna++)
            {
                QTableWidgetItem* novoItem = new QTableWidgetItem(obterDados.value(coluna).toString());
                ui->tableWidget_OrdemProd->setItem(linha, coluna, novoItem);

                // formatar data
                QString dataStr = obterDados.value("Data_ordemProducao").toString();
                QDateTime dataHora = QDateTime::fromString(dataStr, Qt::ISODate);
                QString dataFormatada = dataHora.toString("dd-MM-yyyy HH:mm");
                ui->tableWidget_OrdemProd->setItem(linha, 7, new QTableWidgetItem(dataFormatada));
            }

            linha++;
        }

        ui->lblTotalOPs->setText("Ordens de Produção: " + QString::number(linha));

        //colocar os títulos das colunas igual à ordem da query 'obterDados'
        QStringList titulos;
        titulos = {"Registo", "Nr. OP", "Nr. Encomenda", "Cód. Produto", "Produto", "Quantidade (un)", "Estado", "Data OP"};
        ui->tableWidget_OrdemProd->setHorizontalHeaderLabels(titulos);
        // formatar título
        ui->tableWidget_OrdemProd->horizontalHeader()->setStyleSheet("QHeaderView::section {color: white; background-color: #004b23; font: bold 10px}");
        ui->tableWidget_OrdemProd->setStyleSheet("QTableWidget::item {background-color: #f0f0f0; color: black;}");
        // ocultar os números das linhas
        ui->tableWidget_OrdemProd->verticalHeader()->setVisible(false);
        // ajustar a largura e altura das colunas
        //ui->tableWidget_OrdemProd->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
        ui->tableWidget_OrdemProd->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
        //definir a largura da coluna
        ui->tableWidget_OrdemProd->setColumnWidth(0, 90);
        ui->tableWidget_OrdemProd->setColumnWidth(1, 110);
        ui->tableWidget_OrdemProd->setColumnWidth(2, 110);
        ui->tableWidget_OrdemProd->setColumnWidth(3, 110);
        ui->tableWidget_OrdemProd->setColumnWidth(4, 180);
        ui->tableWidget_OrdemProd->setColumnWidth(5, 120);
        ui->tableWidget_OrdemProd->setColumnWidth(6, 120);
        ui->tableWidget_OrdemProd->setColumnWidth(7, 100);
        // desabilitar a edição dos dados
        ui->tableWidget_OrdemProd->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // selecionar a linha inteira da tabela
        ui->tableWidget_OrdemProd->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_OrdemProd->setStyleSheet("QTableWidget {border: 2px solid #004b23;}");
    }
    else
    {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao carregar a informação das OPs na tabela Lista de Ordens de Produção."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Erro ao carregar a informação das Ordens de Produção na tabela:" << obterDados.lastError().text();
        qDebug() << "Consulta SQL Produção:" << obterDados.lastQuery();
    }
}

// limpar os dados da tabela
void Producao::limparTableWidget(QTableWidget *limpaTW)
{
    while(limpaTW->rowCount() > 0)
    {
        limpaTW->removeRow(0);
    }
}

void Producao::on_btnPesquisar_clicked()
{
    QString numOP = ui->txtNrOP->text();
    QString produto = ui->txtProduto->text();
    QString status = ui->cmbStatusOP->currentText();

    // construir a consulta SQL
    QString pesquisa = "SELECT producao.ID_Producao, producao.Num_OP, encomenda.Num_Encomenda, produto.Codigo_Produto, "
                       "produto.Produto, producao.Qtd_produzida, producao.Status_OP, producao.Data_ordemProducao "
                       "FROM producao INNER JOIN encomenda ON producao.ID_Encomenda = encomenda.ID_Encomenda "
                       "INNER JOIN  producaodetalhe ON producao.ID_Producao = producaodetalhe.ID_Producao "
                       "INNER JOIN  produto ON producaodetalhe.ID_Produto = produto.ID_Produto "
                       "WHERE 1 = 1 ";


    if (!numOP.isEmpty()) {
        pesquisa += " AND Num_OP = :Num_OP";
    }

    if (!produto.isEmpty()) {
        pesquisa += " AND Produto LIKE :Produto";
        produto = "%" + produto + "%";
    }

    if (!status.isEmpty()) {
        pesquisa += " AND Status_OP = :Status_OP";
    }

    // executar a consulta
    QSqlQuery queryPesquisa;
    queryPesquisa.prepare(pesquisa);
    queryPesquisa.bindValue(":Num_OP", numOP);
    queryPesquisa.bindValue(":Produto", produto);
    queryPesquisa.bindValue(":Status_OP", status);

    if (queryPesquisa.exec()) {
        limparTableWidget(ui->tableWidget_OrdemProd);
        int linha = 0;

        while (queryPesquisa.next()) {
            ui->tableWidget_OrdemProd->insertRow(linha);
            for(int coluna = 0; coluna < 8; coluna++)
            {
                QTableWidgetItem* novoItem = new QTableWidgetItem(queryPesquisa.value(coluna).toString());
                ui->tableWidget_OrdemProd->setItem(linha, coluna, novoItem);
            }

            linha++;
        }
        ui->lblTotalOPs->setText("Ordens de Produção: " + QString::number(linha));
    } else {
        qDebug() << "Erro ao executar a consulta:" << queryPesquisa.lastError().text();
    }
}

void Producao::on_btnLimparPesquisa_clicked()
{
    ui->txtNrOP->clear();
    ui->txtProduto->clear();
    ui->cmbStatusOP->setCurrentIndex(0);
    carregarDadosProducao();
}
