// https://www.aceptaelreto.com/problem/statement.php?id=216

#include <stdio.h>

char *gotera(int s);

int main() {
    int nPruebas;
    
    int s;
    int* output = (int*) calloc(1, sizeof(int));

    int c = 0;
    int i;

    scanf("%d", &nPruebas);
    while (nPruebas-- > 0) {
        scanf("%d", &s);
        *(output + c++) = gotera(s);
        output = realloc(output, (c+1)*sizeof(int));
    }
    for (i = 0; i < c; i++) {
        printf("%s\n", output[i]);
        free(output[i]);
    }

    free(output);

    return 0;
}

char *gotera(int s) {
    char *resultado = calloc(9, sizeof(char));
    sprintf(resultado, "%02d:%02d:%02d", s/3600, s/60%60, s%60);
    return resultado;
}