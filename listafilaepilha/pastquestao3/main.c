#include <stdio.h>
#include "FilaEstatica.h"

int josefo(int n, int k) {
    if (n <= 0 || k <= 0)
        return -1;

      Fila *fi = cria_Fila(n);
    if (fi == NULL)
        return -1;

       struct aluno al;
    for (int i = 1; i <= n; i++) {
        al.matricula = i;
        snprintf(al.nome, sizeof(al.nome), "Aluno %d", i);
        al.n1 = 0.0f;
        al.n2 = 0.0f;
        al.n3 = 0.0f;
           if (!insere_Fila(fi, al)) {
            libera_Fila(fi);
            return -1;
        }
    }

    printf("Ordem de saida (n=%d, k=%d): ", n, k);
      int primeiro = 1;
    while (tamanho_Fila(fi) > 1) {
        for (int c = 1; c < k; c++) {
              consulta_Fila(fi, &al);
            remove_Fila(fi);
              insere_Fila(fi, al);
          }
        consulta_Fila(fi, &al);
          remove_Fila(fi);
        if (!primeiro)
            printf(", ");
        printf("%d", al.matricula);
        primeiro = 0;
    }

    if (primeiro)
           printf("(nenhum)");
    printf("\n");

    consulta_Fila(fi, &al);
    int sobrevivente = al.matricula;
        libera_Fila(fi);
    return sobrevivente;
}

static void testa_josefo(int n, int k) {
        int s = josefo(n, k);
    if (s == -1)
        printf("Parametros invalidos (n=%d, k=%d) -> retorno: %d\n\n", n, k, s);
    else
        printf("Sobrevivente (n=%d, k=%d): %d\n\n", n, k, s);
}

int main(void) {
    testa_josefo(7, 3);
        testa_josefo(5, 2);
    testa_josefo(1, 4);
       testa_josefo(6, 1);
    testa_josefo(0, 3);
    testa_josefo(5, 0);
    return 0;
}