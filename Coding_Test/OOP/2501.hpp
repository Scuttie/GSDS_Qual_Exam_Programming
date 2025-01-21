#ifndef QE_PROB3_H
#define QE_PROB3_H

#include <iostream>
#include <cmath>

// 2D 벡터 클래스
class Vector2D {
private:
    float x;
    float y;

public:
    // 생성자
    Vector2D(float xVal = 0.0f, float yVal = 0.0f)
        : x(xVal), y(yVal) {}

    // 소멸자(다형성 지원을 위해 가상 소멸자로 선언)
    virtual ~Vector2D() {}

    // x, y 게터
    float getX() const { return x; }
    float getY() const { return y; }

    // 2D 벡터의 크기 (magnitude)
    virtual float magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    // 벡터 정규화 (결과를 동적 할당하여 Vector2D* 형태로 반환)
    virtual Vector2D* normalize() const {
        float mag = magnitude();
        if (mag == 0.0f) {
            // 영벡터(0,0)를 normalize() 하면 다시 (0,0) 반환
            return new Vector2D(0.0f, 0.0f);
        }
        return new Vector2D(x / mag, y / mag);
    }

    // 벡터 덧셈
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // 벡터 뺄셈
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // 벡터 내적 (dot product)
    float operator*(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    // 벡터 비교
    bool operator==(const Vector2D& other) const {
        return (x == other.x) && (y == other.y);
    }

    // 스트림 출력 연산자
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "Vector2D(" << v.x << ", " << v.y << ")";
        return os;
    }
};

// 3D 벡터 클래스 (Vector2D 상속)
class Vector3D : public Vector2D {
private:
    float z;

public:
    // 생성자
    Vector3D(float xVal = 0.0f, float yVal = 0.0f, float zVal = 0.0f)
        : Vector2D(xVal, yVal), z(zVal) {}

    // z 게터
    float getZ() const { return z; }

    // 3D 벡터의 크기 (magnitude)
    float magnitude() const override {
        // getX(), getY()는 부모 클래스(Vector2D)에서 제공
        return std::sqrt(getX() * getX() + getY() * getY() + z * z);
    }

    // 벡터 정규화 (결과를 동적 할당하여 Vector3D* 형태로 반환)
    Vector3D* normalize() const override {
        float mag = magnitude();
        if (mag == 0.0f) {
            // 영벡터(0,0,0)를 normalize() 하면 다시 (0,0,0) 반환
            return new Vector3D(0.0f, 0.0f, 0.0f);
        }
        return new Vector3D(getX() / mag, getY() / mag, z / mag);
    }

    // 벡터 덧셈
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(getX() + other.getX(), 
                        getY() + other.getY(),
                        z + other.z);
    }

    // 벡터 뺄셈
    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(getX() - other.getX(),
                        getY() - other.getY(),
                        z - other.z);
    }

    // 벡터 내적 (dot product)
    float operator*(const Vector3D& other) const {
        return (getX() * other.getX()) +
               (getY() * other.getY()) +
               (z * other.z);
    }

    // 벡터 비교
    bool operator==(const Vector3D& other) const {
        return (getX() == other.getX()) &&
               (getY() == other.getY()) &&
               (z == other.z);
    }

    // 스트림 출력 연산자
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
        os << "Vector3D(" << v.getX() << ", "
                         << v.getY() << ", "
                         << v.z << ")";
        return os;
    }
};

#endif // QE_PROB3_H
