#include "expedicao.h"
#include "ui_expedicao.h"

Expedicao::Expedicao(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Expedicao)
{
    ui->setupUi(this);
    // inicializa na página 0
    ui->stackedWidget->setCurrentIndex(0);
}

Expedicao::~Expedicao()
{
    delete ui;
}

void Expedicao::on_btnInicio_expedicao_clicked()
{
    emit InicioClicked();
}


void Expedicao::on_btnNovo_expedicao_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Expedicao::on_btnVoltar_expedicoes_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

