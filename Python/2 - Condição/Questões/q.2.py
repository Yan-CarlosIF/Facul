salario = float(input("Digite o salario do funcionario:"))

if salario <= 500:
    bonificao = 0.05
elif salario <= 1200:
    bonificao = 0.12
else:
    bonificao = 0

if salario <= 600:
    aumento = 150
else:
    aumento = 100

salarioNovo = salario + (salario * bonificao) + aumento
print(f"\nO novo salario é: {salarioNovo}")