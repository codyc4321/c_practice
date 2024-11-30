#include <stdio.h>
#include <stdlib.h>

int* factor_a_number(int num, int* number_of_factors) {

    int* factors = (int*)malloc(num * sizeof(int));

    if (factors == NULL) {
        *number_of_factors = 0;
        return NULL;
    }

    int index = 0;

    while (num % 2 == 0) {
        factors[index++] = 2;
        num /= 2;
    }

    for (int i=3; i * i <= num; i += 2) {
        while (num % i == 0) {
            factors[index++] = i;
            num /= i;
        }
    }

    if (num > 2) {
        factors[index++] = num;
    }

    *number_of_factors = index;

    factors = (int*)realloc(factors, index * sizeof(int));

    return factors;
}

int main() {
    int number, number_of_factors;
    int* factors;

    printf("Enter a number to factor: ");
    scanf("%d", &number);

    factors = factor_a_number(number, &number_of_factors);

    if (factors != NULL) {
        for (int i=0; i < number_of_factors; i++) {
            printf("%d ", factors[i]);
        }
    }
    printf("\n");

    free(factors);
}