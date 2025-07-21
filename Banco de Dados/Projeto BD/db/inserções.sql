use GameStore;

insert into Cliente (cpf, telefone, nome, email, rua, cidade, numero_casa) values
('123.456.789-01', '85912345678', 'Yan Carlos', 'yan@example.com', 'Rua das Flores', 'Fortaleza', 101),
('987.654.321-00', '85987654321', 'Maria Silva', 'maria.silva@gmail.com', 'Av. Brasil', 'Aracati', 202),
('456.789.123-00', '85911223344', 'João Pedro', 'joao.pedro@yahoo.com', 'Rua do Sol', 'Sobral', 303);

insert into Produto (nome, preco, descricao, estoque) values
('God of War Ragnarok', 299.90, 'Aventura épica de Kratos e Atreus.', 10),        
('The Legend of Zelda: Tears of the Kingdom', 349.90, 'Jogo de ação e aventura da Nintendo.', 8), 
('Elden Ring', 279.90, 'RPG desafiador em mundo aberto.', 5),                     
('Controle PS5', 399.90, 'Controle sem fio DualSense para PlayStation 5.', 15),   
('Headset Gamer Logitech', 259.90, 'Headset com som surround e microfone.', 20),
('Cyberpunk 2077', 80, ' Um RPG de ação e aventura em mundo aberto, ambientado em Night City, uma megalópole futurista e decadente', 30);

insert into Jogo (id_produto, desenvolvedora, data_lancamento, plataforma) values
(1, 'Santa Monica Studio', '2022-11-09', 'PlayStation 5'),
(2, 'Nintendo', '2023-05-12', 'Nintendo Switch'),
(3, 'FromSoftware', '2022-02-25', 'Multiplataforma'),
(6, 'CD Projekt Red', '2020-12-10', 'PC');

insert into Genero (nome, id_jogo) values
('Ação', 1),
('Aventura', 1),
('Aventura', 2),
('RPG', 3),
('RPG', 6),
('Fantasia', 3),
('Mundo Aberto', 6),
('Mundo Aberto', 3);

insert into ItemEletronico (fabricante, tipo, id_produto) values
('Sony', 'Controle', 4),
('Logitech', 'Headset', 5);

insert into Pedido (valor_total, status, data, cpf_cliente) values
(999.70, 'Entregue', '2025-07-01', '123.456.789-01'),   -- 299.90 + 699.80
(839.70, 'Em entrega', '2025-07-02', '987.654.321-00'), -- 3 Elden Ring
(519.80, 'Cancelado', '2025-07-03', '456.789.123-00');  -- 2 Headsets

-- Pedido 1: 1 God of War + 2 Zeldas
insert into ProdutoPedido (quantidade, sub_total, id_pedido, id_produto) values
(1, 299.90, 1, 1),         -- 1 * 299.90
(2, 699.80, 1, 2);         -- 2 * 349.90

-- Pedido 2: 3 Elden Ring
insert into ProdutoPedido (quantidade, sub_total, id_pedido, id_produto) values
(3, 839.70, 2, 3);         -- 3 * 279.90

-- Pedido 3: 2 Headsets
insert into ProdutoPedido (quantidade, sub_total, id_pedido, id_produto) values
(2, 519.80, 3, 5);         -- 2 * 259.90
