#include "QE_prob3.hpp"
#include <iostream>

int main() {
    // Vector2D 기능 테스트
    Vector2D a(3, 4);
    Vector2D b(3, 4);

    std::cout << "a.getX() = " << a.getX() << std::endl;
    std::cout << "a.getY() = " << a.getY() << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "|a| = " << a.magnitude() << std::endl;
    std::cout << "norm(a) = " << *a.normalize() << std::endl;  // normalize()는 new로 할당된 포인터 반환

    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << std::boolalpha; // bool을 true/false로 출력
    std::cout << "a == b = " << (a == b) << std::endl;

    // Vector3D 기능 테스트
    Vector3D c(1, 2, 3);
    Vector3D d(1, 2, 3);

    std::cout << "\nc = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "c + d = " << c + d << std::endl;
    std::cout << "c - d = " << c - d << std::endl;
    std::cout << "c * d = " << c * d << std::endl;
    std::cout << "c == d = " << (c == d) << std::endl;

    return 0;
}
