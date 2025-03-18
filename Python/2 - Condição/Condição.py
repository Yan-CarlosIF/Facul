# Definindo uma variável de idade
idade = 20

# 1. Usando if para verificar se a pessoa é maior de idade
if idade >= 18:
    print("Você é maior de idade.")  # Este bloco será executado se a condição for verdadeira

# 2. Usando if...else para verificar se a pessoa é maior ou menor de idade
idade = 16

if idade >= 18:
    print("Você é maior de idade.")
else:
    print("Você é menor de idade.")  # Este bloco será executado se a condição for falsa

# 3. Usando elif para classificar a nota
nota = 85

if nota >= 90:
    print("Excelente")  # Este bloco será executado se a nota for maior ou igual a 90
elif nota >= 75:
    print("Bom")  # Este bloco será executado se a nota for entre 75 e 89
else:
    print("Precisa melhorar")  # Este bloco será executado se a nota for menor que 75

# 4. Usando o operador ternário para atribuir uma mensagem com base na idade
idade = 20                            
mensagem = "Você é maior de idade." if idade >= 18 else "Você é menor de idade."

print(mensagem)  # Saída: Você é maior de idade.

# 5. Usando match para identificar o dia da semana com base em um número
dia = 3

match dia:
    case 1:
        print("Domingo")
    case 2:
        print("Segunda-feira")
    case 3:
        print("Terça-feira")
    case 4:
        print("Quarta-feira")
    case 5:
        print("Quinta-feira")
    case 6:
        print("Sexta-feira")
    case 7:
        print("Sábado")
    case _:
        print("Dia inválido")  # Este bloco será executado se nenhum dos casos anteriores for correspondido