create database GameStore;
use GameStore;

create table Cliente (
	cpf varchar(14) primary key,
    telefone varchar(16) not null,
    nome varchar(100) not null,
    email varchar(100) not null unique,
    rua varchar(100) not null,
    cidade varchar(100) not null,
    numero_casa int not null
);

create table Produto (
	id int primary key auto_increment,
	nome varchar(100) unique not null,
	preco decimal(10,2) not null,
	descricao text not null,
	estoque int not null
);

create table Jogo (
	id_produto int primary key,
	desenvolvedora varchar(100) not null,
	data_lancamento date not null,
	plataforma varchar(50) not null,
	foreign key (id_produto) references Produto(id)
);

create table Genero (
	id int primary key auto_increment,
	nome varchar(50) not null,
	id_jogo int not null,
	foreign key (id_jogo) references Jogo(id_produto)
);

create table ItemEletronico (
	fabricante varchar(100) not null,
	tipo varchar(50) not null,
	id_produto int primary key,
	foreign key (id_produto) references Produto(id)
);

create table Pedido (
	id int primary key auto_increment,
    valor_total decimal(10,2) not null,
    status enum('Cancelado', 'Em entrega', 'Entregue') not null,
    data date not null,
    cpf_cliente varchar(14) not null,
    foreign key (cpf_cliente) references Cliente(cpf)
);

create table ProdutoPedido (
	id int primary key auto_increment,
    quantidade int not null,
    sub_total decimal(10,2) not null,
    id_pedido int not null,
    id_produto int not null,
    foreign key (id_pedido) references Pedido(id),
    foreign key (id_produto) references Produto(id),
    unique key unique_pedido_produto (id_pedido, id_produto)
);
