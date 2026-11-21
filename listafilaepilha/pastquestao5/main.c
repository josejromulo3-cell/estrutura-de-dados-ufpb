#include <stdio.h>
#include <string.h>
 #include "PilhaChar.h"

   static int par_corresponde(char abre, char fecha) {
    return (abre == '(' && fecha == ')') ||
           (abre == '[' && fecha == ']') ||
           (abre == '{' && fecha == '}');
}

     int verifica_delimitadores(const char *expr) {
    if (expr == NULL)
        return 0;

    size_t len = strlen(expr);
    if (len == 0)
        return 1;

    Pilha *pi = cria_Pilha((int)len);
    if (pi == NULL)
        return 0;

    for (size_t i = 0; i < len; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
              if (!insere_Pilha(pi, ch)) {
                libera_Pilha(pi);
                return 0;
            }
        } else if (ch == ')' || ch == ']' || ch == '}') {
            char topo;
              if (!consulta_topo_Pilha(pi, &topo) || !par_corresponde(topo, ch)) {
                 libera_Pilha(pi);
                return 0;
            }
            remove_Pilha(pi);
        }
    }

    int valida = (Pilha_vazia(pi) == 1);
    libera_Pilha(pi);
       return valida;
}

   static void testa_expr(const char *expr) {
    printf("verifica_delimitadores(\"%s\") -> %d\n",
              expr ? expr : "NULL", verifica_delimitadores(expr));
}

   int main(void) {
    testa_expr("(())");
      testa_expr("()()");
    testa_expr("{a[b(c)d]e}");
    testa_expr(")(");
    testa_expr("(()(");
    testa_expr("([)]");
       testa_expr("");
    testa_expr("abc");
    testa_expr(NULL);
        return 0;
}