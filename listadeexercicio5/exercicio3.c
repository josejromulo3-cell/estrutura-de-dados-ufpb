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

  int busca_tarefa_desc(ListaTarefas* li, char *texto, struct tarefa *t) {
    if (li == NULL || texto == NULL) {
        return 0;
    }

    struct elemento* atual = *li;

    while (atual != NULL) {
        if (strstr(atual->dados.descricao, texto) != NULL) {
            *t = atual->dados;
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}

int main(void) {
    ListaTarefas* minha_lista = cria_lista();

    struct tarefa t1 = {1, "Comprar leite no supermercado", 3};
     struct tarefa t2 = {2, "cachorro caramelo", 1};
    struct tarefa t3 = {3, "Estudar para a prova", 2};
    struct tarefa t4 = {4, "para o professor", 2};

    insere_tarefa_final(minha_lista, t1);
     insere_tarefa_final(minha_lista, t2);
    insere_tarefa_final(minha_lista, t3);
    insere_tarefa_final(minha_lista, t4);

    struct tarefa encontrada;

    printf("TESTE 1: Substring que existe\n");
    if (busca_tarefa_desc(minha_lista, "caramelo", &encontrada)) {
        printf("Encontrada! Codigo: %d | Descricao: %s | Prioridade: %d\n\n",
                encontrada.codigo, encontrada.descricao, encontrada.prioridade);
    } else {
        printf("Nenhuma tarefa encontrada.\n\n");
    }

    printf("TESTE 2: Substring que aparece em mais de uma (deve pegar a primeira)\n");
    if (busca_tarefa_desc(minha_lista, "para", &encontrada)) {
        printf("Encontrada! Codigo: %d | Descricao: %s | Prioridade: %d\n\n",
               encontrada.codigo, encontrada.descricao, encontrada.prioridade);
    } else {
        printf("Nenhuma tarefa encontrada.\n\n");
    }

    printf("TESTE 3: Substring que NAO existe\n");
    if (busca_tarefa_desc(minha_lista, "Academia", &encontrada)) {
        printf("Encontrada! Codigo: %d | Descricao: %s\n",
               encontrada.codigo, encontrada.descricao);
    } else {
        printf("Nenhuma tarefa encontrada com a palavra 'Academia'.\n");
    }

    return 0;
}