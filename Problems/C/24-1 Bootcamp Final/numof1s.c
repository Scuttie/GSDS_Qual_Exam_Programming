#include <stdio.h>
#include <stdlib.h>


// Implement the function numOf1s() 
// that counts the number of 1s in the binary representation of the input n.
int numOf1s(int n){
    /*Write your code here*/
    int count = 0;
    //계속 2로 나누면서 나머지 1 생길때마다 count 1씩 증가시키면 됩니다.
    while (n > 0) {
        if (n % 2 == 1) {
            count++;
        }
        n = n / 2;
    }
    return count;

}

/*Do not modify below*/
int main(int argc, char * argv[]){
    if(argc!=4){
        printf("Invalid input!");
    }else{
        int a=atoi(argv[1]);
        int b=atoi(argv[2]);
        int c=atoi(argv[3]);
        printf("%d %d %d",numOf1s(a),numOf1s(b),numOf1s(c));
    }
    return 0;
}
