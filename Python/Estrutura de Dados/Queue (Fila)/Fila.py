# Pode ser implementada com a classe deque do módulo collections para um desempenho eficiente.
from collections import deque

# Criando uma fila
fila = deque()

# Enfileirando (enqueue)
fila.append("A")
fila.append("B")
fila.append("C")

# Desenfileirando (dequeue)
primeiro = fila.popleft()  # Remove e retorna o primeiro elemento: "A"

# Exibindo a fila
print(fila)  # deque(['B', 'C'])
