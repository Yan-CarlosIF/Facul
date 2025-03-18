# Fila - TypeScript

## Como usar uma fila em TypeScript

Da mesma forma da pilha, é possível usar uma fila em TypeScript, usando simplesmente arrays e as funções da propia linguagem, como push e shift, mas a forma que irei abordar aqui é usando arrays e classes.

## Implementando uma fila em TypeScript

Para implementar uma fila em TypeScript, precisaremos uma classe que represente a fila, que terá um array privado para armazenar os elementos da fila, usando generics para definir o tipo do array.

```typescript
class Fila<T> {
  private fila: T[] = [];

  enqueue(item: T): void {
    this.fila.push(item);
  }

  dequeue(): T | undefined {
    return this.fila.shift();
  }

  peek(): T | undefined {
    return this.fila[0];
  }

  isEmpty(): boolean {
    return this.fila.length === 0;
  }

  size(): number {
    return this.fila.length;
  }

  clear(): void {
    this.fila = [];
  }
}
```

## Usando a fila em TypeScript

Para usar uma fila em TypeScript, basta criar uma instância da classe Fila e chamar as funções da mesma, como enqueue, dequeue, peek, isEmpty, size e clear.

```typescript
const fila = new Fila<number>();

fila.enqueue(1); // [1]
fila.enqueue(2); // [1, 2]
fila.enqueue(3); // [1, 2, 3]

console.log(fila.dequeue()); // 1
console.log(fila.peek()); // 2
console.log(fila.isEmpty()); // false
console.log(fila.size()); // 2
fila.clear();
console.log(fila.isEmpty()); // true
```
