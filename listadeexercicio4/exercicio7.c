#include <stdio.h>
#include <string.h>

#define MAX 100 

struct produto {
    int codigo;
    char nome[30];
    float preco;
};

typedef struct lista {
    int qtd;
    struct produto dados[MAX];
} Lista;

int remove_abaixo_de(Lista* li, float precoMinimo) {
    if (li == NULL) {
        return 0;
    }

    int removidos = 0;
    int i = 0;

    while (i < li->qtd) {
        if (li->dados[i].preco < precoMinimo) {
              li->qtd--;
            li->dados[i] = li->dados[li->qtd];
              removidos++;
        } else {
            i++;
        }
    }

    return removidos;
}

int main(void) {
    Lista minha_lista;
      minha_lista.qtd = 0; 

    minha_lista.dados[0].codigo = 1;
       strcpy(minha_lista.dados[0].nome, "Cabo USB");
    minha_lista.dados[0].preco = 15.00;
      minha_lista.qtd++;

    minha_lista.dados[1].codigo = 2;
      strcpy(minha_lista.dados[1].nome, "Teclado");
    minha_lista.dados[1].preco = 120.00;
      minha_lista.qtd++;

      minha_lista.dados[2].codigo = 3;
    strcpy(minha_lista.dados[2].nome, "Adaptador");
      minha_lista.dados[2].preco = 25.00;
    minha_lista.qtd++;

    minha_lista.dados[3].codigo = 4;
      strcpy(minha_lista.dados[3].nome, "Monitor");
    minha_lista.dados[3].preco = 800.00;
       minha_lista.qtd++;

    minha_lista.dados[4].codigo = 5;
      strcpy(minha_lista.dados[4].nome, "Pen Drive");
    minha_lista.dados[4].preco = 30.00;
       minha_lista.qtd++;

    printf(" LISTA ORIGINAL \n");
       for (int k = 0; k < minha_lista.qtd; k++) {
        printf("[%d] %s - R$ %.2f\n", k, minha_lista.dados[k].nome, minha_lista.dados[k].preco);
    }

      float limite = 50.00;
    int total_removidos = remove_abaixo_de(&minha_lista, limite);

    printf("\nRemovendo produtos abaixo de R$ %.2f...\n", limite);
      printf("Total de produtos removidos: %d\n", total_removidos);

    printf("\n LISTA APOS REMOCOES \n");
      for (int k = 0; k < minha_lista.qtd; k++) {
        printf("[%d] %s - R$ %.2f\n", k, minha_lista.dados[k].nome, minha_lista.dados[k].preco);
    }

    return 0;
}