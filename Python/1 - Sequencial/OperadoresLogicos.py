# Definindo algumas variáveis booleanas
a = True
b = False
c = True

# Usando o operador 'and' and == &&
resultado_and = a and b
print(f"Resultado de 'a and b': {resultado_and}")  # False

# Usando o operador 'or' or == ||
resultado_or = a or b
print(f"Resultado de 'a or b': {resultado_or}")  # True

# Usando o operador 'not' not == !
resultado_not = not a
print(f"Resultado de 'not a': {resultado_not}")  # False

# Combinando os operadores
resultado_comb = (a and b) or (not c)
print(f"Resultado de '(a and b) or (not c)': {resultado_comb}")  # False

# Outro exemplo de combinação
resultado_comb2 = not (a or b) and c
print(f"Resultado de 'not (a or b) and c': {resultado_comb2}")  # False
