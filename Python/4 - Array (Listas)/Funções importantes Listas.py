# Criando uma lista inicial
arr = [1, 2, 3]

# 1. Adicionando um item ao final da lista
arr.append(4)
print("Depois de append(4):", arr)  # [1, 2, 3, 4]

# 2. Adicionando todos os elementos de um iterável ao final da lista
arr.extend([5, 6])
print("Depois de extend([5, 6]):", arr)  # [1, 2, 3, 4, 5, 6]

# 3. Inserindo um item em uma posição específica
arr.insert(2, 9)
print("Depois de insert(2, 9):", arr)  # [1, 2, 9, 3, 4, 5, 6]

# 4. Removendo o primeiro item na lista com o valor especificado
arr.remove(9)
print("Depois de remove(9):", arr)  # [1, 2, 3, 4, 5, 6]

# 5. Removendo e retornando o item na posição especificada
popped_item = arr.pop()  # Remove o último item
print("Depois de pop():", arr)  # [1, 2, 3, 4, 5]
print("Item removido com pop():", popped_item)  # 6

# Removendo o item na indice 2
popped_item = arr.pop(2)
print("Depois de pop(2):", arr)  # [1, 2, 4, 5]
print("Item removido com pop(2):", popped_item)  # 3

# 6. Obtendo o índice do primeiro item com o valor especificado
index = arr.index(4)
print("Índice de 4:", index)  # 2

# 7. Contando o número de vezes que um item aparece na lista
count = arr.count(4)
print("Quantidade de vezes que 4 aparece:", count)  # 1

# 8. Ordenando a lista
arr.sort()
print("Depois de sort():", arr)  # [1, 2, 4, 5]

# 9. Invertendo a ordem dos elementos na lista
arr.reverse()
print("Depois de reverse():", arr)  # [5, 4, 2, 1]

# 10. Criando uma cópia da lista
arr_copy = arr.copy()
print("Cópia da lista:", arr_copy)  # [5, 4, 2, 1]

# 11. Limpando todos os itens da lista
arr.clear()
print("Depois de clear():", arr)  # []
