#ifndef CLIENTES_H
#define CLIENTES_H


#include <QWidget>
#include <QTableWidget>

namespace Ui {
class Clientes;
}

class Clientes : public QWidget
{
    Q_OBJECT

public:
    explicit Clientes(QWidget *parent = nullptr);
    ~Clientes();

    // métodos da classe
    void carregarDadosClientes();

    // atributos da classe

private:
    Ui::Clientes *ui;


    // métodos da classe
    void limparCampos();
    void desabilitarCampos();
    void habilitarCampos();
    void limparTableWidget(QTableWidget *limpaTW);
    void atualizarCliente();
    bool verificarCampos();

    // atributos da classe
    QString idClienteSelecionado = "";


signals:
    void InicioClicked();
    void clientesAtualizados();

private slots:
    void on_btnInicio_clientes_clicked();
    void on_btnNovo_cliente_clicked();
    void on_btnVoltar_clientes_clicked();
    void on_btnGuardar_clicked();
    void on_btnCancelar_clicked();
    void on_btnModificar_clicked();
    void on_btnEliminar_clicked();
    void on_tableWidget_clientes_cellDoubleClicked();
    void on_btnPesquisarCliente_clicked();
    void on_btnLimparPesquisa_clicked();
};

#endif // CLIENTES_H
