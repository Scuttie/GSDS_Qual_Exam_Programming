#include <stdio.h>

// Swap function without pointers (incorrect swap)
void swap_without_pointers(int a, int b) {
    printf("Inside swap_without_pointers:\n");
    printf("Address of a (local copy of x): %p\n", (void*)&a);
    printf("Address of b (local copy of y): %p\n", (void*)&b);
    printf("Values before swap: a = %d, b = %d\n", a, b);
    
    int temp = a;
    a = b;
    b = temp;
    
    printf("Values after swap: a = %d, b = %d\n", a, b);
    printf("Addresses after swap remain the same:\n");
    printf("Address of a: %p\n", (void*)&a);
    printf("Address of b: %p\n", (void*)&b);
    printf("\n");
}

// Swap function with pointers (correct swap)
void swap_with_pointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;

    // Initial values and addresses
    printf("Before swap (initial values):\n");
    printf("x = %d, y = %d\n", x, y);
    printf("Address of x: %p\n", (void*)&x);
    printf("Address of y: %p\n\n", (void*)&y);

    // Attempt to swap without pointers
    swap_without_pointers(x, y);
    printf("After swap_without_pointers (back in main):\n");
    printf("x = %d, y = %d\n", x, y);  // Values remain unchanged
    printf("Address of x: %p\n", (void*)&x);
    printf("Address of y: %p\n\n", (void*)&y);

    // Correct swap with pointers
    swap_with_pointers(&x, &y);
    printf("After swap_with_pointers:\n");
    printf("x = %d, y = %d\n", x, y);  // Values are swapped
    printf("Address of x: %p\n", (void*)&x);
    printf("Address of y: %p\n", (void*)&y);

    return 0;
}
