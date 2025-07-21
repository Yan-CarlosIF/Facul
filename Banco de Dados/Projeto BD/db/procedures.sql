use GameStore;

delimiter //

-- Top 5 clientes que mais gastaram
-- Retorna os 5 clientes com maior valor somado em pedidos.
create procedure top_5_clients()
begin
	SELECT 
		c.nome AS cliente,
		c.cpf,
		SUM(p.valor_total) AS total_gasto
	FROM cliente c
	JOIN pedido p ON c.cpf = p.cpf_cliente
	GROUP BY c.nome, c.cpf
	ORDER BY total_gasto DESC
	LIMIT 5;
end //

-- Contar quantos pedidos foram feitos por mês
-- Agrupar pedidos por mês/ano e mostrar a quantidade de pedidos em cada período.
create procedure orders_in_a_month()
begin
	select
		year(data) as ano,
		month(data) as mes,
		monthname(data) as nome_mes,
		count(id) as total_pedidos
	from
		pedido
	group by
		ano,
		mes,
		nome_mes
	order by
		ano desc,
		mes desc;
end //

-- Jogos por Gênero
-- Objetivo: Calcular valor total de vendas agrupadas por gênero de jogo
create procedure game_sales_per_genre()
begin
	select 
		genero.nome as genero,
		sum(pp.sub_total) as valor_total
	from jogo j
	join genero on j.id_produto = id_jogo
	join produto on produto.id = j.id_produto
	join produtopedido pp on pp.id_produto = j.id_produto
	group by genero.nome;
end //

-- todos os gêneros de um jogo específico
-- Dado o nome de um jogo, retornar todos os gêneros associados a ele.
create procedure game_genres(
	in nome_jogo varchar(100)
)
begin
	select 
		genero.nome, produto.nome
	from 
		jogo join genero
	on 
		id_produto = id_jogo 
	join 
		produto on id_produto = produto.id
	where 
		produto.nome = nome_jogo;
end //

-- Listar itens eletrônicos de um fabricante específico (ex: Sony)
-- Retornar nome, preço e tipo de todos os itens eletrônicos de um determinado fabricante.
create procedure eletronic_itens_fabricator (
	p_fabricante varchar(100)
)
begin
	select
		produto.nome, preco, tipo
	from 
		produto join itemeletronico
	on
		produto.id = id_produto
	where
		fabricante = p_fabricante;
end //

-- Buscar pedidos de um cliente específico
-- Mostrar ID do pedido, data e valor total para todos os pedidos feitos por um determinado CPF.
create procedure client_orders (
	in p_cpf varchar(14)
)
begin
	select
		pedido.id, data, valor_total
	from 
		cliente join pedido
	on
		cpf = cpf_cliente
	where 
		cpf_cliente = p_cpf;
end //

-- Relatório de Vendas por Cliente
-- Objetivo: Listar todos os pedidos de um cliente específico com detalhes dos produtos
create procedure sales_report (
	p_cpf varchar(14)
)
begin
	SELECT 
		cliente.nome AS cliente_nome,
		pedido.id AS id_pedido,
		valor_total,
		(
			SELECT COUNT(*) 
			FROM produtopedido
			WHERE id_pedido = pedido.id
		) AS qtd_itens,
		produto.nome AS produto_nome,
		preco,
		quantidade AS qtd_produto,
		sub_total
	FROM cliente 
	JOIN pedido ON cpf = pedido.cpf_cliente
	JOIN produtopedido ON pedido.id = id_pedido
	JOIN produto ON id_produto = produto.id
	WHERE p_cpf = cpf;
end //

-- Listar jogos lançados entre duas datas
-- Mostrar nome, plataforma e data de lançamento dos jogos.
create procedure released_between_dates(
	in data_inicial date,
    in data_final date
)
begin
	select 
		nome, 
		plataforma, 
		data_lancamento
	from produto 
	join jogo on id = id_produto
	where data_lancamento 
	between data_inicial and data_final;
end //

-- Relatório do faturamento mensal por tipo de produto (jogo, eletronico, etc).
create procedure monthly_sales_by_type()
begin
	select
		year(p.data) as ano,
		month(p.data) as mes,
		monthname(p.data) as nome_mes,
		case
			when j.id_produto is not null then 'jogo'
			when e.id_produto is not null then 'eletrônico'
			else 'outro'
		end as tipo_produto,
		sum(pp.sub_total) as faturamento
	from pedido p
	join produtopedido pp on p.id = pp.id_pedido
	join produto pr on pr.id = pp.id_produto
	left join jogo j on j.id_produto = pr.id
	left join itemeletronico e on e.id_produto = pr.id
	group by ano, mes, nome_mes, tipo_produto
	order by ano desc, mes desc, tipo_produto;
end //

-- Identificar clientes que não compram há mais de 6 meses
create procedure inactive_clients()
begin
	select 
		c.cpf,
		c.nome,
		c.email,
		max(p.data) as ultima_compra
	from cliente c
	left join pedido p on c.cpf = p.cpf_cliente
	group by c.cpf, c.nome, c.email
	having ultima_compra is null or ultima_compra < date_sub(curdate(), interval 6 month)
	order by ultima_compra;
end //

delimiter ;