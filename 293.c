// https://www.aceptaelreto.com/problem/statement.php?id=293

#include <stdio.h>

int artropodos(int ins, int arac, int crust, int esc, int an);

int main() {
    int nPruebas;
    
    int ins, arac, crust, esc, an;
    int* output = (int*) calloc(1, sizeof(int));

    int c = 0;
    int i;

    scanf("%d", &nPruebas);
    while (nPruebas-- > 0) {
        scanf("%d %d %d %d %d", &ins, &arac, &crust, &esc, &an);
        *(output + c++) = artropodos(ins, arac, crust, esc, an);
        output = realloc(output, (c+1)*sizeof(int));
    }
    for (i = 0; i < c; i++) {
        printf("%d\n", output[i]);
    }

    free(output);

    return 0;
}

int artropodos(int ins, int arac, int crust, int esc, int an) {
    return 6*ins + 8*arac + 10*crust + 2*esc*an;
}