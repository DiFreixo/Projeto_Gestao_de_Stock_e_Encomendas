#include "clientes.h"
#include "ui_clientes.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include <QTimer>

Clientes::Clientes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clientes)
{
    ui->setupUi(this);
    // inicializa na página 0
    ui->stackedWidget->setCurrentIndex(0);

    carregarDadosClientes();

    // formatar o estilo dos botões
    QString buttonStyle = "QPushButton:enabled {background-color: #F09200; color: #004b23; "
                          "border: 1.5px solid #F09200;border-style: outset;border-radius: 5px;}"
                          "QPushButton:disabled {background-color: #FFC374;}";

    ui->btnVoltar_clientes->setStyleSheet(buttonStyle);
    ui->btnEliminar->setStyleSheet(buttonStyle);
    ui->btnGuardar->setStyleSheet(buttonStyle);
    ui->btnCancelar->setStyleSheet(buttonStyle);
    ui->btnModificar->setStyleSheet(buttonStyle);

    QIntValidator *nifTex = new QIntValidator(this);
    ui->txtNIF->setValidator(nifTex);
    QIntValidator *telefone = new QIntValidator(this);
    ui->txtTelefone->setValidator(telefone);
    //ui->txtTelefone->setInputMask("999 999 999;_");

}

Clientes::~Clientes()
{
    delete ui;
}

void Clientes::on_btnInicio_clientes_clicked()
{
    emit InicioClicked();
}

void Clientes::on_btnNovo_cliente_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    limparCampos();
    habilitarCampos();
    ui->btnVoltar_clientes->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
}

void Clientes::on_btnVoltar_clientes_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// Guardar o registo do cliente na base de dados
void Clientes::on_btnGuardar_clicked()
{
    QString cliente = ui->txtNome->text().trimmed();
    int nifNumero = ui->txtNIF->text().toInt();
    QString telefone = ui->txtTelefone->text();
    QString email = ui->txtEmail->text().trimmed();
    QString endereco = ui->txtEndereco->toPlainText().trimmed();
    QString observacoes = ui->txtObservacoes->toPlainText().trimmed();

    // verificar se o NIF do cliente já existe na base de dados,
    QString queryStr = "SELECT COUNT(*) FROM cliente WHERE NIF = :nifNumero";
    // se o cliente já estiver registado na base de dados, esse registo é ignorado,
    //para que a verificação do NIF não considere o próprio cliente como um registro duplicado.
    if (!ui->txtRegisto->text().isEmpty()) {
        queryStr += " AND ID_Cliente != :idCliente";
    }

    QSqlQuery queryNifExistente;
    queryNifExistente.prepare(queryStr);
    queryNifExistente.bindValue(":nifNumero", nifNumero);
    if (!ui->txtRegisto->text().isEmpty()) { //cliente já existe na base de dados
        int idCliente = ui->txtRegisto->text().toInt();
        queryNifExistente.bindValue(":idCliente", idCliente);
    }

    queryNifExistente.exec();
    if (queryNifExistente.next() && queryNifExistente.value(0).toInt() > 0) {
        QMessageBox::warning(this, "NIF existente", "Já existe um cliente com este NIF.");
        return;
    }

    if(!ui->txtRegisto->text().isEmpty()) //cliente já existe na base de dados
    {
        atualizarCliente();
    }
    else  // novo cliente a ser guardado na base de dados
    {
        if (!verificarCampos()) {
            qDebug() << "Falha na verificação dos campos.";
            return;
        }

        // ligação à base de dados para guardar os valores
        QSqlDatabase bd = QSqlDatabase::database();
        bd.transaction(); // Inicia uma transação

        QSqlQuery dados;

        dados.prepare("INSERT INTO cliente (NIF, Cliente, Telefone, Email, Endereco, Observacoes) VALUES "
                      "(:nifNumero, :cliente, :telefone, :email, :endereco, :observacoes)");
        dados.bindValue(":nifNumero", nifNumero);
        dados.bindValue(":cliente", cliente);
        dados.bindValue(":telefone", telefone);
        dados.bindValue(":email", email);
        dados.bindValue(":endereco", endereco);
        dados.bindValue(":observacoes", observacoes);

        if (!dados.exec()) {
            qDebug() << "Falha ao inserir na tabela Cliente:" << dados.lastError().text();
            bd.rollback(); // Desfaz a transação
            return;
        }

        if (!bd.commit()) {
            QMessageBox::critical(this, "Erro na base de dados", "Falha ao guardar as informações do cliente na base de dados."
                                                                 "\nPor favor, contacte o suporte!");
            return;
        }

        qDebug() << "Cliente inserido com sucesso.";
        QMessageBox::information(this, "Aviso", "Registo guardado com sucesso!");

        limparCampos();
        habilitarCampos();
    }

    ui->btnVoltar_clientes->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    carregarDadosClientes();
    emit clientesAtualizados();
}

void Clientes::on_btnCancelar_clicked()
{
    limparCampos();
    desabilitarCampos();
    ui->btnVoltar_clientes->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(true);
}

void Clientes::carregarDadosClientes()
{
    limparTableWidget(ui->tableWidget_clientes);

    QSqlQuery obterDados;
    obterDados.prepare("SELECT ID_Cliente, NIF, Cliente, Telefone, Email, Data_criacao FROM cliente;");

    //verificar o acesso à BD
    if(obterDados.exec())
    {
        int linha = 0;
        // criar uma tabela com 6 colunas
        ui->tableWidget_clientes->setColumnCount(6);

        // enquanto existirem registos na base de dados
        while(obterDados.next())
        {
            //inserir uma linha na tabela do formulário
            ui->tableWidget_clientes->insertRow(linha);
            for(int coluna = 0; coluna < 6; coluna++)
            {
                QTableWidgetItem* novoItem = new QTableWidgetItem(obterDados.value(coluna).toString());
                ui->tableWidget_clientes->setItem(linha, coluna, novoItem);
            }
            linha++;
        }
        ui->lblTotalClientes->setText("Clientes: " + QString::number(linha));

        //colocar os títulos das colunas igual à ordem da query 'obterDados'
        QStringList titulos;
        titulos = {"Registo", "NIF", "Cliente", "Telefone", "Email", "Data Criação"};
        ui->tableWidget_clientes->setHorizontalHeaderLabels(titulos);
        // formatar título
        ui->tableWidget_clientes->horizontalHeader()->setStyleSheet("QHeaderView::section {color: white; background-color: #004b23; font: bold 10px}");
        ui->tableWidget_clientes->setStyleSheet("QTableWidget::item {background-color: #f0f0f0; color: black;}");
        // ocultar os números das linhas
        ui->tableWidget_clientes->verticalHeader()->setVisible(false);
        // ajustar a altura das colunas
        ui->tableWidget_clientes->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
        //definir a largura da coluna
        ui->tableWidget_clientes->setColumnWidth(0, 100);
        ui->tableWidget_clientes->setColumnWidth(1, 100);
        ui->tableWidget_clientes->setColumnWidth(2, 200);
        ui->tableWidget_clientes->setColumnWidth(3, 200);
        ui->tableWidget_clientes->setColumnWidth(4, 200);
        ui->tableWidget_clientes->setColumnWidth(5, 200);
        // desabilitar a edição dos dados
        ui->tableWidget_clientes->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // selecionar a linha inteira da tabela
        ui->tableWidget_clientes->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget_clientes->setStyleSheet("QTableWidget {border: 2px solid #004b23;}");
    }
    else
    {
        QMessageBox::critical(this, "Atenção", "Erro ao carregar a informação dos clientes na tabela");
        qDebug() << "Erro ao carregar a informação dos clientes:" << obterDados.lastError().text();
        qDebug() << "Consulta SQL Lista de clientes:" << obterDados.lastQuery();
    }
}

void Clientes::limparTableWidget(QTableWidget *limpaTW)
{
    while(limpaTW->rowCount() > 0)
    {
        limpaTW->removeRow(0);
    }
}

void Clientes::on_tableWidget_clientes_cellDoubleClicked()
{
    ui->btnVoltar_clientes->setEnabled(true);
    ui->btnEliminar->setEnabled(true);
    ui->btnGuardar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(true);
    desabilitarCampos();

    int linhaAtual = 0;
    int idCliente = 0;
    linhaAtual = ui->tableWidget_clientes->currentRow();
    idClienteSelecionado  = ui->tableWidget_clientes->item(linhaAtual, 0)->text();
    idCliente = idClienteSelecionado.toInt();

    ui->stackedWidget->setCurrentIndex(1);

    QSqlQuery obterDados;
    obterDados.prepare("SELECT * FROM cliente WHERE ID_Cliente = :idCliente;");
    obterDados.bindValue(":idCliente", idCliente);

    if(obterDados.exec() && obterDados.first())
    {
        ui->txtRegisto->setText(obterDados.value("ID_Cliente").toString());
        ui->txtNome->setText(obterDados.value("Cliente").toString());
        ui->txtNIF->setText(obterDados.value("NIF").toString());
        ui->txtTelefone->setText(obterDados.value("Telefone").toString());
        ui->txtEmail->setText(obterDados.value("Email").toString());
        ui->txtEndereco->setText(obterDados.value("Endereco").toString());
        ui->txtObservacoes->setText(obterDados.value("Observacoes").toString());

        // formatar data
        QString dataStr = obterDados.value("Data_criacao").toString();
        QDateTime dataHora = QDateTime::fromString(dataStr, Qt::ISODate);
        QString dataFormatada = dataHora.toString("dd-MM-yyyy");
        ui->txtData->setText(dataFormatada);
    }
    else
    {
        QMessageBox::critical(this, "Atenção", "Erro ao carregar dados do cliente!");
        qDebug() << "Erro ao carregar dados do cliente:" << obterDados.lastError().text();
    }
}

void Clientes::on_btnModificar_clicked()
{
    ui->btnVoltar_clientes->setEnabled(true);
    ui->btnEliminar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnModificar->setEnabled(false);
    habilitarCampos();
}

void Clientes::atualizarCliente()
{  
    int idCliente = idClienteSelecionado.toInt();

    QString cliente = ui->txtNome->text().trimmed();
    int nifNumero = ui->txtNIF->text().toInt();
    QString telefone = ui->txtTelefone->text();
    QString email = ui->txtEmail->text().trimmed();
    QString endereco = ui->txtEndereco->toPlainText().trimmed();
    QString observacoes = ui->txtObservacoes->toPlainText().trimmed();

    // Antes de proceder com a atualização, verificar os campos
    if (!verificarCampos()) {
        qDebug() << "Falha na verificação dos campos.";
        return;
    }

    // ligação à base de dados para guardar/atualizar os valores
    QSqlDatabase bd = QSqlDatabase::database();
    bd.transaction(); // Inicia uma transação

    QSqlQuery dados;
    // Alterar na tabela 'cliente'
    dados.prepare("UPDATE cliente SET NIF = :NIF, "
                  "Cliente = :Cliente, "
                  "Telefone = :Telefone, "
                  "Email = :Email, "
                  "Endereco = :Endereco, "
                  "Observacoes = :Observacoes "
                  "WHERE ID_Cliente = :ID_Cliente");
    dados.bindValue(":NIF", nifNumero);
    dados.bindValue(":Cliente", cliente);
    dados.bindValue(":Telefone", telefone);
    dados.bindValue(":Email", email);
    dados.bindValue(":Endereco", endereco);
    dados.bindValue(":Observacoes", observacoes);
    dados.bindValue(":ID_Cliente", idCliente);

    if (!dados.exec()) {
        qDebug() << "Falha ao atualizar dados na tabela Cliente:" << dados.lastError().text();
        bd.rollback();
        return;
    }

    if (!bd.commit()) {
        QMessageBox::critical(this, "Erro na base de dados", "Falha ao guardar as alterações do cliente na base de dados."
                                                             "\nPor favor, contacte o suporte!");
        qDebug() << "Consulta SQL Lista de clientes:" << dados.lastQuery();
        return;
    }
    qDebug() << "Informações do cliente alteradas com sucesso.";
    QMessageBox::information(this, "Aviso", "Alterações guardadas com sucesso!");

    limparCampos();
    habilitarCampos();
}

void Clientes::on_btnEliminar_clicked()
{
    if (ui->txtRegisto->text().isEmpty()){
        QMessageBox::warning(this, "Registo vazio", "Não é possível eliminar registos vazios.");
        return;
    }
    else{
        QMessageBox::StandardButton confirmar;
        confirmar = QMessageBox::question(this, "Confirmar",
                                          "Pretende eliminar o cliente " + ui->txtNome->text() + " ?",
                                          QMessageBox::Yes|QMessageBox::No);

        if (confirmar == QMessageBox::Yes)
        {
            int idCliente = idClienteSelecionado.toInt();

            QSqlDatabase bd = QSqlDatabase::database();
            bd.transaction();

            QSqlQuery eliminar;

            eliminar.prepare("DELETE FROM cliente WHERE ID_Cliente = :ID_Cliente");
            eliminar.bindValue(":ID_Cliente", idCliente);
            if (!eliminar.exec()) {
                bd.rollback(); // Reverte a transação se ocorrer um erro
                qDebug() << "Erro ao excluir  o registo da tabela cliente:" << eliminar.lastError().text();
                return;
            }

            if (!bd.commit()) {
                QMessageBox::critical(this, "Erro na base de dados", "Falha ao eliminar o registo do cliente da base de dados."
                                                                     "\nPor favor, contacte o suporte!");
                return;
            }

            QMessageBox::information(this, "Aviso", "Registo eliminado com sucesso!");

            ui->btnVoltar_clientes->setEnabled(true);
            ui->btnEliminar->setEnabled(false);
            ui->btnGuardar->setEnabled(false);
            ui->btnCancelar->setEnabled(false);
            ui->btnModificar->setEnabled(false);

            limparCampos();
            desabilitarCampos();
            carregarDadosClientes();
            emit clientesAtualizados();
        }
    }
}


void Clientes::on_btnPesquisarCliente_clicked()
{
    QString nif = ui->txtNifPesquisa->text();
    QString cliente = ui->txtClientePesquisa->text();

    QString pesquisa = "SELECT ID_Cliente, NIF, Cliente, Telefone, Email, Data_criacao FROM cliente WHERE 1=1 ";
    if (!nif.isEmpty()) {
        pesquisa += " AND NIF = :nif";
    }
    if (!cliente.isEmpty()) {
        pesquisa += " AND Cliente LIKE :cliente";
        cliente = "%" + cliente + "%";
    }

    // executar a consulta
    QSqlQuery queryPesquisa;
    queryPesquisa.prepare(pesquisa);
    queryPesquisa.bindValue(":nif", nif);
    queryPesquisa.bindValue(":cliente", cliente);

    if (queryPesquisa.exec()) {
        limparTableWidget(ui->tableWidget_clientes);
        int linha = 0;
        // enquanto existirem registos na base de dados
        while (queryPesquisa.next()) {
            ui->tableWidget_clientes->insertRow(linha);
            for(int coluna = 0; coluna < 6; coluna++)
            {
                ui->tableWidget_clientes->setItem(linha, coluna, new QTableWidgetItem(queryPesquisa.value(coluna).toString()));
            }
            linha++;
        }
        ui->lblTotalClientes->setText("Clientes: " + QString::number(linha));
    } else {
        qDebug() << "Erro ao executar a consulta de clientes:" << queryPesquisa.lastError().text();
    }
}

void Clientes::limparCampos()
{
    ui->txtRegisto->clear();
    ui->txtNome->clear();
    ui->txtNIF->clear();
    ui->txtTelefone->clear();
    ui->txtEmail->clear();
    ui->txtEndereco->clear();
    ui->txtObservacoes->clear();
    ui->txtData->clear();
}

void Clientes::desabilitarCampos()
{
    ui->txtRegisto->setReadOnly(true);
    ui->txtNome->setReadOnly(true);
    ui->txtNIF->setReadOnly(true);
    ui->txtTelefone->setReadOnly(true);
    ui->txtEmail->setReadOnly(true);
    ui->txtEndereco->setReadOnly(true);
    ui->txtObservacoes->setReadOnly(true);
    ui->txtData->setReadOnly(true);
}

void Clientes::habilitarCampos()
{
    ui->txtNome->setReadOnly(false);
    ui->txtNIF->setReadOnly(false);
    ui->txtTelefone->setReadOnly(false);
    ui->txtEmail->setReadOnly(false);
    ui->txtEndereco->setReadOnly(false);
    ui->txtObservacoes->setReadOnly(false);
}

// Verificar se os campos obrigatórios estão preenchidos
bool Clientes::verificarCampos()
{
    if(ui->txtNome->text().isEmpty()){
        ui->lblErro->setText("Atenção! O campo Cliente é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtNome->setFocus();
        return false;
    }
    if(ui->txtNIF->text().isEmpty() || ui->txtNIF->text().length() != 9){
        ui->lblErro->setText("Atenção! Erro no campo NIF!");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtNIF->setFocus();
        return false;
    }
    if( ui->txtTelefone->text().isEmpty() || ui->txtTelefone->text().length() != 9){
        ui->lblErro->setText("Atenção! Erro no campo Telefone!");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtTelefone->setFocus();
        return false;

    }
    if(ui->txtEmail->text().isEmpty()){
        ui->lblErro->setText("Atenção! O campo Email é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtEmail->setFocus();
        return false;
    }
    if(ui->txtEndereco->toPlainText().isEmpty()){
        ui->lblErro->setText("Atenção! O campo Endereço é obrigatório.");
        QTimer::singleShot(3000, ui->lblErro, &QLabel::clear);
        ui->txtEndereco->setFocus();
        return false;
    }
    return true;
}

void Clientes::on_btnLimparPesquisa_clicked()
{
    ui->txtNifPesquisa->clear();
    ui->txtClientePesquisa->clear();
    carregarDadosClientes();
}

