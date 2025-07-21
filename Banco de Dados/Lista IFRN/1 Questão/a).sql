-- Pesquise os itens que foram vendidos sem desconto. As colunas presentes no 
-- resultado da consulta são: ID_NF, ID_ITEM, COD_PROD E VALOR_UNIT.
-- ou * para retornar tudo incluindo o desconto
select
    ID_NF,
    ID_ITEM,
    COD_PROD,
    VALOR_UNIT
from
    Item
where
    DESCONTO is null;