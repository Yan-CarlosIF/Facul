# Implemente uma função recursiva chamada fatorial que calcule o fatorial de um número n. 
# Lembre-se que o fatorial de 0 é 1, e para outros números, n! = n * (n-1)!.

def fatorial(numero):
    if numero == 0:
        return 1
    if numero == 1:
        return 1
    else:
        return numero * fatorial(numero - 1)

numero = int(input("Digite o numero que deseja saber o fatorial: "))
print(f"\nFatorial de {numero} = {fatorial(numero)}")