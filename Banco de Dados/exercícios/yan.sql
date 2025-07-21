use hospital;

create table Paciente (
	id_paciente int primary key auto_increment,
    nome varchar(100) not null,
    data_nascimento date not null,
    telefone varchar(15),
    endereco varchar(100)
);

create table Medico (
	id_medico int primary key auto_increment,
    nome varchar(100) not null,
    especialidade varchar(50) not null,
    crm varchar(15) unique not null
);

create table Consulta (
	id_consulta int primary key auto_increment,
    id_paciente int,
    id_medico int,
    data_consulta datetime not null,
    observacoes text,
    foreign key (id_paciente) references Paciente(id_paciente),
    foreign key (id_medico) references Medico(id_medico)
);

/* Inserts */
insert into Paciente (
	nome,
    data_nascimento,
    telefone,
    endereco
) values (
	'Yan Carlos',
    '2005-01-31',
    '88996543569',
    'Rua brutal'
);

insert into Paciente (
	nome,
    data_nascimento,
    telefone,
    endereco
) values (
	'Reperquilson',
    '2000-02-28',
    '88996543249',
    'Seila man'
), (
	'Felipe Bastos',
    '1985-02-25',
    '8542495924',
    'Sorriso monalisa'
);

update Paciente 
set nome = 'Reperquilsa', endereco = 'vizinha de felipe' 
where id_paciente = 2; 

create table Teste (
	id int primary key,
    texto text
);

delete from Paciente where id_paciente = 2;

insert into Medico (
	nome,
    especialidade,
    crm
) values (
	'Medico 1',
    'Cardiologista',
    '123456'
);

insert into Medico (
	nome,
    especialidade,
    crm
) values (
	'Medico 2',
    'Dermatologista',
    '12344556'
);

insert into Consulta (
	id_paciente,
    id_medico,
    data_consulta,
    observacoes
) values (
	1,
    2,
    '2021-02-23 14:23:13',
    'paciente mto doido'
), (
	3,
    1,
    '2024-08-30 18:44:43',
    'paciente is crazy'
);

update Paciente set nome = 'Josefina' where id_paciente = 1;

delete from Consulta where id_consulta >= 2;

/* Adicionar coluna */
alter table teste add column nome varchar(50);
/* Modificar tipo */
alter table teste modify nome int;
/* Modificar o atrr */
alter table Teste change nome name varchar(50);

select * from Paciente;
select * from Medico;
select * from Consulta;
select * from Teste;