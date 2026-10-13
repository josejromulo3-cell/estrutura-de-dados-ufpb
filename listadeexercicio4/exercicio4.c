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



int insere_lista_decrescente(Lista* li, struct produto p) {
    
    if (li == NULL || li->qtd >= MAX) {
        return 0; 
    }

    int i = 0;
    
    
    while (i < li->qtd && li->dados[i].preco >= p.preco) {
        i++;
    }

   
    for (int j = li->qtd - 1; j >= i; j--) {
         li->dados[j + 1] = li->dados[j];
    }

    
     li->dados[i] = p;
    
    
    li->qtd++;

    return 1; 
}



int main(void) {
    
    Lista minha_lista;
    minha_lista.qtd = 0; 

   
    struct produto p1 = {1, "Mouse", 50.00};
      struct produto p2 = {2, "Monitor", 800.00};
    struct produto p3 = {3, "Teclado", 150.00};
     struct produto p4 = {4, "Cabo USB", 25.00};

   
    insere_lista_decrescente(&minha_lista, p1); 
     insere_lista_decrescente(&minha_lista, p2); 
     insere_lista_decrescente(&minha_lista, p3); 
    insere_lista_decrescente(&minha_lista, p4); 

  
    printf("LISTA ORDENADA POR PRECO (DECRESCENTE)\n");
    for (int i = 0; i < minha_lista.qtd; i++) {
        printf("%dº lugar: %s (R$ %.2f)\n", 
               i + 1, 
               minha_lista.dados[i].nome, 
                minha_lista.dados[i].preco);
    }

    return 0;
}