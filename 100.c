#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sortDigit(int num, int asc);
int exponential(int base, int exp);
int nDigits(int num);
int kaprekar(int num);

int main() {
    int nPruebas;
    scanf("%d", &nPruebas);

    int input;
    int* output = (int*) malloc(sizeof(int)*nPruebas);
    int i = 0;
    while (i < nPruebas) {
        scanf("%d", &input);
        *(output + i++) = kaprekar(input);
    }
    for (i = 0; i < nPruebas; i++) {
        printf("%d\n", output[i]);
    }

    return 0;
}



int sortDigit(int num, int asc) {
    float result = 0;
    int exp = 0;
    int i;
    int temp;

    if (!asc && nDigits(num) < 4) {
        while (nDigits < 4) {
            num *= 10;
        }
    }

    for (i = 0; i <= 9; i++) {
        for (temp = num; temp > 0; temp /= 10) {
            if (temp%10 == i) {
                if (asc) {
                    result *= 10;
                    result += i;
                } else {
                    result += i*exponential(10, exp);
                    exp++;
                }
            }
        }
    }
    return result;
}

int exponential(int base, int exp) {
    int result = 1;
    int i;
    for (i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int nDigits(int num) {
    return floor(log10(abs(num))) + 1;
}

int kaprekar(int num) {
    int iter = 0;
    if (num == 6174) return 0;
    while (num != 6174) {
        if (num == 0) return 8;
        num = sortDigit(num, 0) - sortDigit(num, 1);
        iter++;
    }
    return iter;
}