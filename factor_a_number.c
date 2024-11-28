#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
Goal is to factor a number "factorable" where 

    int factorable = 60;
    array factor_this_num(factorable) {
        return [2, 2, 3, 5];
    }
    
but how do this in C? hmm

starting with the lowest prime number, 2, try to divide factorable by 2
if factorable is divisible by 2, add 2 to the array of factors, and set factorable to 30 (use recursion?!?)
again, reset the divisor to the lowest prime 2. continue attempting to factor:
    factors = [2, 2]
now try 2, but 15/2 returns 7.5 which is_integer() says is false, therefore 2 is not a divisor
now increment divisor to 3, which works
    factors = [2, 2, 3]
repeat this process until factorable (5) / divisor (5) returns 1
this tells us that the process is over

remember, each time we increment to try to divide factorable by a prime, we have to use is_prime()
to check if this new number is a prime to factor it correctly.

IF factorable = 17 and all numbers up to and including 16 fail, once we increment and divisor == factorable,
we can return result -1 instead of an array, or ask Dr. Peter return empty array to say prime?

*/

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

    float prime_divisor_second = 2;
    float divided_second = possible_prime / prime_divisor_second;
    bool is_divisible_second = is_integer(divided_second);
    if (is_divisible_second) {
        return false;
    } else {
        return true;
    }
}


int main() {

    /*
    float not_integer = 87.001f;
    bool is_it_huh = is_integer(not_integer);
    // https://stackoverflow.com/questions/17307275/what-is-the-printf-format-specifier-for-bool
    printf("Is integer returned %s", is_it_huh ? "true" : "false");
    */
    
   printf("hello world\n");
//    fflush(stdout);

    float not_prime_1 = 4;
    bool prime_result_1 = is_prime(not_prime_1);
    printf("Is %f prime? %s\n", not_prime_1, prime_result_1 ? "yes" : "no");
    // fflush(stdout);

    float not_prime_2 = 9;
    bool prime_result_2 = is_prime(not_prime_2);
    printf("Is %f prime? %s\n", not_prime_2, prime_result_2 ? "yes" : "no");
    fflush(stdout);

    // float maybe_prime = 87;
    // bool prime_result = is_prime(maybe_prime);
    // printf("Is %d prime? %s", maybe_prime, prime_result ? "yes" : "no");

    /*
    if (prime_huh) {
        printf("Yes, it was prime");
    } else {
        printf("No, not prime.");
    }
    */

   return 0;
}