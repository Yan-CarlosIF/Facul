#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
O arquivo anexo contem os registros simplificados de 1 milhão de ligações telefônicas. O seu programa deve processar o arquivo e informar:
A ligação telefônica mais antiga (Quem ligou para quem, em que data e horário)?
Quem originou mais ligações?
Quem recebeu mais ligações?
Considerando como 80 centavos o minuto de ligação, qual a conta telefônica de cada originador de ligações?

Formato do texto do arquivo:
***
Origem: Jalia Magalhaes
Data: 19-03-2024	Hora: 14:30:01
Duracao: 5 minutos
Destino: Elieno Gilbos
****
*/

#define CUSTO_LIGACAO 0.8

typedef struct {
    char origem[50];
    char destino[50];
    char data[11];    // Formato: DD-MM-YYYY
    char hora[9];     // Formato: HH:MM:SS
    int duracao;      // Duração em minutos
} Ligacao;

typedef struct Contagem {
    char nome[50];
    int num_ligacoes;
    float conta_telefonica;
    struct Contagem *next;
} Contagem;

bool compararDataHora(const char *dataAtual, const char *horaAtual, const char *dataAntiga, const char *HoraAntiga);
void atualizarContagem(Contagem **lista, const char *nome, int duracao, bool originou);
Contagem* OriginouRecebeuMais(Contagem **lista);
void freeLista(Contagem **lista);

int main() {
    FILE *file = fopen("banco.txt", "r");
    
    Ligacao atual, mais_antiga;
    Contagem *listaOriginou = NULL, *listaRecebeu = NULL;
    int cont = 0;

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(file, "***\nOrigem: %49[^\n]\nData: %10[^\n]\tHora: %8[^\n]\nDuracao: %d minutos\nDestino: %49[^\n]\n****\n",
           atual.origem, atual.data, atual.hora, &atual.duracao, atual.destino) == 5) {

        if (cont == 0 || compararDataHora(atual.data, atual.hora, mais_antiga.data, mais_antiga.hora)) {
            mais_antiga = atual;
        }

        atualizarContagem(&listaOriginou, atual.origem, atual.duracao, true);
        atualizarContagem(&listaRecebeu, atual.destino, 0, false);
        
        cont++;
    } 


    printf("Ligacao mais antiga:\nOrigem: %s\nData: %s\tHora: %s\nDuracao: %d minutos\nDestino: %s\n\n",
    mais_antiga.origem, mais_antiga.data, mais_antiga.hora, mais_antiga.duracao, mais_antiga.destino);

    Contagem *maisLigacoesOriginadas = OriginouRecebeuMais(&listaOriginou);
    printf("\nQuem mais Originou ligacoes foi:\nNome: %s\nNumero de ligacoes: %d\n", maisLigacoesOriginadas->nome, maisLigacoesOriginadas->num_ligacoes);

    Contagem *maisLigacoesRecebidas = OriginouRecebeuMais(&listaRecebeu);
    printf("\nQuem mais Recebeu ligacoes foi:\nNome: %s\nNumero de ligacoes: %d\n", maisLigacoesRecebidas->nome, maisLigacoesRecebidas->num_ligacoes);

    printf("\nLista Originou:\n");
    Contagem *temp = listaOriginou;
    cont = 1;

    while (temp != NULL) {  
        
        printf("\n%d Pessoa:\nNome: %s\nNum ligacoes: %d\nconta: %.2f\n", cont, temp->nome, temp->num_ligacoes, temp->conta_telefonica);
        temp = temp->next;
        cont++;
    }     

    freeLista(&listaOriginou);
    freeLista(&listaRecebeu);
    free(maisLigacoesOriginadas);
    free(maisLigacoesRecebidas);
    fclose(file);
    return 0;
}

bool compararDataHora(const char *dataAtual, const char *horaAtual, const char *dataAntiga, const char *HoraAntiga) {
    if ((strcmp(dataAtual, dataAntiga) < 0) || (strcmp(dataAtual, dataAntiga) == 0 && strcmp(horaAtual, HoraAntiga) < 0)) {
        return true;
    }
    return false;
}

void atualizarContagem(Contagem **lista, const char *nome, int duracao, bool originou) {
    Contagem *temp = *lista;

    while (temp != NULL && strcmp(temp->nome, nome) != 0) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        Contagem *novaPessoa = (Contagem*)malloc(sizeof(Contagem));
        strcpy(novaPessoa->nome, nome);
        novaPessoa->num_ligacoes = 1;
        novaPessoa->conta_telefonica = originou ? duracao * CUSTO_LIGACAO : 0;
        novaPessoa->next = *lista;
        *lista = novaPessoa;
    } else {
        temp->num_ligacoes++;
        if (originou) {
            temp->conta_telefonica += duracao * CUSTO_LIGACAO;
        }
    }
}

Contagem* OriginouRecebeuMais(Contagem **lista) {    
    Contagem *temp = *lista, *Maior = temp;
    
    while (temp != NULL) {
        if (Maior->num_ligacoes < temp->num_ligacoes) {
            Maior = temp;
        }

        temp = temp->next;
    }
    
    return Maior;
}

void freeLista(Contagem **lista) {
    Contagem *temp;
    while (*lista != NULL) {
        temp = *lista;
        *lista = (*lista)->next;
        free(temp);
    }
}