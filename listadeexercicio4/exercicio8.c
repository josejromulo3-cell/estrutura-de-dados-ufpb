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

int mescla_listas(Lista* destino, Lista* origem) {
    if (destino == NULL || origem == NULL) {
        return 0;
    }

    int inseridos = 0;

    for (int i = 0; i < origem->qtd; i++) {
        if (destino->qtd >= MAX) {
            break;
        }

        int existe = 0;
        for (int j = 0; j < destino->qtd; j++) {
            if (destino->dados[j].codigo == origem->dados[i].codigo) {
                existe = 1;
                break;
            }
        }

        if (!existe) {
            destino->dados[destino->qtd] = origem->dados[i];
            destino->qtd++;
            inseridos++;
        }
    }

    return inseridos;
}

int main(void) {
    Lista destino;
    destino.qtd = 0;
    
    destino.dados[0].codigo = 10;
      strcpy(destino.dados[0].nome, "Teclado");
    destino.dados[0].preco = 150.00;
    destino.qtd++;

    destino.dados[1].codigo = 20;
     strcpy(destino.dados[1].nome, "Mouse");
      destino.dados[1].preco = 80.00;
    destino.qtd++;

    Lista origem;
    origem.qtd = 0;

    origem.dados[0].codigo = 20;
     strcpy(origem.dados[0].nome, "Mouse Gamer");
      origem.dados[0].preco = 120.00;
    origem.qtd++;

      origem.dados[1].codigo = 30;
    strcpy(origem.dados[1].nome, "Monitor");
      origem.dados[1].preco = 900.00;
    origem.qtd++;

     origem.dados[2].codigo = 40;
    strcpy(origem.dados[2].nome, "Cabo USB");
       origem.dados[2].preco = 20.00;
    origem.qtd++;

    printf(" LISTA DESTINO (ANTES) \n");
      for (int k = 0; k < destino.qtd; k++) {
        printf("Codigo: %d | %s\n", destino.dados[k].codigo, destino.dados[k].nome);
    }

     int inseridos = mescla_listas(&destino, &origem);

    printf("\nMesclando as listas...\n");
      printf("Foram inseridos %d novos produtos.\n", inseridos);

    printf("\n LISTA DESTINO (DEPOIS) \n");
      for (int k = 0; k < destino.qtd; k++) {
        printf("Codigo: %d | %s\n", destino.dados[k].codigo, destino.dados[k].nome);
    }

    return 0;
}