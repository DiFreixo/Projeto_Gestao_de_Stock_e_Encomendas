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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Producao
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page1_ListarOP;
    QLabel *label;
    QPushButton *btnInicio_producao;
    QPushButton *btnNovo_OP;
    QTableWidget *tableWidget_producao;
    QWidget *page2_RegistarOP;
    QPushButton *btnVoltar_producao;
    QLabel *label_9;

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
        page1_ListarOP = new QWidget();
        page1_ListarOP->setObjectName("page1_ListarOP");
        label = new QLabel(page1_ListarOP);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 30, 711, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label->setAlignment(Qt::AlignCenter);
        btnInicio_producao = new QPushButton(page1_ListarOP);
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
        btnNovo_OP = new QPushButton(page1_ListarOP);
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
        tableWidget_producao = new QTableWidget(page1_ListarOP);
        tableWidget_producao->setObjectName("tableWidget_producao");
        tableWidget_producao->setGeometry(QRect(30, 80, 951, 351));
        tableWidget_producao->setStyleSheet(QString::fromUtf8("background-color: #E6F7E6;"));
        stackedWidget->addWidget(page1_ListarOP);
        page2_RegistarOP = new QWidget();
        page2_RegistarOP->setObjectName("page2_RegistarOP");
        btnVoltar_producao = new QPushButton(page2_RegistarOP);
        btnVoltar_producao->setObjectName("btnVoltar_producao");
        btnVoltar_producao->setGeometry(QRect(30, 30, 96, 35));
        btnVoltar_producao->setFont(font1);
        btnVoltar_producao->setCursor(QCursor(Qt::PointingHandCursor));
        btnVoltar_producao->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVoltar_producao->setIcon(icon2);
        label_9 = new QLabel(page2_RegistarOP);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(150, 30, 711, 31));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label_9->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page2_RegistarOP);

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
        btnVoltar_producao->setText(QCoreApplication::translate("Producao", " Voltar", nullptr));
        label_9->setText(QCoreApplication::translate("Producao", "Registo de Ordens de Produ\303\247\303\243o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Producao: public Ui_Producao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCAO_H
