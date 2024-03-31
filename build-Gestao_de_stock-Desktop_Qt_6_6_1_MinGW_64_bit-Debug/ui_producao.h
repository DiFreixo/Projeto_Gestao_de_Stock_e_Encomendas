/********************************************************************************
** Form generated from reading UI file 'producao.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCAO_H
#define UI_PRODUCAO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Producao
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page1_ListarEncomendas;
    QLabel *label;
    QPushButton *btnInicio_producao;
    QPushButton *btnNovo_OP;
    QTableWidget *tableWidget_OrdemProd;
    QGroupBox *groupBox;
    QComboBox *cmbStatusOP;
    QLabel *label_3;
    QLabel *lblTotalOPs;
    QPushButton *btnPesquisar;
    QLabel *label_4;
    QLineEdit *txtProduto;
    QLabel *label_5;
    QLineEdit *txtNrOP;
    QPushButton *btnLimparPesquisa;
    QWidget *page2_RegistarEncomendas;
    QLabel *label_8;
    QPushButton *btnVoltar_producao;
    QPushButton *btnCancelar;
    QLineEdit *txtRegisto;
    QLineEdit *txtCodigo;
    QPushButton *btnEliminar;
    QLabel *label_44;
    QPushButton *btnModificar;
    QLabel *label_10;
    QLineEdit *txtDataCriacao;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_18;
    QLineEdit *txtQtdTotal;
    QLabel *label_43;
    QPushButton *btnGuardar;
    QComboBox *cmbNrEncomenda;
    QLineEdit *txtDataProducao;
    QLabel *label_19;
    QLabel *label_52;
    QLineEdit *txtStatusOP;
    QTableWidget *tableWidget_Produtos;
    QPushButton *btnAdLinha;
    QPushButton *btnEliminaLinha;
    QLabel *lblErro;
    QLabel *label_12;
    QDateEdit *dateEdit;
    QLineEdit *txtCliente;
    QPushButton *btnProducao;
    QPushButton *btnFechar;
    QLabel *label_20;

    void setupUi(QWidget *Producao)
    {
        if (Producao->objectName().isEmpty())
            Producao->setObjectName("Producao");
        Producao->resize(1010, 671);
        Producao->setMinimumSize(QSize(1010, 671));
        Producao->setMaximumSize(QSize(1010, 671));
        stackedWidget = new QStackedWidget(Producao);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1010, 671));
        stackedWidget->setMinimumSize(QSize(1010, 671));
        stackedWidget->setMaximumSize(QSize(1010, 671));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #ADCE74;"));
        page1_ListarEncomendas = new QWidget();
        page1_ListarEncomendas->setObjectName("page1_ListarEncomendas");
        label = new QLabel(page1_ListarEncomendas);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 30, 711, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label->setAlignment(Qt::AlignCenter);
        btnInicio_producao = new QPushButton(page1_ListarEncomendas);
        btnInicio_producao->setObjectName("btnInicio_producao");
        btnInicio_producao->setGeometry(QRect(30, 30, 96, 35));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        btnInicio_producao->setFont(font1);
        btnInicio_producao->setCursor(QCursor(Qt::PointingHandCursor));
        btnInicio_producao->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/Home.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInicio_producao->setIcon(icon);
        btnNovo_OP = new QPushButton(page1_ListarEncomendas);
        btnNovo_OP->setObjectName("btnNovo_OP");
        btnNovo_OP->setGeometry(QRect(884, 30, 96, 35));
        btnNovo_OP->setFont(font1);
        btnNovo_OP->setCursor(QCursor(Qt::PointingHandCursor));
        btnNovo_OP->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNovo_OP->setIcon(icon1);
        tableWidget_OrdemProd = new QTableWidget(page1_ListarEncomendas);
        tableWidget_OrdemProd->setObjectName("tableWidget_OrdemProd");
        tableWidget_OrdemProd->setGeometry(QRect(30, 80, 951, 371));
        tableWidget_OrdemProd->setStyleSheet(QString::fromUtf8("background-color: #E6F7E6;"));
        tableWidget_OrdemProd->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget_OrdemProd->horizontalHeader()->setHighlightSections(false);
        tableWidget_OrdemProd->horizontalHeader()->setStretchLastSection(true);
        groupBox = new QGroupBox(page1_ListarEncomendas);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 460, 951, 191));
        QFont font2;
        font2.setPointSize(10);
        font2.setWeight(QFont::DemiBold);
        groupBox->setFont(font2);
        cmbStatusOP = new QComboBox(groupBox);
        cmbStatusOP->addItem(QString());
        cmbStatusOP->addItem(QString());
        cmbStatusOP->addItem(QString());
        cmbStatusOP->addItem(QString());
        cmbStatusOP->setObjectName("cmbStatusOP");
        cmbStatusOP->setGeometry(QRect(200, 60, 121, 22));
        cmbStatusOP->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 40, 151, 20));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        label_3->setFont(font3);
        lblTotalOPs = new QLabel(groupBox);
        lblTotalOPs->setObjectName("lblTotalOPs");
        lblTotalOPs->setGeometry(QRect(20, 160, 221, 16));
        QFont font4;
        font4.setPointSize(10);
        font4.setWeight(QFont::ExtraBold);
        lblTotalOPs->setFont(font4);
        btnPesquisar = new QPushButton(groupBox);
        btnPesquisar->setObjectName("btnPesquisar");
        btnPesquisar->setGeometry(QRect(350, 110, 51, 25));
        QFont font5;
        font5.setWeight(QFont::DemiBold);
        btnPesquisar->setFont(font5);
        btnPesquisar->setCursor(QCursor(Qt::PointingHandCursor));
        btnPesquisar->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 196, 196);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/pesquisar.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPesquisar->setIcon(icon2);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 40, 121, 20));
        label_4->setFont(font3);
        txtProduto = new QLineEdit(groupBox);
        txtProduto->setObjectName("txtProduto");
        txtProduto->setGeometry(QRect(20, 110, 301, 22));
        txtProduto->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 90, 121, 20));
        label_5->setFont(font3);
        txtNrOP = new QLineEdit(groupBox);
        txtNrOP->setObjectName("txtNrOP");
        txtNrOP->setGeometry(QRect(20, 60, 91, 22));
        txtNrOP->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        btnLimparPesquisa = new QPushButton(groupBox);
        btnLimparPesquisa->setObjectName("btnLimparPesquisa");
        btnLimparPesquisa->setGeometry(QRect(420, 110, 51, 25));
        btnLimparPesquisa->setFont(font5);
        btnLimparPesquisa->setCursor(QCursor(Qt::PointingHandCursor));
        btnLimparPesquisa->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(196, 196, 196);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/Refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLimparPesquisa->setIcon(icon3);
        stackedWidget->addWidget(page1_ListarEncomendas);
        page2_RegistarEncomendas = new QWidget();
        page2_RegistarEncomendas->setObjectName("page2_RegistarEncomendas");
        label_8 = new QLabel(page2_RegistarEncomendas);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(150, 30, 711, 31));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label_8->setAlignment(Qt::AlignCenter);
        btnVoltar_producao = new QPushButton(page2_RegistarEncomendas);
        btnVoltar_producao->setObjectName("btnVoltar_producao");
        btnVoltar_producao->setGeometry(QRect(30, 30, 96, 35));
        btnVoltar_producao->setFont(font1);
        btnVoltar_producao->setCursor(QCursor(Qt::PointingHandCursor));
        btnVoltar_producao->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVoltar_producao->setIcon(icon4);
        btnCancelar = new QPushButton(page2_RegistarEncomendas);
        btnCancelar->setObjectName("btnCancelar");
        btnCancelar->setGeometry(QRect(890, 210, 96, 35));
        btnCancelar->setFont(font1);
        btnCancelar->setCursor(QCursor(Qt::PointingHandCursor));
        btnCancelar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancelar->setIcon(icon5);
        txtRegisto = new QLineEdit(page2_RegistarEncomendas);
        txtRegisto->setObjectName("txtRegisto");
        txtRegisto->setEnabled(false);
        txtRegisto->setGeometry(QRect(30, 170, 113, 22));
        txtRegisto->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(208, 208, 208);\n"
""));
        txtRegisto->setFrame(false);
        txtRegisto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        txtCodigo = new QLineEdit(page2_RegistarEncomendas);
        txtCodigo->setObjectName("txtCodigo");
        txtCodigo->setEnabled(false);
        txtCodigo->setGeometry(QRect(180, 170, 113, 22));
        txtCodigo->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtCodigo->setFrame(false);
        txtCodigo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btnEliminar = new QPushButton(page2_RegistarEncomendas);
        btnEliminar->setObjectName("btnEliminar");
        btnEliminar->setGeometry(QRect(890, 330, 96, 35));
        btnEliminar->setFont(font1);
        btnEliminar->setCursor(QCursor(Qt::PointingHandCursor));
        btnEliminar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/img/Apagar.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEliminar->setIcon(icon6);
        label_44 = new QLabel(page2_RegistarEncomendas);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(30, 340, 131, 16));
        btnModificar = new QPushButton(page2_RegistarEncomendas);
        btnModificar->setObjectName("btnModificar");
        btnModificar->setGeometry(QRect(890, 270, 96, 35));
        btnModificar->setFont(font1);
        btnModificar->setCursor(QCursor(Qt::PointingHandCursor));
        btnModificar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/img/Modify.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModificar->setIcon(icon7);
        label_10 = new QLabel(page2_RegistarEncomendas);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(180, 150, 141, 16));
        txtDataCriacao = new QLineEdit(page2_RegistarEncomendas);
        txtDataCriacao->setObjectName("txtDataCriacao");
        txtDataCriacao->setEnabled(false);
        txtDataCriacao->setGeometry(QRect(390, 300, 112, 22));
        txtDataCriacao->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtDataCriacao->setFrame(false);
        txtDataCriacao->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(page2_RegistarEncomendas);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 150, 81, 16));
        label_11 = new QLabel(page2_RegistarEncomendas);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 280, 191, 16));
        label_18 = new QLabel(page2_RegistarEncomendas);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(390, 280, 111, 16));
        txtQtdTotal = new QLineEdit(page2_RegistarEncomendas);
        txtQtdTotal->setObjectName("txtQtdTotal");
        txtQtdTotal->setEnabled(false);
        txtQtdTotal->setGeometry(QRect(30, 360, 113, 22));
        txtQtdTotal->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtQtdTotal->setFrame(false);
        txtQtdTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_43 = new QLabel(page2_RegistarEncomendas);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(150, 360, 51, 16));
        btnGuardar = new QPushButton(page2_RegistarEncomendas);
        btnGuardar->setObjectName("btnGuardar");
        btnGuardar->setGeometry(QRect(890, 150, 96, 35));
        btnGuardar->setFont(font1);
        btnGuardar->setCursor(QCursor(Qt::PointingHandCursor));
        btnGuardar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/img/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGuardar->setIcon(icon8);
        cmbNrEncomenda = new QComboBox(page2_RegistarEncomendas);
        cmbNrEncomenda->setObjectName("cmbNrEncomenda");
        cmbNrEncomenda->setGeometry(QRect(30, 240, 151, 22));
        cmbNrEncomenda->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtDataProducao = new QLineEdit(page2_RegistarEncomendas);
        txtDataProducao->setObjectName("txtDataProducao");
        txtDataProducao->setGeometry(QRect(390, 360, 112, 22));
        txtDataProducao->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtDataProducao->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_19 = new QLabel(page2_RegistarEncomendas);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(390, 340, 111, 16));
        label_52 = new QLabel(page2_RegistarEncomendas);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(540, 150, 111, 16));
        txtStatusOP = new QLineEdit(page2_RegistarEncomendas);
        txtStatusOP->setObjectName("txtStatusOP");
        txtStatusOP->setEnabled(false);
        txtStatusOP->setGeometry(QRect(540, 170, 112, 22));
        txtStatusOP->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtStatusOP->setFrame(false);
        tableWidget_Produtos = new QTableWidget(page2_RegistarEncomendas);
        tableWidget_Produtos->setObjectName("tableWidget_Produtos");
        tableWidget_Produtos->setGeometry(QRect(30, 410, 751, 241));
        tableWidget_Produtos->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        tableWidget_Produtos->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget_Produtos->horizontalHeader()->setHighlightSections(false);
        tableWidget_Produtos->horizontalHeader()->setStretchLastSection(true);
        tableWidget_Produtos->verticalHeader()->setHighlightSections(false);
        btnAdLinha = new QPushButton(page2_RegistarEncomendas);
        btnAdLinha->setObjectName("btnAdLinha");
        btnAdLinha->setGeometry(QRect(790, 420, 41, 18));
        btnAdLinha->setCursor(QCursor(Qt::PointingHandCursor));
        btnAdLinha->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 196, 196);"));
        btnAdLinha->setIcon(icon1);
        btnEliminaLinha = new QPushButton(page2_RegistarEncomendas);
        btnEliminaLinha->setObjectName("btnEliminaLinha");
        btnEliminaLinha->setGeometry(QRect(790, 450, 41, 18));
        btnEliminaLinha->setCursor(QCursor(Qt::PointingHandCursor));
        btnEliminaLinha->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 196, 196);"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/img/Remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEliminaLinha->setIcon(icon9);
        lblErro = new QLabel(page2_RegistarEncomendas);
        lblErro->setObjectName("lblErro");
        lblErro->setGeometry(QRect(610, 15, 371, 21));
        label_12 = new QLabel(page2_RegistarEncomendas);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 220, 91, 16));
        dateEdit = new QDateEdit(page2_RegistarEncomendas);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(550, 360, 111, 22));
        dateEdit->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        dateEdit->setWrapping(false);
        dateEdit->setAlignment(Qt::AlignCenter);
        dateEdit->setReadOnly(false);
        dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit->setCalendarPopup(true);
        txtCliente = new QLineEdit(page2_RegistarEncomendas);
        txtCliente->setObjectName("txtCliente");
        txtCliente->setGeometry(QRect(30, 300, 261, 22));
        txtCliente->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        btnProducao = new QPushButton(page2_RegistarEncomendas);
        btnProducao->setObjectName("btnProducao");
        btnProducao->setGeometry(QRect(550, 100, 96, 30));
        btnProducao->setFont(font1);
        btnProducao->setCursor(QCursor(Qt::PointingHandCursor));
        btnProducao->setStyleSheet(QString::fromUtf8("	background-color:#A4CE95;\n"
"	color: #004b23;\n"
"	border: 1px solid  #004b23 ;\n"
"	border-style: outset;\n"
"	border-radius: 1px;"));
        btnFechar = new QPushButton(page2_RegistarEncomendas);
        btnFechar->setObjectName("btnFechar");
        btnFechar->setGeometry(QRect(690, 100, 96, 30));
        btnFechar->setFont(font1);
        btnFechar->setCursor(QCursor(Qt::PointingHandCursor));
        btnFechar->setStyleSheet(QString::fromUtf8("	background-color:#A4CE95;\n"
"	color: #004b23;\n"
"	border: 1px solid  #004b23 ;\n"
"	border-style: outset;\n"
"	border-radius: 1px;"));
        label_20 = new QLabel(page2_RegistarEncomendas);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(550, 340, 111, 16));
        stackedWidget->addWidget(page2_RegistarEncomendas);

        retranslateUi(Producao);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Producao);
    } // setupUi

    void retranslateUi(QWidget *Producao)
    {
        Producao->setWindowTitle(QCoreApplication::translate("Producao", "Form", nullptr));
        label->setText(QCoreApplication::translate("Producao", "Lista de Ordens de Produ\303\247\303\243o", nullptr));
        btnInicio_producao->setText(QCoreApplication::translate("Producao", " In\303\255cio", nullptr));
        btnNovo_OP->setText(QCoreApplication::translate("Producao", " Novo", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Producao", "Pesquisar por:", nullptr));
        cmbStatusOP->setItemText(0, QString());
        cmbStatusOP->setItemText(1, QCoreApplication::translate("Producao", "Planeada", nullptr));
        cmbStatusOP->setItemText(2, QCoreApplication::translate("Producao", "Em progresso", nullptr));
        cmbStatusOP->setItemText(3, QCoreApplication::translate("Producao", "Fechada", nullptr));

        label_3->setText(QCoreApplication::translate("Producao", "Status OP", nullptr));
        lblTotalOPs->setText(QCoreApplication::translate("Producao", "Ordens de Produ\303\247\303\243o:", nullptr));
        btnPesquisar->setText(QString());
        label_4->setText(QCoreApplication::translate("Producao", "Nr. OP", nullptr));
        label_5->setText(QCoreApplication::translate("Producao", "Produto", nullptr));
        btnLimparPesquisa->setText(QString());
        label_8->setText(QCoreApplication::translate("Producao", "Registo de Ordens de Produ\303\247\303\243o", nullptr));
        btnVoltar_producao->setText(QCoreApplication::translate("Producao", " Voltar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("Producao", " Cancelar", nullptr));
        txtCodigo->setText(QString());
        btnEliminar->setText(QCoreApplication::translate("Producao", " Eliminar", nullptr));
        label_44->setText(QCoreApplication::translate("Producao", "Quant. Total a produzir", nullptr));
        btnModificar->setText(QCoreApplication::translate("Producao", " Alterar", nullptr));
        label_10->setText(QCoreApplication::translate("Producao", "Nr. OP", nullptr));
        txtDataCriacao->setText(QString());
        label_9->setText(QCoreApplication::translate("Producao", "Registo", nullptr));
        label_11->setText(QCoreApplication::translate("Producao", "Cliente", nullptr));
        label_18->setText(QCoreApplication::translate("Producao", "Data OP", nullptr));
        txtQtdTotal->setText(QString());
        label_43->setText(QCoreApplication::translate("Producao", "un", nullptr));
        btnGuardar->setText(QCoreApplication::translate("Producao", " Guardar", nullptr));
        txtDataProducao->setText(QString());
        label_19->setText(QCoreApplication::translate("Producao", "Data Prod. Prevista", nullptr));
        label_52->setText(QCoreApplication::translate("Producao", "Status OP", nullptr));
        txtStatusOP->setText(QString());
        btnAdLinha->setText(QString());
        btnEliminaLinha->setText(QString());
        lblErro->setText(QString());
        label_12->setText(QCoreApplication::translate("Producao", "Nr. Encomenda", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("Producao", "dd-MM-yyyy", nullptr));
        txtCliente->setText(QString());
        btnProducao->setText(QCoreApplication::translate("Producao", "Produ\303\247\303\243o", nullptr));
        btnFechar->setText(QCoreApplication::translate("Producao", "Fechar", nullptr));
        label_20->setText(QCoreApplication::translate("Producao", "Calend\303\241rio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Producao: public Ui_Producao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCAO_H
