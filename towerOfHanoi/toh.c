#include<stdio.h>

void towerOfHanoi(int discs, char source, char temp, char destination){
    if(discs>0){
        towerOfHanoi(discs-1, source, temp, destination);
        printf("\tMove disk %d from %c to %c.\n",discs,source,destination);
        towerOfHanoi(discs-1, temp, destination, source);
    }

    return;
}

int main(){
    int numberOfDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numberOfDisks);
    printf("\nSteps to solve Tower of Hanoi problem:\n\n");
    towerOfHanoi(numberOfDisks, 's', 't', 'd');
    printf("\n");
    return 0;
}