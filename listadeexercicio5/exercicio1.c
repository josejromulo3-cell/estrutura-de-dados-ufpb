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

ListaTarefas* cria_lista() {
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

int conta_tarefas_prioridade(ListaTarefas* li, int prioridade) {
    if (li == NULL) {
        return -1;
    }

    int cont = 0;
    struct elemento* atual = *li;

    while (atual != NULL) {
        if (atual->dados.prioridade == prioridade) {
            cont++;
        }
        atual = atual->prox;
    }

    return cont;
}

int main(void) {
    ListaTarefas* minha_lista = cria_lista();

    struct tarefa t1 = {101, "Comprar pão", 2};
    struct tarefa t2 = {102, "Pagar boleto", 1};
      struct tarefa t3 = {103, "Estudar C", 1};
      struct tarefa t4 = {104, "Lavar o carro", 5};
    struct tarefa t5 = {105, "Limpar a casa", 3};

    insere_tarefa_final(minha_lista, t1);
    insere_tarefa_final(minha_lista, t2);
      insere_tarefa_final(minha_lista, t3);
    insere_tarefa_final(minha_lista, t4);
    insere_tarefa_final(minha_lista, t5);

    int p = 1;
    int qtd_prioridade = conta_tarefas_prioridade(minha_lista, p);
    printf("Total de tarefas com prioridade %d: %d\n", p, qtd_prioridade);

    p = 2;
    qtd_prioridade = conta_tarefas_prioridade(minha_lista, p);
     printf("Total de tarefas com prioridade %d: %d\n", p, qtd_prioridade);

    p = 4;
      qtd_prioridade = conta_tarefas_prioridade(minha_lista, p);
    printf("Total de tarefas com prioridade %d: %d\n", p, qtd_prioridade);

    int qtd_nula = conta_tarefas_prioridade(NULL, 1);
      printf("Teste lista NULL: %d\n", qtd_nula);
   
    return 0;
}