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

int tarefa_mais_urgente(ListaTarefas* li, struct tarefa *t) {
     if (li == NULL || *li == NULL) {
        return 0;
    }

    struct elemento* atual = *li;
    struct elemento* mais_urgente = *li;

     while (atual != NULL) {
        if (atual->dados.prioridade < mais_urgente->dados.prioridade) {
            mais_urgente = atual;
        }
        atual = atual->prox;
    }

     *t = mais_urgente->dados;
    return 1;
}

int main(void) {
    ListaTarefas* minha_lista = cria_lista();

     struct tarefa t1 = {10, "Lavar a louca", 4};
    struct tarefa t2 = {20, "Estudar C", 2};
    struct tarefa t3 = {30, "Fazer o trabalho", 2};
    struct tarefa t4 = {40, "Dormir", 5};
     struct tarefa t5 = {50, "Pagar contas", 1};
    struct tarefa t6 = {60, "Fazer compras", 1};

   
 insere_tarefa_final(minha_lista, t1);
    insere_tarefa_final(minha_lista, t2);
    insere_tarefa_final(minha_lista, t3);
 insere_tarefa_final(minha_lista, t4);
    insere_tarefa_final(minha_lista, t5);
    insere_tarefa_final(minha_lista, t6);

    struct tarefa urgente;
    int sucesso = tarefa_mais_urgente(minha_lista, &urgente);

    if (sucesso) {
        printf("Tarefa mais urgente encontrada:\n");
        printf("Codigo: %d | Descricao: %s | Prioridade: %d\n", 
               urgente.codigo, urgente.descricao, urgente.prioridade);
    } else {
        printf("Lista invalida ou vazia.\n");
    }

    return 0;
}