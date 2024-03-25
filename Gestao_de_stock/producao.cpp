#include "producao.h"
#include "ui_producao.h"

Producao::Producao(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Producao)
{
    ui->setupUi(this);
    // inicializa na página 0
    ui->stackedWidget->setCurrentIndex(0);
}

Producao::~Producao()
{
    delete ui;
}

void Producao::on_btnInicio_producao_clicked()
{
    emit InicioClicked();
}


void Producao::on_btnNovo_OP_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Producao::on_btnVoltar_producao_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

