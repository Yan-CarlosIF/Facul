# Questão 2: Função com Parâmetros
# Escreva uma função chamada area_retangulo que recebe dois parâmetros (largura e altura) e retorna a área de um retângulo. 
# Teste a função com largura 5 e altura 10.

def areaRetangulo(largura, altura):
    return largura * altura

area_retangulo = lambda largura, altura: largura * altura

print(f"Area do retangulo = {areaRetangulo(6, 4)}")
print(f"Area do retangulo lambda {area_retangulo(6, 4)}")