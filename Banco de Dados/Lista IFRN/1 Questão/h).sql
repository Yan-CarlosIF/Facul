-- Consulte as NF que  foram vendidas mais de  10 unidades  de  pelo menos um produto. 
-- As colunas presentes no resultado da consulta são: ID_NF,  COD_PROD, QUANTIDADE. 
-- Agrupe o resultado da consulta por ID_NF, COD_PROD.

select ID_NF, COD_PROD, QUANTIDADE
from VENDA
where QUANTIDADE > 10