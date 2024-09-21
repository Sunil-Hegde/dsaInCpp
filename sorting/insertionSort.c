#include<stdio.h>

void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++){
        int key = array[i];
        int j = i-1;
        while(array[j] > key && j>=0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    for(int i = 0;i<size;i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter unsorted elements: \n");
    for(int i = 0; i < n;i++){
        scanf("%d", &array[i]);
    }
    printf("\nElements in unsorted array:\n");
    for(int i = 0;i < n;i++){
        printf("%d ", array[i]);
    }

    printf("\n\nAfter sorting using Insertion Sort:\n");
    insertionSort(array, n); 
    return 0;
}