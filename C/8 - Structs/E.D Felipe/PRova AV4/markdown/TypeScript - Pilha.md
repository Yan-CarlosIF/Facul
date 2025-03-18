# Pilha - TypeScript

## Como usar uma pilha em TypeScript

Para usarmos uma pilha em TypeScript, podemos criá-la de varias formas diferentes, usando simplesmente arrays e as funções da própria linguagem, como push e pop, mas a forma que irei abordar aqui é usando arrays e classes.

## Implementando uma pilha em TypeScript

Para implementar uma pilha em TypeScript, precisaremos uma classe que represente a pilha, que terá um array privado para armazenar os elementos da pilha, usando generics para definir o tipo do array.

```typescript
class Pilha<T> {
  private pilha: T[] = [];

  push(item: T): void {
    this.pilha.push(item);
  }

  pop(): T | undefined {
    return this.pilha.pop();
  }

  peek(): T | undefined {
    return this.pilha[this.pilha.length - 1];
  }

  isEmpty(): boolean {
    return this.pilha.length === 0;
  }

  size(): number {
    return this.pilha.length;
  }

  clear(): void {
    this.pilha = [];
  }
}
```

#

## Usando a pilha em TypeScript

```typescript
const pilha = new Pilha<number>();

pilha.push(1); // [1]
pilha.push(2); // [1, 2]
pilha.push(3); // [1, 2, 3]

console.log(pilha.pop()); // Output: 3
console.log(pilha.peek()); // Output: 2
console.log(pilha.isEmpty()); // Output: false
console.log(pilha.size()); // Output: 2
pilha.clear(); // Limpa a pilha
console.log(pilha.isEmpty()); // Output: true
```
