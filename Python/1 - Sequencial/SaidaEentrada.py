# Entrada de dados:
professor = input("Digite o nome do prof:")
horasDaAula = int(input("Digite quantas horas o curso tem:"))
stringConcatenada = f"O professor {professor} dará aula de python, e seu curso terá {horasDaAula} horas." # Usando F-strings
# OU                         # Transforma Variavel em String
#stringConcatenada = "O professor " + str(professor) + " dará aula de python, e seu curso terá " + str(horasDaAula) + " horas."
# OU 
# stringConcatenada = "O professor {}".format(professor) + " dará aula de python, e seu curso terá {}".format(horasDaAula) + " horas."

# Saída de dados:
print(stringConcatenada)
print(f"{professor} da aulas as {horasDaAula}")