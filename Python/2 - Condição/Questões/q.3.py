salarioMinimo = float(input("Digite o valor do salario minimo:"))
horasTrabalhadas = float(input("Insira as horas trabalhadas:"))
dependentes = int(input("Insira o numero de dependentes:"))
horasExtras = float(input("Insira quantas horas extras foram feitas:"))
valorHoraTrabalhada = salarioMinimo / 5
salarioBruto = (valorHoraTrabalhada * horasTrabalhadas) + (dependentes * 32) + ((valorHoraTrabalhada / 2 + valorHoraTrabalhada) * horasExtras)
print(f"\nSalario Bruto: {salarioBruto}")

if salarioBruto < 200:
    impostoDeRenda = 0
elif salarioBruto <= 500:
    impostoDeRenda = 0.1
else:
    impostoDeRenda = 0.2

salarioLiquido = salarioBruto - (salarioBruto * impostoDeRenda)

if salarioLiquido <= 350:
    gratificacao = 100
else: 
    gratificacao = 50

salarioLiquido += gratificacao
print(f"\nSalario que o funcionario irá receber: {salarioLiquido}")