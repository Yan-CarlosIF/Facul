# Classe base 'Veiculo'
class Veiculo:
    def __init__(self, marca, modelo):
        self.marca = marca  # Atributo público
        self.modelo = modelo  # Atributo público

    def exibir_info(self):
        # Método para exibir informações do veículo
        print(f"Veículo: {self.marca} {self.modelo}")

# Classe 'Carro', que herda de 'Veiculo'
class Carro(Veiculo):
    def __init__(self, marca, modelo, ano):
        super().__init__(marca, modelo)  # Chama o construtor da classe pai
        self.__ano = ano  # Atributo privado (encapsulado)

    def exibir_detalhes(self):
        # Método que exibe detalhes do carro
        print(f"Carro: {self.marca} {self.modelo}, Ano: {self.__ano}")

    def atualizar_ano(self, novo_ano):
        # Método para alterar o ano do carro
        self.__ano = novo_ano

# Classe 'Moto', que também herda de 'Veiculo'
class Moto(Veiculo):
    def __init__(self, marca, modelo, cilindrada):
        super().__init__(marca, modelo)
        self.cilindrada = cilindrada

    def exibir_detalhes(self):
        # Método que exibe detalhes da moto
        print(f"Moto: {self.marca} {self.modelo}, Cilindrada: {self.cilindrada} cc")

# Função para demonstrar polimorfismo
def exibir_veiculo(veiculo):
    # Função que aceita qualquer objeto derivado de 'Veiculo'
    veiculo.exibir_detalhes()

# Classe 'Animal', base para demonstração de polimorfismo
class Animal:
    def emitir_som(self):
        # Método genérico que será sobrescrito nas subclasses
        pass

# Classe 'Cachorro', que herda de 'Animal'
class Cachorro(Animal):
    def emitir_som(self):
        print("O cachorro late")

# Classe 'Gato', que herda de 'Animal'
class Gato(Animal):
    def emitir_som(self):
        print("O gato mia")

# Função polimórfica para emitir o som de diferentes animais
def fazer_barulho(animal):
    animal.emitir_som()

# --- Testando o código ---

# Criando objetos da classe 'Carro'
carro1 = Carro("Toyota", "Corolla", 2020)
carro2 = Carro("Honda", "Civic", 2022)

# Criando objetos da classe 'Moto'
moto1 = Moto("Yamaha", "MT-07", 689)
moto2 = Moto("Honda", "CBR 500R", 500)

# Exibindo informações e detalhes dos veículos
carro1.exibir_info()  # Veículo: Toyota Corolla
carro1.exibir_detalhes()  # Carro: Toyota Corolla, Ano: 2020

# Atualizando o ano do carro
carro1.atualizar_ano(2021)
carro1.exibir_detalhes()  # Carro: Toyota Corolla, Ano: 2021

# Exibindo informações de outro carro
carro2.exibir_detalhes()  # Carro: Honda Civic, Ano: 2022

# Exibindo detalhes das motos
moto1.exibir_detalhes()  # Moto: Yamaha MT-07, Cilindrada: 689 cc
moto2.exibir_detalhes()  # Moto: Honda CBR 500R, Cilindrada: 500 cc

# Demonstrando polimorfismo com veículos
exibir_veiculo(carro1)  # Carro: Toyota Corolla, Ano: 2021
exibir_veiculo(moto1)  # Moto: Yamaha MT-07, Cilindrada: 689 cc

# Criando objetos de 'Cachorro' e 'Gato' e demonstrando polimorfismo
dog = Cachorro()
cat = Gato()

fazer_barulho(dog)  # Saída: O cachorro late
fazer_barulho(cat)  # Saída: O gato mia