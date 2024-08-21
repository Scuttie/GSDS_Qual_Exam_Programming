#include <stdio.h>

int main() {
    // 1. Array Basics
    int arr[5] = {10, 20, 30, 40, 50};
    printf("Array elements and their addresses:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, Address: %p\n", i, arr[i], (void*)&arr[i]);
    }
    printf("\n");

    // 2. Array Pointer
    int *arr_ptr = arr;  // Array name itself is a pointer to the first element
    printf("Array pointer (arr_ptr) pointing to arr[0]: %p\n", (void*)arr_ptr);
    printf("Dereferencing arr_ptr: %d\n\n", *arr_ptr);  // Should print the first element (10)

    // 3. Pointer Arithmetic
    printf("Pointer arithmetic:\n");
    printf("arr_ptr = %p, *arr_ptr = %d\n", (void*)arr_ptr, *arr_ptr);
    arr_ptr++;  // Move pointer to the next element
    printf("arr_ptr + 1 = %p, *(arr_ptr + 1) = %d\n", (void*)arr_ptr, *arr_ptr);  // Should print the second element (20)
    arr_ptr++;
    printf("arr_ptr + 2 = %p, *(arr_ptr + 2) = %d\n", (void*)arr_ptr, *arr_ptr);  // Should print the third element (30)
    printf("\n");

    // Resetting pointer to the start of the array
    arr_ptr = arr;
    
    // 4. Multi-Dimensional Array (2D Array)
    int multi_arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    printf("Multi-Dimensional Array elements and their addresses:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("multi_arr[%d][%d] = %d, Address: %p\n", i, j, multi_arr[i][j], (void*)&multi_arr[i][j]);
        }
    }
    printf("\n");

    // Accessing elements using a pointer to the first element
    int *ptr = &multi_arr[0][0];
    printf("Accessing Multi-Dimensional Array elements using pointer arithmetic:\n");
    for (int i = 0; i < 6; i++) {  // Flattened access to 2x3 array
        printf("*(ptr + %d) = %d, Address: %p\n", i, *(ptr + i), (void*)(ptr + i));
    }
    printf("\n");

    // 5. Pointer to Multi-Dimensional Array
    int (*multi_ptr)[3] = multi_arr;  // Pointer to an array of 3 integers
    printf("Pointer to multi-dimensional array (multi_ptr):\n");
    printf("multi_ptr = %p, *multi_ptr = %p\n", (void*)multi_ptr, (void*)(*multi_ptr));
    printf("Dereferencing multi_ptr: multi_ptr[0][0] = %d\n", (*multi_ptr)[0]);
    printf("Accessing next row using pointer: multi_ptr + 1 = %p, (*(multi_ptr + 1))[0] = %d\n", 
           (void*)(multi_ptr + 1), (*(multi_ptr + 1))[0]);

    // Accessing all elements using the pointer to the rows
    printf("\nAccessing all elements using row pointers:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("multi_ptr[%d][%d] = %d, Address: %p\n", i, j, multi_ptr[i][j], (void*)&multi_ptr[i][j]);
        }
    }
    printf("\n");

    // Understanding memory layout in multi-dimensional arrays
    printf("Memory layout in multi-dimensional array:\n");
    printf("Address of multi_arr: %p\n", (void*)multi_arr);
    printf("Address of multi_arr[0]: %p\n", (void*)multi_arr[0]);
    printf("Address of multi_arr[1]: %p\n", (void*)multi_arr[1]);
    printf("Size of each row (multi_arr[0]): %zu bytes\n", sizeof(multi_arr[0]));
    printf("Distance between multi_arr[0] and multi_arr[1]: %ld bytes\n",
           (char*)multi_arr[1] - (char*)multi_arr[0]);

    return 0;
}
