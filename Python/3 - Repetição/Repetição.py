# Estrutura de Repetição com `for`

# Iterando sobre uma lista
frutas = ["maçã", "banana", "laranja"]
print("Iterando sobre uma lista:")
for fruta in frutas:
    print(fruta)

# Iterando usando `range()`
print("\nIterando usando `range()`:")
for i in range(5):  # Gera números de 0 a 4
    print(i)

# Iterando sobre um dicionário (parecido com Objeto)
pessoa = {"nome": "João", "idade": 25}
print("\nIterando sobre um dicionário (chaves ou Objeto):")
for chave in pessoa:
    print(chave, pessoa[chave])

print("\nIterando sobre um dicionário (chave e valor):")
for chave, valor in pessoa.items():
    print(chave, valor)

# Estrutura de Repetição com `while`

# Usando `while` para contar de 0 a 4
contador = 0
print("\nUsando `while` para contar de 0 a 4:")
while contador < 5:
    print(contador)
    contador += 1

# Usando `while True` com `break` para repetir até condição
print("\nUsando `while True` com `break`: ")
while True:
    entrada = input("Digite 'sair' para encerrar: ")
    if entrada.lower() == 'sair':
        print("Encerrando o loop.")
        break
    else:
        print("Você digitou:", entrada)

# Usando `else` em loops

# `else` após `for`
print("\n`else` após `for`:")
for i in range(3):
    print(i)
else:
    print("Loop `for` terminado.")

# `else` após `while`
print("\n`else` após `while`:")
contador = 0
while contador < 3:
    print(contador)
    contador += 1
else:
    print("Loop `while` terminado.")

# Compreensão de Lista (List Comprehension)
print("\nCompreensão de Lista (List Comprehension):")
quadrados = [x ** 2 for x in range(10)]
print(quadrados)
