// https://www.aceptaelreto.com/problem/statement.php?id=540

#include <stdio.h>

char* hueco_escalera(int p, int e, int pC, int eC);

int main(void) {
    int nPruebas;
    
    int p, e, pC, eC;
    int* output = (int*) calloc(1, sizeof(int));

    int c = 0;
    int i;

    scanf("%d", &nPruebas);
    while (nPruebas-- > 0) {
        scanf("%d %d %d %d", &p, &e, &pC, &eC);
        *(output + c++) = hueco_escalera(p, e, pC, eC);
        output = realloc(output, (c+1)*sizeof(int));
    }
    for (i = 0; i < c; i++) {
        printf("%s\n", output[i]);
    }

    free(output);

    return 0;
}

char* hueco_escalera(int p, int e, int pC, int eC) {
    char* resultado = (char*) malloc(50*sizeof(char));
    sprintf(resultado, "%d %d", pC*e+eC, pC*e+eC+p*e);
    return resultado;
}