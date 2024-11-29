#include <stdio.h>


// page 164
// https://books.google.pt/books?id=qjUqDwAAQBAJ&pg=PA156&dq=size_t+array+index&hl=en&sa=X&ved=0ahUKEwiJv9WK5dHnAhV15OAKHbxhC2kQ6AEIOzAC#v=onepage&q=size_t%20array%20index&f=false

int array[] = {1, 2, 3, 4, 5};

void array_sum(void) {
    size_t i;
    int sum = 0;
    for (i=0; i < sizeof(array)/sizeof(int); i++) {
        sum = sum + array[i];
    }
    printf("The sum is: %d\n", sum);
}

int main(int argc, char** argv) {
    array_sum();
    return 0;
}