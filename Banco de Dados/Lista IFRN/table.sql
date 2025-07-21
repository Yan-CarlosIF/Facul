-- CRIAÇÃO DA TABELA ITEM
CREATE TABLE
    Item (
        ID_NF INT NOT NULL,
        ID_ITEM INT NOT NULL,
        COD_PROD INT NOT NULL,
        VALOR_UNIT FLOAT NOT NULL,
        QUANTIDADE INT NOT NULL,
        DESCONTO INT
    );

-- INSERÇÃO DE DADOS COM DESCONTO
insert into
    Item (
        ID_NF,
        ID_ITEM,
        COD_PROD,
        VALOR_UNIT,
        QUANTIDADE,
        DESCONTO
    )
values
    (1, 1, 1, 25, 10, 5);

-- INSERÇÃO DE DADOS SEM DESCONTO(NULL)
insert into
    Item (ID_NF, ID_ITEM, COD_PROD, VALOR_UNIT, QUANTIDADE)
values
    (1, 2, 2, 13.5, 3);

insert into
    Item (ID_NF, ID_ITEM, COD_PROD, VALOR_UNIT, QUANTIDADE)
values
    (1, 3, 3, 15, 2);