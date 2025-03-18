# Lista - TypeScript

## Como funcionam Listas em TypeScript?

No TypeScript, as listas são representadas por arrays, que permitem armazenar múltiplos valores do mesmo tipo. Além disso, podemos utilizar tuplas, que permitem listas com tipos diferentes para cada posição.

### Como criar uma lista em TypeScript?

Para criar uma lista em TypeScript, podemos utilizar o array literal, ou o construtor Array.

```typescript
const numeros: number[] = [1, 2, 3, 4, 5];
// podemos criar uma lista com mais de um tipo de dado
const numString: (number | string)[] = [1, "Yan", 2, "Artur", 3, "Marquin"];
const nomes: Array<string> = ["Yan", "Artur", "Marquin"];
```

### Como acessar elementos de uma lista em TypeScript?

Para acessar elementos de uma lista em TypeScript, podemos utilizar o operador de colchetes.

```typescript
const numeros: number[] = [1, 2, 3];

console.log(numeros[0]); // 1
console.log(numeros[1]); // 2
console.log(numeros[2]); // 3
```

### Tuplas em TypeScript

As tuplas são um tipo especial de lista em TypeScript que permite armazenar diferentes tipos de dados em uma ordem específica.

```typescript
const tupla: [number, string] = [1, "Yan"];
console.log(tupla[0]); // 1
console.log(tupla[1]); // "Yan"

tupla.push("Artur", 2); // Causa um erro por estar em ordem diferente
```

#

## Metodos para trabalhar com listas em TypeScript

```typescript
let alunos: string[] = ["Clara", "Gustavo", "Davi"];

// Adicionar um elemento ao final da lista
alunos.push("Yan");

// Remover o ultimo elemento da lista
const alunoRemovido = alunos.pop();

// Remover ou Adicionar um elemento em uma posição desejada da lista
alunos.splice(1, 0, "Artur");
alunos.splice(1, 1);

// Inverter a ordem dos elementos da lista
alunos.reverse();

// Ordenar os elementos da lista
alunos.sort();

// Buscar um elemento na lista
const alunoEncontrado = alunos.find((aluno) => aluno === "Yan");

// Buscar o indice de um elemento na lista
const indicesAluno = alunos.indexOf("Yan");

// Verificar se um elemento existe na lista
const alunoExiste = alunos.includes("Yan");

// Adicionar um elemento ao inicio da lista
alunos.unshift("Yan");

// Remover o primeiro elemento da lista
alunos.shift();

// interar sobre os elementos da lista
alunos.forEach((aluno) => console.log(aluno));
```

### Existem mais metodos que podem ser utilizados para trabalhar com listas em TypeScript, vai da sua curiosidade e vontade de aprender mais!
