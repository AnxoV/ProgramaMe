// https://www.aceptaelreto.com/problem/statement.php?id=337

#include <stdio.h>
#include <string.h>

char *abuelaMaria(char* strAr, char* strAb);

int main() {
    int nPruebas;
    
    char dArriba[1024];
    char dAbajo[1024];
    int* output = (int*) calloc(1, sizeof(int));

    int c = 0;
    int i;

    scanf("%d", &nPruebas);
    while (nPruebas-- > 0) {
        scanf("\n%[^\n]", dArriba);
        scanf("\n%[^\n]", dAbajo);
        *(output + c++) = abuelaMaria(dArriba, dAbajo);
        output = realloc(output, (c+1)*sizeof(int));
    }
    for (i = 0; i < c; i++) {
        printf("%s\n", output[i]);
    }

    free(output);

    return 0;
}

char *abuelaMaria(char* strAr, char* strAb) {
    int ar, ab, last = NULL;

    int *bufferAr = (int*) calloc(1, sizeof(int));
    int *bufferAb = (int*) calloc(1, sizeof(int));
    char *tok = strtok(strAr, " ");

    int c = 0;
    int i;

    while (tok) {
        *(bufferAr + c++) = (int) strtol(tok, NULL, 10);
        bufferAr = realloc(bufferAr, (c+1)*sizeof(int));
        tok = strtok(NULL, " ");
    }

    c = 0;
    tok = strtok(strAb, " ");

    while (tok) {
        *(bufferAb + c++) = (int) strtol(tok, NULL, 10);
        bufferAb = realloc(bufferAb, (c+1)*sizeof(int));
        tok = strtok(NULL, " ");
    }

    for (i = 0; i < c; i++) {
        if (!last) {
            last = bufferAr[i]+bufferAb[i];
        } else if (last != bufferAr[i]+bufferAb[i]) {
            return "NO";
        }
    }

    free(bufferAr);
    free(bufferAb);

    return "SI";
}