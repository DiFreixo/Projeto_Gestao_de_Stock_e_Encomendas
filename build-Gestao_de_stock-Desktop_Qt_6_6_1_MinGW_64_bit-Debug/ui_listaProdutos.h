/********************************************************************************
** Form generated from reading UI file 'listaprodutos.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTAPRODUTOS_H
#define UI_LISTAPRODUTOS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListaProdutos
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page1_ListarProdutos;
    QLabel *label;
    QPushButton *btnInicio_produtos;
    QPushButton *btnNovo_produto;
    QGroupBox *groupBox;
    QComboBox *cmbPesquisarGama;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QRadioButton *rbCanela;
    QRadioButton *rbFolhaMorta;
    QRadioButton *rbAzul;
    QRadioButton *rbNegro;
    QRadioButton *rbBranco;
    QRadioButton *rbVerde;
    QRadioButton *rbAmbar;
    QGroupBox *groupBox_6;
    QComboBox *cmbDiametro_min;
    QComboBox *cmbDiametro_max;
    QLabel *label_19;
    QLabel *label_22;
    QGroupBox *groupBox_5;
    QComboBox *cmbAltura_min;
    QComboBox *cmbAltura_max;
    QLabel *label_6;
    QLabel *label_21;
    QLabel *lblTotalProdutos;
    QPushButton *btnPesquisarProduto;
    QPushButton *btnLimparPesquisa;
    QGroupBox *groupBox_4;
    QComboBox *cmbPeso_min;
    QComboBox *cmbPeso_max;
    QLabel *label_5;
    QLabel *label_20;
    QGroupBox *groupBox_3;
    QComboBox *cmbVolume_min;
    QComboBox *cmbVolume_max;
    QLabel *label_2;
    QLabel *label_4;
    QTableWidget *tableWidget_ListaProdutos;
    QWidget *page2_RegistarProdutos;
    QPushButton *btnVoltar_produtos;
    QLabel *label_8;
    QPushButton *btnGuardar;
    QPushButton *btnEliminar;
    QPushButton *btnCancelar;
    QPushButton *btnModificar;
    QLabel *label_9;
    QLineEdit *txtRegisto;
    QLineEdit *txtCodigo;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *txtNome;
    QLineEdit *txtStockMin;
    QLabel *label_12;
    QLineEdit *txtPrecoVenda;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QTextEdit *txtDescricao;
    QLabel *lblImagem;
    QPushButton *btnGuardarImagem;
    QLineEdit *txtDataCriacao;
    QLabel *label_18;
    QLineEdit *txtQtdTotal;
    QLabel *label_43;
    QLabel *label_44;
    QLineEdit *txtQtdDisponivel;
    QLabel *label_45;
    QLabel *label_46;
    QLineEdit *txtQtdReservada;
    QLabel *label_47;
    QLabel *label_48;
    QPushButton *btnEliminarImagem;
    QLabel *label_49;
    QLineEdit *txtTotalVendas;
    QLabel *label_50;
    QLabel *label_80;
    QLineEdit *txtTotalVendido;
    QLabel *label_81;
    QGroupBox *groupBox_Gama;
    QRadioButton *rbVinhos;
    QRadioButton *rbAlimentacao;
    QRadioButton *rbCervejas;
    QRadioButton *rbEspumantes;
    QRadioButton *rbLicores;
    QRadioButton *rbAguas;
    QGroupBox *groupBox_Cor;
    QRadioButton *rbCanela_2;
    QRadioButton *rbFolhaMorta_2;
    QRadioButton *rbAzul_2;
    QRadioButton *rbNegro_2;
    QRadioButton *rbBranco_2;
    QRadioButton *rbVerde_2;
    QRadioButton *rbAmbar_2;
    QGroupBox *groupBox_9;
    QLabel *label_28;
    QLineEdit *txtDiametro;
    QLabel *label_29;
    QLabel *label_23;
    QLineEdit *txtAltura;
    QLabel *label_17;
    QLabel *label_25;
    QLabel *label_24;
    QLineEdit *txtPeso;
    QLabel *label_26;
    QLabel *label_27;
    QLineEdit *txtVolume;
    QRadioButton *rbGamas;
    QRadioButton *rbCores;
    QLabel *lblErro;
    QButtonGroup *buttonGroup_Cor;
    QButtonGroup *buttonGroup_pesquisarCor;
    QButtonGroup *buttonGroup_Gama;

    void setupUi(QWidget *ListaProdutos)
    {
        if (ListaProdutos->objectName().isEmpty())
            ListaProdutos->setObjectName("ListaProdutos");
        ListaProdutos->resize(1010, 671);
        ListaProdutos->setMinimumSize(QSize(1010, 671));
        ListaProdutos->setMaximumSize(QSize(1010, 671));
        ListaProdutos->setStyleSheet(QString::fromUtf8(""));
        stackedWidget = new QStackedWidget(ListaProdutos);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1010, 671));
        stackedWidget->setMinimumSize(QSize(1010, 671));
        stackedWidget->setMaximumSize(QSize(1010, 671));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #ADCE74;"));
        page1_ListarProdutos = new QWidget();
        page1_ListarProdutos->setObjectName("page1_ListarProdutos");
        label = new QLabel(page1_ListarProdutos);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 30, 711, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label->setAlignment(Qt::AlignCenter);
        btnInicio_produtos = new QPushButton(page1_ListarProdutos);
        btnInicio_produtos->setObjectName("btnInicio_produtos");
        btnInicio_produtos->setGeometry(QRect(30, 30, 91, 35));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        btnInicio_produtos->setFont(font1);
        btnInicio_produtos->setCursor(QCursor(Qt::PointingHandCursor));
        btnInicio_produtos->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/Home.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInicio_produtos->setIcon(icon);
        btnNovo_produto = new QPushButton(page1_ListarProdutos);
        btnNovo_produto->setObjectName("btnNovo_produto");
        btnNovo_produto->setGeometry(QRect(884, 30, 96, 31));
        btnNovo_produto->setFont(font1);
        btnNovo_produto->setCursor(QCursor(Qt::PointingHandCursor));
        btnNovo_produto->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNovo_produto->setIcon(icon1);
        groupBox = new QGroupBox(page1_ListarProdutos);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 460, 951, 191));
        QFont font2;
        font2.setPointSize(10);
        font2.setWeight(QFont::DemiBold);
        groupBox->setFont(font2);
        cmbPesquisarGama = new QComboBox(groupBox);
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->setObjectName("cmbPesquisarGama");
        cmbPesquisarGama->setGeometry(QRect(20, 50, 171, 22));
        cmbPesquisarGama->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 151, 20));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        label_3->setFont(font3);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(250, 40, 271, 111));
        rbCanela = new QRadioButton(groupBox_2);
        buttonGroup_pesquisarCor = new QButtonGroup(ListaProdutos);
        buttonGroup_pesquisarCor->setObjectName("buttonGroup_pesquisarCor");
        buttonGroup_pesquisarCor->addButton(rbCanela);
        rbCanela->setObjectName("rbCanela");
        rbCanela->setGeometry(QRect(10, 20, 69, 18));
        rbCanela->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {background-color:#82581D;}\n"
""));
        rbFolhaMorta = new QRadioButton(groupBox_2);
        buttonGroup_pesquisarCor->addButton(rbFolhaMorta);
        rbFolhaMorta->setObjectName("rbFolhaMorta");
        rbFolhaMorta->setGeometry(QRect(10, 50, 91, 18));
        rbFolhaMorta->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    background-color: #B8AA4D;\n"
"}\n"
""));
        rbAzul = new QRadioButton(groupBox_2);
        buttonGroup_pesquisarCor->addButton(rbAzul);
        rbAzul->setObjectName("rbAzul");
        rbAzul->setGeometry(QRect(10, 80, 69, 18));
        rbAzul->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    background-color: #2125E0;\n"
"}\n"
""));
        rbNegro = new QRadioButton(groupBox_2);
        buttonGroup_pesquisarCor->addButton(rbNegro);
        rbNegro->setObjectName("rbNegro");
        rbNegro->setGeometry(QRect(110, 20, 69, 18));
        rbNegro->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    background-color: #332A33;\n"
"}\n"
""));
        rbBranco = new QRadioButton(groupBox_2);
        buttonGroup_pesquisarCor->addButton(rbBranco);
        rbBranco->setObjectName("rbBranco");
        rbBranco->setGeometry(QRect(110, 50, 69, 18));
        rbBranco->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        rbVerde = new QRadioButton(groupBox_2);
        buttonGroup_pesquisarCor->addButton(rbVerde);
        rbVerde->setObjectName("rbVerde");
        rbVerde->setGeometry(QRect(110, 80, 69, 18));
        rbVerde->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    background-color: #5FB916;\n"
"}\n"
""));
        rbAmbar = new QRadioButton(groupBox_2);
        buttonGroup_pesquisarCor->addButton(rbAmbar);
        rbAmbar->setObjectName("rbAmbar");
        rbAmbar->setGeometry(QRect(200, 20, 61, 18));
        rbAmbar->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    background-color: #912E06;\n"
"}\n"
""));
        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(570, 110, 171, 71));
        QFont font4;
        font4.setBold(true);
        groupBox_6->setFont(font4);
        groupBox_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 9pt \"Segoe UI\";}"));
        groupBox_6->setAlignment(Qt::AlignCenter);
        cmbDiametro_min = new QComboBox(groupBox_6);
        cmbDiametro_min->addItem(QString());
        cmbDiametro_min->addItem(QString());
        cmbDiametro_min->addItem(QString());
        cmbDiametro_min->setObjectName("cmbDiametro_min");
        cmbDiametro_min->setGeometry(QRect(20, 40, 51, 22));
        cmbDiametro_min->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        cmbDiametro_max = new QComboBox(groupBox_6);
        cmbDiametro_max->addItem(QString());
        cmbDiametro_max->addItem(QString());
        cmbDiametro_max->addItem(QString());
        cmbDiametro_max->setObjectName("cmbDiametro_max");
        cmbDiametro_max->setGeometry(QRect(97, 40, 51, 22));
        cmbDiametro_max->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 20, 71, 16));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Segoe UI")});
        font5.setPointSize(9);
        font5.setBold(false);
        font5.setItalic(false);
        label_19->setFont(font5);
        label_19->setStyleSheet(QString::fromUtf8(""));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(97, 20, 71, 16));
        label_22->setFont(font5);
        label_22->setTextFormat(Qt::AutoText);
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(570, 30, 171, 71));
        groupBox_5->setFont(font4);
        groupBox_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 9pt \"Segoe UI\";}"));
        groupBox_5->setAlignment(Qt::AlignCenter);
        cmbAltura_min = new QComboBox(groupBox_5);
        cmbAltura_min->addItem(QString());
        cmbAltura_min->addItem(QString());
        cmbAltura_min->addItem(QString());
        cmbAltura_min->addItem(QString());
        cmbAltura_min->addItem(QString());
        cmbAltura_min->setObjectName("cmbAltura_min");
        cmbAltura_min->setGeometry(QRect(20, 40, 51, 22));
        cmbAltura_min->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        cmbAltura_max = new QComboBox(groupBox_5);
        cmbAltura_max->addItem(QString());
        cmbAltura_max->addItem(QString());
        cmbAltura_max->addItem(QString());
        cmbAltura_max->addItem(QString());
        cmbAltura_max->addItem(QString());
        cmbAltura_max->setObjectName("cmbAltura_max");
        cmbAltura_max->setGeometry(QRect(97, 40, 51, 22));
        cmbAltura_max->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 20, 71, 16));
        label_6->setFont(font5);
        label_6->setStyleSheet(QString::fromUtf8(""));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(97, 20, 71, 16));
        label_21->setFont(font5);
        label_21->setTextFormat(Qt::AutoText);
        lblTotalProdutos = new QLabel(groupBox);
        lblTotalProdutos->setObjectName("lblTotalProdutos");
        lblTotalProdutos->setGeometry(QRect(10, 160, 221, 16));
        QFont font6;
        font6.setPointSize(10);
        font6.setWeight(QFont::ExtraBold);
        lblTotalProdutos->setFont(font6);
        btnPesquisarProduto = new QPushButton(groupBox);
        btnPesquisarProduto->setObjectName("btnPesquisarProduto");
        btnPesquisarProduto->setGeometry(QRect(20, 100, 51, 25));
        QFont font7;
        font7.setWeight(QFont::DemiBold);
        btnPesquisarProduto->setFont(font7);
        btnPesquisarProduto->setCursor(QCursor(Qt::PointingHandCursor));
        btnPesquisarProduto->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(196, 196, 196);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/pesquisar.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPesquisarProduto->setIcon(icon2);
        btnLimparPesquisa = new QPushButton(groupBox);
        btnLimparPesquisa->setObjectName("btnLimparPesquisa");
        btnLimparPesquisa->setGeometry(QRect(120, 100, 51, 25));
        btnLimparPesquisa->setFont(font7);
        btnLimparPesquisa->setCursor(QCursor(Qt::PointingHandCursor));
        btnLimparPesquisa->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(196, 196, 196);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/Refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLimparPesquisa->setIcon(icon3);
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(760, 30, 171, 71));
        groupBox_4->setFont(font4);
        groupBox_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 9pt \"Segoe UI\";}"));
        groupBox_4->setAlignment(Qt::AlignCenter);
        cmbPeso_min = new QComboBox(groupBox_4);
        cmbPeso_min->addItem(QString());
        cmbPeso_min->addItem(QString());
        cmbPeso_min->addItem(QString());
        cmbPeso_min->addItem(QString());
        cmbPeso_min->addItem(QString());
        cmbPeso_min->addItem(QString());
        cmbPeso_min->setObjectName("cmbPeso_min");
        cmbPeso_min->setGeometry(QRect(20, 40, 51, 22));
        cmbPeso_min->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        cmbPeso_max = new QComboBox(groupBox_4);
        cmbPeso_max->addItem(QString());
        cmbPeso_max->addItem(QString());
        cmbPeso_max->addItem(QString());
        cmbPeso_max->addItem(QString());
        cmbPeso_max->addItem(QString());
        cmbPeso_max->addItem(QString());
        cmbPeso_max->setObjectName("cmbPeso_max");
        cmbPeso_max->setGeometry(QRect(97, 40, 51, 22));
        cmbPeso_max->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 20, 71, 16));
        label_5->setFont(font5);
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(97, 20, 71, 16));
        label_20->setFont(font5);
        label_20->setTextFormat(Qt::AutoText);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(760, 110, 171, 71));
        groupBox_3->setFont(font4);
        groupBox_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 9pt \"Segoe UI\";}"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        cmbVolume_min = new QComboBox(groupBox_3);
        cmbVolume_min->addItem(QString());
        cmbVolume_min->addItem(QString());
        cmbVolume_min->addItem(QString());
        cmbVolume_min->addItem(QString());
        cmbVolume_min->addItem(QString());
        cmbVolume_min->addItem(QString());
        cmbVolume_min->setObjectName("cmbVolume_min");
        cmbVolume_min->setGeometry(QRect(20, 40, 51, 22));
        cmbVolume_min->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        cmbVolume_max = new QComboBox(groupBox_3);
        cmbVolume_max->addItem(QString());
        cmbVolume_max->addItem(QString());
        cmbVolume_max->addItem(QString());
        cmbVolume_max->addItem(QString());
        cmbVolume_max->addItem(QString());
        cmbVolume_max->addItem(QString());
        cmbVolume_max->addItem(QString());
        cmbVolume_max->addItem(QString());
        cmbVolume_max->setObjectName("cmbVolume_max");
        cmbVolume_max->setGeometry(QRect(97, 40, 51, 22));
        cmbVolume_max->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 71, 16));
        label_2->setFont(font5);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(97, 20, 71, 16));
        label_4->setFont(font5);
        label_4->setTextFormat(Qt::AutoText);
        tableWidget_ListaProdutos = new QTableWidget(page1_ListarProdutos);
        tableWidget_ListaProdutos->setObjectName("tableWidget_ListaProdutos");
        tableWidget_ListaProdutos->setGeometry(QRect(30, 80, 951, 371));
        tableWidget_ListaProdutos->setStyleSheet(QString::fromUtf8("background-color: #E6F7E6;"));
        tableWidget_ListaProdutos->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget_ListaProdutos->horizontalHeader()->setHighlightSections(false);
        tableWidget_ListaProdutos->horizontalHeader()->setStretchLastSection(false);
        stackedWidget->addWidget(page1_ListarProdutos);
        page2_RegistarProdutos = new QWidget();
        page2_RegistarProdutos->setObjectName("page2_RegistarProdutos");
        btnVoltar_produtos = new QPushButton(page2_RegistarProdutos);
        btnVoltar_produtos->setObjectName("btnVoltar_produtos");
        btnVoltar_produtos->setGeometry(QRect(30, 30, 96, 35));
        btnVoltar_produtos->setFont(font1);
        btnVoltar_produtos->setCursor(QCursor(Qt::PointingHandCursor));
        btnVoltar_produtos->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVoltar_produtos->setIcon(icon4);
        label_8 = new QLabel(page2_RegistarProdutos);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(150, 30, 711, 31));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label_8->setAlignment(Qt::AlignCenter);
        btnGuardar = new QPushButton(page2_RegistarProdutos);
        btnGuardar->setObjectName("btnGuardar");
        btnGuardar->setGeometry(QRect(890, 70, 96, 35));
        btnGuardar->setFont(font1);
        btnGuardar->setCursor(QCursor(Qt::PointingHandCursor));
        btnGuardar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGuardar->setIcon(icon5);
        btnEliminar = new QPushButton(page2_RegistarProdutos);
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
        btnCancelar = new QPushButton(page2_RegistarProdutos);
        btnCancelar->setObjectName("btnCancelar");
        btnCancelar->setGeometry(QRect(890, 130, 96, 35));
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
        btnModificar = new QPushButton(page2_RegistarProdutos);
        btnModificar->setObjectName("btnModificar");
        btnModificar->setGeometry(QRect(890, 190, 96, 35));
        btnModificar->setFont(font1);
        btnModificar->setCursor(QCursor(Qt::PointingHandCursor));
        btnModificar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/img/Modify.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModificar->setIcon(icon8);
        label_9 = new QLabel(page2_RegistarProdutos);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 100, 81, 16));
        txtRegisto = new QLineEdit(page2_RegistarProdutos);
        txtRegisto->setObjectName("txtRegisto");
        txtRegisto->setEnabled(false);
        txtRegisto->setGeometry(QRect(30, 120, 113, 22));
        txtRegisto->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(208, 208, 208);\n"
""));
        txtRegisto->setFrame(false);
        txtRegisto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        txtCodigo = new QLineEdit(page2_RegistarProdutos);
        txtCodigo->setObjectName("txtCodigo");
        txtCodigo->setEnabled(false);
        txtCodigo->setGeometry(QRect(180, 120, 113, 22));
        txtCodigo->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtCodigo->setFrame(false);
        txtCodigo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_10 = new QLabel(page2_RegistarProdutos);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(180, 100, 111, 16));
        label_11 = new QLabel(page2_RegistarProdutos);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 160, 191, 16));
        txtNome = new QLineEdit(page2_RegistarProdutos);
        txtNome->setObjectName("txtNome");
        txtNome->setGeometry(QRect(30, 180, 411, 22));
        txtNome->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtStockMin = new QLineEdit(page2_RegistarProdutos);
        txtStockMin->setObjectName("txtStockMin");
        txtStockMin->setGeometry(QRect(460, 390, 113, 22));
        txtStockMin->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtStockMin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_12 = new QLabel(page2_RegistarProdutos);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(460, 370, 91, 16));
        txtPrecoVenda = new QLineEdit(page2_RegistarProdutos);
        txtPrecoVenda->setObjectName("txtPrecoVenda");
        txtPrecoVenda->setGeometry(QRect(460, 450, 113, 22));
        txtPrecoVenda->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtPrecoVenda->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_13 = new QLabel(page2_RegistarProdutos);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(460, 430, 91, 16));
        label_14 = new QLabel(page2_RegistarProdutos);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(580, 390, 51, 16));
        label_15 = new QLabel(page2_RegistarProdutos);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(580, 450, 51, 16));
        label_16 = new QLabel(page2_RegistarProdutos);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(30, 220, 91, 16));
        txtDescricao = new QTextEdit(page2_RegistarProdutos);
        txtDescricao->setObjectName("txtDescricao");
        txtDescricao->setGeometry(QRect(30, 240, 411, 64));
        txtDescricao->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        lblImagem = new QLabel(page2_RegistarProdutos);
        lblImagem->setObjectName("lblImagem");
        lblImagem->setGeometry(QRect(590, 180, 221, 151));
        lblImagem->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        lblImagem->setScaledContents(false);
        lblImagem->setAlignment(Qt::AlignCenter);
        btnGuardarImagem = new QPushButton(page2_RegistarProdutos);
        btnGuardarImagem->setObjectName("btnGuardarImagem");
        btnGuardarImagem->setGeometry(QRect(610, 340, 80, 20));
        btnGuardarImagem->setFont(font7);
        btnGuardarImagem->setCursor(QCursor(Qt::PointingHandCursor));
        btnGuardarImagem->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(196, 196, 196);"));
        txtDataCriacao = new QLineEdit(page2_RegistarProdutos);
        txtDataCriacao->setObjectName("txtDataCriacao");
        txtDataCriacao->setEnabled(false);
        txtDataCriacao->setGeometry(QRect(670, 120, 141, 22));
        txtDataCriacao->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtDataCriacao->setFrame(false);
        txtDataCriacao->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_18 = new QLabel(page2_RegistarProdutos);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(670, 100, 111, 16));
        txtQtdTotal = new QLineEdit(page2_RegistarProdutos);
        txtQtdTotal->setObjectName("txtQtdTotal");
        txtQtdTotal->setEnabled(false);
        txtQtdTotal->setGeometry(QRect(450, 530, 113, 22));
        txtQtdTotal->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtQtdTotal->setFrame(false);
        txtQtdTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_43 = new QLabel(page2_RegistarProdutos);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(570, 530, 51, 16));
        label_44 = new QLabel(page2_RegistarProdutos);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(450, 510, 111, 16));
        txtQtdDisponivel = new QLineEdit(page2_RegistarProdutos);
        txtQtdDisponivel->setObjectName("txtQtdDisponivel");
        txtQtdDisponivel->setEnabled(false);
        txtQtdDisponivel->setGeometry(QRect(810, 530, 113, 22));
        txtQtdDisponivel->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtQtdDisponivel->setFrame(false);
        txtQtdDisponivel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_45 = new QLabel(page2_RegistarProdutos);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(930, 530, 51, 16));
        label_46 = new QLabel(page2_RegistarProdutos);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(810, 510, 111, 16));
        txtQtdReservada = new QLineEdit(page2_RegistarProdutos);
        txtQtdReservada->setObjectName("txtQtdReservada");
        txtQtdReservada->setEnabled(false);
        txtQtdReservada->setGeometry(QRect(630, 530, 113, 22));
        txtQtdReservada->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtQtdReservada->setFrame(false);
        txtQtdReservada->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_47 = new QLabel(page2_RegistarProdutos);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(750, 530, 51, 16));
        label_48 = new QLabel(page2_RegistarProdutos);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(630, 510, 111, 16));
        btnEliminarImagem = new QPushButton(page2_RegistarProdutos);
        btnEliminarImagem->setObjectName("btnEliminarImagem");
        btnEliminarImagem->setGeometry(QRect(710, 340, 80, 20));
        btnEliminarImagem->setFont(font7);
        btnEliminarImagem->setCursor(QCursor(Qt::PointingHandCursor));
        btnEliminarImagem->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(196, 196, 196);"));
        label_49 = new QLabel(page2_RegistarProdutos);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(750, 600, 51, 16));
        txtTotalVendas = new QLineEdit(page2_RegistarProdutos);
        txtTotalVendas->setObjectName("txtTotalVendas");
        txtTotalVendas->setEnabled(false);
        txtTotalVendas->setGeometry(QRect(630, 600, 113, 22));
        txtTotalVendas->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtTotalVendas->setFrame(false);
        txtTotalVendas->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_50 = new QLabel(page2_RegistarProdutos);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(630, 580, 111, 16));
        label_80 = new QLabel(page2_RegistarProdutos);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(570, 600, 51, 16));
        txtTotalVendido = new QLineEdit(page2_RegistarProdutos);
        txtTotalVendido->setObjectName("txtTotalVendido");
        txtTotalVendido->setEnabled(false);
        txtTotalVendido->setGeometry(QRect(450, 600, 113, 22));
        txtTotalVendido->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtTotalVendido->setFrame(false);
        txtTotalVendido->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_81 = new QLabel(page2_RegistarProdutos);
        label_81->setObjectName("label_81");
        label_81->setGeometry(QRect(450, 580, 111, 16));
        groupBox_Gama = new QGroupBox(page2_RegistarProdutos);
        groupBox_Gama->setObjectName("groupBox_Gama");
        groupBox_Gama->setGeometry(QRect(50, 490, 151, 141));
        rbVinhos = new QRadioButton(groupBox_Gama);
        buttonGroup_Gama = new QButtonGroup(ListaProdutos);
        buttonGroup_Gama->setObjectName("buttonGroup_Gama");
        buttonGroup_Gama->addButton(rbVinhos);
        rbVinhos->setObjectName("rbVinhos");
        rbVinhos->setGeometry(QRect(10, 20, 131, 18));
        rbAlimentacao = new QRadioButton(groupBox_Gama);
        buttonGroup_Gama->addButton(rbAlimentacao);
        rbAlimentacao->setObjectName("rbAlimentacao");
        rbAlimentacao->setGeometry(QRect(10, 40, 131, 18));
        rbCervejas = new QRadioButton(groupBox_Gama);
        buttonGroup_Gama->addButton(rbCervejas);
        rbCervejas->setObjectName("rbCervejas");
        rbCervejas->setGeometry(QRect(10, 60, 131, 18));
        rbEspumantes = new QRadioButton(groupBox_Gama);
        buttonGroup_Gama->addButton(rbEspumantes);
        rbEspumantes->setObjectName("rbEspumantes");
        rbEspumantes->setGeometry(QRect(10, 80, 131, 18));
        rbLicores = new QRadioButton(groupBox_Gama);
        buttonGroup_Gama->addButton(rbLicores);
        rbLicores->setObjectName("rbLicores");
        rbLicores->setGeometry(QRect(10, 100, 131, 18));
        rbAguas = new QRadioButton(groupBox_Gama);
        buttonGroup_Gama->addButton(rbAguas);
        rbAguas->setObjectName("rbAguas");
        rbAguas->setGeometry(QRect(10, 120, 131, 18));
        groupBox_Cor = new QGroupBox(page2_RegistarProdutos);
        groupBox_Cor->setObjectName("groupBox_Cor");
        groupBox_Cor->setGeometry(QRect(270, 490, 121, 161));
        rbCanela_2 = new QRadioButton(groupBox_Cor);
        buttonGroup_Cor = new QButtonGroup(ListaProdutos);
        buttonGroup_Cor->setObjectName("buttonGroup_Cor");
        buttonGroup_Cor->addButton(rbCanela_2);
        rbCanela_2->setObjectName("rbCanela_2");
        rbCanela_2->setGeometry(QRect(10, 20, 101, 18));
        rbFolhaMorta_2 = new QRadioButton(groupBox_Cor);
        buttonGroup_Cor->addButton(rbFolhaMorta_2);
        rbFolhaMorta_2->setObjectName("rbFolhaMorta_2");
        rbFolhaMorta_2->setGeometry(QRect(10, 40, 101, 18));
        rbAzul_2 = new QRadioButton(groupBox_Cor);
        buttonGroup_Cor->addButton(rbAzul_2);
        rbAzul_2->setObjectName("rbAzul_2");
        rbAzul_2->setGeometry(QRect(10, 60, 101, 18));
        rbNegro_2 = new QRadioButton(groupBox_Cor);
        buttonGroup_Cor->addButton(rbNegro_2);
        rbNegro_2->setObjectName("rbNegro_2");
        rbNegro_2->setGeometry(QRect(10, 80, 101, 18));
        rbBranco_2 = new QRadioButton(groupBox_Cor);
        buttonGroup_Cor->addButton(rbBranco_2);
        rbBranco_2->setObjectName("rbBranco_2");
        rbBranco_2->setGeometry(QRect(10, 100, 101, 18));
        rbVerde_2 = new QRadioButton(groupBox_Cor);
        buttonGroup_Cor->addButton(rbVerde_2);
        rbVerde_2->setObjectName("rbVerde_2");
        rbVerde_2->setGeometry(QRect(10, 120, 101, 18));
        rbAmbar_2 = new QRadioButton(groupBox_Cor);
        buttonGroup_Cor->addButton(rbAmbar_2);
        rbAmbar_2->setObjectName("rbAmbar_2");
        rbAmbar_2->setGeometry(QRect(10, 140, 101, 18));
        groupBox_9 = new QGroupBox(page2_RegistarProdutos);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(30, 330, 401, 131));
        label_28 = new QLabel(groupBox_9);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(20, 80, 91, 16));
        txtDiametro = new QLineEdit(groupBox_9);
        txtDiametro->setObjectName("txtDiametro");
        txtDiametro->setGeometry(QRect(20, 100, 113, 22));
        txtDiametro->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtDiametro->setMaxLength(3);
        txtDiametro->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_29 = new QLabel(groupBox_9);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(140, 100, 51, 16));
        label_23 = new QLabel(groupBox_9);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(140, 40, 51, 16));
        txtAltura = new QLineEdit(groupBox_9);
        txtAltura->setObjectName("txtAltura");
        txtAltura->setGeometry(QRect(20, 40, 113, 22));
        txtAltura->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtAltura->setMaxLength(3);
        txtAltura->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_17 = new QLabel(groupBox_9);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 20, 91, 16));
        label_25 = new QLabel(groupBox_9);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(360, 40, 31, 16));
        label_24 = new QLabel(groupBox_9);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(240, 20, 91, 16));
        txtPeso = new QLineEdit(groupBox_9);
        txtPeso->setObjectName("txtPeso");
        txtPeso->setGeometry(QRect(240, 40, 113, 22));
        txtPeso->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtPeso->setMaxLength(4);
        txtPeso->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_26 = new QLabel(groupBox_9);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(240, 80, 91, 16));
        label_27 = new QLabel(groupBox_9);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(360, 100, 31, 16));
        txtVolume = new QLineEdit(groupBox_9);
        txtVolume->setObjectName("txtVolume");
        txtVolume->setGeometry(QRect(240, 100, 113, 22));
        txtVolume->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtVolume->setMaxLength(3);
        txtVolume->setFrame(true);
        txtVolume->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rbGamas = new QRadioButton(page2_RegistarProdutos);
        buttonGroup_Gama->addButton(rbGamas);
        rbGamas->setObjectName("rbGamas");
        rbGamas->setEnabled(false);
        rbGamas->setGeometry(QRect(60, 640, 69, 10));
        QFont font8;
        font8.setPointSize(6);
        rbGamas->setFont(font8);
        rbCores = new QRadioButton(page2_RegistarProdutos);
        buttonGroup_Cor->addButton(rbCores);
        rbCores->setObjectName("rbCores");
        rbCores->setEnabled(false);
        rbCores->setGeometry(QRect(280, 660, 61, 10));
        rbCores->setFont(font8);
        lblErro = new QLabel(page2_RegistarProdutos);
        lblErro->setObjectName("lblErro");
        lblErro->setGeometry(QRect(590, 20, 381, 20));
        stackedWidget->addWidget(page2_RegistarProdutos);
        QWidget::setTabOrder(txtNome, txtDescricao);
        QWidget::setTabOrder(txtDescricao, txtAltura);
        QWidget::setTabOrder(txtAltura, txtPeso);
        QWidget::setTabOrder(txtPeso, txtDiametro);
        QWidget::setTabOrder(txtDiametro, txtVolume);
        QWidget::setTabOrder(txtVolume, rbVinhos);
        QWidget::setTabOrder(rbVinhos, rbAlimentacao);
        QWidget::setTabOrder(rbAlimentacao, rbCervejas);
        QWidget::setTabOrder(rbCervejas, rbEspumantes);
        QWidget::setTabOrder(rbEspumantes, rbLicores);
        QWidget::setTabOrder(rbLicores, rbAguas);
        QWidget::setTabOrder(rbAguas, rbCanela_2);
        QWidget::setTabOrder(rbCanela_2, rbFolhaMorta_2);
        QWidget::setTabOrder(rbFolhaMorta_2, rbAzul_2);
        QWidget::setTabOrder(rbAzul_2, rbNegro_2);
        QWidget::setTabOrder(rbNegro_2, rbBranco_2);
        QWidget::setTabOrder(rbBranco_2, rbVerde_2);
        QWidget::setTabOrder(rbVerde_2, rbAmbar_2);
        QWidget::setTabOrder(rbAmbar_2, txtStockMin);
        QWidget::setTabOrder(txtStockMin, txtPrecoVenda);
        QWidget::setTabOrder(txtPrecoVenda, btnGuardarImagem);
        QWidget::setTabOrder(btnGuardarImagem, btnEliminarImagem);
        QWidget::setTabOrder(btnEliminarImagem, btnModificar);
        QWidget::setTabOrder(btnModificar, txtRegisto);
        QWidget::setTabOrder(txtRegisto, txtCodigo);
        QWidget::setTabOrder(txtCodigo, btnInicio_produtos);
        QWidget::setTabOrder(btnInicio_produtos, cmbPesquisarGama);
        QWidget::setTabOrder(cmbPesquisarGama, btnNovo_produto);
        QWidget::setTabOrder(btnNovo_produto, rbCanela);
        QWidget::setTabOrder(rbCanela, txtDataCriacao);
        QWidget::setTabOrder(txtDataCriacao, txtQtdTotal);
        QWidget::setTabOrder(txtQtdTotal, txtQtdDisponivel);
        QWidget::setTabOrder(txtQtdDisponivel, txtQtdReservada);
        QWidget::setTabOrder(txtQtdReservada, rbFolhaMorta);
        QWidget::setTabOrder(rbFolhaMorta, txtTotalVendas);
        QWidget::setTabOrder(txtTotalVendas, txtTotalVendido);
        QWidget::setTabOrder(txtTotalVendido, rbNegro);
        QWidget::setTabOrder(rbNegro, rbBranco);
        QWidget::setTabOrder(rbBranco, rbVerde);
        QWidget::setTabOrder(rbVerde, rbAmbar);
        QWidget::setTabOrder(rbAmbar, cmbVolume_min);
        QWidget::setTabOrder(cmbVolume_min, cmbVolume_max);
        QWidget::setTabOrder(cmbVolume_max, cmbPeso_min);
        QWidget::setTabOrder(cmbPeso_min, cmbPeso_max);
        QWidget::setTabOrder(cmbPeso_max, cmbDiametro_min);
        QWidget::setTabOrder(cmbDiametro_min, cmbDiametro_max);
        QWidget::setTabOrder(cmbDiametro_max, cmbAltura_min);
        QWidget::setTabOrder(cmbAltura_min, cmbAltura_max);
        QWidget::setTabOrder(cmbAltura_max, btnVoltar_produtos);
        QWidget::setTabOrder(btnVoltar_produtos, btnGuardar);
        QWidget::setTabOrder(btnGuardar, btnEliminar);
        QWidget::setTabOrder(btnEliminar, btnCancelar);
        QWidget::setTabOrder(btnCancelar, rbAzul);

        retranslateUi(ListaProdutos);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ListaProdutos);
    } // setupUi

    void retranslateUi(QWidget *ListaProdutos)
    {
        ListaProdutos->setWindowTitle(QCoreApplication::translate("ListaProdutos", "Form", nullptr));
        label->setText(QCoreApplication::translate("ListaProdutos", "Lista de Produtos", nullptr));
        btnInicio_produtos->setText(QCoreApplication::translate("ListaProdutos", " In\303\255cio", nullptr));
        btnNovo_produto->setText(QCoreApplication::translate("ListaProdutos", " Novo", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ListaProdutos", "Pesquisar por:", nullptr));
        cmbPesquisarGama->setItemText(0, QString());
        cmbPesquisarGama->setItemText(1, QCoreApplication::translate("ListaProdutos", "Vinhos de Mesa", nullptr));
        cmbPesquisarGama->setItemText(2, QCoreApplication::translate("ListaProdutos", "Alimenta\303\247\303\243o", nullptr));
        cmbPesquisarGama->setItemText(3, QCoreApplication::translate("ListaProdutos", "Cervejas", nullptr));
        cmbPesquisarGama->setItemText(4, QCoreApplication::translate("ListaProdutos", "Espumantes e Sidras", nullptr));
        cmbPesquisarGama->setItemText(5, QCoreApplication::translate("ListaProdutos", "Licores e Aguardentes", nullptr));
        cmbPesquisarGama->setItemText(6, QCoreApplication::translate("ListaProdutos", "\303\201guas e Refrescos", nullptr));

        label_3->setText(QCoreApplication::translate("ListaProdutos", "Gama ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ListaProdutos", "Cor", nullptr));
        rbCanela->setText(QCoreApplication::translate("ListaProdutos", "Canela", nullptr));
        rbFolhaMorta->setText(QCoreApplication::translate("ListaProdutos", "Folha Morta", nullptr));
        rbAzul->setText(QCoreApplication::translate("ListaProdutos", "Azul", nullptr));
        rbNegro->setText(QCoreApplication::translate("ListaProdutos", "Negro", nullptr));
        rbBranco->setText(QCoreApplication::translate("ListaProdutos", "Branco", nullptr));
        rbVerde->setText(QCoreApplication::translate("ListaProdutos", "Verde", nullptr));
        rbAmbar->setText(QCoreApplication::translate("ListaProdutos", "\303\202mbar", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("ListaProdutos", "Di\303\242metro", nullptr));
        cmbDiametro_min->setItemText(0, QCoreApplication::translate("ListaProdutos", "40", nullptr));
        cmbDiametro_min->setItemText(1, QCoreApplication::translate("ListaProdutos", "80", nullptr));
        cmbDiametro_min->setItemText(2, QCoreApplication::translate("ListaProdutos", "120", nullptr));

        cmbDiametro_max->setItemText(0, QCoreApplication::translate("ListaProdutos", "160", nullptr));
        cmbDiametro_max->setItemText(1, QCoreApplication::translate("ListaProdutos", "120", nullptr));
        cmbDiametro_max->setItemText(2, QCoreApplication::translate("ListaProdutos", "80", nullptr));

        label_19->setText(QCoreApplication::translate("ListaProdutos", "mm M\303\255nimo", nullptr));
        label_22->setText(QCoreApplication::translate("ListaProdutos", "mm M\303\241ximo", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("ListaProdutos", "Altura", nullptr));
        cmbAltura_min->setItemText(0, QCoreApplication::translate("ListaProdutos", "40", nullptr));
        cmbAltura_min->setItemText(1, QCoreApplication::translate("ListaProdutos", "100", nullptr));
        cmbAltura_min->setItemText(2, QCoreApplication::translate("ListaProdutos", "160", nullptr));
        cmbAltura_min->setItemText(3, QCoreApplication::translate("ListaProdutos", "200", nullptr));
        cmbAltura_min->setItemText(4, QCoreApplication::translate("ListaProdutos", "260", nullptr));

        cmbAltura_max->setItemText(0, QCoreApplication::translate("ListaProdutos", "360", nullptr));
        cmbAltura_max->setItemText(1, QCoreApplication::translate("ListaProdutos", "260", nullptr));
        cmbAltura_max->setItemText(2, QCoreApplication::translate("ListaProdutos", "200", nullptr));
        cmbAltura_max->setItemText(3, QCoreApplication::translate("ListaProdutos", "160", nullptr));
        cmbAltura_max->setItemText(4, QCoreApplication::translate("ListaProdutos", "100", nullptr));

        label_6->setText(QCoreApplication::translate("ListaProdutos", "mm M\303\255nimo", nullptr));
        label_21->setText(QCoreApplication::translate("ListaProdutos", "mm M\303\241ximo", nullptr));
        lblTotalProdutos->setText(QCoreApplication::translate("ListaProdutos", "Produtos:", nullptr));
        btnPesquisarProduto->setText(QString());
        btnLimparPesquisa->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("ListaProdutos", "Peso", nullptr));
        cmbPeso_min->setItemText(0, QCoreApplication::translate("ListaProdutos", "75", nullptr));
        cmbPeso_min->setItemText(1, QCoreApplication::translate("ListaProdutos", "150", nullptr));
        cmbPeso_min->setItemText(2, QCoreApplication::translate("ListaProdutos", "300", nullptr));
        cmbPeso_min->setItemText(3, QCoreApplication::translate("ListaProdutos", "500", nullptr));
        cmbPeso_min->setItemText(4, QCoreApplication::translate("ListaProdutos", "700", nullptr));
        cmbPeso_min->setItemText(5, QCoreApplication::translate("ListaProdutos", "1000", nullptr));

        cmbPeso_max->setItemText(0, QCoreApplication::translate("ListaProdutos", "1500", nullptr));
        cmbPeso_max->setItemText(1, QCoreApplication::translate("ListaProdutos", "1000", nullptr));
        cmbPeso_max->setItemText(2, QCoreApplication::translate("ListaProdutos", "700", nullptr));
        cmbPeso_max->setItemText(3, QCoreApplication::translate("ListaProdutos", "500", nullptr));
        cmbPeso_max->setItemText(4, QCoreApplication::translate("ListaProdutos", "300", nullptr));
        cmbPeso_max->setItemText(5, QCoreApplication::translate("ListaProdutos", "150", nullptr));

        label_5->setText(QCoreApplication::translate("ListaProdutos", "g M\303\255nimo", nullptr));
        label_20->setText(QCoreApplication::translate("ListaProdutos", "g M\303\241ximo", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ListaProdutos", " Volume ", nullptr));
        cmbVolume_min->setItemText(0, QCoreApplication::translate("ListaProdutos", "5", nullptr));
        cmbVolume_min->setItemText(1, QCoreApplication::translate("ListaProdutos", "30", nullptr));
        cmbVolume_min->setItemText(2, QCoreApplication::translate("ListaProdutos", "50", nullptr));
        cmbVolume_min->setItemText(3, QCoreApplication::translate("ListaProdutos", "70", nullptr));
        cmbVolume_min->setItemText(4, QCoreApplication::translate("ListaProdutos", "150", nullptr));
        cmbVolume_min->setItemText(5, QCoreApplication::translate("ListaProdutos", "200", nullptr));

        cmbVolume_max->setItemText(0, QCoreApplication::translate("ListaProdutos", "390", nullptr));
        cmbVolume_max->setItemText(1, QCoreApplication::translate("ListaProdutos", "200", nullptr));
        cmbVolume_max->setItemText(2, QCoreApplication::translate("ListaProdutos", "150", nullptr));
        cmbVolume_max->setItemText(3, QCoreApplication::translate("ListaProdutos", "100", nullptr));
        cmbVolume_max->setItemText(4, QCoreApplication::translate("ListaProdutos", "70", nullptr));
        cmbVolume_max->setItemText(5, QCoreApplication::translate("ListaProdutos", "50", nullptr));
        cmbVolume_max->setItemText(6, QCoreApplication::translate("ListaProdutos", "30", nullptr));
        cmbVolume_max->setItemText(7, QCoreApplication::translate("ListaProdutos", "15", nullptr));

        label_2->setText(QCoreApplication::translate("ListaProdutos", "cl M\303\255nimo", nullptr));
        label_4->setText(QCoreApplication::translate("ListaProdutos", "cl M\303\241ximo", nullptr));
        btnVoltar_produtos->setText(QCoreApplication::translate("ListaProdutos", " Voltar", nullptr));
        label_8->setText(QCoreApplication::translate("ListaProdutos", "Registo de Produtos", nullptr));
        btnGuardar->setText(QCoreApplication::translate("ListaProdutos", " Guardar", nullptr));
        btnEliminar->setText(QCoreApplication::translate("ListaProdutos", " Eliminar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("ListaProdutos", " Cancelar", nullptr));
        btnModificar->setText(QCoreApplication::translate("ListaProdutos", " Alterar", nullptr));
        label_9->setText(QCoreApplication::translate("ListaProdutos", "Registo", nullptr));
        txtCodigo->setText(QString());
        label_10->setText(QCoreApplication::translate("ListaProdutos", "C\303\263digo do Produto", nullptr));
        label_11->setText(QCoreApplication::translate("ListaProdutos", "Produto", nullptr));
        txtNome->setText(QString());
        txtStockMin->setText(QString());
        label_12->setText(QCoreApplication::translate("ListaProdutos", "Stock m\303\255nimo", nullptr));
        txtPrecoVenda->setText(QString());
        label_13->setText(QCoreApplication::translate("ListaProdutos", "Pre\303\247o de Venda", nullptr));
        label_14->setText(QCoreApplication::translate("ListaProdutos", "un", nullptr));
        label_15->setText(QCoreApplication::translate("ListaProdutos", "euros", nullptr));
        label_16->setText(QCoreApplication::translate("ListaProdutos", "Descri\303\247\303\243o", nullptr));
        lblImagem->setText(QString());
        btnGuardarImagem->setText(QCoreApplication::translate("ListaProdutos", "Inserir", nullptr));
        txtDataCriacao->setText(QString());
        label_18->setText(QCoreApplication::translate("ListaProdutos", "Data do registo", nullptr));
        txtQtdTotal->setText(QString());
        label_43->setText(QCoreApplication::translate("ListaProdutos", "un", nullptr));
        label_44->setText(QCoreApplication::translate("ListaProdutos", "Quant. Total", nullptr));
        txtQtdDisponivel->setText(QString());
        label_45->setText(QCoreApplication::translate("ListaProdutos", "un", nullptr));
        label_46->setText(QCoreApplication::translate("ListaProdutos", "Quant. Dispon\303\255vel", nullptr));
        txtQtdReservada->setText(QString());
        label_47->setText(QCoreApplication::translate("ListaProdutos", "un", nullptr));
        label_48->setText(QCoreApplication::translate("ListaProdutos", "Quant. Reservada", nullptr));
        btnEliminarImagem->setText(QCoreApplication::translate("ListaProdutos", "Eliminar", nullptr));
        label_49->setText(QCoreApplication::translate("ListaProdutos", "euros", nullptr));
        txtTotalVendas->setText(QString());
        label_50->setText(QCoreApplication::translate("ListaProdutos", "Total Vendas", nullptr));
        label_80->setText(QCoreApplication::translate("ListaProdutos", "un", nullptr));
        txtTotalVendido->setText(QString());
        label_81->setText(QCoreApplication::translate("ListaProdutos", "Total Vendido", nullptr));
        groupBox_Gama->setTitle(QCoreApplication::translate("ListaProdutos", "Gama", nullptr));
        rbVinhos->setText(QCoreApplication::translate("ListaProdutos", "Vinhos de mesa", nullptr));
        rbAlimentacao->setText(QCoreApplication::translate("ListaProdutos", "Alimenta\303\247\303\243o", nullptr));
        rbCervejas->setText(QCoreApplication::translate("ListaProdutos", "Cervejas", nullptr));
        rbEspumantes->setText(QCoreApplication::translate("ListaProdutos", "Espumantes e Sidras", nullptr));
        rbLicores->setText(QCoreApplication::translate("ListaProdutos", "Licores e Aguardentes", nullptr));
        rbAguas->setText(QCoreApplication::translate("ListaProdutos", "\303\201guas e Refrescos", nullptr));
        groupBox_Cor->setTitle(QCoreApplication::translate("ListaProdutos", "Cor", nullptr));
        rbCanela_2->setText(QCoreApplication::translate("ListaProdutos", "Canela", nullptr));
        rbFolhaMorta_2->setText(QCoreApplication::translate("ListaProdutos", "Folha Morta", nullptr));
        rbAzul_2->setText(QCoreApplication::translate("ListaProdutos", "Azul", nullptr));
        rbNegro_2->setText(QCoreApplication::translate("ListaProdutos", "Negro", nullptr));
        rbBranco_2->setText(QCoreApplication::translate("ListaProdutos", "Branco", nullptr));
        rbVerde_2->setText(QCoreApplication::translate("ListaProdutos", "Verde", nullptr));
        rbAmbar_2->setText(QCoreApplication::translate("ListaProdutos", "\303\202mbar", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("ListaProdutos", "Dimens\303\265es", nullptr));
        label_28->setText(QCoreApplication::translate("ListaProdutos", "Di\303\242metro", nullptr));
        txtDiametro->setText(QString());
        label_29->setText(QCoreApplication::translate("ListaProdutos", "mm", nullptr));
        label_23->setText(QCoreApplication::translate("ListaProdutos", "mm", nullptr));
        txtAltura->setText(QString());
        label_17->setText(QCoreApplication::translate("ListaProdutos", "Altura", nullptr));
        label_25->setText(QCoreApplication::translate("ListaProdutos", "g", nullptr));
        label_24->setText(QCoreApplication::translate("ListaProdutos", "Peso", nullptr));
        txtPeso->setText(QString());
        label_26->setText(QCoreApplication::translate("ListaProdutos", "Volume", nullptr));
        label_27->setText(QCoreApplication::translate("ListaProdutos", "cl", nullptr));
        txtVolume->setText(QString());
        rbGamas->setText(QCoreApplication::translate("ListaProdutos", "Gamas", nullptr));
        rbCores->setText(QCoreApplication::translate("ListaProdutos", "Cores", nullptr));
        lblErro->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListaProdutos: public Ui_ListaProdutos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTAPRODUTOS_H
