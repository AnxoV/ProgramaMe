// https://www.aceptaelreto.com/problem/statement.php?id=368

#include <stdio.h>

int nochevieja(int horas, int minutos);

int main() {
    int horas, minutos;
    int* output = (int*) calloc(1, sizeof(int));
    
    short c = 0;
    short i;

    do {
        scanf("%d:%d", &horas, &minutos);
        *(output + c++) = nochevieja(horas, minutos);
        output = realloc(output, (c+1)*sizeof(int));
    } while (horas != 0 || minutos != 0);

    for (i = 0; i < c-1; i++) {
        printf("%d\n", output[i]);
    }

    free(output);

    return 0;
}

int nochevieja(int horas, int minutos) {
    return 1440-(horas*60+minutos);
}