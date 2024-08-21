#include <stdio.h>

int main() {
    // 1. If Statement
    int num = 10;
    if (num > 5) {
        printf("Number is greater than 5\n");
    }

    // 2. If-Else Statement
    num = 3;
    if (num > 5) {
        printf("Number is greater than 5\n");
    } else {
        printf("Number is 5 or less\n");
    }

    // 3. Switch Statement
    char keyPress = 'b';
    switch (keyPress) {
        case 'a':
            printf("You pressed A\n");
            break;
        case 'b':
            printf("You pressed B\n");
            break;
        default:
            printf("Unknown key\n");
            break;
    }

    // 4. While Statement
    int i = 0;
    while (i < 5) {
        printf("While Loop: i = %d\n", i);
        i++;
    }

    // 5. Do-While Statement
    i = 0;
    do {
        printf("Do-While Loop: i = %d\n", i);
        i++;
    } while (i < 5);

    // 6. For Statement
    for (i = 0; i < 5; i++) {
        printf("For Loop: i = %d\n", i);
    }

    // 7. Break Statement in a loop
    for (i = 0; i < 10; i++) {
        if (i == 5) {
            break;  // Exits the loop when i equals 5
        }
        printf("Break Example: i = %d\n", i);
    }

    // 8. Continue Statement in a loop
    for (i = 0; i < 10; i++) {
        if (i == 5) {
            continue;  // Skips the rest of the loop body when i equals 5
        }
        printf("Continue Example: i = %d\n", i);
    }

    return 0;
}
