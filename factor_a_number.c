#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

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

bool is_float_prime(float possible_prime) {
    // naive version: divides "possible_prime" by every number lower than itself,
    // while incrementing the divisor by 1 each time until we reach "possible_prime" argument
    // each time we divide, we check if the result is an int using "is_integer"
    // if "is_integer" returns true ever, than "possible_prime" was divisible by that divisor, hence
    // it cannot be a prime.
    // if we keep dividing and finally reach "possible_prime", then it actually is a prime! 
    // as it is only divisible by 1, and itself.
    // of course we have to start dividing by 2, the first prime number, 1 is not a prime.
    float prime_divisor = 2;

    while (1) {
        float divided = possible_prime / prime_divisor;
        bool is_divisible = is_integer(divided);
        if (is_divisible) {
            return false;
        }
        prime_divisor++;
        if (prime_divisor == possible_prime) {
            return true;
        }
    }
}

bool is_integer_prime(int possible_prime) {
    // what happens if we use the same parameter name in a different function?
    int prime_divisor = 2;

    while (1) {
        int remainder = possible_prime % prime_divisor;
        // bool is_divisible = is_integer(divided);
        if (remainder == 0) {
            return false;
        }
        prime_divisor++;
        if (prime_divisor == possible_prime) {
            return true;
        }
    }
}

// https://stackoverflow.com/questions/3536153/c-dynamically-growing-array

//https://stackoverflow.com/questions/11656532/returning-an-array-using-c
void factor_any_number(int *factors, size_t factors_array_size, float number_to_divide) {
    /*
    for number_to_divide = 40;
    start with divisor = 2;
    divide number_to_divide by the divisor
    check if the result is an even number (is_integer())
    if so, add 2 to the factors array AND set number_to_divide to 20
        set divisor back to the bottom prime number (2)
    else, increment divisor to 3 and try again 
    wouldn't modulo be an easier and cleaner way to do this than changing between floats to ints?
    after each divisible, check if the number_to_divide is prime with is_prime()? would this
    flow be more performant? I think so maybe
    */
   int placeholder = 0;
}


void run_tests(void) {
        // https://stackoverflow.com/questions/17307275/what-is-the-printf-format-specifier-for-bool
    
    // write some ugly tests, can't get C Unit working yet need Dr. Dom
    float not_prime_1 = 4;
    assert(is_float_prime(not_prime_1) == false);
    float not_prime_2 = 9;
    assert(is_float_prime(not_prime_2) == false);
    float is_prime_1 = 17;
    assert(is_float_prime(is_prime_1));
    float is_prime_2 = 113;
    assert(is_float_prime(is_prime_2));

    int not_prime_int_1 = 4;
    assert(is_integer_prime(not_prime_int_1) == false);
    int not_prime_int_2 = 9;
    assert(is_integer_prime(not_prime_int_2) == false);
    int prime_int_1 = 113;
    assert(is_integer_prime(prime_int_1));
}

int main(int argc, char** argv) {

    run_tests();

    int command_line_arg = atoi(argv[1]);
    printf("You passed in number: %d\n", command_line_arg);

    bool is_it_prime = is_integer_prime(command_line_arg);
    if (is_it_prime) {
        printf("Yes, it is prime!");
    } else {
        printf("No, it isn't prime.");
    }
    return 0;
}