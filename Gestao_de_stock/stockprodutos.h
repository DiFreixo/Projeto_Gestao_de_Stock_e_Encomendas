#ifndef STOCKPRODUTOS_H
#define STOCKPRODUTOS_H

#include <QWidget>
#include <QTableWidget>


namespace Ui {
class StockProdutos;
}

class StockProdutos : public QWidget
{
    Q_OBJECT

public:
    explicit StockProdutos(QWidget *parent = nullptr);
    ~StockProdutos();

    // métodos da classe
    void carregarDadosStock();
    // atributos da classe



private:
    Ui::StockProdutos *ui;

    // métodos da classe
    void limparTableWidget(QTableWidget *limpaTW);
    void alterarCoresLinhas();
    bool verificarCampos();

    // atributos da classe
    int qtdTotalProduto = 0;

signals:
    void InicioClicked();

private slots:
    void on_btnInicio_stock_clicked();
    void on_btnPesquisarProduto_stock_clicked();
    void on_btnEntradaStock_clicked();
    void on_btnSaidaStock_clicked();

    void on_btnLimparPesquisa_clicked();

public slots:


};

#endif // STOCKPRODUTOS_H
