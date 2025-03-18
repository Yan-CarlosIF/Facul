#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096  // Cada página tem 4KB
#define NUM_PAGES 5     // Número de páginas virtuais
#define NUM_FRAMES 8    // Número de quadros físicos

// Estrutura da Tabela de Páginas
typedef struct {
  int frame_number;  // Número do quadro físico (-1 se não estiver na RAM)
  int present;  // Bit de presença (1 = na RAM, 0 = precisa carregar do disco)
} PageTableEntry;

// Inicializa a Page Table
void initializePageTable(PageTableEntry *pageTable) {
  for (int i = 0; i < NUM_PAGES; i++) {
    pageTable[i].frame_number = -1;  // Nenhuma página carregada no início
    pageTable[i].present = 0;
  }

  // Simulando algumas páginas carregadas na RAM
  pageTable[0].frame_number = 3;
  pageTable[0].present = 1;
  pageTable[1].frame_number = 7;
  pageTable[1].present = 1;
  pageTable[3].frame_number = 5;
  pageTable[3].present = 1;
  pageTable[4].frame_number = 2;
  pageTable[4].present = 1;
}

// Traduz um endereço virtual para físico
void translateAddress(PageTableEntry *pageTable, int virtual_address) {
  int page_number = virtual_address / PAGE_SIZE;  // Obtém o número da página
  int offset =
      virtual_address % PAGE_SIZE;  // Obtém o deslocamento dentro da página

  if (page_number >= NUM_PAGES) {
    printf("Erro: Endereço virtual inválido!\n");
    return;
  }

  // Verifica se a página está carregada na RAM
  if (pageTable[page_number].present) {
    int frame_number = pageTable[page_number].frame_number;
    int physical_address = (frame_number * PAGE_SIZE) + offset;
    printf(
        "Endereço Virtual: 0x%X -> Endereço Físico: 0x%X (Página %d -> Quadro "
        "%d)\n",
        virtual_address, physical_address, page_number, frame_number);
  } else {
    printf("Page Fault! A página %d não está na RAM.\n", page_number);
  }
}

int main() {
  PageTableEntry pageTable[NUM_PAGES];
  initializePageTable(pageTable);

  // Simulando alguns acessos a endereços virtuais
  int test_addresses[] = {0x00004567, 0x0000A234, 0x0000F100, 0x00013000};
  int num_tests = sizeof(test_addresses) / sizeof(test_addresses[0]);

  for (int i = 0; i < num_tests; i++) {
    translateAddress(pageTable, test_addresses[i]);
  }

  return 0;
}
