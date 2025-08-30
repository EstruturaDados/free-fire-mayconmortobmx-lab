#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Constantes para critérios de ordenação
#define POR_NOME 1
#define POR_TIPO 2
#define POR_PRIORIDADE 3

// Estrutura do item
typedef struct {
    char nome[50];
    char tipo[20];
    int prioridade;
} Item;

// Variáveis globais
#define MAX_ITENS 100
Item mochila[MAX_ITENS];
int totalItens = 0;
int comparacoes = 0;

// Função de ordenação (Insertion Sort)
void insertionSort(int criterio) {
    for(int i = 1; i < totalItens; i++) {
        Item key = mochila[i];
        int j = i - 1;
        bool comp = false;

        if(criterio == POR_NOME)
            while(j >= 0 && (comp = strcmp(mochila[j].nome, key.nome) > 0)) {
                mochila[j + 1] = mochila[j];
                j--;
                comparacoes++;
            }
        else if(criterio == POR_TIPO)
            while(j >= 0 && (comp = strcmp(mochila[j].tipo, key.tipo) > 0)) {
                mochila[j + 1] = mochila[j];
                j--;
                comparacoes++;
            }
        else if(criterio == POR_PRIORIDADE)
            while(j >= 0 && (comp = mochila[j].prioridade > key.prioridade)) {
                mochila[j + 1] = mochila[j];
                j--;
                comparacoes++;
            }

        mochila[j + 1] = key;
    }
}

// Função para testar a ordenação
void imprimirMochila() {
    for(int i = 0; i < totalItens; i++) {
        printf("Nome: %s, Tipo: %s, Prioridade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].prioridade);
    }
}

int main() {
    // Exemplo de itens
    totalItens = 5;
    strcpy(mochila[0].nome, "Arco");
    strcpy(mochila[0].tipo, "Ataque");
    mochila[0].prioridade = 3;

    strcpy(mochila[1].nome, "Poção");
    strcpy(mochila[1].tipo, "Cura");
    mochila[1].prioridade = 1;

    strcpy(mochila[2].nome, "Espada");
    strcpy(mochila[2].tipo, "Ataque");
    mochila[2].prioridade = 2;

    strcpy(mochila[3].nome, "Escudo");
    strcpy(mochila[3].tipo, "Defesa");
    mochila[3].prioridade = 4;

    strcpy(mochila[4].nome, "Armadilha");
    strcpy(mochila[4].tipo, "Defesa");
    mochila[4].prioridade = 5;

    printf("Antes da ordenação:\n");
    imprimirMochila();

    insertionSort(POR_NOME);

    printf("\nDepois da ordenação por nome:\n");
    imprimirMochila();

    return 0;
}
