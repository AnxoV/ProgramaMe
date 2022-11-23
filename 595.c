// https://www.aceptaelreto.com/problem/statement.php?id=595

#include <stdio.h>
#include <math.h>

int volumen(int num);

int main() {
    int nPruebas;
    
    int num;
    int* output = (int*) calloc(1, sizeof(int));

    int c = 0;
    int i;

    scanf("%d", &nPruebas);
    while (nPruebas-- > 0) {
        scanf("%d", &num);
        *(output + c++) = volumen(num);
        output = realloc(output, (c+1)*sizeof(int));
    }
    for (i = 0; i < c; i++) {
        printf("%d\n", output[i]);
    }

    free(output);

    return 0;
}

int volumen(int num) {
    return round(num/100);
}