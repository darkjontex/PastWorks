CREATE DATABASE bd_roupas;

use bd_roupas;

CREATE TABLE Fornecedor
(
CNPJ CHAR(18) NOT NULL UNIQUE,
tipo_peca CHAR(15) NOT NULL,
logradouro CHAR(20) NOT NULL,
numero INTEGER(5),
bairro CHAR(20) NOT NULL,
cidade CHAR(20) NOT NULL,
UF CHAR(2) NOT NULL,
CEP CHAR(9) NOT NULL,
PRIMARY KEY(CNPJ)
);

CREATE TABLE Fornecedor_telefone
(
CNPJ CHAR(18) NOT NULL,
telefone1 INTEGER(10),
telefone2 INTEGER(10),
PRIMARY KEY(CNPJ)
);

CREATE TABLE Cliente
(
CPF CHAR(14) NOT NULL UNIQUE,
nome CHAR(30) NOT NULL,
data_nasc DATE NOT NULL,
VIP CHAR NOT NULL,
PRIMARY KEY(CPF)
);

CREATE TABLE Cliente_endereco
(
CPF CHAR(14) NOT NULL,
logradouro CHAR(20) NOT NULL,
numero INTEGER(5),
bairro CHAR(20) NOT NULL,
cidade CHAR(20) NOT NULL,
UF CHAR(2) NOT NULL,
CEP CHAR(9) NOT NULL,
PRIMARY KEY(CPF)
);

CREATE TABLE Cliente_telefone
(
CPF CHAR(14) NOT NULL,
telefone1 INTEGER(10),
telefone2 INTEGER(10),
PRIMARY KEY(CPF)
);

CREATE TABLE Historico_compras
(
id_venda INTEGER NOT NULL,
total_gasto REAL NOT NULL,
data_ult_compra DATE NOT NULL,
CPF_cliente CHAR(9) NOT NULL,
PRIMARY KEY(id_venda),
FOREIGN KEY(CPF_cliente) REFERENCES Cliente(CPF)
);

CREATE TABLE Pecas_compradas
(
id_venda INTEGER NOT NULL,
cod_pecas INTEGER NOT NULL,
PRIMARY KEY(id_venda, cod_pecas),
FOREIGN KEY(id_venda) REFERENCES Historico_compras(id_venda)
);

CREATE TABLE Peca
(
codigo INTEGER NOT NULL,
tamanho CHAR(2) NOT NULL,
cor CHAR(20) not null,
codigo_roupa INTEGER NOT NULL,
codigo_fornecedor CHAR(18) NOT NULL,
PRIMARY KEY(codigo),
FOREIGN KEY(codigo_roupa) REFERENCES Roupa(codigo),
FOREIGN KEY(codigo_fornecedor) REFERENCES Fornecedor(CNPJ)
);

CREATE TABLE Fornecedor_peca
(
codigo_peca INTEGER NOT NULL,
codigo_fornecedor CHAR(18) NOT NULL,
PRIMARY KEY(codigo_peca, codigo_fornecedor),
FOREIGN KEY(codigo_peca) REFERENCES Peca(codigo),
FOREIGN KEY(codigo_fornecedor) REFERENCES Fornecedor(CNPJ)
);

CREATE TABLE Pedido
(
codigo_fornecedor CHAR(18) NOT NULL,
qtd INTEGER NOT NULL,
data_entrega DATE NOT NULL,
data_pedido DATE NOT NULL,
data_fabricacao DATE NOT NULL,
PRIMARY KEY(codigo_fornecedor),
FOREIGN KEY(codigo_fornecedor) REFERENCES Fornecedor(CNPJ)
);

CREATE TABLE Roupa
(
codigo INTEGER NOT NULL,
nome CHAR(20) NOT NULL,
preco REAL NOT NULL,
genero CHAR NOT NULL,
tipo_roupa CHAR(15) NOT NULL,
marca CHAR(20) NOT NULL,
qtd_pecas INTEGER NOT NULL,
PRIMARY KEY(codigo)
);

CREATE TABLE Funcionario
(
codigo INTEGER NOT NULL,
nome CHAR(30) NOT NULL,
data_admissao DATE NOT NULL,
data_nasc DATE NOT NULL,
logradouro CHAR(20) NOT NULL,
numero INTEGER(5),
bairro CHAR(20) NOT NULL,
cidade CHAR(20) NOT NULL,
UF CHAR(2) NOT NULL,
CEP CHAR(9) NOT NULL UNIQUE,
PRIMARY KEY(codigo)
);

CREATE TABLE Funcionario_Telefone
(
codigo_forn INTEGER NOT NULL,
telefone1 INTEGER(10),
telefone2 INTEGER(10),
PRIMARY KEY(codigo_forn),
FOREIGN KEY(codigo_forn) REFERENCES Funcionario(codigo)
);

CREATE TABLE Historico_venda_mensal
(
data_hst DATE NOT NULL,
codigo_funcionario INTEGER NOT NULL,
venda_total REAL NOT NULL,
PRIMARY KEY(data_hst, codigo_funcionario)
);

CREATE TABLE Historico_pecas_vendidas_mensal
(
data_hst DATE NOT NULL,
codigo_funcionario INTEGER NOT NULL,
cod_peca INTEGER NOT NULL,
PRIMARY KEY(data_hst, codigo_funcionario, cod_peca),
FOREIGN KEY(data_hst) REFERENCES Historico_venda_mensal(data_hst)
);

CREATE TABLE Venda
(
CPF CHAR(14) NOT NULL,
codigo_funcionario INTEGER NOT NULL,
valor REAL NOT NULL,
data_venda DATE NOT NULL,
PRIMARY KEY(CPF, codigo_funcionario),
FOREIGN KEY(CPF) REFERENCES Cliente(CPF),
FOREIGN KEY(codigo_funcionario) REFERENCES Funcionario(codigo)
);

CREATE TABLE Venda_peca
(
CPF CHAR(14) NOT NULL,
codigo_funcionario INTEGER NOT NULL,
cod_peca INTEGER NOT NULL,
PRIMARY KEY(CPF, codigo_funcionario),
FOREIGN KEY(CPF) REFERENCES Cliente(CPF),
FOREIGN KEY(codigo_funcionario) REFERENCES Funcionario(codigo)
);

CREATE TABLE Peca_valor
(
cod_peca INTEGER NOT NULL,
qtd_peca INTEGER NOT NULL,
PRIMARY KEY(cod_peca),
FOREIGN KEY(cod_peca) REFERENCES Peca(codigo)
);