create database atividadenoite;
use atividadenoite;

create table Turma(
	codigo_turma int primary key,
    nome varchar(100)
);

create table Aluno (
	matricula int primary key,
    nome varchar(100),
    telefone varchar(16),
    codigo_turma int,
    foreign key (codigo_turma) references Turma(codigo_turma)
);

create table Disciplina (
	codigo_disc int primary key,
    nome varchar(100),
    carga_horaria int,
    codigo_turma int,
    foreign key (codigo_turma) references Turma(codigo_turma)
);

alter table Aluno
add column cpf varchar(14);

alter table Disciplina
change nome nome_disc varchar(100);

insert into Turma
(codigo_turma, nome) values (
	1, 
    "Informática"
), (
	2,
    "Computação Gráfica"
), (
	3,
    "Computação Forense"
);

insert into Aluno values (
	100,
	"Ana",
    "(88)1111-1111",
    1, 
    "011.011.011-01"
), (
	200,
    "José",
    "(85)2222-2222",
    2,
    "022.022.022-02"
), (
	300,
    "Denise",
    "(85)3333-3333",
    3,
    "033.033.033-03"
), (
	400,
    "Bruno",
    null,
    1,
    "044.044.044-04"
), (
	500,
    "Joaquina",
    "(88)7777-7777",
    2,
    "055.055.055-05"
);

insert into Disciplina values (
	1000,
    "BD",
    80,
    1
), (
	2000,
    "POO",
    80,
    1
), (
	3000,
    "Web Design",
    80,
    2
), (
	4000,
    "Game Design",
    120,
    2
), (
	5000,
    "Segurança",
    60,
    3
);

delete from Aluno where matricula = 100;

update Disciplina
set nome_disc = "Banco de Dados"
where codigo_disc = 1000;

update Disciplina
set nome_disc = "Programação Orientada a Objeto"
where codigo_disc = 2000;

-- drop table Turma; 
/* 
	Não funcionou por que as outras duas tabelas tem sua 
	chave primária como chave estrangeira
*/

update Disciplina
set carga_horaria = 40
where codigo_disc = 1000;

-- Consultas:

-- 1
select a.nome as nome_aluno, t.nome as nome_turma
from Aluno a join Turma t
on a.codigo_turma = t.codigo_turma
where a.codigo_turma = 1;

-- 2
select nome_disc, carga_horaria
from Turma t join Disciplina d
on t.codigo_turma = d.codigo_turma
where t.codigo_turma = 2;

-- 3
select nome
from Aluno
where nome like "J%";

-- 4
select nome_disc
from Disciplina
where carga_horaria between 40 and 60;

-- 5
select nome
from Aluno
where telefone is null;

-- 6
select nome_disc
from Disciplina
order by carga_horaria desc;

-- 7
select nome
from Aluno
where matricula in (100, 200, 300);

-- 8
select a.nome, t.nome
from Aluno a join Turma t
on a.codigo_turma = t.codigo_turma
where t.codigo_turma != 1;

-- 9
select distinct nome
from Turma join Disciplina
on Turma.codigo_turma = Disciplina.codigo_turma
where Disciplina.carga_horaria > 60;

-- 10
select nome_disc
from Disciplina
where nome_disc not like "%Computação%";
