#include <stdio.h>

int main() {
    // 1. One Character I/O

    // putchar: single character output
    char ch = 'A';
    putchar(ch);
    putchar('\n'); // new line

    // getchar: single character input
    printf("Enter a character: ");
    ch = getchar();  // reads a single character
    printf("You entered: ");
    putchar(ch);
    putchar('\n'); // new line

    // 2. Buffered I/O
    // Buffered I/O is automatically handled by C's standard I/O functions like printf and scanf.
    
    // 3. Formatted I/O

    // printf: formatted output
    int num = 123;
    float pi = 3.14159;
    char str[] = "Hello, World!";
    printf("Integer: %d\n", num);
    printf("Float: %.2f\n", pi); // displays two decimal places
    printf("String: %s\n", str);

    // scanf: formatted input
    printf("Enter an integer: ");
    scanf("%d", &num);  // reads an integer
    printf("Enter a floating-point number: ");
    scanf("%f", &pi);  // reads a float
    printf("You entered integer: %d and float: %.2f\n", num, pi);

    // 4. File I/O

    // File pointer
    FILE *filePtr;

    // Opening a file in write mode
    filePtr = fopen("example.txt", "w");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Writing formatted data to a file
    fprintf(filePtr, "Integer: %d\n", num);
    fprintf(filePtr, "Float: %.2f\n", pi);
    fprintf(filePtr, "String: %s\n", str);
    
    // Closing the file after writing
    fclose(filePtr);

    // Reopening the file in read mode
    filePtr = fopen("example.txt", "r");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Reading and displaying data from the file
    int file_num;
    float file_pi;
    char file_str[50];

    fscanf(filePtr, "Integer: %d\n", &file_num);
    fscanf(filePtr, "Float: %f\n", &file_pi);
    fscanf(filePtr, "String: %s\n", file_str);

    printf("Data read from file:\n");
    printf("Integer: %d\n", file_num);
    printf("Float: %.2f\n", file_pi);
    printf("String: %s\n", file_str);

    // Closing the file after reading
    fclose(filePtr);

    return 0;
}
