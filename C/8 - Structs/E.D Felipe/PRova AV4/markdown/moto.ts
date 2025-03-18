interface Moto {
  marca: string;
  modelo: string;
  cilindrada: number;
  exibirDetalhes(): void;
}

const moto1: Moto = {
  marca: "Yamaha",
  modelo: "MT-07",
  cilindrada: 689,

  exibirDetalhes(): void {
    console.log(
      `Moto: ${this.marca} - ${this.modelo}, Cilindrada: ${this.cilindrada} cc`
    );
  },
};

// Tambem podemos criar uma classe que implementa a interface
class classeMoto implements Moto {
  marca: string;
  modelo: string;
  cilindrada: number;

  constructor(marca: string, modelo: string, cilindrada: number) {
    this.marca = marca;
    this.modelo = modelo;
    this.cilindrada = cilindrada;
  }

  exibirDetalhes(): void {
    console.log(
      `Moto: ${this.marca} - ${this.modelo}, Cilindrada: ${this.cilindrada} cc`
    );
  }
}

const moto2: classeMoto = new classeMoto("Yamaha", "R15", 155);

moto1.exibirDetalhes(); // Moto: Yamaha - MT-07, Cilindrada: 689 cc
moto2.exibirDetalhes(); // Moto: Yamaha - R15, Cilindrada: 155 cc
