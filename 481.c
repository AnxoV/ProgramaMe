// https://www.aceptaelreto.com/problem/statement.php?id=481

#include <stdio.h>
#include <math.h>

int main() {
    char* letras = "hgfedcba";

    int fila, columna;
    int* output = (int*) calloc(1, sizeof(int));
    
    short c = 0;
    short i;

    do {
        scanf("%d %d", &fila, &columna);
        *(output + c++) = fila*10 + columna;
        output = realloc(output, (c+1)*sizeof(int));
    } while (fila != 0 && columna != 0);



    for (i = 0; i < c-1; i++) {
        printf("%c%d\n", letras[(output[i]/10)-1], output[i]%10);
    }

    free(output);

    return 0;
}