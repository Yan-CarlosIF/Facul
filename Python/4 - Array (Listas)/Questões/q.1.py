NOTAS = 2
ALUNOS = 6
notaAlunos = [[0 for _ in range(NOTAS)] for _ in range(ALUNOS)]
medias = [0 for _ in range(ALUNOS)]
contAprov = 0
contExam = 0
contRepro = 0
mediaClasse = 0

for i in range(ALUNOS):
    for j in range(NOTAS):
        notaAlunos[i][j] = float(input(f"Digite a {j + 1}° nota do {i + 1}° aluno:"))
        medias[i] += notaAlunos[i][j]
    medias[i] /= NOTAS

i = 0
for notas in medias:
    if notas < 3:
        mensagem = "Reprovado"
        contRepro += 1
    elif notas < 7:
        mensagem = "Exame"
        contExam += 1
    else:
        mensagem = "Aprovado"
        contAprov += 1
    print(f"Aluno {i + 1}°, Media = {notas}, Aluno está {mensagem}")
    mediaClasse += notas
    i += 1

print(f"Quantidade de alunos Aprovados: {contAprov}")
print(f"Quantidade de alunos no Exame: {contExam}")
print(f"Quantidade de alunos Reprovados: {contRepro}")
print(f"\nMedia da classe: {mediaClasse / ALUNOS}")