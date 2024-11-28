#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool is_integer(float possible_int) {
    bool is_an_int = ceilf(possible_int) == possible_int;
}

// float is_prime(float number) {
//     float prime_divisor = 2;
//     float divided = number / prime_divisor;
//     return divided;
// }

int main() {

    float not_integer = 87.001f;

    bool is_it_huh = is_integer(not_integer);

    printf("Is integer returned %s", not_integer ? "true" : "false");

    // float number_to_factor = 87;

    // float prime_huh = is_prime(number_to_factor);

    // printf("%f", prime_huh);

    /*
    if (prime_huh) {
        printf("Yes, it was prime");
    } else {
        printf("No, not prime.");
    }
    */
}