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

int insere_tarefa_final_prioridade(ListaTarefas* li, struct tarefa t) {
    if (li == NULL) {
        return 0;
    }

    struct elemento* no = (struct elemento*) malloc(sizeof(struct elemento));
    if (no == NULL) {
        return 0;
    }
    no->dados = t;

    if (*li == NULL) {
        no->prox = NULL;
        *li = no;
        return 1;
    }

    struct elemento* atual = *li;
    struct elemento* ultimo_prio = NULL;
    struct elemento* ultimo_no = NULL;

    while (atual != NULL) {
        if (atual->dados.prioridade == t.prioridade) {
            ultimo_prio = atual;
        }
        ultimo_no = atual;
        atual = atual->prox;
    }

    if (ultimo_prio != NULL) {
        no->prox = ultimo_prio->prox;
        ultimo_prio->prox = no;
    } else {
        no->prox = NULL;
        ultimo_no->prox = no;
    }

    return 1;
}

void imprime_lista(ListaTarefas* li) {
    if (li == NULL) return;
    struct elemento* atual = *li;
    int pos = 1;
    while (atual != NULL) {
        printf("%d. [Prio %d] Cod %d: %s\n", 
               pos, atual->dados.prioridade, atual->dados.codigo, atual->dados.descricao);
        atual = atual->prox;
        pos++;
    }
}

int main(void) {
    ListaTarefas* minha_lista = cria_lista();

     struct tarefa t1 = {10, "Configurar servidor", 2};
    struct tarefa t2 = {20, "Corrigir bug critico", 1};
    struct tarefa t3 = {30, "Atualizar documentacao", 4};
     struct tarefa t4 = {40, "Testar API", 2};
    struct tarefa t5 = {50, "Reuniao de equipa", 1};
     struct tarefa t6 = {60, "Limpar logs", 5};

     insere_tarefa_final_prioridade(minha_lista, t1);
    insere_tarefa_final_prioridade(minha_lista, t2);
    insere_tarefa_final_prioridade(minha_lista, t3);

    printf("LISTA INICIAL (Prioridades 2, 1 e 4)\n");
    imprime_lista(minha_lista);

     insere_tarefa_final_prioridade(minha_lista, t4);
    insere_tarefa_final_prioridade(minha_lista, t5);
    insere_tarefa_final_prioridade(minha_lista, t6);

     printf("\nLISTA APOS NOVAS INSERCOES\n");
    imprime_lista(minha_lista);

    return 0;
}