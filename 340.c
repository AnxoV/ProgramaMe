// https://www.aceptaelreto.com/problem/statement.php?id=340

#include <stdio.h>

int cerillas(int n, int m);

int main() {
    int nPruebas;
    
    int n, m;
    int* output = (int*) calloc(1, sizeof(int));

    int c = 0;
    int i;

    scanf("%d", &nPruebas);
    while (nPruebas-- > 0) {
        scanf("%d %d", &n, &m);
        *(output + c++) = cerillas(n, m);
        output = realloc(output, (c+1)*sizeof(int));
    }
    for (i = 0; i < c; i++) {
        printf("%d\n", output[i]);
    }

    free(output);

    return 0;
}

int cerillas(int n, int m) {
    return 2*n+2*m+n*(m-1)+m*(n-1);
}