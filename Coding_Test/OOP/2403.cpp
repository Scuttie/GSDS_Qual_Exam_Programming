#include <iostream>
#include <string>
using namespace std;

//------------------------------------
// 1. Animal, Dog, Pug 클래스 구현
//------------------------------------
class Animal {
private:
    // 모든 Animal 계열 객체(Animal, Dog, Pug 포함)의
    // 총 생성 개수를 추적하기 위한 static 멤버
    static int AniNum;

public:
    // 생성자에서 AniNum 증가
    Animal() {
        AniNum++;
    }

    // 소멸자에서 AniNum 감소
    virtual ~Animal() {
        AniNum--;
    }

    // 현재 Animal 계열 객체 개수를 반환하는 정적 함수
    static int getAniNum() {
        return AniNum;
    }

    // 문제에서 요구한 virtual 함수
    virtual string get_name() {
        return "Animal";
    }

    virtual int get_weight() {
        return 0; // Animal은 문제에서 별도 weight가 명시되지 않아 0으로 가정
    }
};

// 정적 멤버 변수 초기화
int Animal::AniNum = 0;

// Dog 클래스: Animal 상속
class Dog : public Animal {
public:
    Dog() : Animal() {}
    virtual ~Dog() {}

    virtual string get_name() override {
        return "Dog";
    }

    virtual int get_weight() override {
        return 10;
    }
};

// Pug 클래스: Dog 상속
class Pug : public Dog {
public:
    Pug() : Dog() {}
    virtual ~Pug() {}

    virtual string get_name() override {
        return "Pug";
    }

    virtual int get_weight() override {
        return 20;
    }
};

int main() {
    //------------------------------------
    // 3. Animal 포인터 배열로 Animal, Dog, Pug 각각 1개씩 생성
    //------------------------------------
    Animal* arr[3];
    arr[0] = new Animal();
    arr[1] = new Dog();
    arr[2] = new Pug();

    // 현재 Animal 계열 객체 수 출력
    cout << "Number of animals: " << Animal::getAniNum() << endl;

    //------------------------------------
    // 4. 생성된 3개의 인스턴스 정보 출력
    //------------------------------------
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << arr[i]->get_name()
             << ", Weight: " << arr[i]->get_weight() << " kg" << endl;
    }

    //------------------------------------
    // 5. Animal, Dog, Pug 인스턴스 삭제 후 AniNum 출력
    //------------------------------------
    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }

    cout << "Number of animals: " << Animal::getAniNum() << endl;

    return 0;
}
