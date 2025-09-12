#include <stdio.h>
#define PRODUCTS 10
#define WAREHOUSES 5

// Crie um programa que:
// ■ receba o preço de dez produtos e armazene-os em um vetor;
// ■ receba a quantidade estocada de cada um desses produtos, em cinco armazéns
// diferentes, utilizando uma matriz 5  10. O programa deverá calcular e
// mostrar: ■ a quantidade de produtos estocados em cada um dos armazéns; ■ a
// quantidade de cada um dos produtos estocados, em todos os armazéns juntos; ■
// o preço do produto que possui maior estoque em um único armazém; ■ o menor
// estoque armazenado; ■ o custo de cada armazém.

int main() {
  float productsPrice[PRODUCTS];
  int stockQuantities[WAREHOUSES][PRODUCTS];

  for (int i = 0; i < PRODUCTS; i++) {
    printf("Insira o preço do %d° produto: ", i + 1);
    scanf("%f", &productsPrice[i]);
  }

  for (int i = 0; i < WAREHOUSES; i++) {
    for (int j = 0; j < PRODUCTS; j++) {
      printf("Insira a quantidade estocada do %d° produto no %d° armazem: ",
             j + 1, i + 1);
      scanf("%d", &stockQuantities[i][j]);
    }
  }

  int stockQuantityInWarehouse[WAREHOUSES] = {0};
  int stockQuantityPerProduct[PRODUCTS] = {0};
  float productPriceFromGreatestStock = productsPrice[0];
  int greatestStock = stockQuantities[0][0];
  int warehouseWithGreatestStock = 1;
  int minorStock = stockQuantities[0][0];
  float warehouseCusts[WAREHOUSES] = {0};

  for (int i = 0; i < WAREHOUSES; i++) {
    for (int j = 0; j < PRODUCTS; j++) {
      warehouseCusts[i] += (productsPrice[j] * stockQuantities[i][j]);
      stockQuantityInWarehouse[i] += stockQuantities[i][j];
      stockQuantityPerProduct[j] += stockQuantities[i][j];

      if (greatestStock < stockQuantities[i][j]) {
        warehouseWithGreatestStock = i + 1;
        greatestStock = stockQuantities[i][j];
        productPriceFromGreatestStock = productsPrice[j];
      }

      if (minorStock > stockQuantities[i][j]) {
        minorStock = stockQuantities[i][j];
      }
    }
  }

  for (int i = 0; i < WAREHOUSES; i++) {
    printf("Quantidade de produtos estocados no armazem %d: %d\n", i + 1,
           stockQuantityInWarehouse[i]);
  }

  for (int i = 0; i < PRODUCTS; i++) {
    printf("Quantidade do produto %d em todos os armazens: %d\n", i + 1,
           stockQuantityPerProduct[i]);
  }

  printf("Preço do produto com mais estoque de %d no armazem %d: %.2f\n",
         greatestStock, warehouseWithGreatestStock,
         productPriceFromGreatestStock);

  printf("Menor quantidade de produtos em um armazem: %d\n", minorStock);

  for (int i = 0; i < WAREHOUSES; i++) {
    printf("Custo total do armazem %d: %.2f\n", i + 1, warehouseCusts[i]);
  }
  return 0;
}