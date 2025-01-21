#include <iostream>
#include <iomanip>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // 1. 기본 생성자(0 + 0i 로 초기화)
    Complex() : real(0.0), imag(0.0) {}
    
    // 2. 실수부, 허수부를 받는 생성자
    Complex(double r, double i) : real(r), imag(i) {}

    // Getter & Setter
    double getReal() const {
        return real;
    }
    double getImag() const {
        return imag;
    }
    void setReal(double r) {
        real = r;
    }
    void setImag(double i) {
        imag = i;
    }

    // 연산자 오버로딩

    // (1) + 연산자 오버로딩: 두 복소수 더하기
    Complex operator+(const Complex& other) const {
        Complex result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }

    // (2) 단항 - 연산자 오버로딩: 실수부와 허수부의 값을 서로 교환
    //    문제 설명에 따라, 원본 객체의 실수부와 허수부를 교환한 뒤 반환합니다.
    Complex operator-() {
        double temp = real;
        real = imag;
        imag = temp;
        return *this;
    }

    // (3) << 연산자 오버로딩: "a + bi" 형태로 출력
    //    friend 로 선언하여 private 멤버에 접근 가능
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

int main(void) {
    std::cout << std::fixed << std::setprecision(2);

    Complex c1(3.3, 2.6);
    Complex c2, c3;

    c2.setReal(7.89);
    c2.setImag(-9.21);

    // + 연산자 테스트
    c3 = c2 + c1;
    std::cout << "c3 = " << c3 << std::endl;
    std::cout << "Real part is " << c3.getReal() << std::endl;
    std::cout << "Imag part is " << c3.getImag() << std::endl;

    // 단항 - 연산자(스왑) 테스트
    std::cout << "\nBefore swap: c1 = " << c1 << std::endl;
    -c1; // c1의 실수부와 허수부가 서로 바뀜
    std::cout << "After swap : c1 = " << c1 << std::endl;

    return 0;
}
