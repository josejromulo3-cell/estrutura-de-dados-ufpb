#include <stdio.h>
#include <stdlib.h>

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


int lista_tem_espaco(Lista* li, int n) {
    
      if (li == NULL) {
        return 0;
    }

    if (li->qtd + n <= MAX) {
        return 1;
    }

    return 0;
}



int main(void) {
    
    Lista* listaNula = NULL;
      int resultado1 = lista_tem_espaco(listaNula, 5);
    printf("Cenario 1 (Lista NULL tentando 5 insercoes): %d (Esperado: 0)\n", resultado1);


    Lista minhaLista;
    minhaLista.qtd = 90; 

    int resultado2 = lista_tem_espaco(&minhaLista, 5);
     printf("Cenario 2 (Lista com 90 itens tentando 5 insercoes): %d (Esperado: 1)\n", resultado2);

     int resultado3 = lista_tem_espaco(&minhaLista, 15);
    printf("Cenario 3 (Lista com 90 itens tentando 15 insercoes): %d (Esperado: 0)\n", resultado3);

    return 0;
}