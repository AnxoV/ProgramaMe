// https://www.aceptaelreto.com/problem/statement.php?id=184

#include <stdio.h>

char *dormir(int minutos);

int main() {
    int noches, minutos, temp;
    int hI, mI, hF, mF;
    int* output = (int*) calloc(1, sizeof(int));
    
    short c = 0;
    short i;

    do {
        scanf("%d", &noches);
        temp = noches;
        minutos = 0;
        while (temp -- > 0) {
            scanf("%d:%d-%d:%d", &hI, &mI, &hF, &mF);
            minutos += ((hI > hF) ? (24+hF)*60+mF : hF*60+mF) - (hI*60+mI);
        }

        *(output + c++) = dormir(minutos);
        output = realloc(output, (c+1)*sizeof(int));
    } while (noches != 0);


    for (i = 0; i < c-1; i++) {
        printf("%s\n", output[i]);
        free(output[i]);
    }

    free(output);

    return 0;
}

char *dormir(int minutos) {
    char *resultado = (char*) calloc(6, sizeof(char));
    sprintf(resultado, "%02d:%02d", minutos/60, minutos%60);
    return resultado;
}