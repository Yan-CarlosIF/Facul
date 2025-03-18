salario = float(input("Digite o salario:"))
opcao = int(input("Digite:\n1 - Imposto\n2 - Novo Salário\n3 - Classificação\n"))

match opcao:
    case 1:
        if salario < 500:
            percentual = 0.05
        elif salario <= 850:
            percentual = 0.1
        else:
            percentual = 0.15
        print(f"Valor do Imposto = {salario * percentual}")
    case 2:
        if salario > 1500:
            aumento = 25
        elif salario >= 750:
            aumento = 50
        elif salario >= 450:
            aumento = 75
        else:
            aumento = 100
        print(f"Novo Salario = {salario + aumento}")
    case 3:
        mensagem = "Estribado" if salario > 700 else "Liso"
        print(mensagem)
    case _:
        print("Opcao inválida!")