 #include <stdio.h>
#include <stdlib.h>
  #include <string.h>

struct tarefa {
    int codigo;
     char descricao[40];
    int prioridade;
};

struct elemento {
     struct tarefa dados;
    struct elemento* prox;
};

  typedef struct elemento* ListaTarefas;

ListaTarefas* cria_lista(void) {
      ListaTarefas* li = (ListaTarefas*) malloc(sizeof(ListaTarefas));
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}

int insere_tarefa_final(ListaTarefas* li, struct tarefa t) {
      if (li == NULL) return 0;

    struct elemento* no = (struct elemento*) malloc(sizeof(struct elemento));
      if (no == NULL) return 0;

    no->dados = t;
      no->prox = NULL;

    if ((*li) == NULL) {
         *li = no;
    } else {
        struct elemento* aux = *li;
         while (aux->prox != NULL) {
            aux = aux->prox;
        }
         aux->prox = no;
    }
    return 1;
}

int mescla_tarefas(ListaTarefas* dst, ListaTarefas* src) {
     if (dst == NULL || src == NULL) {
        return -1;
    }

    if (*src == NULL) {
        return 0;
    }

      int cont = 0;
     struct elemento* atual = *src;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }

    if (*dst == NULL) {
         *dst = *src;
    } else {
         struct elemento* ultimo = *dst;
         while (ultimo->prox != NULL) {
              ultimo = ultimo->prox;
        }
        ultimo->prox = *src;
    }

    *src = NULL;
    return cont;
}

void imprime_lista(ListaTarefas* li) {
      if (li == NULL || *li == NULL) {
        printf("(Lista vazia)\n");
        return;
    }
     struct elemento* atual = *li;
    while (atual != NULL) {
        printf("Cod %d: %s [Prio %d]\n", 
               atual->dados.codigo, atual->dados.descricao, atual->dados.prioridade);
        atual = atual->prox;
    }
}

int main(void) {
    ListaTarefas* lista_dst = cria_lista();
      ListaTarefas* lista_src = cria_lista();

    struct tarefa t1 = {10, "Tarefa Destino 1", 1};
      struct tarefa t2 = {20, "Tarefa Destino 2", 2};

    struct tarefa t3 = {30, "Tarefa Origem 1", 3};
     struct tarefa t4 = {40, "Tarefa Origem 2", 4};
    struct tarefa t5 = {50, "Tarefa Origem 3", 5};

    insere_tarefa_final(lista_dst, t1);
     insere_tarefa_final(lista_dst, t2);

     insere_tarefa_final(lista_src, t3);
     insere_tarefa_final(lista_src, t4);
    insere_tarefa_final(lista_src, t5);

    printf("ANTES DE MESCLAR\n");
     printf("Lista Destino (dst):\n");
    imprime_lista(lista_dst);
    printf("\nLista Origem (src):\n");
    imprime_lista(lista_src);

    int transferidas = mescla_tarefas(lista_dst, lista_src);

     printf("\nDEPOIS DE MESCLAR (Transferidas: %d)\n", transferidas);
    printf("Lista Destino (dst):\n");
     imprime_lista(lista_dst);
    printf("\nLista Origem (src):\n");
     imprime_lista(lista_src);

    return 0;
}