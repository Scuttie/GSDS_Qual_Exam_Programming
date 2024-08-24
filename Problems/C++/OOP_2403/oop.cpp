#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
// 상속 / virtual 함수 및 제거 / base pointer 사용 / static 변수(instance 수 세기)
//g++ -o oop oop.cpp
using namespace std;


class Animal {
    protected:

    public:
        Animal() {instanceCount++;}
        
        static int instanceCount;

        virtual ~Animal() {instanceCount--;}

        virtual string get_name() const { return "Animal"; }
        virtual int get_weight() const { return 0; }

};

int Animal::instanceCount = 0;

class Dog : public Animal{

    public:
        Dog() {}
        virtual ~Dog() {}

        string get_name() const override { return "Dog"; }
        int get_weight() const override { return 10; }
        // 둘다 됨
        //virtual string get_name() const { return "Dog"; }
        //virtual int get_weight() const { return 10; }

        //이건 안됨
        //string get_name() const { return "Dog"; }
        //int get_weight() const { return 10; }
};

class Pug : public Dog{

    public:
        Pug() {}
        ~Pug() {}

        string get_name() const { return "Pug"; }
        int get_weight() const { return 20; }
};

int main (){

    //class pointer 활용
    Animal* animal = new Animal();  // 다형성 활용 animal 포인터로 pug를 부를 수 있다
    Animal* dog = new Dog();  // 다형성 활용 animal 포인터로 pug를 부를 수 있다
    Animal* pug = new Pug();  // 다형성 활용 animal 포인터로 pug를 부를 수 있다

    cout << "Num of Animals: " << Animal::instanceCount << endl;

    cout << "Name: " << animal->get_name() << ", Weight: " << animal->get_weight() << endl;
    cout << "Name: " << dog->get_name() << ", Weight: " << dog->get_weight() << endl;
    cout << "Name: " << pug->get_name() << ", Weight: " << pug->get_weight() << endl;

    delete animal;  // 올바르게 Pug, Dog, Animal 소멸자 호출
    delete dog;  // 올바르게 Pug, Dog, Animal 소멸자 호출
    delete pug;  // 올바르게 Pug, Dog, Animal 소멸자 호출

    cout << "Num of Animals: " << Animal::instanceCount << endl;

}