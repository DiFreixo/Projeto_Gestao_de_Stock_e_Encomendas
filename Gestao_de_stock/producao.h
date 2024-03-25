#ifndef PRODUCAO_H
#define PRODUCAO_H

#include <QWidget>

namespace Ui {
class Producao;
}

class Producao : public QWidget
{
    Q_OBJECT

public:
    explicit Producao(QWidget *parent = nullptr);
    ~Producao();

private:
    Ui::Producao *ui;


signals:
    void InicioClicked();
private slots:
    void on_btnInicio_producao_clicked();
    void on_btnNovo_OP_clicked();
    void on_btnVoltar_producao_clicked();
};

#endif // PRODUCAO_H
