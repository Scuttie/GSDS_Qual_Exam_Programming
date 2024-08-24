#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
// 상속 / virtual 함수 사용
//g++ -o oop oop.cpp
using namespace std;

// 추상 클래스는 하나 이상의 가상 함수를 포함 
class Shape {
    protected:

    public:
        Shape() {}
        virtual ~Shape() {}

        virtual double calc_area() = 0;
        virtual string get_name(){return "Shape";}

};


class Rectangle : public Shape{

    public:
        Rectangle(double w, double h) : width(w), height(h) {}
        virtual ~Rectangle() {}

        double width;
        double height;

        string get_name() override { return "Rectangle"; }
        double calc_area() override { return width * height; }
};

class Triangle : public Shape{

    public:
        Triangle(double A, double B, double C) : a(A), b(B), c(C) {}
        virtual ~Triangle() {}

        double a;
        double b;
        double c;

        string get_name() override { return "Triangle"; }
        double calc_area() override { 
            double s = (a+b+c)/2.;
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }
};

class RightTriangle : public Triangle{

    public:
        RightTriangle(double A, double B) : Triangle(A,B, sqrt(pow(A,2)+pow(B,2))), a(A), b(B) {}
        virtual ~RightTriangle() {}

        double a;
        double b;


        string get_name() override { return "RightTriangle"; }
        double calc_area() override {return (a*b)/2;}
};

int main (){
    //g++ -o oop oop.cpp
    //./oop.exe
    Rectangle rect(10,10);
    cout << "Name: " << rect.get_name() << ", Weight: " << rect.calc_area() << endl;
    
    Triangle tri(10,10,10);
    cout << "Name: " << tri.get_name() << ", Weight: " << tri.calc_area() << endl;

    RightTriangle Rtri(10, 10);
    cout << "Name: " << Rtri.get_name() << ", Weight: " << Rtri.calc_area() << endl;

}