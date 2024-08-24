#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

class Animal{
public: //숨길 멤버 변수 선언 후에 꼭 붙여주기
    Animal(){AniNum++;}
    virtual  ~Animal() {AniNum--;}

    virtual string get_name(){return "Animal";}
    virtual int get_weight(){return 0;}

    static int AniNum; //정적 변수 초기화는 class 밖에서 
};


class Dog: public Animal{ //public 선언해야 pug에서 animal의 정적변수 AniNum에 접근 가능
public:
    Dog() {}
    ~Dog() {}

    string get_name(){return "Dog";}
    int get_weight(){return 10;}
};


class Pug: public Dog{
public:
    Pug() {}
    ~Pug() {}

    string get_name(){return "Pug";}
    int get_weight(){return 20;}
};

int Animal::AniNum = 0;

int main(){
    Animal * animalarray[3]; //class pointer array
    animalarray[0] = new Animal(); //new 로 dymamic allocation
    animalarray[1] = new Dog();
    animalarray[2] = new Pug();
    cout << "Number of animals: " << Animal::AniNum << endl;
    for (Animal* animal: animalarray){
        cout << "Name: " << animal -> get_name() << ", Weight: " << animal -> get_weight() << "kg" << endl; //() 붙여야
    }
    for (Animal* animal: animalarray){
        delete animal;
    }
    cout << "Number of animals: " << Animal::AniNum << endl;
}