#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int maximum(int *array, int size){
    int maxNum = array[0]; 
    for (int i = 1; i < size; i++){
        if (array[i] > maxNum){
            maxNum = array[i];
        }
    }
    return maxNum;
}

void countSort(int *array, int size, int pos){
    int count[10] = {0};
    int *output = (int *)malloc(size * sizeof(int)); 

    for(int i = 0; i < size; i++){
        count[(array[i] / pos) % 10]++;
    }

    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--){
        output[count[(array[i] / pos) % 10] - 1] = array[i];
        count[(array[i] / pos) % 10]--;
    }

    for(int i = 0; i < size; i++){
        array[i] = output[i];
    }

    free(output); 
}

void radixSort(int *array, int size){
    int max = maximum(array, size);
    for(int pos = 1; max / pos > 0; pos *= 10){
        countSort(array, size, pos);
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter unsorted elements: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    printf("\nElements in unsorted array:\n");
    printArray(array, n);

    printf("After sorting using Radix Sort:\n");
    radixSort(array, n);
    printArray(array, n);
    return 0;
}
