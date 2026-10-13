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

int busca_por_nome(Lista* li, char *nome, struct produto *p) {

    if (li == NULL) {
        return 0;
    }


    for (int i = 0; i < li->qtd; i++) {
        
        if (strcmp(li->dados[i].nome, nome) == 0) {
            
        
            *p = li->dados[i]; 
            
            return 1; 
        }
    }

    return 0;
}


int main(void) {

    Lista minha_lista;
    minha_lista.qtd = 0; 


    minha_lista.dados[0].codigo = 50;
    strcpy(minha_lista.dados[0].nome, "Teclado Mecanico");
     minha_lista.dados[0].preco = 250.00;
    minha_lista.qtd++;

    
    minha_lista.dados[1].codigo = 51;
    strcpy(minha_lista.dados[1].nome, "mouse");
     minha_lista.dados[1].preco = 85.50;
    minha_lista.qtd++;

    
    struct produto produto_encontrado;

    printf(" TESTE 1: Procurando um produto que existe \n");
    
    int sucesso = busca_por_nome(&minha_lista, "mouse", &produto_encontrado);
    
    if (sucesso == 1) {
        printf("Produto encontrado!\n");
         printf("Codigo: %d | Nome: %s | Preco: R$ %.2f\n\n", 
               produto_encontrado.codigo, 
                 produto_encontrado.nome, 
               produto_encontrado.preco);
    } else {
        printf("Produto NAO encontrado.\n\n");
    }


    printf("teste 2: Procurando um produto que nao existe\n");
      int falha = busca_por_nome(&minha_lista, "Monitor", &produto_encontrado);
    
    if (falha == 1) {
        printf("Produto encontrado!\n");
     } else {
        printf("Produto nao encontrado. (nao se encontra na lista)\n");
    }

      return 0;
}