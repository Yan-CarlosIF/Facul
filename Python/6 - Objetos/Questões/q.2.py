class Veiculo:
    def __init__(self, marca, modelo, ano, quilometragem):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
        self.quilometragem = quilometragem
    
    def calcularCustoManutencao(self):
        pass
    
class Carro(Veiculo):
    def __init__(self, marca, modelo, ano, quilometragem, numPortas):
        super().__init__(marca, modelo, ano, quilometragem)
        self.numPortas = numPortas

    def calcularCustoManutencao(self):
        custo = 500 + (0.5 * self.quilometragem)
        return custo

class Caminhao(Veiculo):
    def __init__(self, marca, modelo, ano, quilometragem, carga):
        super().__init__(marca, modelo, ano, quilometragem)
        self.carga = carga

    def calcularCustoManutencao(self):
        custo = 1000 + (1 * self.quilometragem) if 2024 - self.ano <= 10 else 2000 + 1000 + (1 * self.quilometragem)
        return custo

class Onibus(Veiculo):
    def __init__(self, marca, modelo, ano, quilometragem, numAssentos):
        super().__init__(marca, modelo, ano, quilometragem)
        self.numAssentos = numAssentos

    def calcularCustoManutencao(self):
        custo = 800 + (0.8 * self.quilometragem) if self.numAssentos > 30 else 1500 + 800 + (0.8 * self.quilometragem)
        return custo

class Frota:
    def __init__(self):
        self.frota = []

    def addVeiculo(self, veiculo):
        if isinstance(veiculo, (Carro, Caminhao, Onibus)):
            self.frota.append(veiculo)
            print("Veículo adicionado com sucesso!")
        else:
            print("Veículo não foi adicionado com exito...")


    def exibirVeiculos(self):
        for veiculo in self.frota:
            print(f"\nVeiculo: {type(veiculo).__name__}\nMarca: {veiculo.marca}\nModelo: {veiculo.modelo}\nAno: {veiculo.ano}\nQuilometragem: {veiculo.quilometragem}")


    def custoManutencaoTotal(self):
        custo = 0
        for veiculo in self.frota:
            custo += veiculo.calcularCustoManutencao()
        print(f"Custo de Manutenção da frota = {custo}R$")

honda = Carro("honda", "Civic", 2012, 5000, 4)
caminhao = Caminhao("Mercedes", "sla", 2012, 1, 200)
buzao = Onibus("Mercedes", "Busao", 2010, 10000, 30)

frotaDeVeiculos = Frota()
frotaDeVeiculos.addVeiculo(honda)
frotaDeVeiculos.addVeiculo(caminhao)
frotaDeVeiculos.addVeiculo(buzao)
frotaDeVeiculos.exibirVeiculos()
frotaDeVeiculos.custoManutencaoTotal()