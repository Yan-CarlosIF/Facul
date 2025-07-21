use GameStore;

-- Top 5 clientes que mais gastaram
-- Retorna os 5 clientes com maior valor somado em pedidos.
call top_5_clients();

-- Contar quantos pedidos foram feitos por mês
-- Agrupar pedidos por mês/ano e mostrar a quantidade de pedidos em cada período.
call orders_in_a_month();

-- Jogos por Gênero
-- Objetivo: Calcular valor total de vendas agrupadas por gênero de jogo
call game_sales_per_genre();

-- Buscar pedidos de um cliente específico
-- Mostrar ID do pedido, data e valor total para todos os pedidos feitos por um determinado CPF.
call client_orders('123.456.789-01');

-- Relatório de Vendas por Cliente
-- Objetivo: Listar todos os pedidos de um cliente específico com detalhes dos produtos
call sales_report('123.456.789-01');

-- todos os gêneros de um jogo específico
-- Dado o nome de um jogo, retornar todos os gêneros associados a ele.
call game_genres('Cyberpunk 2077');

-- Listar itens eletrônicos de um fabricante específico (ex: Sony)
-- Retornar nome, preço e tipo de todos os itens eletrônicos de um determinado fabricante.
call eletronic_itens_fabricator('Sony');

-- Listar jogos lançados entre duas datas
-- Mostrar nome, plataforma e data de lançamento dos jogos.
call released_between_dates('2022-03-07', '2025-03-07');

-- Relatório do faturamento mensal por tipo de produto (jogo, eletronico, etc).
call monthly_sales_by_type();

-- Identificar clientes que não compram há mais de 6 meses
call inactive_clients();
