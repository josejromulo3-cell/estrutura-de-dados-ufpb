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

   int remove_tarefa_pos(ListaTarefas* li, int pos) {
    if (li == NULL || *li == NULL || pos < 1) {
        return 0;
    }

      struct elemento* ant = NULL;
    struct elemento* atual = *li;
    int k = 1;

    while (atual != NULL && k < pos) {
         ant = atual;
        atual = atual->prox;
        k++;
    }

    if (atual == NULL) {
        return 0;
    }

     if (ant == NULL) {
        *li = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

      free(atual);
    return 1;
}

  void imprime_lista(ListaTarefas* li) {
     if (li == NULL || *li == NULL) {
        printf("(Lista vazia)\n");
        return;
    }
    struct elemento* atual = *li;
      int pos = 1;
    while (atual != NULL) {
        printf("Pos %d -> Cod %d: %s [Prio %d]\n", 
               pos, atual->dados.codigo, atual->dados.descricao, atual->dados.prioridade);
        atual = atual->prox;
        pos++;
    }
}

 int main(void) {
    ListaTarefas* minha_lista = cria_lista();

     struct tarefa t1 = {10, "Tarefa Um", 1};
    struct tarefa t2 = {20, "Tarefa Dois", 2};
      struct tarefa t3 = {30, "Tarefa Tres", 3};
     struct tarefa t4 = {40, "Tarefa Quatro", 4};

     insere_tarefa_final(minha_lista, t1);
    insere_tarefa_final(minha_lista, t2);
     insere_tarefa_final(minha_lista, t3);
    insere_tarefa_final(minha_lista, t4);

    printf("LISTA INICIAL\n");
     imprime_lista(minha_lista);

    printf("\nRemovendo a posicao 3\n");
     if (remove_tarefa_pos(minha_lista, 3)) {
        imprime_lista(minha_lista);
    }

      printf("\n Removendo a posicao 1 (inicio) \n");
    if (remove_tarefa_pos(minha_lista, 1)) {
        imprime_lista(minha_lista);
    }

      printf("\n Tentando remover a posicao 10 (inexistente) \n");
    if (!remove_tarefa_pos(minha_lista, 10)) {
        printf("Falha esperada: posicao 10 nao existe na lista.\n");
    }

    return 0;
}