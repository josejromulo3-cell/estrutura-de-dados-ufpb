 #include <stdio.h>
#include "FilaEstatica.h"

static void mostra_fila(const char *titulo, Fila *fi) {
    struct aluno atual;
    int tam = tamanho_Fila(fi);
    printf("%s | qtd=%d | cheia=%d | vazia=%d\n",
           titulo, tam, Fila_cheia(fi), Fila_vazia(fi));
    if (tam > 0 && consulta_Fila(fi, &atual)) {
        printf("  inicio atual: matricula %d (%s)\n", atual.matricula, atual.nome);
    }
}

int main(void) {
    struct aluno a1 = {1, "Ana", 9.0f, 8.5f, 9.0f};
    struct aluno a2 = {2, "Bruno", 7.5f, 8.0f, 7.0f};
    struct aluno a3 = {3, "Carla", 8.5f, 9.0f, 8.5f};
      struct aluno a4 = {4, "Diego", 6.5f, 7.0f, 7.5f};
    struct aluno a5 = {5, "Elisa", 9.5f, 9.0f, 9.5f};

    Fila *fi = cria_Fila(3);
    mostra_fila("1. Fila vazia criada", fi);

      printf("fura_Fila em fila vazia -> %d\n", fura_Fila(fi, a1));
     mostra_fila("2. Apos fura_Fila(a1)", fi);

      printf("insere_Fila(a2) -> %d\n", insere_Fila(fi, a2));
    printf("insere_Fila(a3) -> %d\n", insere_Fila(fi, a3));
      mostra_fila("3. Fila cheia (a1 na frente, a2, a3)", fi);

    printf("fura_Fila em fila cheia -> %d\n", fura_Fila(fi, a4));
    mostra_fila("4. Apos tentativa de fura_Fila(a4) com fila cheia", fi);

    printf("remove_Fila -> %d\n", remove_Fila(fi));
      printf("remove_Fila -> %d\n", remove_Fila(fi));
     mostra_fila("5. Apos duas remocoes (resta a3)", fi);

       printf("fura_Fila(a5) com inicio != 0 -> %d\n", fura_Fila(fi, a5));
    mostra_fila("6. Apos fura_Fila(a5) (a5 na frente, depois a3)", fi);

    libera_Fila(fi);
       return 0;
}