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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
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
    QTableWidget *tableWidget_expedicao;
    QWidget *page2_RegistarExpedicoes;
    QLabel *label_8;
    QPushButton *btnVoltar_expedicoes;

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
        tableWidget_expedicao = new QTableWidget(page1_ListarExpedicoes);
        tableWidget_expedicao->setObjectName("tableWidget_expedicao");
        tableWidget_expedicao->setGeometry(QRect(30, 80, 951, 371));
        tableWidget_expedicao->setStyleSheet(QString::fromUtf8("background-color: #E6F7E6;"));
        stackedWidget->addWidget(page1_ListarExpedicoes);
        page2_RegistarExpedicoes = new QWidget();
        page2_RegistarExpedicoes->setObjectName("page2_RegistarExpedicoes");
        label_8 = new QLabel(page2_RegistarExpedicoes);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(150, 30, 711, 31));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label_8->setAlignment(Qt::AlignCenter);
        btnVoltar_expedicoes = new QPushButton(page2_RegistarExpedicoes);
        btnVoltar_expedicoes->setObjectName("btnVoltar_expedicoes");
        btnVoltar_expedicoes->setGeometry(QRect(30, 30, 96, 35));
        btnVoltar_expedicoes->setFont(font1);
        btnVoltar_expedicoes->setCursor(QCursor(Qt::PointingHandCursor));
        btnVoltar_expedicoes->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVoltar_expedicoes->setIcon(icon2);
        stackedWidget->addWidget(page2_RegistarExpedicoes);

        retranslateUi(Expedicao);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Expedicao);
    } // setupUi

    void retranslateUi(QWidget *Expedicao)
    {
        Expedicao->setWindowTitle(QCoreApplication::translate("Expedicao", "Form", nullptr));
        label->setText(QCoreApplication::translate("Expedicao", "Lista de Expedi\303\247\303\265es", nullptr));
        btnInicio_expedicao->setText(QCoreApplication::translate("Expedicao", " In\303\255cio", nullptr));
        btnNovo_expedicao->setText(QCoreApplication::translate("Expedicao", " Nova", nullptr));
        label_8->setText(QCoreApplication::translate("Expedicao", "Registo de Expedi\303\247\303\265es", nullptr));
        btnVoltar_expedicoes->setText(QCoreApplication::translate("Expedicao", " Voltar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Expedicao: public Ui_Expedicao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPEDICAO_H
