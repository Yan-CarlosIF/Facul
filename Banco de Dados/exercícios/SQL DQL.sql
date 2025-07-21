CREATE TABLE Departamento (
  codigoDepartamento INT PRIMARY KEY,
  nome VARCHAR(100) NOT NULL
);

CREATE TABLE Empregado (
  codigoEmpregado INT PRIMARY KEY,
  nome VARCHAR(100) NOT NULL,
  endereco VARCHAR(255),
  salario DECIMAL(10,2),
  codigoDepartamento INT,
  FOREIGN KEY (codigoDepartamento) REFERENCES Departamento(codigoDepartamento)
);

-- Departamentos
INSERT INTO Departamento (codigoDepartamento, nome) VALUES
(100, 'RH'),
(200, 'Informática'),
(300, 'Financeiro'),
(400, 'Marketing');

-- Empregados
INSERT INTO Empregado (codigoEmpregado, nome, endereco, salario, codigoDepartamento) VALUES
(1, 'Ana', 'Rua Boa esperança', 2500.00, 200),
(2, 'Beatriz', 'Avenida Coronel Antônio', 3000.00, 300),
(3, 'Carlos', 'Avenida Doutor Antônio', 2500.00, 200),
(4, 'Daniel', 'Travessa José Roberto', 2500.00, 400),
(5, 'Érica', 'Travessa João Abreu', 1500.00, 100),
(6, 'Fernando', 'Travessa 11 de setembro', 1500.00, 100),
(7, 'Gean', 'Rua João Francisco', 2500.00, 200),
(8, 'Helena', 'Rua Chico Nogueira', 3000.00, 300),
(9, 'Iderlan', 'Rua Padre Rocha', 3000.00, 300),
(10, 'Joana', 'Avenida Simão de Góes', 2500.00, 200);

-- Questões
-- Obter quais departamentos a empresa possui.
select * from departamento;

-- Obter nome e salário dos empregados.
select nome, salario
from empregado;

-- Obter o nome e salário apenas dos que ganham mais de 2500.
select nome, salario
from empregado
where salario > 2500;

-- Obter o nome dos funcionários que trabalham no departamento de RH ou Informática.
select e.nome, d.nome
from empregado e join departamento d
on e.codigoDepartamento = d.codigoDepartamento
where d.nome in ('RH', 'Informática');

-- Encontre o total de salários, o maior salário, o menor salário e a média salarial
-- da relação empregados

select 
	count(salario) as total_salarios, 
    max(salario) as maior_salario,
    min(salario) as menor_salario,
    avg(salario) as media_salarial
from empregado;

-- Encontre o maior e menor salário do departamento de RH
select max(salario), min(salario)
from empregado e join departamento d
on e.codigoDepartamento = d.codigoDepartamento
where d.nome = 'RH';

-- Obtenha o número de empregados da empresa
select count(codigoEmpregado) as qtd_empregados
from empregado;

-- listar todos os empregados e seus respectivos departamentos;
select e.nome, d.nome
from empregado e join departamento d
on e.codigoDepartamento = d.codigoDepartamento;

-- listar todos os empregados que trabalham no departamento de "Informática“
select e.nome, d.nome
from empregado e join departamento d
on e.codigoDepartamento = d.codigoDepartamento
where d.nome = 'RH';

-- listar todos os empregados com um salário superior a 2000 e o nome do departamento
select e.nome, salario, d.nome
from empregado e join departamento d
on e.codigoDepartamento = d.codigoDepartamento
where salario > 2000;

-- adicionar empregados sem um departamento;
insert into empregado (codigoEmpregado ,nome, endereco, salario)
values (11, 'Yan', 'Vila Grega', '2500');

-- adicionar departamento que não tenha nenhum empregado;
insert into departamento (codigoDepartamento, nome)
values (600, 'Desenvolvimento');

-- listar todos os departamentos e os empregados associados, se houver;
select d.nome, e.nome
from departamento d left join empregado e
on d.codigoDepartamento = e.codigoDepartamento;

-- encontrar todos os empregados que não estão associados a um departamento;
select e.nome
from empregado e
where e.codigoDepartamento is null;

-- listar todos os empregados e seus respectivos departamentos,
-- incluindo todos os empregados, mesmo que não pertençam a um departamento;
select e.nome, d.nome
from departamento d right join empregado e
on d.codigoDepartamento = e.codigoDepartamento;

-- contar o número de empregados em cada departamento;
select 
	count(codigoEmpregado) as total_empregados,
    d.nome as departamento
from departamento d 
left join empregado e
on d.codigoDepartamento = e.codigoDepartamento
group by d.nome;

-- calcular o salário médio dos empregados em cada departamento;
select 
	avg(salario) as media_salario,
    d.nome as departamento
from departamento d 
left join empregado e
on d.codigoDepartamento = e.codigoDepartamento
group by d.nome;

-- encontrar o salário máximo e mínimo dos empregados em cada departamento;
select 
	max(salario) as maior_salario,
    min(salario) as menor_salario,
    d.nome as departamento
from departamento d 
left join empregado e
on d.codigoDepartamento = e.codigoDepartamento
group by d.nome;

-- listar departamentos com mais de 2 empregados;
select count(codigoEmpregado), d.nome
from departamento d join empregado e
on d.codigoDepartamento = e.codigoDepartamento
group by d.nome
having count(codigoEmpregado) > 2;

-- encontrar departamentos com salários médios acima de 2500;
select d.nome, avg(e.salario) as media
from departamento d join empregado e
on d.codigoDepartamento = e.codigoDepartamento
group by d.nome
having media > 2500;

-- listar o total de salários gastos por departamento, incluindo apenas
-- departamentos com uma soma total de salários superior a 5000;
select d.nome, sum(salario) as folha_salarial
from departamento d join empregado e
on d.codigoDepartamento = e.codigoDepartamento
group by d.nome
having folha_salarial > 5000;