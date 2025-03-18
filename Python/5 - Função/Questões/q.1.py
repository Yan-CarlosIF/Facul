def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

def exibir_fibonacci(n):
    for i in range(n):
        print(fibonacci(i), end=" ")

n = 11
print(f"Os primeiros {n} números da sequência de Fibonacci são:")
exibir_fibonacci(n)