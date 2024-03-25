/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_imagemFundo;
    QWidget *barraEsquerda;
    QPushButton *btnProdutos;
    QPushButton *btnProducao;
    QPushButton *btnStock;
    QPushButton *btnClientes;
    QPushButton *btnEncomendas;
    QPushButton *btnExpedicao;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1150, 692);
        MainWindow->setMinimumSize(QSize(1150, 692));
        MainWindow->setMaximumSize(QSize(1150, 692));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/glowglass.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_imagemFundo = new QLabel(centralwidget);
        label_imagemFundo->setObjectName("label_imagemFundo");
        label_imagemFundo->setEnabled(true);
        label_imagemFundo->setGeometry(QRect(0, 0, 1150, 692));
        label_imagemFundo->setMinimumSize(QSize(1150, 692));
        label_imagemFundo->setMaximumSize(QSize(1150, 692));
        label_imagemFundo->setFrameShape(QFrame::Box);
        label_imagemFundo->setFrameShadow(QFrame::Plain);
        label_imagemFundo->setLineWidth(1);
        label_imagemFundo->setScaledContents(true);
        barraEsquerda = new QWidget(centralwidget);
        barraEsquerda->setObjectName("barraEsquerda");
        barraEsquerda->setGeometry(QRect(0, 0, 141, 671));
        barraEsquerda->setStyleSheet(QString::fromUtf8("QWidget { border: 2px solid #004b23; }"));
        btnProdutos = new QPushButton(barraEsquerda);
        btnProdutos->setObjectName("btnProdutos");
        btnProdutos->setGeometry(QRect(7, 120, 122, 51));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        btnProdutos->setFont(font);
        btnProdutos->setCursor(QCursor(Qt::PointingHandCursor));
        btnProdutos->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #004b23;\n"
"	color: #F09200;\n"
"	border: 1.5px solid #004b23;\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"}"));
        btnProducao = new QPushButton(barraEsquerda);
        btnProducao->setObjectName("btnProducao");
        btnProducao->setGeometry(QRect(7, 200, 122, 51));
        btnProducao->setFont(font);
        btnProducao->setCursor(QCursor(Qt::PointingHandCursor));
        btnProducao->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #004b23;\n"
"	color: #F09200;\n"
"	border: 1.5px solid #004b23;\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"}"));
        btnStock = new QPushButton(barraEsquerda);
        btnStock->setObjectName("btnStock");
        btnStock->setGeometry(QRect(7, 280, 122, 51));
        btnStock->setFont(font);
        btnStock->setCursor(QCursor(Qt::PointingHandCursor));
        btnStock->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #004b23;\n"
"	color: #F09200;\n"
"	border: 1.5px solid #004b23;\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"}"));
        btnClientes = new QPushButton(barraEsquerda);
        btnClientes->setObjectName("btnClientes");
        btnClientes->setGeometry(QRect(7, 360, 122, 51));
        btnClientes->setFont(font);
        btnClientes->setCursor(QCursor(Qt::PointingHandCursor));
        btnClientes->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #004b23;\n"
"	color: #F09200;\n"
"	border: 1.5px solid #004b23;\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"}"));
        btnEncomendas = new QPushButton(barraEsquerda);
        btnEncomendas->setObjectName("btnEncomendas");
        btnEncomendas->setGeometry(QRect(7, 440, 122, 51));
        btnEncomendas->setFont(font);
        btnEncomendas->setCursor(QCursor(Qt::PointingHandCursor));
        btnEncomendas->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #004b23;\n"
"	color: #F09200;\n"
"	border: 1.5px solid #004b23;\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"}"));
        btnExpedicao = new QPushButton(barraEsquerda);
        btnExpedicao->setObjectName("btnExpedicao");
        btnExpedicao->setGeometry(QRect(7, 520, 122, 51));
        btnExpedicao->setFont(font);
        btnExpedicao->setCursor(QCursor(Qt::PointingHandCursor));
        btnExpedicao->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #004b23;\n"
"	color: #F09200;\n"
"	border: 1.5px solid #004b23;\n"
"	border-style: outset;\n"
"	border-radius: 5px;\n"
"}"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(141, 0, 1010, 671));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        stackedWidget->setFont(font1);
        page = new QWidget();
        page->setObjectName("page");
        page->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(355, 270, 301, 131));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/glowglass2.png")));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);
        stackedWidget->addWidget(page);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GlowGlass", nullptr));
        label_imagemFundo->setText(QString());
        btnProdutos->setText(QCoreApplication::translate("MainWindow", "Produtos", nullptr));
        btnProducao->setText(QCoreApplication::translate("MainWindow", "Produ\303\247\303\243o", nullptr));
        btnStock->setText(QCoreApplication::translate("MainWindow", "Stock", nullptr));
        btnClientes->setText(QCoreApplication::translate("MainWindow", "Clientes", nullptr));
        btnEncomendas->setText(QCoreApplication::translate("MainWindow", "Encomendas", nullptr));
        btnExpedicao->setText(QCoreApplication::translate("MainWindow", "Expedi\303\247\303\243o", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
