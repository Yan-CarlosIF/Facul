n1 = float(input("Digite a primeira nota:\n"))
n2 = float(input("Digite a segunda nota:\n"))
n3 = float(input("Digite a terceira nota:\n"))
n4 = float(input("Digite a quarta nota:\n"))
p1 = 2 
p2 = 3
e1 = (n1 + n2) / 2
e2 = (n3 + n4) / 2
m = ((e1 * p1) + (e2 * p2)) / (p1 + p2)

if m >= 7:
    print("sua nota foi de ",m," e voce esta aprovado\n")
elif m < 3:
    print("sua nota foi de ",m," e voce esta reprovado\n")
else:
    print("sua nota foi de ",m," e voce ira fazer o Exame Final")
    nr = float(input("Digite a nota do exame final:\n"))
    mf = (m + nr) / 2
    if mf >= 5:
        print("sua nota foi de ",mf,"voce esta aprovado")
    else:
        print("sua nota foi de ",mf,"voce esta reprovado")

