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


float soma_precos(Lista* li) {
    
    if (li == NULL) {
        return 0.0;
    }

    float soma = 0.0;
    
    
    for (int i = 0; i < li->qtd; i++) {
    
        soma += li->dados[i].preco;
    }

    return soma;
}

int main(void) {
   
    Lista minha_lista;
    minha_lista.qtd = 0; 

    minha_lista.dados[0].codigo = 101;
      strcpy(minha_lista.dados[0].nome, "Caderno");
    minha_lista.dados[0].preco = 15.50;
      minha_lista.qtd++;

    
    minha_lista.dados[1].codigo = 102;
    strcpy(minha_lista.dados[1].nome, "Caneta Azul ");
     minha_lista.dados[1].preco = 2.00;
    minha_lista.qtd++;


    minha_lista.dados[2].codigo = 103;
      strcpy(minha_lista.dados[2].nome, "Mochila");
    minha_lista.dados[2].preco = 120.00;
    minha_lista.qtd++;

    float valor_total = soma_precos(&minha_lista);
    

      printf("Lista com %d produtos.\n", minha_lista.qtd);
    printf("A soma total dos precos e: R$ %.2f\n\n", valor_total);

    Lista* lista_inexistente = NULL;
      float valor_nulo = soma_precos(lista_inexistente);
    printf("Soma de uma lista NULL e: R$ %.2f\n", valor_nulo);

    return 0;
}