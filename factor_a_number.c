#include <stdio.h>
#include <stdbool.h>
#include <math.h>



bool is_integer(float possible_int) {
    // nice and clean solution (import math.h):
    // https://stackoverflow.com/questions/5796983/checking-if-float-is-an-integer
    bool is_an_int = ceilf(possible_int) == possible_int;
}

bool is_prime(float possible_prime) {
    // naive version: divides "possible_prime" by every number lower than itself,
    // while incrementing the divisor by 1 each time until we reach "possible_prime" argument
    // each time we divide, we check if the result is an int using "is_integer"
    // if "is_integer" returns true ever, than "possible_prime" was divisible by that divisor, hence
    // it cannot be a prime.
    // if we keep dividing and finally reach "possible_prime", then it actually is a prime! 
    // as it is only divisible by 1, and itself.
    // of course we have to start dividing by 2, the first prime number, 1 is not a prime.
    float prime_divisor = 2;
    float divided = possible_prime / prime_divisor;
    bool is_divisible = is_integer(divided);
    if (is_divisible) {
        return false;
    } else {
        return true;
    }
}


int main() {

    float not_integer = 87.001f;
    bool is_it_huh = is_integer(not_integer);
    // https://stackoverflow.com/questions/17307275/what-is-the-printf-format-specifier-for-bool
    printf("Is integer returned %s", is_it_huh ? "true" : "false");
    
    float maybe_prime = 87;
    bool prime_result = is_prime(maybe_prime);
    printf("Is %d prime? %s", maybe_prime, prime_result ? "yes" : "no");

    /*
    if (prime_huh) {
        printf("Yes, it was prime");
    } else {
        printf("No, not prime.");
    }
    */

   return 0;
}