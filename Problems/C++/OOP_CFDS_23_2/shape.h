
#pragma once

#include <iomanip>

class Shape{
    protected: // derived class, public & protected member만 inherit 받음
        float length;
    public:
        Shape(float length) : length(length){}
        virtual ~Shape(){}
        virtual float area() = 0; // pure virtual function : child class 무조건 Override 해야 함
        void print(); // non-virtual function 
};                    // : derived class에서 override하지 않으면 parent class의 function이 불려짐

class Square : public Shape {
    public:
        Square(float length) : Shape(length){}
        virtual float area() override;
        void print();
};

class Equilateral : public Shape {
    public:
        Equilateral(float length) : Shape(length){}
        virtual float area() override;
        void print();
};