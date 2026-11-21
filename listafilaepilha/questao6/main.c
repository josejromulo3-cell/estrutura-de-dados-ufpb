#include <stdio.h>
#include "PilhaDupla.h"

static struct aluno cria_aluno(int mat) {
    struct aluno al;
    al.matricula = mat;
    snprintf(al.nome, sizeof(al.nome), "Aluno %d", mat);
    al.n1 = 0.0f;
    al.n2 = 0.0f;
    al.n3 = 0.0f;
    return al;
}

static void mostra_estado(const char *acao, int ret, PilhaDupla *pd) {
    struct aluno t1, t2;
    int ok1 = consulta_topo_PilhaDupla(pd, 1, &t1);
    int ok2 = consulta_topo_PilhaDupla(pd, 2, &t2);
    printf("%-28s | ret=%d | tam1=%d tam2=%d cheia=%d | topo1=",
           acao, ret, tamanho_PilhaDupla(pd, 1), tamanho_PilhaDupla(pd, 2), PilhaDupla_cheia(pd));
    if (ok1)
        printf("%d", t1.matricula);
    else
        printf("-");
    printf(" topo2=");
    if (ok2)
        printf("%d\n", t2.matricula);
    else
        printf("-\n");
}

int main(void) {
    PilhaDupla *pd = cria_PilhaDupla(5);
    if (pd == NULL)
        return 1;

    printf("Teste item b (capacidade 5)\n");
    mostra_estado("insere 10 na pilha 1", insere_PilhaDupla(pd, 1, cria_aluno(10)), pd);
    mostra_estado("insere 90 na pilha 2", insere_PilhaDupla(pd, 2, cria_aluno(90)), pd);
    mostra_estado("insere 20 na pilha 1", insere_PilhaDupla(pd, 1, cria_aluno(20)), pd);
        mostra_estado("insere 80 na pilha 2", insere_PilhaDupla(pd, 2, cria_aluno(80)), pd);
    mostra_estado("insere 30 na pilha 1", insere_PilhaDupla(pd, 1, cria_aluno(30)), pd);
    mostra_estado("insere 70 na pilha 2", insere_PilhaDupla(pd, 2, cria_aluno(70)), pd);
    mostra_estado("remove da pilha 2", remove_PilhaDupla(pd, 2), pd);
    mostra_estado("insere 40 na pilha 1", insere_PilhaDupla(pd, 1, cria_aluno(40)), pd);

    printf("\nTestes de parametros invalidos \n");
    printf("tamanho(pd, 3) -> %d\n", tamanho_PilhaDupla(pd, 3));
    printf("insere(pd, 0, 99) -> %d\n", insere_PilhaDupla(pd, 0, cria_aluno(99)));
    printf("remove(NULL, 1) -> %d\n", remove_PilhaDupla(NULL, 1));
    libera_PilhaDupla(pd);

    printf("\nTeste item c (capacidade 8, 5 insercoes na pilha 1) \n");
    PilhaDupla *pd8 = cria_PilhaDupla(8);
    if (pd8 != NULL) {
        for (int i = 1; i <= 5; i++) {
            int ret = insere_PilhaDupla(pd8, 1, cria_aluno(i * 10));
            printf("insere %d na pilha 1 -> ret=%d | tam1=%d tam2=%d\n",
                   i * 10, ret, tamanho_PilhaDupla(pd8, 1), tamanho_PilhaDupla(pd8, 2));
        }
        libera_PilhaDupla(pd8);
    }

    return 0;
}