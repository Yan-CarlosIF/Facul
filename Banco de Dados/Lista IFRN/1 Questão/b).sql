-- Pesquise os itens que foram vendidos com desconto. As colunas presentes no 
-- resultado da consulta são: ID_NF, ID_ITEM, COD_PROD, VALOR_UNIT E DESCONTO.
select
    ID_NF,
    ID_ITEM,
    COD_PROD,
    VALOR_UNIT
from
    Item
where
    DESCONTO is not null;