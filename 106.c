// https://www.aceptaelreto.com/problem/statement.php?id=106

#include <stdio.h>
#include <math.h>
#include <string.h>

char* codigoBarras(char* codigo);

int main() {
    printf("%s", codigoBarras("5029365779425"));
    /*int codigo;
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

char* codigoBarras(char* codigo) {
    int sum = 0;
    int control = (int) strtol(codigo[strlen(codigo)-1], NULL, 10)%10;
    int temp = codigo/10;
    int est = 0;

    char* resultado = calloc(3, sizeof(char));
    char string[50];

    while (temp > 0) {
        sum += (est == 0) ? (temp%10)*3 : temp%10;
        est = (est == 0) ? 1 : 0;
        temp /= 10;
    }
    sum = ((sum / 1) % 10 == 0) ? 0 : 10 - ((sum / 1) % 10);

    resultado = (sum == control) ? "SI" : "NO";

    printf("%d %d %d", codigo);

    if (log10(codigo)+1 == 13 && strncmp(resultado, "NO", 2) != 0) {
        sprintf(string, "%d", codigo);
        if (strncmp(string, "0", 1) == 0) strcpy(string, "EEUU");
        else if (strncmp(string, "50", 1) == 0) strcpy(string, " Inglaterra");
        strcat(resultado, string);
    }

    return resultado;
}