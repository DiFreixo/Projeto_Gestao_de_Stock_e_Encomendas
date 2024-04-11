#ifndef PRODUCAO_H
#define PRODUCAO_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class Producao;
}

class Producao : public QWidget
{
    Q_OBJECT

public:
    explicit Producao(QWidget *parent = nullptr);
    ~Producao();

    //métodos da classe
    void carregarDadosProducao();

    //atributos da classe


private:
    Ui::Producao *ui;

    //métodos da classe
    void limparTableWidget(QTableWidget *limpaTW);
    void limparCampos();
    void desabilitarCampos();
    void habilitarCampos();
    bool verificarCamposCabecalho();
    bool verificarCamposLinhas();
    void preencherComboboxCodigoProduto(const QString &nrEncomenda);
    void calcularQuantidadeTotalCabecalho();
    QMap<QString, QList<QString>> produtosEncomendaSelecionada(const QString &nrEncomenda, bool);
    void apresentarInfoOP(const int &idProducaoGerado);
    void atualizarOrdemProducao(QString dataProducao);
    void habilitarBotaoGuardar();

    //atributos da classe
    QString idProducaoSelecionado = "";


signals:
    void InicioClicked();

public slots:
    void preencherComboboxNrEncomenda(bool);

private slots:
    void on_btnInicio_producao_clicked();
    void on_btnNovo_OP_clicked();
    void on_btnVoltar_producao_clicked();
    void on_btnPesquisar_clicked();
    void on_btnLimparPesquisa_clicked();
    void on_btnGuardar_clicked();
    void on_btnCancelar_clicked();
    void on_btnModificar_clicked();
    void on_btnEliminar_clicked();
    void on_btnProducao_clicked();
    void on_btnFechar_clicked();
    void on_dateEdit_userDateChanged();
    void on_txtDataProducao_editingFinished();
    void on_cmbNrEncomenda_currentTextChanged(const QString &arg1);
    void atualizarInfoProduto(int index);
    void on_tableWidget_OrdemProd_cellDoubleClicked();
};

#endif // PRODUCAO_H
