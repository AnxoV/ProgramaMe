// https://www.aceptaelreto.com/problem/statement.php?id=439

#include <stdio.h>
#include <string.h>

char *cinematica(char char1, int num1, char char2, int num2);

int main() {
    int nPruebas;
    
    char char1, char2;
    int num1, num2;
    int *output = (int*) calloc(1, sizeof(int));

    int c = 0;
    int i;

    scanf("%d", &nPruebas);
    while (nPruebas-- > 0) {
        scanf(" %c=%d %c=%d", &char1, &num1, &char2, &num2);
        *(output + c++) = cinematica(char1, num1, char2, num2);
        output = realloc(output, (c+1)*sizeof(int));
    }
    for (i = 0; i < c; i++) {
        printf("%s\n", output[i]);
        free(output[i]);
    }

    free(output);

    return 0;
}

char *cinematica(char char1, int num1, char char2, int num2) {
    char *resultado = calloc(25, sizeof(char));
    char *operacion = calloc(10, sizeof(char));
    if (char1 == 'D' && char2 == 'T') {
        strcpy(resultado, "V=");
        sprintf(operacion, "%d", (int) (num1/num2));
    } else if (char1 == 'T' && char2 == 'D') {
        strcpy(resultado, "V=");
        sprintf(operacion, "%d", (int) (num2/num1));
    } else if (char1 == 'D' && char2 == 'V') {
        strcpy(resultado, "T=");
        sprintf(operacion, "%d", (int) (num1/num2));
    } else if (char1 == 'V' && char2 == 'D') {
        strcpy(resultado, "T=");
        sprintf(operacion, "%d", (int) (num2/num1));
    } else if (char1 == 'T' && char2 == 'V') {
        strcpy(resultado, "D=");
        sprintf(operacion, "%d", num1*num2);
    } else if (char1 == 'V' && char2 == 'T') {
        strcpy(resultado, "D=");
        sprintf(operacion, "%d", num2*num1);
    }
    strcat(resultado, operacion);
    free(operacion);
    return resultado;
}