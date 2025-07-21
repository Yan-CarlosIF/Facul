-- Pesquise  o  valor  total  das  NF  e  ordene  o  resultado  do  maior  valor  para  o  menor.  As 
-- colunas presentes no resultado da consulta são: ID_NF, VALOR_TOTAL.  OBS:  O 
-- VALOR_TOTAL  é  obtido  pela  fórmula:  ∑  QUANTIDADE  *  VALOR_UNIT. Agrupe o resultado da consulta por ID_NF.
select
    ID_NF,
    sum(QUANTIDADE * VALOR_UNIT) as VALOR_TOTAL -- A função SUM() em SQL é usada para somar todos os valores de uma coluna
from
    Item
group by
    ID_NF
order by
    VALOR_TOTAL desc;