# Classe para instanciar os componentes
class Componente:
    def __init__(self, nome, preco):
        self.nome = nome
        self.preco = preco

# Instanciando os componentes e seus respectivos valores em uma lista
componentes = [
    Componente("Tela", 100),
    Componente("Câmera", 50),
    Componente("GPS", 10),
    Componente("Som", 10),
    Componente("Microfone", 5),
    Componente("Sensor de Impressão Digital", 15),
    Componente("Sensor Giroscópio", 5),
    Componente("Sensor Acelerômetro", 3),
    Componente("Sensor de Luz Ambiente", 2),
    Componente("5G", 30),
    Componente("4G", 15),
    Componente("Wi-Fi", 5),
    Componente("Bluetooth", 2),
    Componente("NFC", 2)
]

# Classe para instanciar o celular
class Celular:
    # Construtor iniciando o celular com uma lista vazia de componentes
    def __init__(self):
        self.componentes = []

    # Método para adicionar componentes
    def adicionar_componente(self, componente):
        self.componentes.append(componente)

    # Método para calcular o preço total em dólares
    def calcular_preco_total(self):
        return sum(componente.preco for componente in self.componentes)

    # Método para calcular o preço em reais
    def calcular_preco_em_reais(self):
        return self.calcular_preco_total() * 6 # 6 reais = 1 dolar

    # Método para mostrar detalhes do celular
    def mostrar_detalhes(self):
        print("\nDetalhes do Celular:")
        for componente in self.componentes:
            print(f"- {componente.nome}: ${componente.preco:.2f}")
        print(f"\nPreço final em dólares: ${self.calcular_preco_total():.2f}")
        print(f"Preço final em reais: R${self.calcular_preco_em_reais():.2f}\n")

# criação do celular
celular = Celular()

# Escolhas de componentes
while len(componentes) > 0:
    for i, componente in enumerate(componentes):
        print(f"({i + 1}) {componente.nome} - ${componente.preco:.2f}")
    
    escolha = int(input("Digite o número do componente que deseja adicionar (ou 0 para parar): "))
    if escolha == 0:
        print("Programa encerrado!")
        break
    elif escolha > 0 and escolha <= len(componentes):
        componente_selecionado = componentes.pop(escolha - 1) # Remove o componente escolhido da lista
        celular.adicionar_componente(componente_selecionado) # Adiciona o componente escolhido ao celular
        print(f"Componente {componente_selecionado.nome} adicionado com sucesso!\n")
    else:
        print(f"Escolha inválida!")

if len(componentes) == 0:
    print("Todos os componentes foram escolhidos!")

# Mostrar detalhes
celular.mostrar_detalhes()

# Justificativa da escolha
justificativa = """
Decidi fazer um codigo em python por que é mais prático que C, e para que o usuario conseguisse 
selecionar os componentes que ele quisesse no celular usando o terminal, decidi não fazer em JavaScript
por que ele teria que rodar em um navegador, e estava meio sem tempo pra estilizar com CSS e fazer algo bem feito kkkkk
"""
print(f"Justificativa:\n{justificativa}")