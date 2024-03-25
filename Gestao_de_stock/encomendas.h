#ifndef ENCOMENDAS_H
#define ENCOMENDAS_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class Encomendas;
}

class Encomendas : public QWidget
{
    Q_OBJECT

public:
    explicit Encomendas(QWidget *parent = nullptr);
    ~Encomendas();

    //métodos da classe
    void carregarDadosEncomendas();

    //atributos da classe



private:
    Ui::Encomendas *ui;

    //métodos da classe
    QMap<QString,  QPair<QString, QString>> listaProdutosDisponiveis();
    void preencherComboboxCodigoProduto();
    void limparTableWidget(QTableWidget *limpaTW);
    void limparCampos();
    void desabilitarCampos();
    void habilitarCampos();
    void atualizarEncomenda();
    bool verificarCamposCabecalho();
    bool verificarCamposLinhas();
    void calcularValorTotalCabecalho();

    //atributos da classe
    QString idEncomendaSelecionada = "";
    int idEncomendaDetalhe = 0;
    QTableWidgetItem* itemQuantidade = nullptr;
    QTableWidgetItem* itemIDEncDetalhe = nullptr;
    QTableWidgetItem* itemIDProduto = nullptr;

signals:
    void InicioClicked();

public slots:
    void preencherComboboxCliente();
    void atualizarComboboxProdutos();

private slots:
    void on_btnInicio_encomendas_clicked();
    void on_btnNovo_encomenda_clicked();
    void on_btnVoltar_encomendas_clicked();
    void on_btnAdLinha_clicked();
    void on_btnEliminaLinha_clicked();
    void atualizarProdutoEPreco(int index);
    void on_calendarWidget_selectionChanged();
    void on_txtDataEntrega_editingFinished();
    void on_btnGuardar_clicked();
    void on_btnCancelar_clicked();
    void on_btnModificar_clicked();
    void on_btnEliminar_clicked();
    void on_btnPesquisar_clicked();
    void on_btnLimparPesquisa_clicked();
    void on_cmbClientes_currentTextChanged(const QString &nif);
    void calcularValorTotalLinha(int row, int column);
    void on_tableWidget_encomendas_cellDoubleClicked();
};

#endif // ENCOMENDAS_H
