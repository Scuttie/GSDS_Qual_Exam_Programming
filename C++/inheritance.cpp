#include <iostream>
#include <string>

using namespace std;

// Pokemon 클래스는 추상 클래스로, 모든 포켓몬의 기본 클래스입니다.
class Pokemon {
protected:
    string name;
    int hp;
    enum Type { ELECTRIC, FIRE, ELECTROFIRE } type; // 포켓몬의 타입 정의

public:
    Pokemon(string name, int hp, Type type) : name(name), hp(hp), type(type) {}

    // 소멸자: 다중 상속에서 기본 클래스 소멸자가 가상 소멸자로 선언되어야 합니다.
    virtual ~Pokemon() {}

    int getHp() const { return hp; }
    string getName() const { return name; }
    Type getType() const { return type; }

    void decreaseHp(int amount) { hp -= amount; }

    // 가상 함수: 자식 클래스에서 재정의될 수 있습니다.
    virtual void attack(Pokemon& opponent) {
        cout << name << " attacks " << opponent.getName() << endl;
    }

    // 순수 가상 함수: 추상 클래스의 정의입니다.
    virtual void sleep() = 0;
};

// ElectricPokemon 클래스는 Pokemon 클래스로부터 상속받아 전기 타입 포켓몬을 정의합니다.
class ElectricPokemon : virtual public Pokemon {
public:
    int electricLevel;
    ElectricPokemon(string name, int hp, int electricLevel)
        : Pokemon(name, hp, ELECTRIC), electricLevel(electricLevel) {}

    void sleep() override { cout << "zzz" << endl; }
};

// FirePokemon 클래스는 Pokemon 클래스로부터 상속받아 불 타입 포켓몬을 정의합니다.
class FirePokemon : virtual public Pokemon {
public:
    int flameLevel;
    FirePokemon(string name, int hp, int flameLevel)
        : Pokemon(name, hp, FIRE), flameLevel(flameLevel) {}

    void sleep() override { cout << "zzz" << endl; }
};

// NoPokemon 클래스는 Pokemon과 dummy 클래스를 다중 상속하여 정의합니다.
class dummy {
public:
    int nothing = 0;
    dummy(int nothing) : nothing(nothing) {}
    void attack() { cout << "nothing" << endl; }
};

class NoPokemon : public Pokemon, public dummy {
public:
    NoPokemon() : Pokemon("Missingno", -10, FIRE), dummy(1) {}

    void sleep() override { cout << "zzz" << endl; }
};

// Pikachu 클래스는 ElectricPokemon 클래스로부터 상속받아 전기 타입 포켓몬을 구체화합니다.
class Pikachu : public ElectricPokemon {
public:
    Pikachu() : Pokemon("Pikachu", 100, ELECTRIC), ElectricPokemon("Pikachu", 100, 10) {}

    void attack(Pokemon& opponent) override {
        Pokemon::attack(opponent);
        if (opponent.getType() == FIRE)
            opponent.decreaseHp(electricLevel - 2);
        else
            opponent.decreaseHp(electricLevel);
    }

    void cry() {
        cout << "Pika Pika!" << endl;
    }
};

// Charmander 클래스는 FirePokemon 클래스로부터 상속받아 불 타입 포켓몬을 구체화합니다.
class Charmander : public FirePokemon {
public:
    int height;
    Charmander() : Pokemon("Charmander", 200, FIRE), FirePokemon("Charmander", 200, 5), height(15) {}
};

// Pikamander 클래스는 ElectricPokemon과 FirePokemon을 다중 상속받아 정의됩니다.
// 다이아몬드 문제를 피하기 위해 virtual 상속을 사용합니다.
class Pikamander : public ElectricPokemon, public FirePokemon {
public:
    // friend 클래스와 friend 함수 정의
    friend class Pikachu;
    friend void revealSecret(Pikamander& p);

    Pikamander()
        : Pokemon("Pikamander", 300, ELECTROFIRE), ElectricPokemon("Pikamander", 300, 10),
          FirePokemon("Pikamander", 300, 5) {}

    void sleep() override {
        cout << "Pikamander sleeping... zzz" << endl;
    }
};

// friend 함수 구현: Pikamander의 비공개 멤버에 접근할 수 있습니다.
void revealSecret(Pikamander& p) {
    cout << p.name << " has a secret level of " << p.electricLevel + p.flameLevel << endl;
}

int main() {
    NoPokemon No;
    // 다중 상속에서 발생하는 모호성을 피하기 위해 클래스 이름을 명시적으로 사용합니다.
    No.dummy::attack(); 

    Pikachu pikachu;
    Charmander charmander;
    Pikamander pikamander;

    // Pikachu가 Charmander를 공격합니다.
    pikachu.attack(charmander);
    cout << "Charmander's HP after attack: " << charmander.getHp() << endl;

    // Pikamander가 잠을 잡니다.
    pikamander.sleep();

    // friend 함수가 Pikamander의 비공개 데이터를 출력합니다.
    revealSecret(pikamander);

    return 0;
}
