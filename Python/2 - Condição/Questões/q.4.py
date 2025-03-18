preco = float(input("Digite o preco do produto:"))
vendaMediaMensal = int(input("Digite a venda media mensal desse produto:"))

if vendaMediaMensal < 500 or preco < 30:
    aumento = 0.1
    desconto = 0
elif vendaMediaMensal < 1200 or preco < 80:
    aumento = 0.2
    desconto = 0
else:
    aumento = 0
    desconto = 0.2

novoPreco = preco + (preco * aumento) - (preco * desconto)
print(f"\nO novo preco do produto é de: {novoPreco}")