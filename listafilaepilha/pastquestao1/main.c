#include <stdio.h>
 #include <stdlib.h>
#include "FilaEstatica.h"

  static void imprimir_estado(const char *rotulo, int ret, int inicio, int final, int qtd, const char *slots[4], const char *pertencentes) {
    printf("%-26s | ret=%d | ini=%d fim=%d qtd=%d | [%s, %s, %s, %s] | fila: %s\n",
           rotulo, ret, inicio, final, qtd, slots[0], slots[1], slots[2], slots[3], pertencentes);
}

  int main(void) {
    struct aluno a5 = {5, "Aluno 5", 8.0f, 8.0f, 8.0f};
      struct aluno a8 = {8, "Aluno 8", 8.0f, 8.0f, 8.0f};
     struct aluno a3 = {3, "Aluno 3", 8.0f, 8.0f, 8.0f};
    struct aluno a9 = {9, "Aluno 9", 8.0f, 8.0f, 8.0f};
      struct aluno a7 = {7, "Aluno 7", 8.0f, 8.0f, 8.0f};
    struct aluno a1 = {1, "Aluno 1", 8.0f, 8.0f, 8.0f};
      struct aluno a6 = {6, "Aluno 6", 8.0f, 8.0f, 8.0f};
      struct aluno al;

    const char *slots[4] = {"-", "-", "-", "-"};
      int ret;

    Fila *fi = cria_Fila(4);
      imprimir_estado("cria_Fila(4)", fi != NULL ? 1 : 0, 0, 0, 0, slots, "nenhuma");

     ret = insere_Fila(fi, a5);
    slots[0] = "a5";
      imprimir_estado("insere_Fila(fi, a5)", ret, 0, 1, 1, slots, "dados[0]");

    ret = insere_Fila(fi, a8);
    slots[1] = "a8";
      imprimir_estado("insere_Fila(fi, a8)", ret, 0, 2, 2, slots, "dados[0], dados[1]");

     ret = insere_Fila(fi, a3);
    slots[2] = "a3";
      imprimir_estado("insere_Fila(fi, a3)", ret, 0, 3, 3, slots, "dados[0], dados[1], dados[2]");

    ret = remove_Fila(fi);
    imprimir_estado("remove_Fila(fi)", ret, 1, 3, 2, slots, "dados[1], dados[2]");

    ret = insere_Fila(fi, a9);
      slots[3] = "a9";
    imprimir_estado("insere_Fila(fi, a9)", ret, 1, 0, 3, slots, "dados[1], dados[2], dados[3]");

      ret = insere_Fila(fi, a7);
    slots[0] = "a7";
      imprimir_estado("insere_Fila(fi, a7)", ret, 1, 1, 4, slots, "dados[1], dados[2], dados[3], dados[0]");

       ret = insere_Fila(fi, a1);
    imprimir_estado("insere_Fila(fi, a1)", ret, 1, 1, 4, slots, "dados[1], dados[2], dados[3], dados[0]");

    ret = remove_Fila(fi);
      imprimir_estado("remove_Fila(fi)", ret, 2, 1, 3, slots, "dados[2], dados[3], dados[0]");

      ret = insere_Fila(fi, a6);
    slots[1] = "a6";
    imprimir_estado("insere_Fila(fi, a6)", ret, 2, 2, 4, slots, "dados[2], dados[3], dados[0], dados[1]");

    ret = consulta_Fila(fi, &al);
       imprimir_estado("consulta_Fila(fi, &al)", ret, 2, 2, 4, slots, "dados[2], dados[3], dados[0], dados[1]");

       printf("\nOrdem final da fila (inicio -> final): ");
    for (int k = 0; k < tamanho_Fila(fi); k++) {
          int idx = (2 + k) % 4;
        printf("a%d%s",
               (idx == 2) ? 3 : (idx == 3) ? 9 : (idx == 0) ? 7 : 6,
               (k + 1 < tamanho_Fila(fi)) ? ", " : "\n");
    }
      printf("Aluno copiado para al: matricula %d (%s)\n", al.matricula, al.nome);

      libera_Fila(fi);
    return 0;
}