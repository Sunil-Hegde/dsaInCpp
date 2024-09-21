#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10
int head = -1, tail = -1;

void insert(int queue[], int number){
    if ((tail + 1) % QUEUE_SIZE == head) {
        printf("Queue is full.\n");
        return;
    }
    if (head == -1 && tail == -1){
        head = tail = 0;
    } else {
        tail = (tail + 1) % QUEUE_SIZE;
    }
    queue[tail] = number;
}

void removeFromQueue(int queue[]){
    if (head == -1 && tail == -1){
        printf("Queue is empty.\n");
    } else if (head == tail){
        int number = queue[head];
        printf("%d removed successfully from the queue.\n", number);
        head = tail = -1;
    } else {
        int number = queue[head];
        printf("%d removed successfully from the queue.\n", number);
        head = (head + 1) % QUEUE_SIZE;
    }
}

void display(int queue[]){
    if (head == -1 && tail == -1){
        printf("Queue is Empty.\n");
    } else {
        printf("Elements of the queue are:\n");
        int i = head;
        while (1) {
            printf("\t%d\n", queue[i]);
            if (i == tail) break;
            i = (i + 1) % QUEUE_SIZE;
        }
    }
}

int main(){
    int queue[QUEUE_SIZE];
    while(1){
        int choice, number;
        printf("\nQueue Operations:\n\t1. Insert\n\t2. Remove\n\t3. Display\n\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &number);
                insert(queue, number);
                break;
            case 2:
                removeFromQueue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
