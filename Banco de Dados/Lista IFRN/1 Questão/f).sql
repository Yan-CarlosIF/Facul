-- Pesquise o valor vendido das NF e ordene o resultado do maior valor para o menor. As
-- colunas presentes no resultado da consulta são: ID_NF, VALOR_VENDIDO. OBS: O
-- VALOR_TOTAL é obtido pela fórmula: ∑ QUANTIDADE * VALOR_UNIT. O
-- VALOR_VENDIDO é igual a ∑ VALOR_UNIT - (VALOR_UNIT*(DESCONTO/100)). Agrupe
-- o resultado da consulta por ID_NF.
select
    ID_NF,
    sum(VALOR_UNIT - (VALOR_UNIT * (DESCONTO / 100))) as VALOR_VENDIDO
from
    Item
group by
    ID_NF
order by
    VALOR_VENDIDO asc;