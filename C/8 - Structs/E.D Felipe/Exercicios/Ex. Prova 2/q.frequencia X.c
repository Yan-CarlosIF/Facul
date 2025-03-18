#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Freq {
    char letra;
    int freq;
    struct Freq *next;
} Freq;

typedef struct {
    Freq *head;
    Freq *tail;
    int size;
} FreqQueue;

FreqQueue* init() {
    FreqQueue *fq = (FreqQueue*)malloc(sizeof(FreqQueue));
    
    fq->head = NULL;
    fq->tail = NULL;
    fq->size = 0;

    return fq;
}

void freeQueue(FreqQueue *fq) {
    if (fq->size <= 0) return;

    Freq *temp = fq->head;

    while (temp != NULL) {
        Freq *dequeuedItem = temp;
        temp = temp->next;
        free(dequeuedItem);
    }

    fq->head = NULL;
    fq->tail = NULL;
    fq->size = 0;
}

void addLetra(FreqQueue *fq, char letra) {
    Freq *temp = fq->head;

    while (temp != NULL) {
        if (temp->letra == letra) {
            temp->freq++;
            return;
        }

        temp = temp->next;
    }

    Freq *newChar = (Freq*)malloc(sizeof(Freq));
    newChar->letra = letra;
    newChar->freq = 1;
    newChar->next = NULL;

    if (fq->size == 0) {
        fq->head = newChar;
        fq->tail = newChar;
    } else if (fq->head->letra < newChar->letra) {
        newChar->next = fq->head;
        fq->head = newChar;
    } else {
        Freq *newTemp = fq->head;

        while (newTemp->next != NULL && newTemp->next->freq >= newChar->freq) 
            newTemp = newTemp->next;

        newChar->next = newTemp->next;
        newTemp->next = newChar;

        if (newChar->next == NULL) {
            fq->tail = newChar;
        }
    }

    fq->size++;
}

void frequencia(FreqQueue *fq, char *str) {
    int size = strlen(str);
    
    for (int i = 0; i < size; i++) {
        addLetra(fq, str[i]);
    }


    
    Freq *temp = fq->head;
    
    while (temp != NULL) {
        printf("%d %d\n", temp->letra, temp->freq);
        temp = temp->next;
    }
    printf("\n");

    freeQueue(fq);
}  

int main() {
    FreqQueue *queue = init();

    char str[] = "AAABBC";
    char str2[] = "122333";

    frequencia(queue, str);
    frequencia(queue, str2);
    return 0;
}