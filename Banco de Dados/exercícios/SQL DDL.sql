use world;

create table Autor (
	autor_id int primary key,
    nome varchar(100) not null,
    nacionalidade varchar(50) not null
);

create table Livro (
	livro_id int primary key auto_increment,
    titulo varchar(100) not null,
    autor_id int,
    publicacao date,
    isbn varchar(50),
    foreign key (autor_id) references Autor(autor_id)
);

create table Membro (
	membro_id int primary key auto_increment,
    nome varchar(100) not null,
    endereco varchar(100),
    telefone varchar(18),
    data_cadastro date
);

create table Emprestimo (
	emprestimo_id int primary key auto_increment,
    livro_id int,
    membro_id int,
    data_emprestimo date,
    data_devolucao date,
    foreign key (livro_id) references Livro(livro_id),
    foreign key (membro_id) references Membro(membro_id)
);

alter table Livro
add column editora varchar(50);

alter table Membro
modify telefone varchar(15);

alter table Membro
change endereco endereco_residencial varchar(50);

describe Livro;
describe Membro;