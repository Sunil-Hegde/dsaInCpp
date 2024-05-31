#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int maximum(int *array, int size) {
    int maxNum = array[0]; 
    for(int i = 1; i < size; i++) {
        if(array[i] > maxNum) {
            maxNum = array[i];
        }
    }
    return maxNum;
}

void countSort(int *array, int size) {
    int i, j;
    int max = maximum(array, size);
    int *count = (int *)calloc(max + 1, sizeof(int));
    if (count == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for(i = 0; i < size; i++) {
        count[array[i]]++;
    }

    i = 0;
    for(j = 0; j <= max; j++) {
        while(count[j] > 0) {
            array[i++] = j;
            count[j]--;
        }
    }

    free(count); 
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter unsorted elements: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("\nElements in unsorted array:\n");
    printArray(array, n);

    printf("After sorting using Count Sort:\n");
    countSort(array, n);
    printArray(array, n);
    return 0;
}
