# Exemplo de função básica com parâmetros e retorno
def soma(a, b):
    # Retorna a soma de dois números
    return a + b

# Exemplo de função sem retorno, apenas com uma ação
def saudacao(nome="Visitante"):
    # Imprime uma mensagem de saudação
    print(f"Bem-vindo, {nome}!")

# Exemplo de função com número variável de argumentos (*args)
def somar_todos(*numeros):
    # Soma todos os números passados como argumento
    return sum(numeros)

# Exemplo de função com argumentos nomeados variáveis (**kwargs)
def informacoes(**dados):
    # Imprime informações fornecidas como pares chave-valor
    for chave, valor in dados.items():
        print(f"{chave}: {valor}")

# Exemplo de função aninhada
def externa():
    # Função que contém outra função dentro dela
    print("Função externa.")

    def interna():
        print("Função interna.")
    
    interna()  # Chama a função interna

# Exemplo de função lambda (anônima)
multiplicar = lambda a, b: a * b

# Testando as funções

# Função com retorno
resultado_soma = soma(5, 10)
print(f"Soma de 5 e 10: {resultado_soma}")  # Saída: 15

# Função sem retorno
saudacao("Carlos")  # Saída: Bem-vindo, Carlos!
saudacao()  # Saída: Bem-vindo, Visitante!

# Função com número variável de argumentos
resultado_somar_todos = somar_todos(1, 2, 3, 4, 5)
print(f"Soma de todos os números: {resultado_somar_todos}")  # Saída: 15

# Função com argumentos nomeados variáveis
informacoes(nome="Carlos", idade=30, cidade="São Paulo")

# Função aninhada
externa()

# Função lambda
resultado_multiplicacao = multiplicar(3, 4)
print(f"Multiplicação de 3 e 4: {resultado_multiplicacao}")  # Saída: 12