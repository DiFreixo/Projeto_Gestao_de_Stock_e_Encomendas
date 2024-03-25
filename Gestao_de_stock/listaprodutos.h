#ifndef LISTAPRODUTOS_H
#define LISTAPRODUTOS_H

#include <QWidget>
#include <QRadioButton>
#include <QTableWidget>


namespace Ui {
class ListaProdutos;
}

class ListaProdutos : public QWidget
{
    Q_OBJECT

public:
    explicit ListaProdutos(QWidget *parent = nullptr);
    ~ListaProdutos();

    // métodos da classe
    void carregarDadosProdutos();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override; // VERIFICAR!!!!!!!


private:
    Ui::ListaProdutos *ui;

    // métodos da classe
    void limparTableWidget(QTableWidget *limpaTW);
    void validarCampo(QLineEdit *campo, int min, int max, const QString &mensagemErro);
    void limparCampos();
    void desabilitarCampos();
    void habilitarCampos();
    void atualizarProduto();
    void ajustarVisibilidadeBotoes(bool isEdited);
    bool verificarCampos();

    // atributos da classe
    QString caminhoImagemSelecionada = "";
    QRadioButton* ultimoBotaoSelecionado = nullptr;
    QString idProdutoSelecionado = "";
    double precoVenda = 0;

signals:
    void InicioClicked();
    void listaProdutosAtualizada();

private slots:
    void on_btnInicio_produtos_clicked();
    void on_btnNovo_produto_clicked();
    void on_btnVoltar_produtos_clicked();

    void toggleRadioButton();
    void on_btnGuardar_clicked();
    void on_btnCancelar_clicked();
    void on_btnModificar_clicked();
    void on_btnEliminar_clicked();

    void on_btnGuardarImagem_clicked();
    void on_btnEliminarImagem_clicked();
    void on_tableWidget_ListaProdutos_cellDoubleClicked();
    void on_btnPesquisarProduto_clicked();
    void on_btnLimparPesquisa_clicked();
};



#endif // LISTAPRODUTOS_H
