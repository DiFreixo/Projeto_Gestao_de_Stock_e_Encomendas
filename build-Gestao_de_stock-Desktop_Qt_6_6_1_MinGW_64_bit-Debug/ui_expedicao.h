/********************************************************************************
** Form generated from reading UI file 'expedicao.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPEDICAO_H
#define UI_EXPEDICAO_H

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
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Expedicao
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page1_ListarExpedicoes;
    QLabel *label;
    QPushButton *btnInicio_expedicao;
    QPushButton *btnNovo_expedicao;
    QGroupBox *groupBox;
    QComboBox *cmbExpedida;
    QLabel *label_3;
    QLabel *lblTotalExpedicoes;
    QPushButton *btnPesquisar;
    QLabel *label_4;
    QLineEdit *txtCliente;
    QLabel *label_5;
    QLineEdit *txtNrExpedicao;
    QPushButton *btnLimparPesquisa;
    QTableWidget *tableWidget_expedicoes;
    QWidget *page2_RegistarExpedicoes;
    QLabel *label_8;
    QPushButton *btnVoltar_expedicao;
    QPushButton *btnModificar;
    QLabel *label_9;
    QLabel *label_20;
    QLabel *label_19;
    QPushButton *btnEliminar;
    QLineEdit *txtCodigo;
    QLabel *label_10;
    QLabel *label_18;
    QPushButton *btnCancelar;
    QLineEdit *txtQtdTotal;
    QLineEdit *txtStatusExpedicao;
    QLabel *label_11;
    QLineEdit *txtNome;
    QLineEdit *txtDataCriacao;
    QLabel *lblQtdTotalExpedir;
    QLabel *label_12;
    QLineEdit *txtRegisto;
    QLineEdit *txtDataExpedicao;
    QPushButton *btnExpedicao;
    QComboBox *cmbNif;
    QLabel *label_43;
    QDateEdit *dateEdit;
    QPushButton *btnGuardar;
    QLabel *label_52;
    QLabel *lblErro;
    QTreeView *treeViewProdutos;

    void setupUi(QWidget *Expedicao)
    {
        if (Expedicao->objectName().isEmpty())
            Expedicao->setObjectName("Expedicao");
        Expedicao->resize(1010, 671);
        Expedicao->setMinimumSize(QSize(1010, 671));
        Expedicao->setMaximumSize(QSize(1010, 671));
        stackedWidget = new QStackedWidget(Expedicao);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1010, 671));
        stackedWidget->setMinimumSize(QSize(1010, 671));
        stackedWidget->setMaximumSize(QSize(1010, 671));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #ADCE74;"));
        page1_ListarExpedicoes = new QWidget();
        page1_ListarExpedicoes->setObjectName("page1_ListarExpedicoes");
        label = new QLabel(page1_ListarExpedicoes);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 30, 711, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label->setAlignment(Qt::AlignCenter);
        btnInicio_expedicao = new QPushButton(page1_ListarExpedicoes);
        btnInicio_expedicao->setObjectName("btnInicio_expedicao");
        btnInicio_expedicao->setGeometry(QRect(30, 30, 96, 35));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        btnInicio_expedicao->setFont(font1);
        btnInicio_expedicao->setCursor(QCursor(Qt::PointingHandCursor));
        btnInicio_expedicao->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/Home.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInicio_expedicao->setIcon(icon);
        btnNovo_expedicao = new QPushButton(page1_ListarExpedicoes);
        btnNovo_expedicao->setObjectName("btnNovo_expedicao");
        btnNovo_expedicao->setGeometry(QRect(884, 30, 96, 35));
        btnNovo_expedicao->setFont(font1);
        btnNovo_expedicao->setCursor(QCursor(Qt::PointingHandCursor));
        btnNovo_expedicao->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNovo_expedicao->setIcon(icon1);
        groupBox = new QGroupBox(page1_ListarExpedicoes);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 460, 951, 191));
        QFont font2;
        font2.setPointSize(10);
        font2.setWeight(QFont::DemiBold);
        groupBox->setFont(font2);
        cmbExpedida = new QComboBox(groupBox);
        cmbExpedida->addItem(QString());
        cmbExpedida->addItem(QString());
        cmbExpedida->addItem(QString());
        cmbExpedida->setObjectName("cmbExpedida");
        cmbExpedida->setGeometry(QRect(200, 60, 121, 22));
        cmbExpedida->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 40, 151, 20));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        label_3->setFont(font3);
        lblTotalExpedicoes = new QLabel(groupBox);
        lblTotalExpedicoes->setObjectName("lblTotalExpedicoes");
        lblTotalExpedicoes->setGeometry(QRect(20, 160, 221, 16));
        QFont font4;
        font4.setPointSize(10);
        font4.setWeight(QFont::ExtraBold);
        lblTotalExpedicoes->setFont(font4);
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
        txtCliente = new QLineEdit(groupBox);
        txtCliente->setObjectName("txtCliente");
        txtCliente->setGeometry(QRect(20, 110, 301, 22));
        txtCliente->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 90, 121, 20));
        label_5->setFont(font3);
        txtNrExpedicao = new QLineEdit(groupBox);
        txtNrExpedicao->setObjectName("txtNrExpedicao");
        txtNrExpedicao->setGeometry(QRect(20, 60, 91, 22));
        txtNrExpedicao->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
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
        tableWidget_expedicoes = new QTableWidget(page1_ListarExpedicoes);
        tableWidget_expedicoes->setObjectName("tableWidget_expedicoes");
        tableWidget_expedicoes->setGeometry(QRect(30, 80, 951, 371));
        tableWidget_expedicoes->setStyleSheet(QString::fromUtf8("background-color: #E6F7E6;"));
        tableWidget_expedicoes->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget_expedicoes->horizontalHeader()->setHighlightSections(false);
        tableWidget_expedicoes->horizontalHeader()->setStretchLastSection(true);
        stackedWidget->addWidget(page1_ListarExpedicoes);
        page2_RegistarExpedicoes = new QWidget();
        page2_RegistarExpedicoes->setObjectName("page2_RegistarExpedicoes");
        label_8 = new QLabel(page2_RegistarExpedicoes);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(150, 30, 711, 31));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label_8->setAlignment(Qt::AlignCenter);
        btnVoltar_expedicao = new QPushButton(page2_RegistarExpedicoes);
        btnVoltar_expedicao->setObjectName("btnVoltar_expedicao");
        btnVoltar_expedicao->setGeometry(QRect(30, 30, 96, 35));
        btnVoltar_expedicao->setFont(font1);
        btnVoltar_expedicao->setCursor(QCursor(Qt::PointingHandCursor));
        btnVoltar_expedicao->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVoltar_expedicao->setIcon(icon4);
        btnModificar = new QPushButton(page2_RegistarExpedicoes);
        btnModificar->setObjectName("btnModificar");
        btnModificar->setGeometry(QRect(890, 250, 96, 35));
        btnModificar->setFont(font1);
        btnModificar->setCursor(QCursor(Qt::PointingHandCursor));
        btnModificar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/Modify.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModificar->setIcon(icon5);
        label_9 = new QLabel(page2_RegistarExpedicoes);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 130, 81, 16));
        label_20 = new QLabel(page2_RegistarExpedicoes);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(550, 320, 111, 16));
        label_19 = new QLabel(page2_RegistarExpedicoes);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(390, 320, 111, 16));
        btnEliminar = new QPushButton(page2_RegistarExpedicoes);
        btnEliminar->setObjectName("btnEliminar");
        btnEliminar->setGeometry(QRect(890, 310, 96, 35));
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
        txtCodigo = new QLineEdit(page2_RegistarExpedicoes);
        txtCodigo->setObjectName("txtCodigo");
        txtCodigo->setEnabled(false);
        txtCodigo->setGeometry(QRect(180, 150, 113, 22));
        txtCodigo->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtCodigo->setFrame(false);
        txtCodigo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_10 = new QLabel(page2_RegistarExpedicoes);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(180, 130, 141, 16));
        label_18 = new QLabel(page2_RegistarExpedicoes);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(390, 260, 111, 16));
        btnCancelar = new QPushButton(page2_RegistarExpedicoes);
        btnCancelar->setObjectName("btnCancelar");
        btnCancelar->setGeometry(QRect(890, 190, 96, 35));
        btnCancelar->setFont(font1);
        btnCancelar->setCursor(QCursor(Qt::PointingHandCursor));
        btnCancelar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/img/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancelar->setIcon(icon7);
        txtQtdTotal = new QLineEdit(page2_RegistarExpedicoes);
        txtQtdTotal->setObjectName("txtQtdTotal");
        txtQtdTotal->setEnabled(false);
        txtQtdTotal->setGeometry(QRect(30, 340, 113, 22));
        txtQtdTotal->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtQtdTotal->setFrame(false);
        txtQtdTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        txtStatusExpedicao = new QLineEdit(page2_RegistarExpedicoes);
        txtStatusExpedicao->setObjectName("txtStatusExpedicao");
        txtStatusExpedicao->setEnabled(false);
        txtStatusExpedicao->setGeometry(QRect(540, 150, 112, 22));
        txtStatusExpedicao->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtStatusExpedicao->setFrame(false);
        label_11 = new QLabel(page2_RegistarExpedicoes);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 260, 191, 16));
        txtNome = new QLineEdit(page2_RegistarExpedicoes);
        txtNome->setObjectName("txtNome");
        txtNome->setGeometry(QRect(30, 280, 261, 22));
        txtNome->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtDataCriacao = new QLineEdit(page2_RegistarExpedicoes);
        txtDataCriacao->setObjectName("txtDataCriacao");
        txtDataCriacao->setEnabled(false);
        txtDataCriacao->setGeometry(QRect(390, 280, 112, 22));
        txtDataCriacao->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtDataCriacao->setFrame(false);
        txtDataCriacao->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblQtdTotalExpedir = new QLabel(page2_RegistarExpedicoes);
        lblQtdTotalExpedir->setObjectName("lblQtdTotalExpedir");
        lblQtdTotalExpedir->setGeometry(QRect(30, 320, 131, 16));
        label_12 = new QLabel(page2_RegistarExpedicoes);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 200, 91, 16));
        txtRegisto = new QLineEdit(page2_RegistarExpedicoes);
        txtRegisto->setObjectName("txtRegisto");
        txtRegisto->setEnabled(false);
        txtRegisto->setGeometry(QRect(30, 150, 113, 22));
        txtRegisto->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(208, 208, 208);\n"
""));
        txtRegisto->setFrame(false);
        txtRegisto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        txtDataExpedicao = new QLineEdit(page2_RegistarExpedicoes);
        txtDataExpedicao->setObjectName("txtDataExpedicao");
        txtDataExpedicao->setGeometry(QRect(390, 340, 112, 22));
        txtDataExpedicao->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtDataExpedicao->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btnExpedicao = new QPushButton(page2_RegistarExpedicoes);
        btnExpedicao->setObjectName("btnExpedicao");
        btnExpedicao->setGeometry(QRect(730, 80, 96, 30));
        btnExpedicao->setFont(font1);
        btnExpedicao->setCursor(QCursor(Qt::PointingHandCursor));
        btnExpedicao->setStyleSheet(QString::fromUtf8("	background-color:#A4CE95;\n"
"	color: #004b23;\n"
"	border: 1px solid  #004b23 ;\n"
"	border-style: outset;\n"
"	border-radius: 1px;"));
        cmbNif = new QComboBox(page2_RegistarExpedicoes);
        cmbNif->setObjectName("cmbNif");
        cmbNif->setGeometry(QRect(30, 220, 151, 22));
        cmbNif->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_43 = new QLabel(page2_RegistarExpedicoes);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(150, 340, 51, 16));
        dateEdit = new QDateEdit(page2_RegistarExpedicoes);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(550, 340, 111, 22));
        dateEdit->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        dateEdit->setWrapping(false);
        dateEdit->setAlignment(Qt::AlignCenter);
        dateEdit->setReadOnly(false);
        dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit->setCalendarPopup(true);
        btnGuardar = new QPushButton(page2_RegistarExpedicoes);
        btnGuardar->setObjectName("btnGuardar");
        btnGuardar->setGeometry(QRect(890, 130, 96, 35));
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
        label_52 = new QLabel(page2_RegistarExpedicoes);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(540, 130, 111, 16));
        lblErro = new QLabel(page2_RegistarExpedicoes);
        lblErro->setObjectName("lblErro");
        lblErro->setGeometry(QRect(590, 16, 371, 21));
        treeViewProdutos = new QTreeView(page2_RegistarExpedicoes);
        treeViewProdutos->setObjectName("treeViewProdutos");
        treeViewProdutos->setGeometry(QRect(30, 390, 801, 260));
        treeViewProdutos->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        stackedWidget->addWidget(page2_RegistarExpedicoes);

        retranslateUi(Expedicao);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Expedicao);
    } // setupUi

    void retranslateUi(QWidget *Expedicao)
    {
        Expedicao->setWindowTitle(QCoreApplication::translate("Expedicao", "Form", nullptr));
        label->setText(QCoreApplication::translate("Expedicao", "Lista de Expedi\303\247\303\265es", nullptr));
        btnInicio_expedicao->setText(QCoreApplication::translate("Expedicao", " In\303\255cio", nullptr));
        btnNovo_expedicao->setText(QCoreApplication::translate("Expedicao", " Novo", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Expedicao", "Pesquisar por:", nullptr));
        cmbExpedida->setItemText(0, QString());
        cmbExpedida->setItemText(1, QCoreApplication::translate("Expedicao", "N\303\243o", nullptr));
        cmbExpedida->setItemText(2, QCoreApplication::translate("Expedicao", "Sim", nullptr));

        label_3->setText(QCoreApplication::translate("Expedicao", "Expedida", nullptr));
        lblTotalExpedicoes->setText(QCoreApplication::translate("Expedicao", "Expedi\303\247\303\265es:", nullptr));
        btnPesquisar->setText(QString());
        label_4->setText(QCoreApplication::translate("Expedicao", "Nr. Expedi\303\247\303\243o", nullptr));
        label_5->setText(QCoreApplication::translate("Expedicao", "Cliente", nullptr));
        btnLimparPesquisa->setText(QString());
        label_8->setText(QCoreApplication::translate("Expedicao", "Registo de Expedi\303\247\303\265es", nullptr));
        btnVoltar_expedicao->setText(QCoreApplication::translate("Expedicao", " Voltar", nullptr));
        btnModificar->setText(QCoreApplication::translate("Expedicao", " Alterar", nullptr));
        label_9->setText(QCoreApplication::translate("Expedicao", "Registo", nullptr));
        label_20->setText(QCoreApplication::translate("Expedicao", "Calend\303\241rio", nullptr));
        label_19->setText(QCoreApplication::translate("Expedicao", "Data Exp. Prevista", nullptr));
        btnEliminar->setText(QCoreApplication::translate("Expedicao", " Eliminar", nullptr));
        txtCodigo->setText(QString());
        label_10->setText(QCoreApplication::translate("Expedicao", "Nr. Expedi\303\247\303\243o", nullptr));
        label_18->setText(QCoreApplication::translate("Expedicao", "Data Registo", nullptr));
        btnCancelar->setText(QCoreApplication::translate("Expedicao", " Cancelar", nullptr));
        txtQtdTotal->setText(QString());
        txtStatusExpedicao->setText(QString());
        label_11->setText(QCoreApplication::translate("Expedicao", "Cliente", nullptr));
        txtNome->setText(QString());
        txtDataCriacao->setText(QString());
        lblQtdTotalExpedir->setText(QCoreApplication::translate("Expedicao", "Quant. Total a expedir", nullptr));
        label_12->setText(QCoreApplication::translate("Expedicao", "NIF", nullptr));
        txtDataExpedicao->setText(QString());
        btnExpedicao->setText(QCoreApplication::translate("Expedicao", "Expedi\303\247\303\243o", nullptr));
        label_43->setText(QCoreApplication::translate("Expedicao", "un", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("Expedicao", "dd-MM-yyyy", nullptr));
        btnGuardar->setText(QCoreApplication::translate("Expedicao", " Guardar", nullptr));
        label_52->setText(QCoreApplication::translate("Expedicao", "Expedida", nullptr));
        lblErro->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Expedicao: public Ui_Expedicao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPEDICAO_H
