#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[20];
    unsigned int regNo;
} student;

void writeToFile(student *array, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open file for writing\n");
        exit(1);
    }
    fwrite(array, sizeof(student), count, file);
    fclose(file);
}

void readFromFile(student *array, int count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file for reading\n");
        exit(1);
    }
    fread(array, sizeof(student), count, file);
    fclose(file);
}

void displayStudents(student *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("\tReg. No: %d\n", array[i].regNo);
        printf("\tName: %s\n\n", array[i].name);
    }
}

int main() {
    int n;
    const char *filename = "students.txt"; 
    printf("Enter the number of student details to enter: ");
    scanf("%d", &n);

    student array[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("\tName: ");
        scanf("%s", array[i].name); 
        printf("\tReg. No: ");
        scanf("%u", &array[i].regNo);
    }

    writeToFile(array, n, filename);

    student readFile[n];
    readFromFile(readFile, n, filename);

    printf("Students read from file:\n");
    displayStudents(readFile, n);

    return 0;
}
