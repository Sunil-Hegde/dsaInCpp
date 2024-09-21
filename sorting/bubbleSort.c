#include<stdio.h>

void bubbleSort(int array[], int size){
    int temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size -1 - i; j++){
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
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

    printf("\n\nAfter sorting using Bubble Sort:\n");
    bubbleSort(array, n); 
    return 0;
}