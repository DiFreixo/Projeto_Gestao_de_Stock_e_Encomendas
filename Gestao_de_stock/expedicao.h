#ifndef EXPEDICAO_H
#define EXPEDICAO_H

#include <QWidget>
#include <QTableWidget>
#include <QStandardItemModel>

namespace Ui {
class Expedicao;
}

class Expedicao : public QWidget
{
    Q_OBJECT

public:
    explicit Expedicao(QWidget *parent = nullptr);
    ~Expedicao();

    //métodos da classe
    void carregarDadosExpedicao();

    //atributos da classe

private:
    Ui::Expedicao *ui;

    //métodos da classe
    void limparTableWidget(QTableWidget *limpaTW);
    void limparCampos();
    void desabilitarCampos();
    void habilitarCampos();
    bool verificarCamposCabecalho();
    void preencherComboboxNif(bool);
    void apresentarEncomendasDisponiveis(const QString &nif);
    void verificarProdutosSelecionados();
    bool verificarSelecaoProdutos();
    void apresentarInfoExpedicao(const int &idExpedicaoGerado);
    void atualizarModeloTreeView();
    void atualizarModeloTableView();
    bool atualizarStatusEncomenda();
    void relatorioExpedicao();


    //atributos da classe
    QString idExpedicaoSelecionado = "";
    QStandardItemModel *modeloTreeView = nullptr;
    QStandardItemModel *modeloTableView = nullptr;
    QTableView *tableViewProdutos = nullptr;

signals:
    void InicioClicked();

private slots:
    void on_btnInicio_expedicao_clicked();
    void on_btnNovo_expedicao_clicked();
    void on_btnVoltar_expedicao_clicked();
    void on_btnPesquisar_clicked();
    void on_btnLimparPesquisa_clicked();
    void on_dateEdit_userDateChanged();
    void on_txtDataExpedicao_editingFinished();
    void on_btnExpedicao_clicked();
    void on_cmbNif_currentTextChanged(const QString &arg1);
    void on_btnGuardar_clicked();
    void on_btnCancelar_clicked();
    void on_btnModificar_clicked();
    void on_tableWidget_expedicoes_cellDoubleClicked();
    void calcularQuantidadeTotalCabecalho();
};

#endif // EXPEDICAO_H
