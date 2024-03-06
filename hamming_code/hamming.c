#include <stdio.h>
#include <math.h>

#define WORD_SIZE 12

int calculateParity(int m) {
    int p = 0;
    while (pow(2, p) < (m + p) + 1) {
        p++;
    }
    return p;
}

int main() {

    int p = calculateParity(WORD_SIZE);

    printf("Para uma informação de %d bits, precisaremos de %d paridades", WORD_SIZE, p);

    return 0;
}
