DROP DATABASE IF EXISTS BDGlowGlass;

CREATE DATABASE BDGlowGlass;

USE BDGlowGlass;

CREATE TABLE Produto (
ID_Produto   	INT AUTO_INCREMENT,
Codigo_Produto 	CHAR(7) NOT NULL,		
Produto			VARCHAR(30) NOT NULL,
Stock_minimo	INT NULL,
Preco_venda		DOUBLE NOT NULL default 0,
Descricao		VARCHAR(300) NULL,
Imagem			VARCHAR(200) NULL,
Data_criacao    TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
PRIMARY KEY (ID_Produto)
);

CREATE TABLE ProdutoDetalhe (
ID_ProdutoDetalhe   INT AUTO_INCREMENT,	
ID_Produto   	    INT NOT NULL,
Gama			    VARCHAR(50) NOT NULL,
Cor					VARCHAR(30) NOT NULL,
Volume				INT(3) NOT NULL,
Peso				INT(4) NOT NULL,
Altura				INT(3) NOT NULL,
Diametro    		INT(3) NOT NULL,
PRIMARY KEY (ID_ProdutoDetalhe),
FOREIGN KEY (ID_Produto) references Produto(ID_Produto)
	on update cascade
);

CREATE TABLE Stock (
ID_Stock   		INT AUTO_INCREMENT,	
ID_Produto   	INT NOT NULL,
Qtd_total		INT NOT NULL default 0,
Qtd_reservada	INT NOT NULL default 0,
Qtd_disponivel	INT NOT NULL default 0,
PRIMARY KEY (ID_Stock),
FOREIGN KEY (ID_Produto) references Produto(ID_Produto)
	on update cascade
);
                   
CREATE TABLE Cliente (
ID_Cliente   INT AUTO_INCREMENT,	
NIF   		 INT(9) NOT NULL UNIQUE,
Cliente		 VARCHAR(150) NOT NULL,
Telefone	 VARCHAR(9) NOT NULL,
Email		 VARCHAR(150) NOT NULL,
Endereco	 VARCHAR(200) NOT NULL,
Observacoes  VARCHAR(400) NULL,
Data_criacao TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
PRIMARY KEY (ID_Cliente)
);
     
CREATE TABLE Encomenda (
ID_Encomenda  	INT AUTO_INCREMENT,
Num_Encomenda 	CHAR(8) NOT NULL,	
ID_Cliente  	INT NOT NULL,
Qtd_encomenda	INT NOT NULL CHECK(Qtd_encomenda > 0),
Data_encomenda	TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
Valor			DOUBLE NOT NULL default 0,
Data_entrega	DATE NULL,
Expedida        VARCHAR(7) NOT NULL DEFAULT 'Não',  
PRIMARY KEY (ID_Encomenda),
FOREIGN KEY (ID_Cliente) references Cliente(ID_Cliente)
	on update cascade
);

CREATE TABLE EncomendaDetalhe (
ID_EncomendaDetalhe  	INT AUTO_INCREMENT,
ID_Encomenda            INT NOT NULL,
ID_Produto		        INT NOT NULL,	
Valor			        DOUBLE NOT NULL default 0,
Qtd_produto  	        INT NOT NULL CHECK(Qtd_produto > 0),
Utilizado               BIT NOT NULL default 0,
PRIMARY KEY (ID_EncomendaDetalhe),
FOREIGN KEY (ID_Encomenda) references Encomenda(ID_Encomenda)
	on update cascade,
FOREIGN KEY (ID_Produto) references Produto(ID_Produto)
	on update cascade
);


CREATE TABLE Expedicao (
ID_Expedicao  	INT AUTO_INCREMENT,
Num_Expedicao 	CHAR(8) NOT NULL,	
ID_Cliente  	INT NOT NULL,
Qtd_expedicao	INT NOT NULL CHECK(Qtd_expedicao > 0),
Data_registo	TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
Valor			DOUBLE NOT NULL default 0,
Data_expedicao	DATE NULL,
PRIMARY KEY (ID_Expedicao)
);

CREATE TABLE ExpedicaoDetalhe (
ID_ExpDetalhes  INT AUTO_INCREMENT,
ID_Expedicao	INT NOT NULL,
ID_Encomenda	INT NOT NULL,
ID_Produto		INT NOT NULL,	
Valor			DOUBLE NOT NULL default 0,
Qtd_produto  	INT NOT NULL CHECK(Qtd_produto > 0),
PRIMARY KEY (ID_ExpDetalhes),
FOREIGN KEY (ID_Encomenda) references Encomenda(ID_Encomenda)
	on update cascade,
FOREIGN KEY (ID_Produto) references Produto(ID_Produto)
	on update cascade,
FOREIGN KEY (ID_Expedicao) references Expedicao(ID_Expedicao)
	on update cascade
);


CREATE TABLE Producao (
ID_Producao  		INT AUTO_INCREMENT,
Num_OP				CHAR(7) NOT NULL,
ID_Encomenda  		INT NOT NULL,
Qtd_produzida		INT NOT NULL CHECK(Qtd_produzida > 0),
Data_ordemProducao	TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
Data_Producao       DATE NULL,
Status_OP           VARCHAR(12) NOT NULL DEFAULT 'Planeada',
PRIMARY KEY (ID_Producao),
FOREIGN KEY (ID_Encomenda) references Encomenda(ID_Encomenda)
	on update cascade
);


CREATE TABLE ProducaoDetalhe (
ID_ProducaoDetalhes  INT AUTO_INCREMENT,
ID_Producao		     INT NOT NULL,
ID_Produto		  	 INT NOT NULL,
Qtd_produto  		 INT NOT NULL CHECK(Qtd_produto > 0),	
PRIMARY KEY (ID_ProducaoDetalhes),
FOREIGN KEY (ID_Producao) references Producao(ID_Producao)
	on update cascade,
FOREIGN KEY (ID_Produto) references Produto(ID_Produto)
	on update cascade
);

CREATE TABLE sequenciaNumero (
    seq_nome VARCHAR(20) NOT NULL PRIMARY KEY,
    seq_valor INT NOT NULL
);

INSERT INTO sequenciaNumero (seq_nome, seq_valor) VALUES ('Codigo_Produto', 0);

DELIMITER $
CREATE TRIGGER antes_de_inserir_produto
BEFORE INSERT ON produto
FOR EACH ROW
BEGIN
    UPDATE sequenciaNumero SET seq_valor = seq_valor + 1 WHERE seq_nome = 'Codigo_Produto';
    SELECT seq_valor INTO @next_seq FROM sequenciaNumero WHERE seq_nome = 'Codigo_Produto';
    SET NEW.Codigo_Produto = CONCAT('PR', LPAD(@next_seq, 5, '0'));
END $
DELIMITER ;

INSERT INTO sequenciaNumero (seq_nome, seq_valor) VALUES ('Num_Encomenda', 0);
DELIMITER $
CREATE TRIGGER antes_de_inserir_encomenda
BEFORE INSERT ON encomenda
FOR EACH ROW
BEGIN
    UPDATE sequenciaNumero SET seq_valor = seq_valor + 1 WHERE seq_nome = 'Num_Encomenda';
    SELECT seq_valor INTO @next_seq FROM sequenciaNumero WHERE seq_nome = 'Num_Encomenda';
    SET NEW.Num_Encomenda = CONCAT('ENC', LPAD(@next_seq, 5, '0'));
END $
DELIMITER ;

INSERT INTO sequenciaNumero (seq_nome, seq_valor) VALUES ('Num_Expedicao', 0);
DELIMITER $
CREATE TRIGGER antes_de_inserir_expedicao
BEFORE INSERT ON expedicao
FOR EACH ROW
BEGIN
    UPDATE sequenciaNumero SET seq_valor = seq_valor + 1 WHERE seq_nome = 'Num_Expedicao';
    SELECT seq_valor INTO @next_seq FROM sequenciaNumero WHERE seq_nome = 'Num_Expedicao';
    SET NEW.Num_Expedicao = CONCAT('EXP', LPAD(@next_seq, 5, '0'));
END $
DELIMITER ;

INSERT INTO sequenciaNumero (seq_nome, seq_valor) VALUES ('Num_OP', 0);
DELIMITER $
CREATE TRIGGER antes_de_inserir_producao
BEFORE INSERT ON producao
FOR EACH ROW
BEGIN
    UPDATE sequenciaNumero SET seq_valor = seq_valor + 1 WHERE seq_nome = 'Num_OP';
    SELECT seq_valor INTO @next_seq FROM sequenciaNumero WHERE seq_nome = 'Num_OP';
    SET NEW.Num_OP = CONCAT('OP', LPAD(@next_seq, 5, '0'));
END $
DELIMITER ;