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

int remove_tarefas_prioridade(ListaTarefas* li, int prioridade) {
    if (li == NULL) {
        return -1;
    }

    int removidos = 0;
    struct elemento* ant = NULL;
    struct elemento* atual = *li;

    while (atual != NULL) {
        if (atual->dados.prioridade == prioridade) {
            struct elemento* temp = atual;
            if (ant == NULL) {
                *li = atual->prox;
            } else {
                ant->prox = atual->prox;
            }
            atual = atual->prox;
            free(temp);
            removidos++;
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }

    return removidos;
}

void imprime_lista(ListaTarefas* li) {
    if (li == NULL || *li == NULL) {
        printf("(Lista vazia)\n");
        return;
    }
    struct elemento* atual = *li;
      while (atual != NULL) {
        printf("[Prio %d] Cod %d: %s\n", 
               atual->dados.prioridade, atual->dados.codigo, atual->dados.descricao);
        atual = atual->prox;
    }
}

int main(void) {
    ListaTarefas* minha_lista = cria_lista();

      struct tarefa t1 = {1, "Tarefa Inicio A", 2};
    struct tarefa t2 = {2, "Tarefa Inicio B", 2};
    struct tarefa t3 = {3, "Tarefa Meio A", 1};
    struct tarefa t4 = {4, "Tarefa Meio B", 2};
     struct tarefa t5 = {5, "Tarefa Meio C", 2};
    struct tarefa t6 = {6, "Tarefa Fim A", 3};
      struct tarefa t7 = {7, "Tarefa Fim B", 2};

    insere_tarefa_final(minha_lista, t1);
      insere_tarefa_final(minha_lista, t2);
    insere_tarefa_final(minha_lista, t3);
    insere_tarefa_final(minha_lista, t4);
      insere_tarefa_final(minha_lista, t5);
    insere_tarefa_final(minha_lista, t6);
     insere_tarefa_final(minha_lista, t7);

    printf("LISTA ANTES DA REMOCAO\n");
     imprime_lista(minha_lista);

    int prio_alvo = 2;
    int qtd = remove_tarefas_prioridade(minha_lista, prio_alvo);

    printf("\nRemovidas %d tarefas com prioridade %d.\n\n", qtd, prio_alvo);

     printf("LISTA DEPOIS DA REMOCAO\n");
    imprime_lista(minha_lista);

      return 0;
}