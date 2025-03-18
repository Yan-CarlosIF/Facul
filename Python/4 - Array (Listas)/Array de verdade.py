# Em Python, a estrutura de array pode ser usada de diferentes maneiras sem recorrer diretamente à lista. 
# Uma forma popular é usando o módulo array, que oferece suporte a arrays eficientes e de tamanho fixo. 
# Esses arrays contêm elementos do mesmo tipo e são mais leves em comparação com as listas para certos casos.

import array

# Criando um array de inteiros (tipo 'i' para inteiros)
# Tipos comuns de dados no módulo array:
# 'i' para inteiros com sinal.
# 'f' para números de ponto flutuante.
# 'd' para ponto flutuante de precisão dupla.
meu_array = array.array('i', [1, 2, 3, 4, 5])

# Exibindo o array
print(meu_array)

# Acessando elementos
print(meu_array[2])  # Saída: 3

# Modificando um elemento
meu_array[1] = 10

# Adicionando um elemento ao final do array
meu_array.append(6)

# Exibindo o array modificado
print(meu_array)