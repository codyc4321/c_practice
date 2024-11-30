#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size;

    printf("Enter the size: ");
    scanf("%d", &size);
    
    arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i=0; i < size; i++) {
        arr[i] = i;
    }

    for (int i=0; i < size; i++) {
        printf("item %d ", arr[i]);
    }

    free(arr);

    return 0;
}