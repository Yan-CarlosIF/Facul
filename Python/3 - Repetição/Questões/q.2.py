CIDADES = 2
codigos = []
veiculosNum = []
acidentesNum = []
media = 0
contCidades2000 = 0
mediaAcidentes = 0

for i in range(CIDADES):
    codigos.append(int(input(f"Digite o codigo da {i + 1}° cidade:")))
    veiculosNum.append(int(input(f"Digite a quantidade de veiculos na {i + 1}° cidade:")))
    acidentesNum.append(int(input(f"Digite o numero de acidentes na {i + 1}° cidade:")))
    media += veiculosNum[i]

    if i == 0:
        maior = acidentesNum[0]
        menor = acidentesNum[0]
        maiorCidade = codigos[0]
        menorCidade = codigos[0]
    else:
        if maior < acidentesNum[i]:
            maior = acidentesNum[i]
            maiorCidade = codigos[i]
        if menor > acidentesNum[i]:
            menor = acidentesNum[i]
            menorCidade = codigos[i]

    if veiculosNum[i] < 2000:
        mediaAcidentes += acidentesNum[i]
        contCidades2000 += 1

print("\nRelatórios:\n")
print(f"O maior indice de acidentes foi na cidade {maiorCidade} com: {maior}\nO maior indice de acidentes foi na cidade {menorCidade} com: {menor}")
print(f"A media de veiculos nas {CIDADES} juntas foi de: {media / CIDADES}")
print(f"A media de acidentes nas cidades com menos de 2000 veiculos: {mediaAcidentes / contCidades2000}")