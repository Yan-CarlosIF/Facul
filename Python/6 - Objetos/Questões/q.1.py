class Publicacao:
    def __init__(self, titulo, autor):
        self.titulo = titulo
        self.autor = autor
    
    def exibirDetalhes(self):
        print(f"\nLivro\nTítulo: {self.titulo}\nAutor: {self.autor}")
    
class Livro(Publicacao):
    def __init__(self, titulo, autor, numPaginas):
        super().__init__(titulo, autor)
        self.numPaginas = numPaginas

    def exibirDetalhes(self):
        super().exibirDetalhes()
        print(f"Numero de Paginas: {self.numPaginas}")


class Resvista(Publicacao):
    def __init__(self, titulo, autor, edicao):
        super().__init__(titulo, autor)
        self.edicao = edicao

    def exibirDetalhes(self):
        super().exibirDetalhes()
        print(f"Edição da revista: {self.edicao}")

livro1 = Livro("O Senhor dos Anéis", "J.R.R. Tolkien", 1178)
revista1 = Resvista("National Geographic", "Diversos", "Meuzovo")

livro1.exibirDetalhes()
revista1.exibirDetalhes()