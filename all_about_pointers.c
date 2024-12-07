#include <stdio.h>

int main() {
    int number = 42;

    // store a pointer
    int *address_of_number = &number;

    printf("The address of 'number' is: %p\n", &number);
    printf("The address of 'number' is: %p\n", address_of_number);
    printf("Dereferencing the pointer back to it's stored value: %d\n", *(&number));
    printf("Dereferencing the pointer back to it's stored value: %d\n", *address_of_number);

    char *alphabetAddress; // wild pointer
    char alphabet = 'a';
    alphabetAddress = &alphabet; // now, not a wild pointer
    // dereferencing a wild pointer before it has a value assigned will lead to unexpected
    // behavior, as we don't know if its memory block is free or not

    char *nullPointer = NULL; // making a null pointer protects us from that,
    // as noone can use the null pointer's address yet

    // void pointers bring flexibility in working will all types, but they must be type-casted
    void *voidPointer = NULL;
    int void_number = 54;
    char void_letter = 'z';
    voidPointer = &void_number;
    printf("The value of the void pointer number: %d\n", *(int *)voidPointer);
    voidPointer = &void_letter;
    printf("The value of the letter: %c", *(char *)voidPointer);
    return 0;
}