// https://www.aceptaelreto.com/problem/statement.php?id=621

#include <stdio.h>

int pagina(int num);

int main() {
    int nPruebas;
    
    int n;
    int* output = (int*) calloc(1, sizeof(int));

    int c = 0;
    int i;

    scanf("%d", &nPruebas);
    while (nPruebas-- > 0) {
        scanf("%d", &n);
        *(output + c++) = pagina(n);
        output = realloc(output, (c+1)*sizeof(int));
    }
    for (i = 0; i < c; i++) {
        printf("%d\n", output[i]);
    }

    free(output);

    return 0;
}

int pagina(int num) {
    return (num%2 == 0) ? num+1 : num-1;
}