#include <stdio.h>
#include <stdlib.h>

void writeToFile(char data[], const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Unable to open file for writing\n");
        exit(1);
    }
    fprintf(file, "%s", data);
    fclose(file);
}

void compareFiles(const char *input1, const char *input2, const char *output) {
    FILE *file1 = fopen(input1, "rb");
    FILE *file2 = fopen(input2, "rb");
    FILE *file3 = fopen(output, "wb");

    if (file1 == NULL || file2 == NULL || file3 == NULL) {
        printf("Unable to open one or more files\n");
        exit(1);
    }

    char ch1 = getc(file1);
    char ch2 = getc(file2);
    while (ch1 != EOF && ch2 != EOF) {
        if (ch1 != ch2) {
            fputc(ch2, file3);
        }
        ch1 = getc(file1);
        ch2 = getc(file2);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    FILE *fin3 = fopen(output, "rb");
    if (fin3 == NULL) {
        printf("Could not read from output file\n");
        exit(0);
    }

    int hasDifferences = 0;
    char ch3;
    while ((ch3 = getc(fin3)) != EOF) {
        if (!hasDifferences) {
            printf("Differences between file1 and file2 are:\n");
            hasDifferences = 1;
        }
        printf("%c", ch3);
    }
    printf("\n");

    if (!hasDifferences) {
        printf("No difference between file1 and file2\n");
    }

    fclose(fin3);
}

int main() {
    const char *inputFile1 = "file1.txt"; 
    const char *inputFile2 = "file2.txt"; 
    const char *outputFile = "file3.txt"; 
    char data1[30], data2[30];

    printf("Enter a line for File 1: ");
    gets(data1);
    printf("Enter a line for File 2: ");
    gets(data2);

    writeToFile(data1, inputFile1);
    writeToFile(data2, inputFile2);
    compareFiles(inputFile1, inputFile2, outputFile);

    return 0;
}
