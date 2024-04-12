#include "stockprodutos.h"
#include "ui_stockprodutos.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QBrush>
#include <QColor>
#include <QTimer>

StockProdutos::StockProdutos(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StockProdutos)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    carregarDadosStock();

    // validar os valores inseridos
    QIntValidator *quantidade = new QIntValidator(this);
    ui->txtQuantidade->setValidator(quantidade);
}

StockProdutos::~StockProdutos()
{
    delete ui;
}

void StockProdutos::on_btnInicio_stock_clicked()
{
    emit InicioClicked();
}

// Apresentar a informação dos produtos na tabela
void StockProdutos::carregarDadosStock()
{
    limparTableWidget(ui->tableWidget_stock);

    QSqlQuery obterDadosStock;

    obterDadosStock.prepare("SELECT produto.Codigo_Produto, produto.Produto, produtodetalhe.Gama, produto.Stock_minimo, "
                        "stock.Qtd_total, stock.Qtd_reservada, stock.Qtd_disponivel FROM produto "
                        "INNER JOIN  produtodetalhe ON produto.ID_Produto = produtodetalhe.ID_Produto "
                        "INNER JOIN stock ON produto.ID_Produto = stock.ID_Produto ORDER BY produto.Codigo_Produto;");

    //verificar o acesso à BD
    if(obterDadosStock.exec())
    {
        int linha = 0;
        // criar uma tabela com 7 colunas
        ui->tableWidget_stock->setColumnCount(7);

        while(obterDadosStock.next())
        {
            //inserir uma linha na tabela do formulário
            ui->tableWidget_stock->insertRow(linha);
            for(int coluna = 0; coluna < 7; coluna++)
            {
                ui->tableWidget_stock->setItem(linha, coluna, new QTableWidgetItem(obterDadosStock.value(coluna).toString()));
            }

            linha++;
        }

        ui->lblTotalProdutos->setText("Produtos: " + QString::number(linha));

        //colocar os títulos das colunas igual à ordem da query 'obterDadosStock'
        QStringList titulos;
        titulos = {"Código", "Produto", "Gama", "Stock Mínimo", "Qtd. Total", "Qtd. Reservada", "Qtd. Disponível"};
        ui->tableWidget_stock->setHorizontalHeaderLabels(titulos);
        // formatar título
        ui->tableWidget_stock->horizontalHeader()->setStyleSheet("QHeaderView::section {color: white; background-color: #004b23; font: bold 10px}");
        ui->tableWidget_stock->setStyleSheet("QTableWidget::item {color: black;}");
        // ocultar os números das linhas
        ui->tableWidget_stock->verticalHeader()->setVisible(false);
        // ajustar a altura das colunas
        ui->tableWidget_stock->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
        //definir a largura da coluna
        ui->tableWidget_stock->setColumnWidth(0, 75);
        ui->tableWidget_stock->setColumnWidth(1, 150);
        ui->tableWidget_stock->setColumnWidth(2, 150);
        ui->tableWidget_stock->setColumnWidth(3, 90);
        ui->tableWidget_stock->setColumnWidth(4, 90);
        ui->tableWidget_stock->setColumnWidth(5, 90);
        ui->tableWidget_stock->setColumnWidth(6, 90);
        // desabilitar a edição dos dados
        ui->tableWidget_stock->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // selecionar a linha inteira da tabela
        ui->tableWidget_stock->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_stock->setStyleSheet("QTableWidget {border: 2px solid #004b23;}");

        alterarCoresLinhas();
    }
    else
    {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao carregar a informação dos produtos na tabela Stock."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Erro ao carregar a informação dos produtos na tabela Stock:" << obterDadosStock.lastError().text();
        qDebug() << "Consulta SQL Stock:" << obterDadosStock.lastQuery();
    }
}

// limpar os dados da tabela
void StockProdutos::limparTableWidget(QTableWidget *limpaTW)
{
    while(limpaTW->rowCount() > 0)
    {
        limpaTW->removeRow(0);
    }
}

void StockProdutos::on_btnPesquisarProduto_stock_clicked()
{
    QString gama = ui->cmbPesquisarGama->currentText();
    QString produto = ui->txtProduto->text();
    QString codigo = ui->txtCodigo->text();

    // construir a consulta SQL
    QString pesquisa = "SELECT produto.Codigo_Produto, produto.Produto, produtodetalhe.Gama, produto.Stock_minimo, "
                            "stock.Qtd_total, stock.Qtd_reservada, stock.Qtd_disponivel FROM produto "
                            "INNER JOIN  produtodetalhe ON produto.ID_Produto = produtodetalhe.ID_Produto "
                            "INNER JOIN stock ON produto.ID_Produto = stock.ID_Produto "
                            "WHERE 1=1 ";

    if (!gama.isEmpty()) {
        pesquisa += " AND Gama = :gama";
    }
    if (!produto.isEmpty()) {
        pesquisa += " AND Produto LIKE :produto";
        produto = "%" + produto + "%";
    }
    if (!codigo.isEmpty()) {
        pesquisa += " AND Codigo_Produto = :codigo";
    }

    // executar a consulta
    QSqlQuery queryPesquisa;
    queryPesquisa.prepare(pesquisa);
    queryPesquisa.bindValue(":gama", gama);
    queryPesquisa.bindValue(":produto", produto);
    queryPesquisa.bindValue(":codigo", codigo);

    if (queryPesquisa.exec()) {
        limparTableWidget(ui->tableWidget_stock);
        int linha = 0;
        // enquanto existirem registos na base de dados
        while (queryPesquisa.next()) {
            ui->tableWidget_stock->insertRow(linha);
            for(int coluna = 0; coluna < 7; coluna++)
            {
                ui->tableWidget_stock->setItem(linha, coluna, new QTableWidgetItem(queryPesquisa.value(coluna).toString()));
            }
            linha++;
        }
        ui->lblTotalProdutos->setText("Produtos: " + QString::number(linha));
        alterarCoresLinhas();
    } else {
        qDebug() << "Erro ao executar a consulta de stock:" << queryPesquisa.lastError().text();
    }
}

void StockProdutos::alterarCoresLinhas() {
    for(int linha = 0; linha < ui->tableWidget_stock->rowCount(); linha++) {
        int qtdDisponivel = ui->tableWidget_stock->item(linha, 6)->text().toInt();
        int stockMinimo = ui->tableWidget_stock->item(linha, 3)->text().toInt();
        int qtReservada = ui->tableWidget_stock->item(linha, 5)->text().toInt();
        int qtTotal = ui->tableWidget_stock->item(linha, 4)->text().toInt();

        QColor corLinha;
        //QColor corLetra;

        if(qtTotal < qtReservada) { // vermelho
            corLinha = QColor(255, 100, 100);
            //corLetra = Qt::white;
        }
        else if(qtdDisponivel < stockMinimo) { //amarelo
            corLinha = QColor(255, 210, 63);
            //corLetra = Qt::black;
        }
        else {
            corLinha = QColor(107, 203, 119); //verde
            //corLetra = Qt::black;
        }

        for(int coluna = 0; coluna < ui->tableWidget_stock->columnCount(); coluna++) {
            ui->tableWidget_stock->item(linha, coluna)->setBackground(QBrush(corLinha));
            //ui->tableWidget_stock->item(linha, coluna)->setForeground(QBrush(corLetra));
        }
    }
}

// fazer uma entrada direta de produto em stock
void StockProdutos::on_btnEntradaStock_clicked()
{
    QString codigo = ui->txtCodigoProduto->text();
    int qtdEntrada = ui->txtQuantidade->text().toInt();

    // verificar se os campos estão corretamente preenchidos
    if (!verificarCampos()) {
        qDebug() << "Falha na verificação dos campos.";
        return;
    }

    // ligação à base de dados
    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction(); // Iniciar a transação

    // Verificar se o codigo do produto existe na base de dados e obter o Id_Produto correspondente
    QSqlQuery verificaProduto;
    verificaProduto.prepare("SELECT ID_Produto FROM produto WHERE Codigo_Produto = :codigo");
    verificaProduto.bindValue(":codigo", codigo);

    if(verificaProduto.exec() && verificaProduto.next())
    {
        int idProduto = verificaProduto.value(0).toInt();

        QSqlQuery atualizaStock;
        // Atualizar na tabela 'stock'
        atualizaStock.prepare("UPDATE stock SET Qtd_total = Qtd_total + :qtdEntrada "
                              "WHERE ID_Produto = :idProduto");
        atualizaStock.bindValue(":qtdEntrada", qtdEntrada);
        atualizaStock.bindValue(":idProduto", idProduto);

        if (!atualizaStock.exec()) {
            qDebug() << "Falha ao atualizar dados na tabela Stock da base de dados:" << atualizaStock.lastError().text();
            bd.rollback();
            return;
        }

        if (!bd.commit()) {
            qDebug() << "Falha ao guardar as informações na tabela Stock da base de dados.";
        } else {
            qDebug() << "Informação inserida com sucesso na tabela Stock da base de dados.";
        }

    } else {
        QMessageBox::warning(this, "Código", "Produto com código " + codigo + " não encontrado.");
        ui->txtCodigoProduto->setFocus();
    }
    ui->txtCodigoProduto->clear();
    ui->txtQuantidade->clear();
    carregarDadosStock();
}

// fazer uma saida direta de produto em stock
void StockProdutos::on_btnSaidaStock_clicked()
{
    QString codigo = ui->txtCodigoProduto->text();
    int qtdSaida = ui->txtQuantidade->text().toInt();

    // verificar se os campos estão corretamente preenchidos
    if (!verificarCampos()) {
        qDebug() << "Falha na verificação dos campos.";
        return;
    }

    // ligação à base de dados
    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction(); // Iniciar a transação

    // Verificar se o codigo do produto existe na base de dados e obter o Id_Produto correspondente
    QSqlQuery verificaProduto;
    verificaProduto.prepare("SELECT ID_Produto FROM produto WHERE Codigo_Produto = :codigo");
    verificaProduto.bindValue(":codigo", codigo);

    if(verificaProduto.exec() && verificaProduto.next())
    {
        int idProduto = verificaProduto.value(0).toInt();

        // Obter os dados atuais de stock para o produto
        QSqlQuery stockAtual(bd);
        stockAtual.prepare("SELECT Qtd_total, Qtd_reservada FROM stock WHERE ID_Produto = :idProduto");
        stockAtual.bindValue(":idProduto", idProduto);

        if(stockAtual.exec() && stockAtual.next())
        {
            int qtdTotal = stockAtual.value("Qtd_total").toInt();
            int qtdReservada = stockAtual.value("Qtd_reservada").toInt();

            int qtdDisponivel = qtdTotal - qtdReservada;

            if (qtdSaida > qtdDisponivel) {
                QMessageBox::warning(this, "Quantidade inválida", "A quantidade de saída não pode ser maior do que a quantidade disponível em stock.");
                bd.rollback();
                return;
            }

            QSqlQuery atualizaStock;
            // Atualizar na tabela 'stock'
            atualizaStock.prepare("UPDATE stock SET Qtd_total = Qtd_total - :qtdSaida "
                                  "WHERE ID_Produto = :idProduto");
            atualizaStock.bindValue(":qtdSaida", qtdSaida);
            atualizaStock.bindValue(":idProduto", idProduto);

            if (!atualizaStock.exec()) {
                qDebug() << "Falha ao atualizar dados na tabela Stock da base de dados:" << atualizaStock.lastError().text();
                bd.rollback();
                return;
            }

            if (!bd.commit()) {
                qDebug() << "Falha ao guardar as informações na tabela Stock da base de dados.";
            } else {
                qDebug() << "Informação inserida com sucesso na tabela Stock da base de dados.";
            }
        } else {
            qDebug() << "Produto com código " << codigo << " não encontrado na tabela stock.";
        }

    } else {
        QMessageBox::warning(this, "Código", "Produto com código " + codigo + " não encontrado.");
        ui->txtCodigoProduto->setFocus();
    }

    ui->txtCodigoProduto->clear();
    ui->txtQuantidade->clear();
    carregarDadosStock();
}

bool StockProdutos::verificarCampos()
{
    if(ui->txtCodigoProduto->text().isEmpty()){
        ui->lblErro->setText("Atenção! O campo Código Produto é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtCodigoProduto->setFocus();
        return false;
    }

    int qtdEntrada = ui->txtQuantidade->text().toInt();
    if (qtdEntrada <= 0){
        ui->lblErro->setText("Atenção! O campo Quantidade é obrigatório e não pode ser negativo.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtQuantidade->setFocus();
        return false;
    }

    return true;
}

void StockProdutos::on_btnLimparPesquisa_clicked()
{
    ui->cmbPesquisarGama->setCurrentIndex(0);
    ui->txtProduto->clear();
    ui->txtCodigo->clear();
    carregarDadosStock();
}

