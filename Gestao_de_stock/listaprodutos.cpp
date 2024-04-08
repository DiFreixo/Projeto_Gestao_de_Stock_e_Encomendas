#include "listaprodutos.h"
#include "ui_listaprodutos.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>
#include <QDateTime>
#include <QTimer>

ListaProdutos::ListaProdutos(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListaProdutos)
{
    ui->setupUi(this);

    carregarDadosProdutos();

    // inicializa na página 'Lista de produtos'
    ui->stackedWidget->setCurrentIndex(0);
    // conecta o sinal clicked() do QRadioButton ao slot correspondente
    connect(ui->rbCanela, &QRadioButton::clicked, this, &ListaProdutos::toggleRadioButton);
    connect(ui->rbFolhaMorta, &QRadioButton::clicked, this, &ListaProdutos::toggleRadioButton);
    connect(ui->rbAzul, &QRadioButton::clicked, this, &ListaProdutos::toggleRadioButton);
    connect(ui->rbNegro, &QRadioButton::clicked, this, &ListaProdutos::toggleRadioButton);
    connect(ui->rbBranco, &QRadioButton::clicked, this, &ListaProdutos::toggleRadioButton);
    connect(ui->rbVerde, &QRadioButton::clicked, this, &ListaProdutos::toggleRadioButton);
    connect(ui->rbAmbar, &QRadioButton::clicked, this, &ListaProdutos::toggleRadioButton);

    // validar os valores inseridos
    QIntValidator *stockMin = new QIntValidator(this);
    ui->txtStockMin->setValidator(stockMin);
    QIntValidator *peso = new QIntValidator(this);
    ui->txtPeso->setValidator(peso);
    QIntValidator *altura = new QIntValidator(this);
    ui->txtAltura->setValidator(altura);
    QIntValidator *diametro = new QIntValidator(this);
    ui->txtDiametro->setValidator(diametro);
    QIntValidator *volume = new QIntValidator(this);
    ui->txtVolume->setValidator(volume);
    QDoubleValidator *precoVenda = new QDoubleValidator(this);
    // permitir até duas casas decimais
    precoVenda->setDecimals(2);
    ui->txtPrecoVenda->setValidator(precoVenda);

    connect(ui->txtPeso, &QLineEdit::editingFinished, this, [=](){
        validarCampo(ui->txtPeso, 75, 1500, "Por favor, insira um valor de peso entre 75 e 1500.");
    });

    connect(ui->txtAltura, &QLineEdit::editingFinished, this, [=](){
        validarCampo(ui->txtAltura, 40, 360, "Por favor, insira um valor de altura entre 40 e 360.");
    });

    connect(ui->txtDiametro, &QLineEdit::editingFinished, this, [=](){
        validarCampo(ui->txtDiametro, 40, 160, "Por favor, insira um valor de diâmetro entre 40 e 160.");
    });

    connect(ui->txtVolume, &QLineEdit::editingFinished, this, [=](){
        validarCampo(ui->txtVolume, 5, 390, "Por favor, insira um valor de volume entre 5 e 390.");
    });

    ui->rbGamas->setVisible(false);
    ui->rbCores->setVisible(false);
    ajustarVisibilidadeBotoes(false);

    // formatar o estilo dos botões
    QString buttonStyle = "QPushButton:enabled {background-color: #F09200; color: #004b23; "
                          "border: 1.5px solid #F09200;border-style: outset;border-radius: 5px;}"
                          "QPushButton:disabled {background-color: #FFC374;}";

    ui->btnVoltar_produtos->setStyleSheet(buttonStyle);
    ui->btnEliminar->setStyleSheet(buttonStyle);
    ui->btnGuardar->setStyleSheet(buttonStyle);
    ui->btnCancelar->setStyleSheet(buttonStyle);
    ui->btnModificar->setStyleSheet(buttonStyle);
}

ListaProdutos::~ListaProdutos()
{
    delete ui;
}

void ListaProdutos::on_btnInicio_produtos_clicked()
{
    emit InicioClicked();
}

void ListaProdutos::on_btnNovo_produto_clicked()
{
    limparCampos();
    ui->stackedWidget->setCurrentIndex(1);
    limparCampos();
    habilitarCampos();
    ajustarVisibilidadeBotoes(true);
    ui->btnVoltar_produtos->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
}

void ListaProdutos::on_btnVoltar_produtos_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//método para validar os valores inseridos nas dimensões do produto
void ListaProdutos::validarCampo(QLineEdit *campo, int min, int max, const QString &mensagemErro)
{
    bool ok;
    int valor = campo->text().toInt(&ok);
    if (ok && (valor < min || valor > max)) {
        QMessageBox::warning(this, "Valor inválido", mensagemErro);
        campo->clear();
    }
}

// Guardar o registo do produto na base de dados
void ListaProdutos::on_btnGuardar_clicked()
{
    // verificar se é, um novo produto a ser guardado na base de dados ou
    // se já é um produto existente que, será modificado e guardadas as suas alterações na base de dados
    if(!ui->txtRegisto->text().isEmpty()) //produto já existe na base de dados
    {
        atualizarProduto();
    }
    else  // novo produto a ser guardado na base de dados
    {
        QString produto = ui->txtNome->text().trimmed();
        QString descricao = ui->txtDescricao->toPlainText().trimmed();
        int stockMin = ui->txtStockMin->text().toInt();
        int diametro = ui->txtDiametro->text().toInt();
        int peso = ui->txtPeso->text().toInt();
        int altura = ui->txtAltura->text().toInt();
        int volume = ui->txtVolume->text().toInt();

        //substituir a vírgula pelo ponto para guardar o valor na base de dados
        QString precoVendaSemVirgula = ui->txtPrecoVenda->text();
        precoVendaSemVirgula.replace(',', '.');
        precoVenda = precoVendaSemVirgula.toDouble();

        QString gama = "", cor = "";
        // verificar qual radioButton está selecionado para obter a Gama e a Cor
        QAbstractButton *gamas = ui->buttonGroup_Gama->checkedButton();
        gama = gamas->text();

        QAbstractButton *cores = ui->buttonGroup_Cor->checkedButton();
        cor = cores->text();

        if (!verificarCampos()) {
            qDebug() << "Falha na verificação dos campos.";
            return;
        }

        // ligação à base de dados para guardar os valores
        QSqlDatabase bd = QSqlDatabase::database();
        bd.transaction(); // Inicia uma transação

        QSqlQuery dados;

        // inserir na tabela 'produto'
        dados.prepare("INSERT INTO produto (Produto, Descricao, Preco_venda, Stock_minimo, Imagem) VALUES "
                      "(:Produto, :Descricao, :Preco_venda, :Stock_minimo, :Imagem)");
        dados.bindValue(":Produto", produto);
        dados.bindValue(":Descricao", descricao);
        dados.bindValue(":Preco_venda", precoVenda);
        dados.bindValue(":Stock_minimo", stockMin);
        dados.bindValue(":Imagem", caminhoImagemSelecionada);

        if (!dados.exec()) {
            qDebug() << "Falha ao inserir na tabela Produto:" << dados.lastError().text();
            bd.rollback(); // Desfaz a transação
            return;
        }

        // Recuperar o ID gerado
        int idGerado = dados.lastInsertId().toInt();

        // Inserir na tabela 'produtoDetalhe'
        dados.prepare("INSERT INTO produtoDetalhe (ID_Produto, Diametro, Peso, Altura, Volume, Gama, Cor) VALUES (:ID_Produto, :Diametro, :Peso, :Altura,"
                      " :Volume, :Gama, :Cor)");
        dados.bindValue(":ID_Produto", idGerado);
        dados.bindValue(":Diametro", diametro);
        dados.bindValue(":Peso", peso);
        dados.bindValue(":Altura", altura);
        dados.bindValue(":Volume", volume);
        dados.bindValue(":Gama", gama);
        dados.bindValue(":Cor", cor);
        if (!dados.exec()) {
            qDebug() << "Falha ao inserir na tabela produtoDetalhe:" << dados.lastError().text();

            // Remove o produto inserido anteriormente
            dados.prepare("DELETE FROM Produto WHERE  ID_Produto = :ID_Produto");
            dados.bindValue(":ID_Produto", idGerado);
            if (!dados.exec()) {
                qDebug() << "Erro ao remover o produto inserido:" << dados.lastError().text();
            }

            bd.rollback(); // Desfaz a transação incluindo a tentativa de remoção
            return;
        }

        // Inserir na tabela 'stock'
        dados.prepare("INSERT INTO stock (ID_Produto) VALUES (:ID_Produto)");
        dados.bindValue(":ID_Produto", idGerado);

        if (!dados.exec()) {
            qDebug() << "Falha ao inserir na tabela stock:" << dados.lastError().text();

            QSqlQuery queryApagar;

            // Remover da tabela 'produtoDetalhe' o produto inserido anteriormente
            queryApagar.prepare("DELETE FROM produtoDetalhe WHERE ID_Produto = :ID_Produto");
            queryApagar.bindValue(":ID_Produto", idGerado);
            if (!queryApagar.exec()) {
                qDebug() << "Erro ao remover o produto da tabela produtoDetalhe:" << queryApagar.lastError().text();
            }

            // Remover da tabela 'produto' o produto inserido anteriormente
            queryApagar.prepare("DELETE FROM produto WHERE ID_Produto = :ID_Produto");
            queryApagar.bindValue(":ID_Produto", idGerado);
            if (!queryApagar.exec()) {
                qDebug() << "Erro ao remover o produto:" << queryApagar.lastError().text();
            }

            bd.rollback(); // Desfaz a transação
            return;
        }

        if (!bd.commit()) {
            QMessageBox::critical(this, "Erro na base de dados", "Falha ao guardar as informações do produto na base de dados."
                                                                 "\nPor favor, contacte o suporte!");

            return;
        }

        qDebug() << "Produto e detalhes inseridos com sucesso.";
        QMessageBox::information(this, "Aviso", "Registo guardado com sucesso!");

        limparCampos();
        habilitarCampos();
        ajustarVisibilidadeBotoes(true);
    }

    ui->btnVoltar_produtos->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    //após registar os produtos é necessário carregar os dados novamente
    carregarDadosProdutos();
    emit listaProdutosAtualizada();
}

// Método para guardar a imagem do produto
void ListaProdutos::on_btnGuardarImagem_clicked()
{
    if(!ui->txtNome->text().isEmpty())
    {
        QString filtro, caminhoImagem;
        filtro = "Imagens (*.jpg *.jpeg *.bmp *.png)";
        caminhoImagem = QFileDialog::getOpenFileName(this, "Selecione a imagem do produto", QDir::homePath(), filtro);
        if (!caminhoImagem.isEmpty())
        {
            this->caminhoImagemSelecionada = caminhoImagem;
            QPixmap imagem(caminhoImagem);
            ui->lblImagem->setPixmap(imagem.scaled(ui->lblImagem->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        else
        {
            QMessageBox::information(this, "Aviso", "Nenhuma imagem selecionada!");
        }
    }
}

// Método para eliminar a imagem do produto
void ListaProdutos::on_btnEliminarImagem_clicked()
{
    if(this->caminhoImagemSelecionada.isEmpty())
    {
        QMessageBox::information(this, "Aviso", "Não há imagem a ser eliminada!");
    }
    else
    {
        ui->lblImagem->clear();
        this->caminhoImagemSelecionada.clear();
        QMessageBox::information(this, "Sucesso", "Imagem removida com sucesso!");
    } 
}

void ListaProdutos::on_btnCancelar_clicked()
{
    limparCampos();
    desabilitarCampos();
    ui->btnVoltar_produtos->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(true);
    ui->lblImagem->setVisible(false);
    ui->btnGuardarImagem->setVisible(false);
    ui->btnEliminarImagem->setVisible(false);
}

// Apresentar a todos os produtos na tabela da lista de produtos
void ListaProdutos::carregarDadosProdutos()
{
    limparTableWidget(ui->tableWidget_ListaProdutos);

    QSqlQuery obterDados;
    obterDados.prepare("SELECT produto.ID_Produto, produto.Codigo_Produto, produto.Produto, produtodetalhe.Gama, produtodetalhe.Cor, "
                       "produtodetalhe.Volume, produtodetalhe.Peso, produtodetalhe.Altura, produtodetalhe.Diametro, produto.Preco_venda, "
                       "produto.Data_criacao FROM produto LEFT JOIN  produtodetalhe ON produto.ID_Produto = produtodetalhe.ID_Produto;");

    //verificar o acesso à BD
    if(obterDados.exec())
    {
        int linha = 0;
        // criar uma tabela com 11 colunas
        ui->tableWidget_ListaProdutos->setColumnCount(11);

        // enquanto existirem registos na base de dados
        while(obterDados.next())
        {
            //inserir uma linha na tabela do formulário
            ui->tableWidget_ListaProdutos->insertRow(linha);
            for(int coluna = 0; coluna < 11; coluna++)
            {
                QTableWidgetItem* novoItem = new QTableWidgetItem(obterDados.value(coluna).toString());
                ui->tableWidget_ListaProdutos->setItem(linha, coluna, novoItem);

                //substituir o ponto pela vírgula e definir 2 casas decimais
                double precoVenda = obterDados.value("Preco_venda").toDouble();
                QString precoVendaSemPonto =  QString::number(precoVenda, 'f', 2);
                precoVendaSemPonto = precoVendaSemPonto.replace('.', ',');
                ui->tableWidget_ListaProdutos->setItem(linha, 9, new QTableWidgetItem(precoVendaSemPonto));
            }

            linha++;
        }

        ui->lblTotalProdutos->setText("Produtos: " + QString::number(linha));

        //colocar os títulos das colunas igual à ordem da query 'obterDados'
        QStringList titulos;
        titulos = {"Registo", "Código", "Produto", "Gama", "Cor", "Volume (cl)", "Peso (g)", "Altura (mm)", "Diâmetro (mm)", "Preço Venda (euros)", "Data Criação"};
        ui->tableWidget_ListaProdutos->setHorizontalHeaderLabels(titulos);
        // formatar título
        ui->tableWidget_ListaProdutos->horizontalHeader()->setStyleSheet("QHeaderView::section {color: white; background-color: #004b23; font: bold 10px}");
        ui->tableWidget_ListaProdutos->setStyleSheet("QTableWidget::item {background-color: #f0f0f0; color: black;}");
        // ocultar os números das linhas
        ui->tableWidget_ListaProdutos->verticalHeader()->setVisible(false);
        // ajustar a largura e altura das colunas
        //ui->tableWidget_ListaProdutos->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
        ui->tableWidget_ListaProdutos->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
        //definir a largura da coluna
        ui->tableWidget_ListaProdutos->setColumnWidth(0, 75);
        ui->tableWidget_ListaProdutos->setColumnWidth(1, 75);
        ui->tableWidget_ListaProdutos->setColumnWidth(2, 130);
        ui->tableWidget_ListaProdutos->setColumnWidth(3, 130);
        ui->tableWidget_ListaProdutos->setColumnWidth(4, 100);
        ui->tableWidget_ListaProdutos->setColumnWidth(5, 90);
        ui->tableWidget_ListaProdutos->setColumnWidth(6, 90);
        ui->tableWidget_ListaProdutos->setColumnWidth(7, 90);
        ui->tableWidget_ListaProdutos->setColumnWidth(8, 90);
        ui->tableWidget_ListaProdutos->setColumnWidth(9, 110);
        ui->tableWidget_ListaProdutos->setColumnWidth(10, 110);
        // desabilitar a edição dos dados
        ui->tableWidget_ListaProdutos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // selecionar a linha inteira da tabela
        ui->tableWidget_ListaProdutos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_ListaProdutos->setStyleSheet("QTableWidget {border: 2px solid #004b23;}");
    }
    else
    {
        QMessageBox::critical(this, "Atenção", "Erro ao carregar a informação dos produtos na tabela.");
        qDebug() << "Erro ao carregar a informação dos produtos na tabela:" << obterDados.lastError().text();
        qDebug() << "Consulta SQL Lista de produtos:" << obterDados.lastQuery();
    }
}

// limpar os dados da tabela
void ListaProdutos::limparTableWidget(QTableWidget *limpaTW)
{
    while(limpaTW->rowCount() > 0)
    {
        limpaTW->removeRow(0);
    }
}

void ListaProdutos::on_tableWidget_ListaProdutos_cellDoubleClicked()
{
    ui->btnVoltar_produtos->setEnabled(true);
    ui->btnEliminar->setEnabled(true);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(true);
    ajustarVisibilidadeBotoes(false);
    desabilitarCampos();

    int idProduto =0;
    int linhaAtual = 0;

    linhaAtual = ui->tableWidget_ListaProdutos->currentRow();
    idProdutoSelecionado = ui->tableWidget_ListaProdutos->item(linhaAtual, 0)->text();
    idProduto = idProdutoSelecionado.toInt();

    ui->stackedWidget->setCurrentIndex(1); // página de registo de produtos

    QSqlQuery obterDados;
    obterDados.prepare("SELECT produto.*, produtodetalhe.Gama, produtodetalhe.Cor, produtodetalhe.Volume, produtodetalhe.Peso, produtodetalhe.Altura, "
                       "produtodetalhe.Diametro, stock.Qtd_total, stock.Qtd_reservada, stock.Qtd_disponivel, expedicaodetalhe.Qtd_produto "
                       "FROM produto LEFT JOIN produtodetalhe ON produto.ID_Produto = produtodetalhe.ID_Produto "
                       "LEFT JOIN stock ON produto.ID_Produto = stock.ID_Produto "
                       "LEFT JOIN expedicaodetalhe ON produto.ID_Produto = expedicaodetalhe.ID_Produto "
                       "WHERE produto.ID_Produto = :idProduto;");     
    obterDados.bindValue(":idProduto", idProduto);

    if(obterDados.exec() && obterDados.first())
    {
        ui->txtRegisto->setText(obterDados.value("ID_Produto").toString());
        ui->txtCodigo->setText(obterDados.value("Codigo_Produto").toString());
        ui->txtNome->setText(obterDados.value("Produto").toString());
        ui->txtDescricao->setText(obterDados.value("Descricao").toString());
        ui->txtAltura->setText(obterDados.value("Altura").toString());
        ui->txtDiametro->setText(obterDados.value("Diametro").toString());
        ui->txtPeso->setText(obterDados.value("Peso").toString());
        ui->txtVolume->setText(obterDados.value("Volume").toString());
        ui->txtStockMin->setText(obterDados.value("Stock_minimo").toString());
        ui->txtQtdTotal->setText(obterDados.value("Qtd_total").toString());
        ui->txtQtdReservada->setText(obterDados.value("Qtd_reservada").toString());
        ui->txtQtdDisponivel->setText(obterDados.value("Qtd_disponivel").toString());

        QString valorGama = obterDados.value("Gama").toString();
        QList<QAbstractButton *> gamas = ui->buttonGroup_Gama->buttons();
        for(QAbstractButton *gama : gamas) {
            if(gama->text() == valorGama) {
                gama->setChecked(true);
                break;
            }
        }

        QString valorCor = obterDados.value("Cor").toString();
        QList<QAbstractButton *> cores = ui->buttonGroup_Cor->buttons();
        for(QAbstractButton *cor : cores) {
            if(cor->text() == valorCor) {
                cor->setChecked(true);
                break;
            }
        }
        //substituir o ponto pela vírgula
        QString precoVendaSemPonto = obterDados.value("Preco_venda").toString();
        precoVendaSemPonto.replace('.', ',');
        ui->txtPrecoVenda->setText(precoVendaSemPonto);

        //  ################ CORRIGIR ###########################
        // Considerar as encomendas expedidas -> é necessário verificar todas as expedições desse produto
        ui->txtTotalVendido->setText(obterDados.value("Qtd_produto").toString());;
        int totalVendas = obterDados.value("Qtd_produto").toInt() * precoVendaSemPonto.toInt();
        ui->txtTotalVendas->setText(QString::number(totalVendas));

        // formatar data
        QString dataStr = obterDados.value("Data_criacao").toString();
        QDateTime dataHora = QDateTime::fromString(dataStr, Qt::ISODate);
        QString dataFormatada = dataHora.toString("dd-MM-yyyy");
        ui->txtDataCriacao->setText(dataFormatada);

        // apresentar a imagem se existir
        QString caminhoImagem = obterDados.value("Imagem").toString();
        if (!caminhoImagem.isEmpty()) {
            QPixmap imagem(caminhoImagem);
            if (!imagem.isNull()) {
                ui->lblImagem->setPixmap(imagem.scaled(ui->lblImagem->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            }
            else {
                qDebug() << "Não foi possível carregar a imagem:" << caminhoImagem;
                ui->lblImagem->setVisible(false);
            }
        } else {
            qDebug() << "Caminho da imagem está vazio.";
            ui->lblImagem->setVisible(false);
        }  
    }
    else
    {
        QMessageBox::critical(this, "Atenção", "Erro ao carregar dados do produto!");
    }
}

void ListaProdutos::on_btnModificar_clicked()
{
    ui->btnVoltar_produtos->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    habilitarCampos();
    ajustarVisibilidadeBotoes(true);
}

void ListaProdutos::atualizarProduto()
{  
    int idProduto = idProdutoSelecionado.toInt();

    QString produto = ui->txtNome->text().trimmed();
    QString descricao = ui->txtDescricao->toPlainText().trimmed();
    int stockMin = ui->txtStockMin->text().toInt();
    int diametro = ui->txtDiametro->text().toInt();
    int peso = ui->txtPeso->text().toInt();
    int altura = ui->txtAltura->text().toInt();
    int volume = ui->txtVolume->text().toInt();

    //substituir a vírgula pelo ponto para guardar o valor na base de dados
    QString precoVendaSemVirgula = ui->txtPrecoVenda->text();
    precoVendaSemVirgula.replace(',', '.');
    precoVenda = precoVendaSemVirgula.toDouble();

    QString gama = "", cor = "";
    // verificar qual radioButton está selecionado para obter a Gama e a Cor
    QAbstractButton *gamas = ui->buttonGroup_Gama->checkedButton();
    gama = gamas->text();

    QAbstractButton *cores = ui->buttonGroup_Cor->checkedButton();
    cor = cores->text();

    // Antes de proceder com a atualização, verificar os campos
    if (!verificarCampos()) {
        qDebug() << "Falha na verificação dos campos.";
        return;
    }

    // ligação à base de dados para guardar/atualizar os valores
    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction(); // Inicia uma transação

    QSqlQuery dados;

    // Alterar na tabela 'produto'
    dados.prepare("UPDATE produto SET Produto = :Produto, "
                  "Descricao = :Descricao, "
                  "Preco_venda = :Preco_venda, "
                  "Stock_minimo = :Stock_minimo, "
                  "Imagem = :Imagem "
                  "WHERE ID_Produto = :ID_Produto");
    dados.bindValue(":ID_Produto", idProduto);
    dados.bindValue(":Produto", produto);
    dados.bindValue(":Descricao", descricao);
    dados.bindValue(":Preco_venda", precoVenda);
    dados.bindValue(":Stock_minimo", stockMin);
    dados.bindValue(":Imagem", caminhoImagemSelecionada);

    if (!dados.exec()) {
        qDebug() << "Falha ao atualizar dados na tabela Produto:" << dados.lastError().text();
        bd.rollback();
        return;
    }

    // Alterar na tabela 'produtoDetalhe'
    dados.prepare("UPDATE produtoDetalhe SET "
                  "Diametro = :Diametro, "
                  "Peso = :Peso, "
                  "Altura = :Altura, "
                  "Volume = :Volume, "
                  "Gama = :Gama, "
                  "Cor = :Cor "
                  "WHERE ID_Produto = :ID_Produto");
    dados.bindValue(":ID_Produto", idProduto);
    dados.bindValue(":Diametro", diametro);
    dados.bindValue(":Peso", peso);
    dados.bindValue(":Altura", altura);
    dados.bindValue(":Volume", volume);
    dados.bindValue(":Gama", gama);
    dados.bindValue(":Cor", cor);
    if (!dados.exec()) {
        qDebug() << "Falha ao atualizar dados na tabela produtoDetalhe:" << dados.lastError().text();
        bd.rollback();
        return;
    }

    if (!bd.commit()) {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao guardar as alterações do produto na base de dados."
                                                             "\nPor favor, contacte o suporte!");
        return;
    }

    qDebug() << "Produto e detalhes alterados com sucesso.";
    QMessageBox::information(this, "Aviso", "Alterações guardadas com sucesso!");

    limparCampos();
    habilitarCampos();
    ajustarVisibilidadeBotoes(true);
}

 //  ################ CORRIGIR ###########################
// Eliminar registo do produto da base de dados
// NOTA1: só é possível eliminar registos de produtos com stock vazio e se não tiver nehuma encomenda/expedição associado a ele - Falta alterar
void ListaProdutos::on_btnEliminar_clicked()
{
    if (ui->txtRegisto->text().isEmpty()){
        QMessageBox::warning(this, "Registo vazio", "Não é possível eliminar registos vazios.");
        return;
    }
    if (ui->txtQtdTotal->text().toInt() > 0){
        QMessageBox::warning(this, "Produto com Stock", "Não é possível eliminar produtos com stock.");
        return;
    }

    else{
        QMessageBox::StandardButton confirmar;
        confirmar = QMessageBox::question(this, "Confirmar",
                                          "Pretende eliminar o produto " + ui->txtNome->text() + "?",
                                          QMessageBox::Yes|QMessageBox::No);

        if (confirmar == QMessageBox::Yes)
        {
            int idProduto = idProdutoSelecionado.toInt();

            QSqlDatabase bd = QSqlDatabase::database();
            bd.transaction();

            QSqlQuery eliminar;

            // primeiro , exclui registos da tabela 'stock', que contem a chave secundária
            eliminar.prepare("DELETE FROM stock WHERE ID_Produto = :idSelecionado");
            eliminar.bindValue(":idSelecionado", idProduto);
            if (!eliminar.exec()) {
                bd.rollback(); // Reverte a transação se ocorrer um erro
                qDebug() << "Erro ao excluir o registo da tabela stock:" << eliminar.lastError().text();
                return;
            }

            // segundo, exclui registos da tabela 'produtoDetalhe', que contem a chave secundária
            eliminar.prepare("DELETE FROM produtodetalhe WHERE ID_Produto = :idSelecionado");
            eliminar.bindValue(":idSelecionado", idProduto);
            if (!eliminar.exec()) {
                bd.rollback(); // Reverte a transação se ocorrer um erro
                qDebug() << "Erro ao excluir o registo da tabela produtoDetalhe:" << eliminar.lastError().text();
                return;
            }

            // Depois, exclui registos da tabela 'produto', que contem a chave primária
            eliminar.prepare("DELETE FROM produto WHERE ID_Produto = :idSelecionado");
            eliminar.bindValue(":idSelecionado", idProduto);
            if (!eliminar.exec()) {
                bd.rollback(); // Reverte a transação se ocorrer um erro
                qDebug() << "Erro ao excluir  o registo da tabela produto:" << eliminar.lastError().text();
                return;
            }

            if (!bd.commit()) {
                QMessageBox::critical(this, "Erro na base de dados", "Falha ao eliminar o registo do produto da base de dados."
                                                                     "\nPor favor, contacte o suporte!");
                return;
            }
            QMessageBox::information(this, "Aviso", "Registo eliminado com sucesso!");

            ui->btnVoltar_produtos->setEnabled(true);
            ui->btnEliminar->setEnabled(false);
            ui->btnGuardar->setEnabled(false);
            ui->btnCancelar->setEnabled(false);
            ui->btnModificar->setEnabled(false);

            ajustarVisibilidadeBotoes(false);
            limparCampos();
            desabilitarCampos();
            carregarDadosProdutos();
            emit listaProdutosAtualizada();
        }
    }
}

bool ListaProdutos::verificarCampos()
{
    if(ui->txtNome->text().isEmpty()){
        ui->lblErro->setText("Atenção! O campo Produto é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtNome->setFocus();
        return false;
    }

    if(ui->txtAltura->text().isEmpty()){
        ui->lblErro->setText("Atenção! O campo Altura é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtAltura->setFocus();
        return false;
    }

    if(ui->txtPeso->text().isEmpty()){
        ui->lblErro->setText("Atenção! O campo Peso é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtPeso->setFocus();
        return false;
    }

    if(ui->txtDiametro->text().isEmpty()){
        ui->lblErro->setText("Atenção! O campo Diâmetro é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtDiametro->setFocus();
        return false;
    }

    if(ui->txtVolume->text().isEmpty()){
        ui->lblErro->setText("Atenção! O campo Volume é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtVolume->setFocus();
        return false;
    }

    if(precoVenda <= 0){
        ui->lblErro->setText("Atenção! O campo Preço Venda é obrigatório e não pode ser negativo.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtPrecoVenda->setFocus();
        return false;
    }

    int stockMin = ui->txtStockMin->text().toInt();
    if (stockMin<0){
        ui->lblErro->setText("Atenção! O campo Stock mínimo não pode ser negativo.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtStockMin->setFocus();
        return false;
    }

    QAbstractButton *gamas = ui->buttonGroup_Gama->checkedButton();
    if (gamas == ui->rbGamas) {
        ui->lblErro->setText("Atenção! Por favor, selecione uma Gama!");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        return false;
    }

    QAbstractButton *cores = ui->buttonGroup_Cor->checkedButton();
    if (cores == ui->rbCores) {
        ui->lblErro->setText("Atenção! Por favor, selecione uma Cor!");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        return false;
    }

    return true;
}

void ListaProdutos::limparCampos()
{
    ui->txtNome->clear();
    ui->txtDescricao->clear();
    ui->txtAltura->clear();
    ui->txtDiametro->clear();
    ui->txtPeso->clear();
    ui->txtVolume->clear();
    ui->txtStockMin->clear();
    ui->txtPrecoVenda->clear();
    ui->lblImagem->clear();
    ui->txtRegisto->clear();
    ui->txtCodigo->clear();
    ui->txtDataCriacao->clear();
    ui->txtQtdTotal->clear();
    ui->txtQtdReservada->clear();
    ui->txtQtdDisponivel->clear();
    ui->txtTotalVendido->clear();
    ui->txtTotalVendas->clear();
    ui->rbCores->setChecked(true);
    ui->rbGamas->setChecked(true);
}

void ListaProdutos::desabilitarCampos()
{
    ui->txtNome->setReadOnly(true);
    ui->txtDescricao->setReadOnly(true);
    ui->txtAltura->setReadOnly(true);
    ui->txtDiametro->setReadOnly(true);
    ui->txtPeso->setReadOnly(true);
    ui->txtVolume->setReadOnly(true);
    ui->txtStockMin->setReadOnly(true);
    ui->txtPrecoVenda->setReadOnly(true);

    QList<QAbstractButton *> buttonsCor = ui->buttonGroup_Cor->buttons();
    for (QAbstractButton *cor : buttonsCor) {
        cor->installEventFilter(this);
    }

    QList<QAbstractButton *> buttonsGama = ui->buttonGroup_Gama->buttons();
    for (QAbstractButton *gama : buttonsGama) {
        gama->installEventFilter(this);
    }
}

bool ListaProdutos::eventFilter(QObject *obj, QEvent *event)
{
    QList<QAbstractButton *> buttonsCor = ui->buttonGroup_Cor->buttons();
    for (QAbstractButton *cor : buttonsCor) {
        if (obj == cor && (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)) {
            // bloqueia o evento, impedindo que o botão seja alterado
            return true;
        }
    }

    QList<QAbstractButton *> buttonsGama = ui->buttonGroup_Gama->buttons();
    for (QAbstractButton *gama : buttonsGama) {
        if (obj == gama && (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)) {
            return true;
        }
    }

    // chama a implementação base para os eventos não tratados
    return QObject::eventFilter(obj, event);
}

void ListaProdutos::habilitarCampos()
{
    ui->txtNome->setReadOnly(false);
    ui->txtDescricao->setReadOnly(false);
    ui->txtAltura->setReadOnly(false);
    ui->txtDiametro->setReadOnly(false);
    ui->txtPeso->setReadOnly(false);
    ui->txtVolume->setReadOnly(false);
    ui->txtStockMin->setReadOnly(false);
    ui->txtPrecoVenda->setReadOnly(false);

    QList<QAbstractButton *> buttonsCor = ui->buttonGroup_Cor->buttons();
    for (QAbstractButton *cor : buttonsCor) {
        cor->removeEventFilter(this);
    }

    QList<QAbstractButton *> buttonsGama = ui->buttonGroup_Gama->buttons();
    for (QAbstractButton *gama : buttonsGama) {
        gama->removeEventFilter(this);
    }
}

void ListaProdutos::on_btnPesquisarProduto_clicked()
{
    QString gama = ui->cmbPesquisarGama->currentText();
    QString cor = "";
    int pesoMin = ui->cmbPeso_min->currentText().toInt();
    int pesoMax = ui->cmbPeso_max->currentText().toInt();
    int volumeMin = ui->cmbVolume_min->currentText().toInt();
    int volumeMax = ui->cmbVolume_max->currentText().toInt();
    int alturaMin = ui->cmbAltura_min->currentText().toInt();
    int alturaMax = ui->cmbAltura_max->currentText().toInt();
    int diametroMin = ui->cmbDiametro_min->currentText().toInt();
    int diametroMax = ui->cmbDiametro_max->currentText().toInt();

    if (pesoMin > pesoMax) {
        QMessageBox::warning(this, "Erro de Pesquisa", "O peso mínimo não pode ser maior do que o peso máximo.");
        return;
    }
    if (volumeMin > volumeMax) {
        QMessageBox::warning(this, "Erro de Pesquisa", "O volume mínimo não pode ser maior do que o volume máximo.");
        return;
    }
    if (alturaMin > alturaMax) {
        QMessageBox::warning(this, "Erro de Pesquisa", "A altura mínima não pode ser maior do que a altura máxima.");
        return;
    }
    if (diametroMin > diametroMax) {
        QMessageBox::warning(this, "Erro de Pesquisa", "O diâmetro mínimo não pode ser maior do que o diâmetro máximo.");
        return;
    }

    if (this->ultimoBotaoSelecionado && this->ultimoBotaoSelecionado->isChecked()) {
        cor = this->ultimoBotaoSelecionado->text(); // Define a cor com base no botão selecionado.
    }

    // construir a consulta SQL
    QString pesquisa = "SELECT produto.ID_Produto, produto.Codigo_Produto, produto.Produto, produtodetalhe.Gama, produtodetalhe.Cor, "
                       "produtodetalhe.Volume, produtodetalhe.Peso, produtodetalhe.Altura, produtodetalhe.Diametro, produto.Preco_venda, "
                       "produto.Data_criacao FROM produto LEFT JOIN  produtodetalhe ON produto.ID_Produto = produtodetalhe.ID_Produto "
                       "WHERE Peso BETWEEN :pesoMin AND :pesoMax AND "
                       "Volume BETWEEN :volumeMin AND :volumeMax AND "
                       "Altura BETWEEN :alturaMin AND :alturaMax AND "
                       "Diametro BETWEEN :diametroMin AND :diametroMax ";

    if (!gama.isEmpty()) {
        pesquisa += " AND Gama = :gama";
    }

    if (!cor.isEmpty()) {
        pesquisa += " AND Cor = :cor";
    }
    else {
        pesquisa += " AND Cor IN ('Canela', 'Folha Morta', 'Azul', 'Negro', 'Branco', 'Verde', 'Âmbar') ";
    }

    // executar a consulta
    QSqlQuery queryPesquisa;
    queryPesquisa.prepare(pesquisa);
    queryPesquisa.bindValue(":pesoMin", pesoMin);
    queryPesquisa.bindValue(":pesoMax", pesoMax);
    queryPesquisa.bindValue(":volumeMin", volumeMin);
    queryPesquisa.bindValue(":volumeMax", volumeMax);
    queryPesquisa.bindValue(":alturaMin", alturaMin);
    queryPesquisa.bindValue(":alturaMax", alturaMax);
    queryPesquisa.bindValue(":diametroMin", diametroMin);
    queryPesquisa.bindValue(":diametroMax", diametroMax);
    queryPesquisa.bindValue(":gama", gama);
    if (!cor.isEmpty()) {
        queryPesquisa.bindValue(":cor", cor);
    }

    if (queryPesquisa.exec()) {
        limparTableWidget(ui->tableWidget_ListaProdutos);
        int linha = 0;

        while (queryPesquisa.next()) {
            ui->tableWidget_ListaProdutos->insertRow(linha);
            for(int coluna = 0; coluna < 11; coluna++)
            {
                QTableWidgetItem* novoItem = new QTableWidgetItem(queryPesquisa.value(coluna).toString());
                ui->tableWidget_ListaProdutos->setItem(linha, coluna, novoItem);

                //substituir o ponto pela vírgula e definir 2 casas decimais
                double precoVenda = queryPesquisa.value("Preco_venda").toDouble();
                QString precoVendaSemPonto =  QString::number(precoVenda, 'f', 2);
                precoVendaSemPonto = precoVendaSemPonto.replace('.', ',');
                ui->tableWidget_ListaProdutos->setItem(linha, 9, new QTableWidgetItem(precoVendaSemPonto));

            }
            linha++;
        }
         ui->lblTotalProdutos->setText("Produtos: " + QString::number(linha));
    } else {
        qDebug() << "Erro ao executar a consulta:" << queryPesquisa.lastError().text();
    }
}

void ListaProdutos::toggleRadioButton()
{
    // definir a cor dos radioButtons
    ui->rbCanela->setStyleSheet("QRadioButton::indicator {background-color:#82581D;}");
    ui->rbFolhaMorta->setStyleSheet("QRadioButton::indicator {background-color:#B8AA4D;}");
    ui->rbAzul->setStyleSheet("QRadioButton::indicator {background-color:#2125E0;}");
    ui->rbNegro->setStyleSheet("QRadioButton::indicator {background-color:#332A33;}");
    ui->rbBranco->setStyleSheet("QRadioButton::indicator {background-color:#FFFFFF;}");
    ui->rbVerde->setStyleSheet("QRadioButton::indicator {background-color:#5FB916;}");
    ui->rbAmbar->setStyleSheet("QRadioButton::indicator {background-color:#912E06;}");

    QRadioButton* rb = qobject_cast<QRadioButton*>(sender());
    // Se o sender não for um QRadioButton -> sair da função
    if (!rb) return;
    // Se o mesmo radioButton foi selecionado novamente e estava marcado, desmarcar e limpar o filtro de cor
    if (rb == this->ultimoBotaoSelecionado && rb->isChecked())
    {
        rb->setChecked(false);
        this->ultimoBotaoSelecionado = nullptr;
        if(rb == ui->rbCanela)
        {
            rb->setStyleSheet("QRadioButton::indicator {background-color:#82581D;}");
            // qDebug() << "rbCanela Unchecked";
        }
        else if(rb == ui->rbFolhaMorta)
        {
            rb->setStyleSheet("QRadioButton::indicator {background-color:#B8AA4D;}");
        }
        else if(rb == ui->rbAzul)
        {
            rb->setStyleSheet("QRadioButton::indicator {background-color:#2125E0;}");
        }
        else if(rb == ui->rbNegro)
        {
            rb->setStyleSheet("QRadioButton::indicator {background-color:#332A33;}");
        }
        else if(rb == ui->rbBranco)
        {
            rb->setStyleSheet("QRadioButton::indicator {background-color:#FFFFFF;}");
        }
        else if(rb == ui->rbVerde)
        {
            rb->setStyleSheet("QRadioButton::indicator {background-color:#5FB916;}");
        }
        else if(rb == ui->rbAmbar)
        {
            rb->setStyleSheet("QRadioButton::indicator {background-color:#912E06;}");
        }
    }
    else
    {
        this->ultimoBotaoSelecionado = rb;
        if(rb == ui->rbCanela)
        {
            rb->setStyleSheet("QRadioButton::indicator:checked {background-color:#82581D; border: 2px solid white; width: 14px;height: 14px;}");
            // qDebug() << "rbCanela Checked";
        }
        else if(rb == ui->rbFolhaMorta)
        {
            rb->setStyleSheet("QRadioButton::indicator:checked {background-color:#B8AA4D; border: 2px solid white; width: 14px;height: 14px;}");
        }
        else if(rb == ui->rbAzul)
        {
            rb->setStyleSheet("QRadioButton::indicator:checked {background-color:#2125E0; border: 2px solid white; width: 14px;height: 14px;}");
        }
        else if(rb == ui->rbNegro)
        {
            rb->setStyleSheet("QRadioButton::indicator:checked {background-color:#332A33; border: 2px solid white; width: 14px;height: 14px;}");
        }
        else if(rb == ui->rbBranco)
        {
            rb->setStyleSheet("QRadioButton::indicator:checked {background-color:#FFFFFF; border: 2px solid white; width: 14px;height: 14px;}");
        }
        else if(rb == ui->rbVerde)
        {
            rb->setStyleSheet("QRadioButton::indicator:checked {background-color:#5FB916; border: 2px solid white; width: 14px;height: 14px;}");
        }
        else if(rb == ui->rbAmbar)
        {
            rb->setStyleSheet("QRadioButton::indicator:checked {background-color:#912E06; border: 2px solid white; width: 14px;height: 14px;}");
        }
    }
}

// método para verificar se o produto está a ser editado ou apenas visualizado
void ListaProdutos::ajustarVisibilidadeBotoes(bool isEdited) {
    // a imagem fica visível no modo edição e no modo visualização
    ui->lblImagem->setVisible(true);

    // habilitar os botões apenas no modo de edição
    ui->btnGuardarImagem->setVisible(isEdited);
    ui->btnEliminarImagem->setVisible(isEdited);
}

void ListaProdutos::on_btnLimparPesquisa_clicked()
{
    ui->cmbPesquisarGama->setCurrentIndex(0);
    ui->cmbPeso_min->setCurrentIndex(0);
    ui->cmbPeso_max->setCurrentIndex(0);
    ui->cmbVolume_min->setCurrentIndex(0);
    ui->cmbVolume_max->setCurrentIndex(0);
    ui->cmbAltura_min->setCurrentIndex(0);
    ui->cmbAltura_max->setCurrentIndex(0);
    ui->cmbDiametro_min->setCurrentIndex(0);
    ui->cmbDiametro_max->setCurrentIndex(0);
    /*
    ui->buttonGroup_pesquisarCor->setExclusive(false); // Permite desmarcar todos os botões
    ui->buttonGroup_pesquisarCor->checkedButton()->setChecked(false);
    //ui->buttonGroup_pesquisarCor->setExclusive(true); // Restaura a exclusividade
    ui->rbCanela->setStyleSheet("QRadioButton::indicator {background-color:#82581D;}");
    ui->rbFolhaMorta->setStyleSheet("QRadioButton::indicator {background-color:#B8AA4D;}");
    ui->rbAzul->setStyleSheet("QRadioButton::indicator {background-color:#2125E0;}");
    ui->rbNegro->setStyleSheet("QRadioButton::indicator {background-color:#332A33;}");
    ui->rbBranco->setStyleSheet("QRadioButton::indicator {background-color:#FFFFFF;}");
    ui->rbVerde->setStyleSheet("QRadioButton::indicator {background-color:#5FB916;}");
    ui->rbAmbar->setStyleSheet("QRadioButton::indicator {background-color:#912E06;}");*/
    carregarDadosProdutos();
}

