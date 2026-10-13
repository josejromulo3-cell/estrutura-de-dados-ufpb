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


int remove_mais_caro(Lista* li, struct produto *removido) {

    if (li == NULL || li->qtd == 0) {
        return 0; 
    }

    int i = 0; 
    
    for (int j = 1; j < li->qtd; j++) {
    
        if (li->dados[j].preco > li->dados[i].preco) {
            i = j; 
        }
    }

   
    *removido = li->dados[i]; 


    li->qtd--; 
    
    
    li->dados[i] = li->dados[li->qtd]; 

    return 1;
}

int main(void) {
    Lista minha_lista;
    minha_lista.qtd = 0; 

    
    minha_lista.dados[0].codigo = 10;
    strcpy(minha_lista.dados[0].nome, "Teclado");
     minha_lista.dados[0].preco = 150.00;
    minha_lista.qtd++;

    
    minha_lista.dados[1].codigo = 20;
      strcpy(minha_lista.dados[1].nome, "Placa de Video");
    minha_lista.dados[1].preco = 3500.00;
    minha_lista.qtd++;


    minha_lista.dados[2].codigo = 30;
     strcpy(minha_lista.dados[2].nome, "Mouse");
    minha_lista.dados[2].preco = 80.00;
    minha_lista.qtd++;


    minha_lista.dados[3].codigo = 40;
    strcpy(minha_lista.dados[3].nome, "Gabinete");
      minha_lista.dados[3].preco = 300.00;
    minha_lista.qtd++;

    printf("LISTA ANTES DA REMOCAO\n");
    for (int k = 0; k < minha_lista.qtd; k++) {
        printf("[%d] %s - R$ %.2f\n", k, minha_lista.dados[k].nome, minha_lista.dados[k].preco);
    }

   
    struct produto apagado;
    
    int sucesso = remove_mais_caro(&minha_lista, &apagado);

    if (sucesso) {
    
        printf("Produto retirado: %s (R$ %.2f)\n", apagado.nome, apagado.preco);
        
        printf("\nLISTA DEPOIS DA REMOCAO\n");
        
        for (int k = 0; k < minha_lista.qtd; k++) {
            printf("[%d] %s - R$ %.2f\n", k, minha_lista.dados[k].nome, minha_lista.dados[k].preco);
        }
    }

    return 0;
}