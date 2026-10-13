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

  int inverte_lista(ListaTarefas* li) {
    if (li == NULL) {
        return 0;
    }

      struct elemento* ant = NULL;
    struct elemento* atual = *li;
    struct elemento* proximo = NULL;

     while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = ant;
         ant = atual;
        atual = proximo;
    }

     *li = ant;
    return 1;
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
     ListaTarefas* minha_lista = cria_lista();

    struct tarefa t1 = {10, "Primeira tarefa", 1};
    struct tarefa t2 = {20, "Segunda tarefa", 2};
     struct tarefa t3 = {30, "Terceira tarefa", 3};
    struct tarefa t4 = {40, "Quarta tarefa", 4};

      insere_tarefa_final(minha_lista, t1);
    insere_tarefa_final(minha_lista, t2);
     insere_tarefa_final(minha_lista, t3);
    insere_tarefa_final(minha_lista, t4);

    printf("LISTA ORIGINAL\n");
    imprime_lista(minha_lista);

    inverte_lista(minha_lista);

    printf("\nLISTA INVERTIDA\n");
    imprime_lista(minha_lista);

    return 0;
}