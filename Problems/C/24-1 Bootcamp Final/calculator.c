#include <stdio.h>
#include <stdlib.h>

void calculator(char op, float a, float b){
    /* implement here */
    switch (op) {
        case '+':
            printf("%.1f\n", a + b);
            break;
        case '-':
            printf("%.1f\n", a - b);
            break;
        case 'x':
            printf("%.1f\n", a * b);
            break;
        case '/':
            if (b != 0)
                printf("%.1f\n", a / b);
            else
                printf("Invalid\n");
            break;
        default:
            printf("Invalid\n");
    }
}

/*Do not modify below*/

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("Invalid output");
        return 0;
    }

    char* op = argv[1];
    float a = atof(argv[2]);
    float b = atof(argv[3]);
    calculator(*op, a, b);
    return 0;
}
