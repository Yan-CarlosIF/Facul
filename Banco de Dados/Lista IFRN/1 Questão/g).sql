-- Consulte  o  produto  que  mais  vendeu  no  geral.  As  colunas  presentes  no  resultado  da 
-- consulta são: COD_PROD, QUANTIDADE. Agrupe o resultado da consulta por COD_PROD.

select
    COD_PROD,
    sum(QUANTIDADE) as QUANTIDADE
from
    Item
group by
    COD_PROD
order by
    QUANTIDADE asc;