/********************************************************************************
** Form generated from reading UI file 'encomendas.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCOMENDAS_H
#define UI_ENCOMENDAS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Encomendas
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page1_ListarEncomendas;
    QLabel *label;
    QPushButton *btnInicio_encomendas;
    QPushButton *btnNovo_encomenda;
    QTableWidget *tableWidget_encomendas;
    QGroupBox *groupBox;
    QComboBox *cmbPesquisar;
    QLabel *label_3;
    QLabel *lblTotalEncomedas;
    QPushButton *btnPesquisar;
    QLabel *label_4;
    QLineEdit *txtCliente;
    QLabel *label_5;
    QLineEdit *txtCodigo_2;
    QPushButton *btnLimparPesquisa;
    QWidget *page2_RegistarEncomendas;
    QLabel *label_8;
    QPushButton *btnVoltar_encomendas;
    QLabel *label_50;
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
    QLineEdit *txtTotalVendas;
    QLabel *label_18;
    QLineEdit *txtQtdTotal;
    QLabel *label_43;
    QLabel *label_49;
    QPushButton *btnGuardar;
    QComboBox *cmbClientes;
    QLineEdit *txtDataEntrega;
    QLabel *label_19;
    QLabel *label_52;
    QLineEdit *txtExpedida;
    QTableWidget *tableWidget_ProdutosEnc;
    QPushButton *btnAdLinha;
    QPushButton *btnEliminaLinha;
    QCalendarWidget *calendarWidget;
    QLabel *lblErro;
    QLabel *label_12;
    QLineEdit *txtNome;

    void setupUi(QWidget *Encomendas)
    {
        if (Encomendas->objectName().isEmpty())
            Encomendas->setObjectName("Encomendas");
        Encomendas->resize(1010, 671);
        Encomendas->setMinimumSize(QSize(1010, 671));
        Encomendas->setMaximumSize(QSize(1010, 671));
        stackedWidget = new QStackedWidget(Encomendas);
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
        btnInicio_encomendas = new QPushButton(page1_ListarEncomendas);
        btnInicio_encomendas->setObjectName("btnInicio_encomendas");
        btnInicio_encomendas->setGeometry(QRect(30, 30, 96, 35));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        btnInicio_encomendas->setFont(font1);
        btnInicio_encomendas->setCursor(QCursor(Qt::PointingHandCursor));
        btnInicio_encomendas->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/Home.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInicio_encomendas->setIcon(icon);
        btnNovo_encomenda = new QPushButton(page1_ListarEncomendas);
        btnNovo_encomenda->setObjectName("btnNovo_encomenda");
        btnNovo_encomenda->setGeometry(QRect(884, 30, 96, 35));
        btnNovo_encomenda->setFont(font1);
        btnNovo_encomenda->setCursor(QCursor(Qt::PointingHandCursor));
        btnNovo_encomenda->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNovo_encomenda->setIcon(icon1);
        tableWidget_encomendas = new QTableWidget(page1_ListarEncomendas);
        tableWidget_encomendas->setObjectName("tableWidget_encomendas");
        tableWidget_encomendas->setGeometry(QRect(30, 80, 951, 371));
        tableWidget_encomendas->setStyleSheet(QString::fromUtf8("background-color: #E6F7E6;"));
        tableWidget_encomendas->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget_encomendas->horizontalHeader()->setHighlightSections(false);
        tableWidget_encomendas->horizontalHeader()->setStretchLastSection(true);
        groupBox = new QGroupBox(page1_ListarEncomendas);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 460, 951, 191));
        QFont font2;
        font2.setPointSize(10);
        font2.setWeight(QFont::DemiBold);
        groupBox->setFont(font2);
        cmbPesquisar = new QComboBox(groupBox);
        cmbPesquisar->addItem(QString());
        cmbPesquisar->addItem(QString());
        cmbPesquisar->addItem(QString());
        cmbPesquisar->addItem(QString());
        cmbPesquisar->setObjectName("cmbPesquisar");
        cmbPesquisar->setGeometry(QRect(200, 60, 121, 22));
        cmbPesquisar->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 40, 151, 20));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        label_3->setFont(font3);
        lblTotalEncomedas = new QLabel(groupBox);
        lblTotalEncomedas->setObjectName("lblTotalEncomedas");
        lblTotalEncomedas->setGeometry(QRect(20, 160, 221, 16));
        QFont font4;
        font4.setPointSize(10);
        font4.setWeight(QFont::ExtraBold);
        lblTotalEncomedas->setFont(font4);
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
        txtCodigo_2 = new QLineEdit(groupBox);
        txtCodigo_2->setObjectName("txtCodigo_2");
        txtCodigo_2->setGeometry(QRect(20, 60, 91, 22));
        txtCodigo_2->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
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
        btnVoltar_encomendas = new QPushButton(page2_RegistarEncomendas);
        btnVoltar_encomendas->setObjectName("btnVoltar_encomendas");
        btnVoltar_encomendas->setGeometry(QRect(30, 30, 96, 35));
        btnVoltar_encomendas->setFont(font1);
        btnVoltar_encomendas->setCursor(QCursor(Qt::PointingHandCursor));
        btnVoltar_encomendas->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVoltar_encomendas->setIcon(icon4);
        label_50 = new QLabel(page2_RegistarEncomendas);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(270, 290, 111, 16));
        btnCancelar = new QPushButton(page2_RegistarEncomendas);
        btnCancelar->setObjectName("btnCancelar");
        btnCancelar->setGeometry(QRect(890, 130, 96, 35));
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
        txtRegisto->setGeometry(QRect(30, 120, 113, 22));
        txtRegisto->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(208, 208, 208);\n"
""));
        txtRegisto->setFrame(false);
        txtRegisto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        txtCodigo = new QLineEdit(page2_RegistarEncomendas);
        txtCodigo->setObjectName("txtCodigo");
        txtCodigo->setEnabled(false);
        txtCodigo->setGeometry(QRect(180, 120, 113, 22));
        txtCodigo->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtCodigo->setFrame(false);
        txtCodigo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btnEliminar = new QPushButton(page2_RegistarEncomendas);
        btnEliminar->setObjectName("btnEliminar");
        btnEliminar->setGeometry(QRect(890, 250, 96, 35));
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
        label_44->setGeometry(QRect(30, 290, 111, 16));
        btnModificar = new QPushButton(page2_RegistarEncomendas);
        btnModificar->setObjectName("btnModificar");
        btnModificar->setGeometry(QRect(890, 190, 96, 35));
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
        label_10->setGeometry(QRect(180, 100, 141, 16));
        txtDataCriacao = new QLineEdit(page2_RegistarEncomendas);
        txtDataCriacao->setObjectName("txtDataCriacao");
        txtDataCriacao->setEnabled(false);
        txtDataCriacao->setGeometry(QRect(480, 120, 111, 22));
        txtDataCriacao->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtDataCriacao->setFrame(false);
        txtDataCriacao->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(page2_RegistarEncomendas);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 100, 81, 16));
        label_11 = new QLabel(page2_RegistarEncomendas);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 230, 191, 16));
        txtTotalVendas = new QLineEdit(page2_RegistarEncomendas);
        txtTotalVendas->setObjectName("txtTotalVendas");
        txtTotalVendas->setEnabled(false);
        txtTotalVendas->setGeometry(QRect(270, 310, 113, 22));
        txtTotalVendas->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtTotalVendas->setFrame(false);
        txtTotalVendas->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_18 = new QLabel(page2_RegistarEncomendas);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(480, 100, 111, 16));
        txtQtdTotal = new QLineEdit(page2_RegistarEncomendas);
        txtQtdTotal->setObjectName("txtQtdTotal");
        txtQtdTotal->setEnabled(false);
        txtQtdTotal->setGeometry(QRect(30, 310, 113, 22));
        txtQtdTotal->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtQtdTotal->setFrame(false);
        txtQtdTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_43 = new QLabel(page2_RegistarEncomendas);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(150, 310, 51, 16));
        label_49 = new QLabel(page2_RegistarEncomendas);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(390, 310, 51, 16));
        btnGuardar = new QPushButton(page2_RegistarEncomendas);
        btnGuardar->setObjectName("btnGuardar");
        btnGuardar->setGeometry(QRect(890, 70, 96, 35));
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
        cmbClientes = new QComboBox(page2_RegistarEncomendas);
        cmbClientes->setObjectName("cmbClientes");
        cmbClientes->setGeometry(QRect(30, 190, 151, 22));
        cmbClientes->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtDataEntrega = new QLineEdit(page2_RegistarEncomendas);
        txtDataEntrega->setObjectName("txtDataEntrega");
        txtDataEntrega->setGeometry(QRect(480, 190, 114, 22));
        txtDataEntrega->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtDataEntrega->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_19 = new QLabel(page2_RegistarEncomendas);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(480, 170, 131, 16));
        label_52 = new QLabel(page2_RegistarEncomendas);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(670, 100, 111, 16));
        txtExpedida = new QLineEdit(page2_RegistarEncomendas);
        txtExpedida->setObjectName("txtExpedida");
        txtExpedida->setEnabled(false);
        txtExpedida->setGeometry(QRect(670, 120, 111, 22));
        txtExpedida->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtExpedida->setFrame(false);
        tableWidget_ProdutosEnc = new QTableWidget(page2_RegistarEncomendas);
        tableWidget_ProdutosEnc->setObjectName("tableWidget_ProdutosEnc");
        tableWidget_ProdutosEnc->setGeometry(QRect(30, 350, 861, 301));
        tableWidget_ProdutosEnc->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        tableWidget_ProdutosEnc->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget_ProdutosEnc->horizontalHeader()->setHighlightSections(false);
        tableWidget_ProdutosEnc->horizontalHeader()->setStretchLastSection(true);
        tableWidget_ProdutosEnc->verticalHeader()->setHighlightSections(false);
        btnAdLinha = new QPushButton(page2_RegistarEncomendas);
        btnAdLinha->setObjectName("btnAdLinha");
        btnAdLinha->setGeometry(QRect(920, 360, 41, 18));
        btnAdLinha->setCursor(QCursor(Qt::PointingHandCursor));
        btnAdLinha->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 196, 196);"));
        btnAdLinha->setIcon(icon1);
        btnEliminaLinha = new QPushButton(page2_RegistarEncomendas);
        btnEliminaLinha->setObjectName("btnEliminaLinha");
        btnEliminaLinha->setGeometry(QRect(920, 390, 41, 18));
        btnEliminaLinha->setCursor(QCursor(Qt::PointingHandCursor));
        btnEliminaLinha->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 196, 196);"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/img/Remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEliminaLinha->setIcon(icon9);
        calendarWidget = new QCalendarWidget(page2_RegistarEncomendas);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(620, 160, 221, 171));
        QFont font6;
        font6.setPointSize(6);
        calendarWidget->setFont(font6);
        calendarWidget->setCursor(QCursor(Qt::PointingHandCursor));
        calendarWidget->setGridVisible(false);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(false);
        calendarWidget->setDateEditAcceptDelay(30);
        lblErro = new QLabel(page2_RegistarEncomendas);
        lblErro->setObjectName("lblErro");
        lblErro->setGeometry(QRect(610, 20, 371, 21));
        label_12 = new QLabel(page2_RegistarEncomendas);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 170, 91, 16));
        txtNome = new QLineEdit(page2_RegistarEncomendas);
        txtNome->setObjectName("txtNome");
        txtNome->setGeometry(QRect(30, 250, 361, 22));
        txtNome->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtNome->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        stackedWidget->addWidget(page2_RegistarEncomendas);

        retranslateUi(Encomendas);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Encomendas);
    } // setupUi

    void retranslateUi(QWidget *Encomendas)
    {
        Encomendas->setWindowTitle(QCoreApplication::translate("Encomendas", "Form", nullptr));
        label->setText(QCoreApplication::translate("Encomendas", "Lista de Encomendas", nullptr));
        btnInicio_encomendas->setText(QCoreApplication::translate("Encomendas", " In\303\255cio", nullptr));
        btnNovo_encomenda->setText(QCoreApplication::translate("Encomendas", " Novo", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Encomendas", "Pesquisar por:", nullptr));
        cmbPesquisar->setItemText(0, QString());
        cmbPesquisar->setItemText(1, QCoreApplication::translate("Encomendas", "N\303\243o", nullptr));
        cmbPesquisar->setItemText(2, QCoreApplication::translate("Encomendas", "Parcial", nullptr));
        cmbPesquisar->setItemText(3, QCoreApplication::translate("Encomendas", "Total", nullptr));

        label_3->setText(QCoreApplication::translate("Encomendas", "Expedida", nullptr));
        lblTotalEncomedas->setText(QCoreApplication::translate("Encomendas", "Encomendas:", nullptr));
        btnPesquisar->setText(QString());
        label_4->setText(QCoreApplication::translate("Encomendas", "C\303\263digo", nullptr));
        label_5->setText(QCoreApplication::translate("Encomendas", "Cliente", nullptr));
        btnLimparPesquisa->setText(QString());
        label_8->setText(QCoreApplication::translate("Encomendas", "Registo de Encomendas", nullptr));
        btnVoltar_encomendas->setText(QCoreApplication::translate("Encomendas", " Voltar", nullptr));
        label_50->setText(QCoreApplication::translate("Encomendas", "Valor", nullptr));
        btnCancelar->setText(QCoreApplication::translate("Encomendas", " Cancelar", nullptr));
        txtCodigo->setText(QString());
        btnEliminar->setText(QCoreApplication::translate("Encomendas", " Eliminar", nullptr));
        label_44->setText(QCoreApplication::translate("Encomendas", "Quant. Total", nullptr));
        btnModificar->setText(QCoreApplication::translate("Encomendas", " Alterar", nullptr));
        label_10->setText(QCoreApplication::translate("Encomendas", "Nr. Encomenda", nullptr));
        txtDataCriacao->setText(QString());
        label_9->setText(QCoreApplication::translate("Encomendas", "Registo", nullptr));
        label_11->setText(QCoreApplication::translate("Encomendas", "Cliente", nullptr));
        txtTotalVendas->setText(QString());
        label_18->setText(QCoreApplication::translate("Encomendas", "Data da Encomenda", nullptr));
        txtQtdTotal->setText(QString());
        label_43->setText(QCoreApplication::translate("Encomendas", "un", nullptr));
        label_49->setText(QCoreApplication::translate("Encomendas", "euros", nullptr));
        btnGuardar->setText(QCoreApplication::translate("Encomendas", " Guardar", nullptr));
        txtDataEntrega->setText(QString());
        label_19->setText(QCoreApplication::translate("Encomendas", "Data Entrega Prevista", nullptr));
        label_52->setText(QCoreApplication::translate("Encomendas", "Expedida", nullptr));
        txtExpedida->setText(QString());
        btnAdLinha->setText(QString());
        btnEliminaLinha->setText(QString());
        lblErro->setText(QString());
        label_12->setText(QCoreApplication::translate("Encomendas", "NIF", nullptr));
        txtNome->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Encomendas: public Ui_Encomendas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCOMENDAS_H
