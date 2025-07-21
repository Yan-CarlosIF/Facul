-- Pesquise os itens que  foram vendidos. As colunas presentes no resultado da consulta 
-- são: ID_NF, ID_ITEM, COD_PROD, VALOR_UNIT, VALOR_TOTAL, DESCONTO, 
-- VALOR_VENDIDO. O  VALOR_TOTAL  é  obtido  pela  fórmula:  
-- QUANTIDADE  *  VALOR_UNIT. O VALOR_VENDIDO é = a VALOR_UNIT - (VALOR_UNIT*(DESCONTO/100))
select
    ID_NF,
    ID_ITEM,
    COD_PROD,
    VALOR_UNIT,
    QUANTIDADE * VALOR_UNIT as VALOR_TOTAL,
    DESCONTO,
    VALOR_UNIT - (VALOR_UNIT * (DESCONTO / 100)) as VALOR_VENDIDO
from
    Item;