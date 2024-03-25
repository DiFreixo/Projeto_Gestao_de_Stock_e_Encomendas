/********************************************************************************
** Form generated from reading UI file 'stockprodutos.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKPRODUTOS_H
#define UI_STOCKPRODUTOS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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

class Ui_StockProdutos
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page1_Stock;
    QPushButton *btnInicio_stock;
    QLabel *label_23;
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *lblTotalProdutos;
    QPushButton *btnPesquisarProduto_stock;
    QLabel *label_4;
    QLineEdit *txtCodigo;
    QLineEdit *txtProduto;
    QLabel *label_5;
    QComboBox *cmbPesquisarGama;
    QPushButton *btnLimparPesquisa;
    QTableWidget *tableWidget_stock;
    QGroupBox *groupBox_2;
    QPushButton *btnSaidaStock;
    QLineEdit *txtQuantidade;
    QLabel *label_6;
    QLineEdit *txtCodigoProduto;
    QPushButton *btnEntradaStock;
    QLabel *label_7;
    QLabel *lblErro;

    void setupUi(QWidget *StockProdutos)
    {
        if (StockProdutos->objectName().isEmpty())
            StockProdutos->setObjectName("StockProdutos");
        StockProdutos->resize(1010, 671);
        StockProdutos->setMinimumSize(QSize(1010, 671));
        StockProdutos->setMaximumSize(QSize(1010, 671));
        stackedWidget = new QStackedWidget(StockProdutos);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1010, 671));
        stackedWidget->setMinimumSize(QSize(1010, 671));
        stackedWidget->setMaximumSize(QSize(1010, 671));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #ADCE74;"));
        page1_Stock = new QWidget();
        page1_Stock->setObjectName("page1_Stock");
        btnInicio_stock = new QPushButton(page1_Stock);
        btnInicio_stock->setObjectName("btnInicio_stock");
        btnInicio_stock->setGeometry(QRect(30, 30, 95, 35));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        btnInicio_stock->setFont(font);
        btnInicio_stock->setCursor(QCursor(Qt::PointingHandCursor));
        btnInicio_stock->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/Home.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInicio_stock->setIcon(icon);
        label_23 = new QLabel(page1_Stock);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(150, 30, 711, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label_23->setFont(font1);
        label_23->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label_23->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(page1_Stock);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(150, 460, 471, 191));
        QFont font2;
        font2.setPointSize(10);
        font2.setWeight(QFont::DemiBold);
        groupBox->setFont(font2);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 30, 151, 20));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        label_3->setFont(font3);
        lblTotalProdutos = new QLabel(groupBox);
        lblTotalProdutos->setObjectName("lblTotalProdutos");
        lblTotalProdutos->setGeometry(QRect(30, 160, 221, 16));
        QFont font4;
        font4.setPointSize(10);
        font4.setWeight(QFont::ExtraBold);
        lblTotalProdutos->setFont(font4);
        btnPesquisarProduto_stock = new QPushButton(groupBox);
        btnPesquisarProduto_stock->setObjectName("btnPesquisarProduto_stock");
        btnPesquisarProduto_stock->setGeometry(QRect(390, 50, 51, 25));
        QFont font5;
        font5.setWeight(QFont::DemiBold);
        btnPesquisarProduto_stock->setFont(font5);
        btnPesquisarProduto_stock->setCursor(QCursor(Qt::PointingHandCursor));
        btnPesquisarProduto_stock->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(196, 196, 196);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/pesquisar.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPesquisarProduto_stock->setIcon(icon1);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 30, 121, 20));
        label_4->setFont(font3);
        txtCodigo = new QLineEdit(groupBox);
        txtCodigo->setObjectName("txtCodigo");
        txtCodigo->setGeometry(QRect(30, 50, 91, 22));
        txtCodigo->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtProduto = new QLineEdit(groupBox);
        txtProduto->setObjectName("txtProduto");
        txtProduto->setGeometry(QRect(30, 100, 301, 22));
        txtProduto->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 80, 121, 20));
        label_5->setFont(font3);
        cmbPesquisarGama = new QComboBox(groupBox);
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->addItem(QString());
        cmbPesquisarGama->setObjectName("cmbPesquisarGama");
        cmbPesquisarGama->setGeometry(QRect(160, 50, 171, 22));
        cmbPesquisarGama->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        btnLimparPesquisa = new QPushButton(groupBox);
        btnLimparPesquisa->setObjectName("btnLimparPesquisa");
        btnLimparPesquisa->setGeometry(QRect(390, 100, 51, 25));
        btnLimparPesquisa->setFont(font5);
        btnLimparPesquisa->setCursor(QCursor(Qt::PointingHandCursor));
        btnLimparPesquisa->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(196, 196, 196);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/Refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLimparPesquisa->setIcon(icon2);
        tableWidget_stock = new QTableWidget(page1_Stock);
        tableWidget_stock->setObjectName("tableWidget_stock");
        tableWidget_stock->setGeometry(QRect(30, 80, 721, 371));
        tableWidget_stock->setStyleSheet(QString::fromUtf8("background-color: #E6F7E6;"));
        tableWidget_stock->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_stock->horizontalHeader()->setHighlightSections(false);
        groupBox_2 = new QGroupBox(page1_Stock);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(780, 70, 201, 371));
        QFont font6;
        font6.setBold(true);
        groupBox_2->setFont(font6);
        groupBox_2->setAlignment(Qt::AlignCenter);
        btnSaidaStock = new QPushButton(groupBox_2);
        btnSaidaStock->setObjectName("btnSaidaStock");
        btnSaidaStock->setGeometry(QRect(40, 260, 121, 35));
        QFont font7;
        font7.setPointSize(10);
        font7.setBold(true);
        btnSaidaStock->setFont(font7);
        btnSaidaStock->setCursor(QCursor(Qt::PointingHandCursor));
        btnSaidaStock->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/Remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaidaStock->setIcon(icon3);
        txtQuantidade = new QLineEdit(groupBox_2);
        txtQuantidade->setObjectName("txtQuantidade");
        txtQuantidade->setGeometry(QRect(40, 140, 121, 25));
        txtQuantidade->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtQuantidade->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 60, 121, 20));
        label_6->setFont(font3);
        txtCodigoProduto = new QLineEdit(groupBox_2);
        txtCodigoProduto->setObjectName("txtCodigoProduto");
        txtCodigoProduto->setGeometry(QRect(40, 80, 121, 25));
        txtCodigoProduto->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtCodigoProduto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btnEntradaStock = new QPushButton(groupBox_2);
        btnEntradaStock->setObjectName("btnEntradaStock");
        btnEntradaStock->setGeometry(QRect(40, 200, 121, 35));
        btnEntradaStock->setFont(font7);
        btnEntradaStock->setCursor(QCursor(Qt::PointingHandCursor));
        btnEntradaStock->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEntradaStock->setIcon(icon4);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 120, 121, 20));
        label_7->setFont(font3);
        lblErro = new QLabel(page1_Stock);
        lblErro->setObjectName("lblErro");
        lblErro->setGeometry(QRect(600, 20, 371, 20));
        stackedWidget->addWidget(page1_Stock);

        retranslateUi(StockProdutos);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StockProdutos);
    } // setupUi

    void retranslateUi(QWidget *StockProdutos)
    {
        StockProdutos->setWindowTitle(QCoreApplication::translate("StockProdutos", "Form", nullptr));
        btnInicio_stock->setText(QCoreApplication::translate("StockProdutos", " In\303\255cio", nullptr));
        label_23->setText(QCoreApplication::translate("StockProdutos", "Stock de Produtos", nullptr));
        groupBox->setTitle(QCoreApplication::translate("StockProdutos", "Pesquisar por:", nullptr));
        label_3->setText(QCoreApplication::translate("StockProdutos", "Gama ", nullptr));
        lblTotalProdutos->setText(QCoreApplication::translate("StockProdutos", "Produtos:", nullptr));
        btnPesquisarProduto_stock->setText(QString());
        label_4->setText(QCoreApplication::translate("StockProdutos", "C\303\263digo", nullptr));
        label_5->setText(QCoreApplication::translate("StockProdutos", "Produto", nullptr));
        cmbPesquisarGama->setItemText(0, QString());
        cmbPesquisarGama->setItemText(1, QCoreApplication::translate("StockProdutos", "Vinhos de Mesa", nullptr));
        cmbPesquisarGama->setItemText(2, QCoreApplication::translate("StockProdutos", "Alimenta\303\247\303\243o", nullptr));
        cmbPesquisarGama->setItemText(3, QCoreApplication::translate("StockProdutos", "Cervejas", nullptr));
        cmbPesquisarGama->setItemText(4, QCoreApplication::translate("StockProdutos", "Espumantes e Sidras", nullptr));
        cmbPesquisarGama->setItemText(5, QCoreApplication::translate("StockProdutos", "Licores e Aguardentes", nullptr));
        cmbPesquisarGama->setItemText(6, QCoreApplication::translate("StockProdutos", "\303\201guas e Refrescos", nullptr));

        btnLimparPesquisa->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("StockProdutos", "ALTERAR STOCK", nullptr));
        btnSaidaStock->setText(QCoreApplication::translate("StockProdutos", " Sa\303\255da Diversa", nullptr));
        label_6->setText(QCoreApplication::translate("StockProdutos", "C\303\263digo do Produto", nullptr));
        btnEntradaStock->setText(QCoreApplication::translate("StockProdutos", "Entrada Diversa", nullptr));
        label_7->setText(QCoreApplication::translate("StockProdutos", "Quantidade", nullptr));
        lblErro->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StockProdutos: public Ui_StockProdutos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKPRODUTOS_H
