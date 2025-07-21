CREATE TABLE Paciente (
  id_paciente INT AUTO_INCREMENT PRIMARY KEY,
  nome VARCHAR(100) NOT NULL,
  data_nascimento DATE NOT NULL,
  telefone VARCHAR(20),
  endereco VARCHAR(255)
);

CREATE TABLE Medico (
  id_medico INT AUTO_INCREMENT PRIMARY KEY,
  nome VARCHAR(100) NOT NULL,
  especialidade VARCHAR(100) NOT NULL,
  crm VARCHAR(20) NOT NULL UNIQUE
);

CREATE TABLE Consulta (
  id_consulta INT AUTO_INCREMENT PRIMARY KEY,
  id_paciente INT,
  id_medico INT,
  data_consulta DATETIME NOT NULL,
  observacoes TEXT,
  FOREIGN KEY (id_paciente) REFERENCES Paciente(id_paciente),
  FOREIGN KEY (id_medico) REFERENCES Medico(id_medico)
);

-- Questões de INSERT

-- Insira um novo paciente chamado Carlos Alberto, nascido em 10/05/1990, com telefone (85)99876-5432 e endereço Rua do Sol, 45.
insert into paciente (nome, data_nascimento, telefone, endereco) 
values ('Carlos Alberto', '1990-05-10', '(85)99876-5432', 'Rua do sol, 45');

-- Cadastre uma médica chamada Dra. Mariana Lima, especializada em Pediatria, com o CRM CRM987654.
insert into medico (nome, especialidade, crm)
values ('Dra. Mariana Lima', 'Pediatria', 'CRM987654');

-- Registre uma consulta no dia 20/07/2025 às 09:30, entre o paciente de ID 1 e o médico de ID 1, com a observação: "Consulta de rotina, sem queixas.".
insert into consulta (data_consulta, id_paciente, id_medico, observacoes)
values ('2025-07-20 09:30:00', 1, 1, 'Consulta de rotina, sem queixas.');

-- Questões de UPDATE

-- Atualize o endereço do paciente de ID 1 para "Avenida Central, 200 - Apt 503".
update paciente
set endereco = 'Avenida Central, 200 - Apt 503'
where id_paciente = 1;

select * from paciente;

-- Corrija o número do CRM do médico de ID 1 para CRM123789.
update medico
set crm = 'CRM123789'
where id_medico = 1;

select * from medico;

-- Mude a data da consulta de ID 3 para o dia 25/07/2025 às 14:00.
update consulta
set data_consulta = '2025-07-25 14:00:00'
where id_consulta = 3;

select * from consulta;

-- Questões de DELETE

-- Remova a consulta marcada com o ID 3.
delete from consulta
where id_consulta = 3;

-- Exclua o paciente cujo ID é 1.
delete from paciente
where id_paciente = 1;

-- Apague o cadastro do médico que possui o CRM "CRM000111".
delete from medico 
where crm = 'CRM123789';
