// https://www.aceptaelreto.com/problem/statement.php?id=370

#include <stdio.h>

char* treceCatorce(int a, int b);

int main(void) {
    int nPruebas;
    
    int a, b;
    int* output = (int*) calloc(1, sizeof(int));

    int c = 0;
    int i;

    scanf("%d", &nPruebas);
    while (nPruebas-- > 0) {
        scanf("%d-%d", &a, &b);
        *(output + c++) = treceCatorce(a, b);
        output = realloc(output, (c+1)*sizeof(int));
    }
    for (i = 0; i < c; i++) {
        printf("%s\n", output[i]);
    }

    free(output);

    return 0;
}

char* treceCatorce(int a, int b) {
    if ((a < b && a % 2 == 0 && a+1 == b) || (b < a && b % 2 == 0 && b+1 == a))
        return "SI";
    return "NO";
}