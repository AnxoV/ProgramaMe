// https://www.aceptaelreto.com/problem/statement.php?id=368

#include <stdio.h>
#include <math.h>

int huevos(int h, int c);

int main() {
    int num1, num2;
    int* output = (int*) calloc(1, sizeof(int));
    
    short c = 0;
    short i;

    do {
        scanf("%d %d", &num1, &num2);
        *(output + c++) = huevos(num1, num2);
        output = realloc(output, (c+1)*sizeof(int));
    } while (num1 != 0 && num2 != 0);

    for (i = 0; i < c-1; i++) {
        printf("%d\n", output[i]);
    }

    free(output);

    return 0;
}

int huevos(int h, int c) {
    if (c == 0) return 0;
    return floor(h/c)*10 + ((h%c >= 1) ? 10 : 0);
}