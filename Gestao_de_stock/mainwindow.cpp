#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlError>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QPixmap>

//#include "listaprodutos.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ---------------- Ligação à base de dados -------------------------------------------------------------------------------------
    // Verificar os drivers disponíveis
    /*
    qDebug() << "Drivers disponíveis:";
    foreach (QString driver, QSqlDatabase::drivers())
        qDebug() << driver;
    */

    QSqlDatabase bd = QSqlDatabase::addDatabase("QMYSQL");
    /*// phpmyadmin
    bd.setHostName("localhost");
    bd.setPort(3306);
    bd.setUserName("root");
    bd.setPassword("");
    bd.setDatabaseName("bdglowglass");
    */
    // servidor
    bd.setHostName("192.168.1.77");
    bd.setPort(3306);
    bd.setUserName("programador");
    bd.setPassword("Server2023!");
    bd.setDatabaseName("bdglowglass");

    if(bd.open())
    {
        ui->statusbar->showMessage(tr("Ligação à base de dados efetuada com sucesso!"), 5000);
        ui->statusbar->setStyleSheet("color: green;");
    }
    else{
        ui->statusbar->showMessage(tr("Erro ao conectar com a base de dados!"), 5000);
        ui->statusbar->setStyleSheet("color: red;");
        qDebug() << "Erro ao conectar com a base de dados!";
        QSqlError err = bd.lastError();
        qDebug() << err.text();
    }


    // ------------ Apresentar imagem de fundo na mainWindow -----------------------------------------------------------------------------------------
    ui->label_imagemFundo->setPixmap(QPixmap(":/img/img/bottles7.jpg"));

    listaProdutos = new ListaProdutos(this);
    producao = new Producao(this);
    stockProdutos = new StockProdutos(this);
    clientes = new Clientes(this);
    encomendas = new Encomendas(this);
    expedicao = new Expedicao(this);
    // ------------ Adicionar os forms ao stackedWidget -----------------------------------------------------------------------------------------
    ui->stackedWidget->insertWidget(1, listaProdutos);
    ui->stackedWidget->insertWidget(2, producao);
    ui->stackedWidget->insertWidget(3, stockProdutos);
    ui->stackedWidget->insertWidget(4, clientes);
    ui->stackedWidget->insertWidget(5, encomendas);
    ui->stackedWidget->insertWidget(6, expedicao);
    // conectar o sinal do botão 'InicioClicked' ao slot 'moveInicio'
    connect(listaProdutos, SIGNAL(InicioClicked()), this, SLOT(moveInicio()));
    connect(producao, SIGNAL(InicioClicked()), this, SLOT(moveInicio()));
    connect(producao, SIGNAL(InicioClicked()), this, SLOT(moveInicio()));
    connect(stockProdutos, SIGNAL(InicioClicked()), this, SLOT(moveInicio()));
    connect(clientes, SIGNAL(InicioClicked()), this, SLOT(moveInicio()));
    connect(encomendas, SIGNAL(InicioClicked()), this, SLOT(moveInicio()));
    connect(expedicao, SIGNAL(InicioClicked()), this, SLOT(moveInicio()));

    // conectar o sinal do Emissor ao slot do Receptor
    connect(clientes, &Clientes::clientesAtualizados, encomendas, &Encomendas::preencherComboboxCliente);
    connect(listaProdutos, &ListaProdutos::listaProdutosAtualizada, encomendas, &Encomendas::atualizarComboboxProdutos);
    //connect(encomendas, &Encomendas::encomendasAtualizadas, producao, &Producao::preencherComboboxNrEncomenda);
    connect(encomendas, &Encomendas::encomendasAtualizadas, this, [this]() {
        producao->preencherComboboxNrEncomenda(true);
    });
}

MainWindow::~MainWindow()
{
    delete ui;  
}

void MainWindow::on_btnProdutos_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    listaProdutos->carregarDadosProdutos();
}

void MainWindow::on_btnProducao_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    producao->carregarDadosProducao();
}

void MainWindow::on_btnStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    stockProdutos->carregarDadosStock();
}

void MainWindow::on_btnClientes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    clientes->carregarDadosClientes();
}

void MainWindow::on_btnEncomendas_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    encomendas->carregarDadosEncomendas();
}

void MainWindow::on_btnExpedicao_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    expedicao->carregarDadosExpedicao();
}

void MainWindow::moveInicio()
{
   ui->stackedWidget->setCurrentIndex(0);
}

