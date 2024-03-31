#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QDialog>
#include <QTextBrowser>
#include <QPushButton>
#include <QVBoxLayout>

class ReportDialog : public QDialog {
    Q_OBJECT

public:
    explicit ReportDialog(const QString &reportContent, QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Relatório da Ordem de Produção");
        setWindowIcon(QIcon(":/img/img/glowglass.png"));
        setStyleSheet("background-color: #ADCE74;");
        resize(400, 300);


        QVBoxLayout *layout = new QVBoxLayout(this);

        QTextBrowser *textBrowser = new QTextBrowser(this);
        textBrowser->setHtml(reportContent); // Define o conteúdo do relatório em formato HTML

        QPushButton *closeButton = new QPushButton("Fechar", this);
        connect(closeButton, &QPushButton::clicked, this, &ReportDialog::accept);

        layout->addWidget(textBrowser);
        layout->addWidget(closeButton);
    }
};

#endif // REPORTDIALOG_H
