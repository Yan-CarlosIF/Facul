# Dicionários (dict): Coleções não ordenadas de pares chave-valor. As chaves devem ser únicas.

# Criando um Dicionário:

# Usando chaves
dicionario = {
    "nome": "Alice", 
    "idade": 30, 
    "cidade": "São Paulo"
}

# Usando a função dict()
dicionario2 = dict(nome="Bob", idade=25, cidade="Rio de Janeiro")

# Acessando e Modificando Valores:

# Acessando um valor
print(dicionario["nome"])  # Saída: Alice

# Modificando um valor
dicionario["idade"] = 31

# Adicionando um novo par chave-valor
dicionario["profissão"] = "Engenheira"

print(dicionario)  # Saída: {'nome': 'Alice', 'idade': 31, 'cidade': 'São Paulo', 'profissão': 'Engenheira'}

# Removendo Itens:

# Removendo um item com pop()
idade = dicionario.pop("idade")
print(idade)  # Saída: 31

# Removendo um item com del
del dicionario["cidade"]

print(dicionario)  # Saída: {'nome': 'Alice', 'profissão': 'Engenheira'}

# Aqui estão alguns métodos úteis para trabalhar com dicionários:

print(dicionario.keys()) # keys(): Retorna uma visualização das chaves do dicionário.
print(dicionario.values()) # values(): Retorna uma visualização dos valores do dicionário.
print(dicionario.items()) # items(): Retorna uma visualização dos pares chave-valor do dicionário.
profissao = dicionario.get("profissão") # get(chave): Retorna o valor associado à chave, ou None se a chave não existir.
print(profissao)  # Saída: Engenheira

# update(outro_dicionario): Atualiza o dicionário com pares chave-valor de outro dicionário ou de um iterable de pares.
dicionario.update({"idade": 31, "cidade": "São Paulo"}) 
print(dicionario)  # Saída: {'nome': 'Alice', 'profissão': 'Engenheira', 'idade': 31, 'cidade': 'São Paulo'}