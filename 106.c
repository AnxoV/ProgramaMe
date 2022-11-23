// https://www.aceptaelreto.com/problem/statement.php?id=106

#include <stdio.h>
#include <math.h>

char* codigoBarras(int codigo);

int main() {
    //printf("%s\n", codigoBarras(65839522));
    printf("%d", log10(10));
    /*
    int codigo;
    int* output = (int*) calloc(1, sizeof(int));
    
    short c = 0;
    short i;

    do {
        scanf("%d", &codigo);
        *(output + c++) = codigoBarras(codigo);
        output = realloc(output, (c+1)*sizeof(int));
    } while (codigo != 0);

    for (i = 0; i < c-1; i++) {
        printf("%d\n", output[i]);
    }

    free(output);

    return 0;*/
}

char* codigoBarras(int codigo) {
    int sum = 0;
    int control = codigo%10;
    int temp = codigo/10;
    int est = 0;

    char resultado[1024];

    while (temp > 0) {
        sum += (est == 0) ? (temp%10)*3 : temp%10;
        est = (est == 0) ? 1 : 0;
        temp /= 10;
    }
    sum = ((sum / 1) % 10 == 0) ? 0 : 10 - ((sum / 1) % 10);

    return "SI";
}