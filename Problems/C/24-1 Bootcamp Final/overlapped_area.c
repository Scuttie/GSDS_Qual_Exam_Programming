#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
}point;

typedef struct RectType{
    // p1 is the left top point of rectangle
    point p1;
    // p2 is the right bottom point of rectangle
    point p2;
}rect;

/* You can declare and use any new functions you create while implementing OverlappedArea(), 
but the final result must be returned by OverlappedArea(). */

float max(float a, float b) {
    return (a > b) ? a : b;
}

// a보다 b가 작으면 a, 아니면 b를 내뱉는 함수
float min(float a, float b) {
    return (a < b) ? a : b;
}

float OverlappedArea(rect r1, rect r2) {
    /*Write your code here*/
    //overlapped area는 다음과 같은 로직으로 생긴다.
    //x의 경우, 우하단 꼭지점의 x 좌표 중 더 작은 것 (더 왼쪽에 있는 것)과 좌상단 꼭지점의 x 좌표 중 더 큰 것 (더 오른쪽에 있는 것)의 차로 결정된다.
    //y의 경우, 좌상단 꼭지점의 x 좌표 중 더 작은 것 (더 아래에 있는 것)과 우하단 꼭지점의 y 좌표 중 더 큰 것 (더 위쪽에 있는 것)의 차로 결정된다.
    //최종 적으로 x * y overlap하면 넓이를 계산할 수 있다.
    float x_overlap = max(0, min(r1.p2.x, r2.p2.x) - max(r1.p1.x, r2.p1.x));
    float y_overlap = max(0, min(r1.p1.y, r2.p1.y) - max(r1.p2.y, r2.p2.y));
    
    return x_overlap * y_overlap;
    ///////////////////////
}


/*Do not modify below*/
int main(int argc, char* argv[]){
    if (argc != 9){
        printf("Invalid");
        return 0;
    }

    rect r1 = {{atof(argv[1]), atof(argv[2])}, {atof(argv[3]), atof(argv[4])}}; 
    rect r2 = {{atof(argv[5]), atof(argv[6])}, {atof(argv[7]), atof(argv[8])}};
    
    float overlapped = OverlappedArea(r1, r2);
    
    printf("The overlapped area of the two rectangles is: %.2f", overlapped);
    
    return 0;

}

