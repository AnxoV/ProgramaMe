// https://www.aceptaelreto.com/problem/statement.php?id=441

#include <stdio.h>
#include <string.h>

char *contarUnoMas(char *numero);

int main() {    
    char *num;

    int c = 0;
    int i;

    while (1) {
        scanf("%s", num);
        printf("%s\n", contarUnoMas(num));
    }

    free(num);

    return 0;
}

char *contarUnoMas(char *numero) {
    char **buffer = (char**) calloc(strlen(numero)%3+1, sizeof(char));
    char *resultado = (char*) calloc(strlen(numero)+2, sizeof(char));
    int curr, next;

    int c = 0;
    int i;
    
    char *token = strtok(numero, ".");
    while (token) {
        *(buffer + c++*3) = token;
        token = strtok(NULL, ".");
    }

    for (i = c-1; i >= 0; i--) {
        curr = (int) strtol(buffer[i*3], NULL, 10);
        if (curr+1 < 1000 && i == c-1) {
            sprintf(buffer[i*3], "%d", curr+1);
        } else if (curr+1 >= 1000) {
            buffer[i*3] = "000";
            sprintf(buffer[(i-1)*3], "%d", (int) strtol(buffer[(i-1)*3], NULL, 10)+1);
        }
    }

    for (i = 0; i < c; i++) {
        strcat(resultado, buffer[i*3]);
        if (i < c-1)
            strcat(resultado, ".");
    }

    free(buffer);

    return resultado;
}