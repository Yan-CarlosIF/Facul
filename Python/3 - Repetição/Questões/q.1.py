salario = 1000
percentual = 0.015
for ano in range(2006, 2025):
    salario = salario + (salario * percentual)
    percentual *= 2
    print(f"Salario do chapa no ano {ano}: {salario}")