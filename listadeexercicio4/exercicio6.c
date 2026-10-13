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


 

int conta_faixa_preco(Lista* li, float min, float max) {
    
    if (li == NULL) {
        return 0;
    }

    int contador = 0;

    
    for (int i = 0; i < li->qtd; i++) {
        
        

        if (li->dados[i].preco >= min && li->dados[i].preco <= max) {
            contador++; 
        }
    }

    
    return contador; 
}



int main(void) {
    Lista minha_lista;
    minha_lista.qtd = 0; 


    minha_lista.dados[0].codigo = 1;
      strcpy(minha_lista.dados[0].nome, "Cabo HDMI");
     minha_lista.dados[0].preco = 25.00;
    minha_lista.qtd++;

     minha_lista.dados[1].codigo = 2;
    strcpy(minha_lista.dados[1].nome, "Teclado Mecanico");
      minha_lista.dados[1].preco = 150.00;
    minha_lista.qtd++;

     minha_lista.dados[2].codigo = 3;
    strcpy(minha_lista.dados[2].nome, "Monitor LCD");
      minha_lista.dados[2].preco = 800.00;
    minha_lista.qtd++;

      minha_lista.dados[3].codigo = 4;
    strcpy(minha_lista.dados[3].nome, "Tapete de Rato");
      minha_lista.dados[3].preco = 50.00;
    minha_lista.qtd++;

     printf("BUSCA POR FAIXA DE PRECO:\n");

    
    float minimo1 = 20.00, maximo1 = 100.00;
      int total1 = conta_faixa_preco(&minha_lista, minimo1, maximo1);
    printf("Produtos entre R$ %.2f e R$ %.2f: %d (Esperado: 2)\n", minimo1, maximo1, total1);

    
    float minimo2 = 150.00, maximo2 = 150.00;
      int total2 = conta_faixa_preco(&minha_lista, minimo2, maximo2);
    printf("Produtos entre R$ %.2f e R$ %.2f: %d (Esperado: 1)\n", minimo2, maximo2, total2);

  
      float minimo3 = 1000.00, maximo3 = 5000.00;
     int total3 = conta_faixa_preco(&minha_lista, minimo3, maximo3);
    printf("Produtos entre R$ %.2f e R$ %.2f: %d (Esperado: 0)\n", minimo3, maximo3, total3);

    return 0;
}