# Criando uma lista
frutas = ["maçã", "banana", "laranja"]

# Adicionando elementos
frutas.append("uva")

# Removendo elementos
frutas.remove("banana")

# Acessando um elemento pelo índice
primeira_fruta = frutas[0]  # "maçã"

# Exibindo a lista final
print(frutas)  # ['maçã', 'laranja', 'uva']

# Tuplas (tuple): Coleções ordenadas e imutáveis de itens. Semelhantes às listas, mas não podem ser alteradas após a criação.
tupla = tuple([1, 2, 3, "quatro", 5.0])
# tupla.__add__(6) linha causa erro!
print(tupla)

