# Conjuntos (set): Coleções não ordenadas de elementos únicos. Não permitem duplicatas.
list = [1, 2, 3, 4, 1, 1, 5]
list = set(list) # convertento uma lista em set
print(list)

conjuntos = {1, 2, 3, 4, 5} # Criando um set literalmente
conjuntos.add(3) # tentando adicionar um numero já existente
print(conjuntos) 

# Conjuntos Imutáveis (frozenset): Versão imutável dos conjuntos, que não pode ser alterada após a criação.
conjunto_imutavel = frozenset([1, 2, 3, 4, 5])