#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//------- Adicionar as novas classes ---------------------------------------
#include "listaprodutos.h"
#include "producao.h"
#include "stockprodutos.h"
#include "clientes.h"
#include "encomendas.h"
#include "expedicao.h"
//------------------------------------------------------------------------

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btnProdutos_clicked();
    void on_btnProducao_clicked();
    void on_btnStock_clicked();
    void on_btnClientes_clicked();
    void on_btnEncomendas_clicked();
    void on_btnExpedicao_clicked();
    void moveInicio();


private:
    Ui::MainWindow *ui;

    //instanciar os objetos das classes
    ListaProdutos *listaProdutos;
    Producao *producao;
    StockProdutos *stockProdutos;
    Clientes *clientes;
    Encomendas *encomendas;
    Expedicao *expedicao;
};
#endif // MAINWINDOW_H
