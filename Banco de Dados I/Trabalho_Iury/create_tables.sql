CREATE DATABASE bd_danca;

use bd_danca;

CREATE TABLE Nivel
(
codigo_nivel INTEGER NOT NULL UNIQUE,
descricao CHAR,
PRIMARY KEY(codigo_nivel)
);

CREATE TABLE Aluno
(
codigo_matricula INTEGER NOT NULL UNIQUE,
nome CHAR(30) NOT NULL,
email CHAR(30),
telefone INTEGER(11),
data_nascimento DATE,
uf CHAR(2),
cidade CHAR(20),
endereco CHAR(60),
bairro CHAR(14),
cep CHAR(9),
PRIMARY KEY(codigo_matricula)
);

CREATE TABLE Modalidade
(
codigo_modalidade INTEGER NOT NULL UNIQUE,
descricao CHAR(25),
preco INTEGER(6),
PRIMARY KEY(codigo_modalidade)
);

CREATE TABLE Professor
(
codigo_professor INTEGER NOT NULL UNIQUE,
nome CHAR(30),
telefone INTEGER(11),
email CHAR(30),
PRIMARY KEY(codigo_professor)
);

CREATE TABLE Salario
(
comprovante INTEGER(14) NOT NULL,
valor INTEGER NOT NULL,
data_pagamento DATE NOT NULL,
codigo_professor INTEGER NOT NULL,
PRIMARY KEY(comprovante, codigo_professor),
FOREIGN KEY(codigo_professor) REFERENCES Professor(codigo_professor)
);

CREATE TABLE Turma
(
codigo_turma INTEGER NOT NULL UNIQUE,
dias_da_semana CHAR(20),
horario DATETIME,
codigo_nivel INTEGER NOT NULL,
codigo_modalidade INTEGER NOT NULL,
codigo_professor INTEGER NOT NULL,
PRIMARY KEY(codigo_turma),
FOREIGN KEY(codigo_nivel) REFERENCES Nivel(codigo_nivel),
FOREIGN KEY(codigo_modalidade) REFERENCES Modalidade(codigo_modalidade),
FOREIGN KEY(codigo_professor) REFERENCES Professor(codigo_professor)
);

CREATE TABLE Aluno_turma
(
codigo_matricula INTEGER NOT NULL,
codigo_turma INTEGER NOT NULL,
PRIMARY KEY(codigo_matricula,codigo_turma),
FOREIGN KEY(codigo_matricula) REFERENCES Aluno(codigo_matricula),
FOREIGN KEY(codigo_turma) REFERENCES Turma(codigo_turma)
);

CREATE TABLE Dinheiro
(
codigo_recibo INTEGER(14) NOT NULL UNIQUE,
valor INTEGER,
data_pagamento DATE NOT NULL,
codigo_matricula INTEGER NOT NULL,
PRIMARY KEY(codigo_recibo),
FOREIGN KEY(codigo_matricula) REFERENCES Aluno(codigo_matricula)
);

CREATE TABLE Cartão
(
numero_cartao INTEGER(24) NOT NULL,
bandeira CHAR(12) NOT NULL,
data_pagamento DATE NOT NULL,
codigo_comprovante INTEGER(14) NOT NULL,
vencimento_cartao DATE,
codigo_matricula INTEGER NOT NULL,
PRIMARY KEY(numero_cartao),
FOREIGN KEY(codigo_matricula) REFERENCES Aluno(codigo_matricula)
);