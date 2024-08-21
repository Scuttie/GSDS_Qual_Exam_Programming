#include <stdio.h>

int main() {
    // 1. Assignment
    int A = 10;  // Assigns the value 10 to A
    int B = 5;
    A = B;       // Now A equals B (A = 5)
    printf("Assignment: A = %d\n", A);

    // 2. Arithmetic Operators
    int sum = A + B;    // Addition
    int diff = A - B;   // Subtraction
    int prod = A * B;   // Multiplication
    int quot = A / B;   // Division
    int mod = A % B;    // Modulus (remainder of division)
    printf("Arithmetic Operators: sum = %d, diff = %d, prod = %d, quot = %d, mod = %d\n", sum, diff, prod, quot, mod);

    // 3. Bitwise Operators
    int bit_and = A & B;  // Bitwise AND
    int bit_or = A | B;   // Bitwise OR
    int bit_xor = A ^ B;  // Bitwise XOR
    int bit_not = ~A;     // Bitwise NOT
    int bit_left_shift = A << 1;  // Left shift
    int bit_right_shift = A >> 1; // Right shift
    printf("Bitwise Operators: AND = %d, OR = %d, XOR = %d, NOT = %d, Left Shift = %d, Right Shift = %d\n", 
           bit_and, bit_or, bit_xor, bit_not, bit_left_shift, bit_right_shift);

    // 4. Logical Operators
    int logical_and = (A > 0) && (B > 0);  // Logical AND
    int logical_or = (A > 0) || (B < 0);   // Logical OR
    int logical_not = !(A > 0);            // Logical NOT
    printf("Logical Operators: AND = %d, OR = %d, NOT = %d\n", logical_and, logical_or, logical_not);

    // 5. Assignment with arithmetic or bitwise operators
    A += B;  // Equivalent to A = A + B
    printf("Assignment with Arithmetic Operator: A += B results in A = %d\n", A);

    A -= B;  // Equivalent to A = A - B
    printf("Assignment with Arithmetic Operator: A -= B results in A = %d\n", A);

    A *= B;  // Equivalent to A = A * B
    printf("Assignment with Arithmetic Operator: A *= B results in A = %d\n", A);

    A /= B;  // Equivalent to A = A / B
    printf("Assignment with Arithmetic Operator: A /= B results in A = %d\n", A);

    A %= B;  // Equivalent to A = A % B
    printf("Assignment with Arithmetic Operator: A %%= B results in A = %d\n", A);

    A &= B;  // Equivalent to A = A & B
    printf("Assignment with Bitwise Operator: A &= B results in A = %d\n", A);

    A |= B;  // Equivalent to A = A | B
    printf("Assignment with Bitwise Operator: A |= B results in A = %d\n", A);

    A ^= B;  // Equivalent to A = A ^ B
    printf("Assignment with Bitwise Operator: A ^= B results in A = %d\n", A);

    A <<= 1; // Equivalent to A = A << 1
    printf("Assignment with Bitwise Operator: A <<= 1 results in A = %d\n", A);

    A >>= 1; // Equivalent to A = A >> 1
    printf("Assignment with Bitwise Operator: A >>= 1 results in A = %d\n", A);

    // 6. Increment or Decrement
    int x = 5;
    printf("Initial value of x: %d\n", x);
    printf("Post-increment (x++): %d\n", x++);  // Prints x and then increments it
    printf("After post-increment, x: %d\n", x);
    
    x = 5;
    printf("Pre-increment (++x): %d\n", ++x);  // Increments x and then prints it

    x = 5;
    printf("Post-decrement (x--): %d\n", x--);  // Prints x and then decrements it
    printf("After post-decrement, x: %d\n", x);
    
    x = 5;
    printf("Pre-decrement (--x): %d\n", --x);  // Decrements x and then prints it

    return 0;
}
