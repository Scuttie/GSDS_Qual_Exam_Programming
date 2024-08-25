#include "shape.h"
#include <iostream>
#include <math.h>

using namespace std;

void Shape::print(){
    cout << fixed << setprecision(6);
    cout << "This is Shape. Area is " << area() << endl; 
}

float Square::area(){
    return length * length; // length, Shape으로부터 상속되므로 함수에서 바로 access 가능
}

void Square::print(){
    cout << fixed << setprecision(6);
    cout << "This is Square. Area is " << area() << endl; 
}

float Equilateral::area(){
    return length * length * sqrt(3) / 4;;
}

void Equilateral::print(){
    cout << fixed << setprecision(6);
    cout << "This is Equilateral. Area is " << area() << endl; 
}
