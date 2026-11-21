#include <stdio.h>
#include "PilhaSequencial.h"

   int sequencia_valida(const char *s) {
      if (s == NULL)
          return 0;

    int altura = 0;
       for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'I') {
              altura++;
        } else if (s[i] == 'R') {
            if (altura == 0)
                  return 0;
            altura--;
        }   else {
            return 0;
        }
    }
      return (altura == 0);
}

static void simula_item_a(const char *seq) {
    Pilha *pi = cria_Pilha(4);
      if (pi == NULL)
        return;

    int proximo = 1;
      struct aluno al;
    int primeiro = 1;

    printf("Simulacao de %s -> saida: ", seq);
      for (int i = 0; seq[i] != '\0'; i++) {
        if (seq[i] == 'I') {
            al.matricula = proximo++;
               snprintf(al.nome, sizeof(al.nome), "Valor %d", al.matricula);
              al.n1 = 0.0f;
            al.n2 = 0.0f;
             al.n3 = 0.0f;
            insere_Pilha(pi, al);
        }   else if (seq[i] == 'R') {
            if (consulta_topo_Pilha(pi, &al)) {
                  remove_Pilha(pi);
                  if (!primeiro)
                     printf(", ");
                printf("%d", al.matricula);
                   primeiro = 0;
            }
        }
    }
       printf("\n\n");
       libera_Pilha(pi);
}

  static void testa_sequencia(const char *s) {
    printf("sequencia_valida(\"%s\") -> %d\n", s ? s : "NULL", sequencia_valida(s));
}

  int main(void) {
    simula_item_a("IIRIIRRR");

      testa_sequencia("IRIIRR");
    testa_sequencia("IRRI");
       testa_sequencia("IIRIIRRR");
    testa_sequencia("IIIR");
     testa_sequencia("R");
    testa_sequencia("");
    testa_sequencia("IRX");
    testa_sequencia(NULL);

    return 0;
}