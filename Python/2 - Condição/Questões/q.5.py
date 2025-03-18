while True: # Gambiarra de do-while
    codigoProd = int(input("Insira o codigo do produto (1 a 10):"))  
    if codigoProd >= 1 and codigoProd <= 10:
        break

peso = float(input("Digite o peso do produto em kg:"))

while True:
    codigoPais = int(input("Insira o codigo do pais (1 a 3):"))
    if codigoPais >= 1 and codigoPais <= 3:
        break

if codigoPais == 1:
    imposto = 0
elif codigoPais == 2:
    imposto = 0.15
else:
    imposto = 0.25

if codigoProd <= 4:
    precoGrama = 10
elif codigoPais <= 7:
    precoGrama = 25
else:
    precoGrama = 35

pesoGramas = peso * 1000
precoTotal = precoGrama * precoGrama
valorTotal = precoTotal - (precoTotal * imposto)
print(f"\nValor total do produto: {valorTotal}")