/********************************************************************************
** Form generated from reading UI file 'clientes.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTES_H
#define UI_CLIENTES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clientes
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page1_ListarClientes;
    QPushButton *btnInicio_clientes;
    QLabel *label;
    QPushButton *btnNovo_cliente;
    QTableWidget *tableWidget_clientes;
    QGroupBox *groupBox;
    QLabel *lblTotalClientes;
    QPushButton *btnPesquisarCliente;
    QLineEdit *txtNifPesquisa;
    QLabel *label_4;
    QLineEdit *txtClientePesquisa;
    QLabel *label_5;
    QPushButton *btnLimparPesquisa;
    QWidget *page2_RegistarClientes;
    QTextEdit *txtObservacoes;
    QLineEdit *txtNIF;
    QLineEdit *txtNome;
    QLabel *label_18;
    QLabel *label_13;
    QLineEdit *txtRegisto;
    QLabel *label_16;
    QLabel *label_8;
    QLabel *label_11;
    QLineEdit *txtTelefone;
    QPushButton *btnVoltar_clientes;
    QLineEdit *txtData;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_22;
    QLineEdit *txtEmail;
    QLabel *label_23;
    QPushButton *btnCancelar;
    QPushButton *btnEliminar;
    QPushButton *btnModificar;
    QPushButton *btnGuardar;
    QTextEdit *txtEndereco;
    QLabel *lblErro;

    void setupUi(QWidget *Clientes)
    {
        if (Clientes->objectName().isEmpty())
            Clientes->setObjectName("Clientes");
        Clientes->resize(1010, 671);
        Clientes->setMinimumSize(QSize(1010, 671));
        Clientes->setMaximumSize(QSize(1010, 671));
        stackedWidget = new QStackedWidget(Clientes);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1010, 671));
        stackedWidget->setMinimumSize(QSize(1010, 671));
        stackedWidget->setMaximumSize(QSize(1010, 671));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #ADCE74;"));
        page1_ListarClientes = new QWidget();
        page1_ListarClientes->setObjectName("page1_ListarClientes");
        btnInicio_clientes = new QPushButton(page1_ListarClientes);
        btnInicio_clientes->setObjectName("btnInicio_clientes");
        btnInicio_clientes->setGeometry(QRect(30, 30, 96, 35));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        btnInicio_clientes->setFont(font);
        btnInicio_clientes->setCursor(QCursor(Qt::PointingHandCursor));
        btnInicio_clientes->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/Home.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInicio_clientes->setIcon(icon);
        label = new QLabel(page1_ListarClientes);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 30, 711, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label->setAlignment(Qt::AlignCenter);
        btnNovo_cliente = new QPushButton(page1_ListarClientes);
        btnNovo_cliente->setObjectName("btnNovo_cliente");
        btnNovo_cliente->setGeometry(QRect(884, 30, 96, 35));
        btnNovo_cliente->setFont(font);
        btnNovo_cliente->setCursor(QCursor(Qt::PointingHandCursor));
        btnNovo_cliente->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNovo_cliente->setIcon(icon1);
        tableWidget_clientes = new QTableWidget(page1_ListarClientes);
        tableWidget_clientes->setObjectName("tableWidget_clientes");
        tableWidget_clientes->setGeometry(QRect(30, 80, 951, 371));
        tableWidget_clientes->setStyleSheet(QString::fromUtf8("background-color: #E6F7E6;"));
        tableWidget_clientes->setWordWrap(true);
        tableWidget_clientes->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_clientes->horizontalHeader()->setHighlightSections(false);
        tableWidget_clientes->horizontalHeader()->setStretchLastSection(false);
        groupBox = new QGroupBox(page1_ListarClientes);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 460, 951, 191));
        QFont font2;
        font2.setPointSize(10);
        font2.setWeight(QFont::DemiBold);
        groupBox->setFont(font2);
        lblTotalClientes = new QLabel(groupBox);
        lblTotalClientes->setObjectName("lblTotalClientes");
        lblTotalClientes->setGeometry(QRect(20, 160, 221, 16));
        QFont font3;
        font3.setPointSize(10);
        font3.setWeight(QFont::ExtraBold);
        lblTotalClientes->setFont(font3);
        btnPesquisarCliente = new QPushButton(groupBox);
        btnPesquisarCliente->setObjectName("btnPesquisarCliente");
        btnPesquisarCliente->setGeometry(QRect(360, 50, 51, 25));
        QFont font4;
        font4.setWeight(QFont::DemiBold);
        btnPesquisarCliente->setFont(font4);
        btnPesquisarCliente->setCursor(QCursor(Qt::PointingHandCursor));
        btnPesquisarCliente->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(196, 196, 196);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/pesquisar.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPesquisarCliente->setIcon(icon2);
        txtNifPesquisa = new QLineEdit(groupBox);
        txtNifPesquisa->setObjectName("txtNifPesquisa");
        txtNifPesquisa->setGeometry(QRect(20, 50, 161, 22));
        txtNifPesquisa->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 30, 121, 20));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        label_4->setFont(font5);
        txtClientePesquisa = new QLineEdit(groupBox);
        txtClientePesquisa->setObjectName("txtClientePesquisa");
        txtClientePesquisa->setGeometry(QRect(20, 110, 301, 22));
        txtClientePesquisa->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 90, 121, 20));
        label_5->setFont(font5);
        btnLimparPesquisa = new QPushButton(groupBox);
        btnLimparPesquisa->setObjectName("btnLimparPesquisa");
        btnLimparPesquisa->setGeometry(QRect(440, 50, 51, 25));
        btnLimparPesquisa->setFont(font4);
        btnLimparPesquisa->setCursor(QCursor(Qt::PointingHandCursor));
        btnLimparPesquisa->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(196, 196, 196);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/Refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLimparPesquisa->setIcon(icon3);
        stackedWidget->addWidget(page1_ListarClientes);
        page2_RegistarClientes = new QWidget();
        page2_RegistarClientes->setObjectName("page2_RegistarClientes");
        txtObservacoes = new QTextEdit(page2_RegistarClientes);
        txtObservacoes->setObjectName("txtObservacoes");
        txtObservacoes->setGeometry(QRect(30, 550, 411, 65));
        txtObservacoes->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtNIF = new QLineEdit(page2_RegistarClientes);
        txtNIF->setObjectName("txtNIF");
        txtNIF->setGeometry(QRect(30, 280, 161, 22));
        txtNIF->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtNIF->setMaxLength(9);
        txtNIF->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        txtNome = new QLineEdit(page2_RegistarClientes);
        txtNome->setObjectName("txtNome");
        txtNome->setGeometry(QRect(30, 190, 411, 22));
        txtNome->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_18 = new QLabel(page2_RegistarClientes);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(670, 100, 111, 16));
        label_13 = new QLabel(page2_RegistarClientes);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(280, 260, 91, 16));
        txtRegisto = new QLineEdit(page2_RegistarClientes);
        txtRegisto->setObjectName("txtRegisto");
        txtRegisto->setEnabled(false);
        txtRegisto->setGeometry(QRect(30, 120, 113, 22));
        txtRegisto->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtRegisto->setFrame(false);
        txtRegisto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_16 = new QLabel(page2_RegistarClientes);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(30, 530, 91, 16));
        label_8 = new QLabel(page2_RegistarClientes);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(150, 30, 711, 31));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: #004b23;"));
        label_8->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(page2_RegistarClientes);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 170, 191, 16));
        txtTelefone = new QLineEdit(page2_RegistarClientes);
        txtTelefone->setObjectName("txtTelefone");
        txtTelefone->setGeometry(QRect(280, 280, 161, 22));
        txtTelefone->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        txtTelefone->setMaxLength(9);
        txtTelefone->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btnVoltar_clientes = new QPushButton(page2_RegistarClientes);
        btnVoltar_clientes->setObjectName("btnVoltar_clientes");
        btnVoltar_clientes->setGeometry(QRect(30, 30, 96, 35));
        btnVoltar_clientes->setFont(font);
        btnVoltar_clientes->setCursor(QCursor(Qt::PointingHandCursor));
        btnVoltar_clientes->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVoltar_clientes->setIcon(icon4);
        txtData = new QLineEdit(page2_RegistarClientes);
        txtData->setObjectName("txtData");
        txtData->setEnabled(false);
        txtData->setGeometry(QRect(670, 120, 141, 22));
        txtData->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);"));
        txtData->setFrame(false);
        txtData->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(page2_RegistarClientes);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 100, 81, 16));
        label_12 = new QLabel(page2_RegistarClientes);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 260, 91, 16));
        label_22 = new QLabel(page2_RegistarClientes);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(30, 410, 91, 16));
        txtEmail = new QLineEdit(page2_RegistarClientes);
        txtEmail->setObjectName("txtEmail");
        txtEmail->setGeometry(QRect(30, 360, 411, 22));
        txtEmail->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        label_23 = new QLabel(page2_RegistarClientes);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(30, 340, 91, 16));
        btnCancelar = new QPushButton(page2_RegistarClientes);
        btnCancelar->setObjectName("btnCancelar");
        btnCancelar->setGeometry(QRect(890, 130, 96, 35));
        btnCancelar->setFont(font);
        btnCancelar->setCursor(QCursor(Qt::PointingHandCursor));
        btnCancelar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancelar->setIcon(icon5);
        btnEliminar = new QPushButton(page2_RegistarClientes);
        btnEliminar->setObjectName("btnEliminar");
        btnEliminar->setGeometry(QRect(890, 250, 96, 35));
        btnEliminar->setFont(font);
        btnEliminar->setCursor(QCursor(Qt::PointingHandCursor));
        btnEliminar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/img/Apagar.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEliminar->setIcon(icon6);
        btnModificar = new QPushButton(page2_RegistarClientes);
        btnModificar->setObjectName("btnModificar");
        btnModificar->setGeometry(QRect(890, 190, 96, 35));
        btnModificar->setFont(font);
        btnModificar->setCursor(QCursor(Qt::PointingHandCursor));
        btnModificar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/img/Modify.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModificar->setIcon(icon7);
        btnGuardar = new QPushButton(page2_RegistarClientes);
        btnGuardar->setObjectName("btnGuardar");
        btnGuardar->setGeometry(QRect(890, 70, 96, 35));
        btnGuardar->setFont(font);
        btnGuardar->setCursor(QCursor(Qt::PointingHandCursor));
        btnGuardar->setStyleSheet(QString::fromUtf8("	background-color: #F09200;\n"
"	color: #004b23;\n"
"	border: 1.5px solid #F09200;\n"
"	border-style: outset;\n"
"	border-radius: 5px;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/img/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGuardar->setIcon(icon8);
        txtEndereco = new QTextEdit(page2_RegistarClientes);
        txtEndereco->setObjectName("txtEndereco");
        txtEndereco->setGeometry(QRect(30, 430, 411, 65));
        txtEndereco->setStyleSheet(QString::fromUtf8("background-color:#DAF7D9;"));
        lblErro = new QLabel(page2_RegistarClientes);
        lblErro->setObjectName("lblErro");
        lblErro->setGeometry(QRect(710, 30, 261, 20));
        stackedWidget->addWidget(page2_RegistarClientes);
        QWidget::setTabOrder(txtRegisto, txtData);
        QWidget::setTabOrder(txtData, txtNome);
        QWidget::setTabOrder(txtNome, txtNIF);
        QWidget::setTabOrder(txtNIF, txtTelefone);
        QWidget::setTabOrder(txtTelefone, txtEmail);
        QWidget::setTabOrder(txtEmail, txtEndereco);
        QWidget::setTabOrder(txtEndereco, txtObservacoes);
        QWidget::setTabOrder(txtObservacoes, tableWidget_clientes);
        QWidget::setTabOrder(tableWidget_clientes, btnInicio_clientes);
        QWidget::setTabOrder(btnInicio_clientes, txtNifPesquisa);
        QWidget::setTabOrder(txtNifPesquisa, btnVoltar_clientes);
        QWidget::setTabOrder(btnVoltar_clientes, btnNovo_cliente);
        QWidget::setTabOrder(btnNovo_cliente, txtClientePesquisa);
        QWidget::setTabOrder(txtClientePesquisa, btnCancelar);
        QWidget::setTabOrder(btnCancelar, btnEliminar);
        QWidget::setTabOrder(btnEliminar, btnModificar);
        QWidget::setTabOrder(btnModificar, btnGuardar);
        QWidget::setTabOrder(btnGuardar, btnPesquisarCliente);

        retranslateUi(Clientes);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Clientes);
    } // setupUi

    void retranslateUi(QWidget *Clientes)
    {
        Clientes->setWindowTitle(QCoreApplication::translate("Clientes", "Form", nullptr));
        btnInicio_clientes->setText(QCoreApplication::translate("Clientes", " In\303\255cio", nullptr));
        label->setText(QCoreApplication::translate("Clientes", "Lista de Clientes", nullptr));
        btnNovo_cliente->setText(QCoreApplication::translate("Clientes", " Novo", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Clientes", "Pesquisar por:", nullptr));
        lblTotalClientes->setText(QCoreApplication::translate("Clientes", "Clientes:", nullptr));
        btnPesquisarCliente->setText(QString());
        label_4->setText(QCoreApplication::translate("Clientes", "NIF", nullptr));
        label_5->setText(QCoreApplication::translate("Clientes", "Cliente", nullptr));
        btnLimparPesquisa->setText(QString());
        txtNIF->setText(QString());
        txtNome->setText(QString());
        label_18->setText(QCoreApplication::translate("Clientes", "Data do registo", nullptr));
        label_13->setText(QCoreApplication::translate("Clientes", "Telefone", nullptr));
        label_16->setText(QCoreApplication::translate("Clientes", "Observa\303\247\303\265es", nullptr));
        label_8->setText(QCoreApplication::translate("Clientes", "Registo de Clientes", nullptr));
        label_11->setText(QCoreApplication::translate("Clientes", "Cliente", nullptr));
        txtTelefone->setText(QString());
        btnVoltar_clientes->setText(QCoreApplication::translate("Clientes", " Voltar", nullptr));
        txtData->setText(QString());
        label_9->setText(QCoreApplication::translate("Clientes", "Registo", nullptr));
        label_12->setText(QCoreApplication::translate("Clientes", "NIF", nullptr));
        label_22->setText(QCoreApplication::translate("Clientes", "Endere\303\247o", nullptr));
        txtEmail->setText(QString());
        label_23->setText(QCoreApplication::translate("Clientes", "Email", nullptr));
        btnCancelar->setText(QCoreApplication::translate("Clientes", " Cancelar", nullptr));
        btnEliminar->setText(QCoreApplication::translate("Clientes", " Eliminar", nullptr));
        btnModificar->setText(QCoreApplication::translate("Clientes", " Alterar", nullptr));
        btnGuardar->setText(QCoreApplication::translate("Clientes", " Guardar", nullptr));
        lblErro->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Clientes: public Ui_Clientes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTES_H
