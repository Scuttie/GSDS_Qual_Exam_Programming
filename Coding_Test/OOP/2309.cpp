#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

class Shape {
public:
    // 순수 가상 함수 (추상 메서드)
    virtual double calc_area() = 0;

    // 가상 소멸자
    virtual ~Shape() {}

    // get_name() 멤버 함수
    virtual std::string get_name() {
        return "Shape";
    }
};

// --------------------------------------------------------------
// Rectangle 클래스
//  - Shape를 상속받는 구체 클래스
//  - 멤버 변수: double w, double h
// --------------------------------------------------------------
class Rectangle : public Shape {
protected:
    double w;
    double h;

public:
    // 생성자
    Rectangle(double width, double height)
        : w(width), h(height) {}

    // calc_area() 구현
    double calc_area() override {
        return w * h;
    }

    // get_name() 오버라이딩
    std::string get_name() override {
        return "Rectangle";
    }
};

// --------------------------------------------------------------
// Square 클래스
//  - Rectangle을 상속받는 구체 클래스
//  - 별도의 멤버 변수 선언 없음
// --------------------------------------------------------------
class Square : public Rectangle {
public:
    // 생성자(부모 클래스의 생성자를 활용)
    Square(double side)
        : Rectangle(side, side) {}

    // get_name() 오버라이딩
    std::string get_name() override {
        return "Square";
    }
};

// --------------------------------------------------------------
// Triangle 클래스
//  - Shape를 상속받는 구체 클래스
//  - 멤버 변수: double a, b, c
// --------------------------------------------------------------
class Triangle : public Shape {
protected:
    double a, b, c;

public:
    // 생성자
    Triangle(double A, double B, double C)
        : a(A), b(B), c(C) {}

    // calc_area() 구현 (헤론의 공식 사용)
    double calc_area() override {
        double s = (a + b + c) / 2.0;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // get_name() 오버라이딩
    std::string get_name() override {
        return "Triangle";
    }
};

// --------------------------------------------------------------
// RightTriangle 클래스
//  - Triangle을 상속받는 구체 클래스
//  - 멤버 변수는 추가로 선언하지 않음
// --------------------------------------------------------------
class RightTriangle : public Triangle {
public:
    // 생성자(부모 클래스의 생성자를 활용)
    // c 값은 sqrt(a^2 + b^2)
    RightTriangle(double A, double B)
        : Triangle(A, B, std::sqrt(A * A + B * B)) {}

    // calc_area() 오버라이딩
    double calc_area() override {
        // 직각삼각형 면적 = (a * b) / 2
        return (a * b) / 2.0;
    }

    // get_name() 오버라이딩
    std::string get_name() override {
        return "RightTriangle";
    }
};

int main() {
    // 문제 (f)
    // 모든 non-abstract 클래스 생성 후 함수 실행 예시

    // 1. Rectangle 생성 및 테스트
    Rectangle rect(2, 3);
    std::cout << "[" << rect.get_name() << "] "
              << "w=" << 2 << ", h=" << 3 << " --> area="
              << rect.calc_area() << std::endl;

    // 2. Square 생성 및 테스트
    Square sq(5);
    std::cout << "[" << sq.get_name() << "] "
              << "side=" << 5 << " --> area="
              << sq.calc_area() << std::endl;

    // 3. Triangle 생성 및 테스트
    Triangle tri(3, 4, 5);
    std::cout << "[" << tri.get_name() << "] "
              << "a=" << 3 << ", b=" << 4 << ", c=" << 5 << " --> area="
              << tri.calc_area() << std::endl;

    // 4. RightTriangle 생성 및 테스트
    RightTriangle rtri(3, 4);
    std::cout << "[" << rtri.get_name() << "] "
              << "a=" << 3 << ", b=" << 4
              << ", c=" << std::sqrt(3*3 + 4*4)
              << " --> area=" << rtri.calc_area() << std::endl;

    return 0;
}
