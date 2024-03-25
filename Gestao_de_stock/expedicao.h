#ifndef EXPEDICAO_H
#define EXPEDICAO_H

#include <QWidget>

namespace Ui {
class Expedicao;
}

class Expedicao : public QWidget
{
    Q_OBJECT

public:
    explicit Expedicao(QWidget *parent = nullptr);
    ~Expedicao();

private:
    Ui::Expedicao *ui;

// ------------------------------------------------------------------------
signals:
    void InicioClicked();
private slots:
    void on_btnInicio_expedicao_clicked();
    void on_btnNovo_expedicao_clicked();
    void on_btnVoltar_expedicoes_clicked();
};

#endif // EXPEDICAO_H
