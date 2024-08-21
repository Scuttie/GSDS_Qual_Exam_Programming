#include <iostream>
#include <stdexcept>  // for std::out_of_range
#include <exception>  // for std::exception
#include <string>

using namespace std;

// 기본 포켓몬 클래스 정의
class Pokemon {
public:
    virtual ~Pokemon() = default;
};

// 전기 타입 포켓몬 클래스 정의
class ElectricPokemon : public Pokemon {
public:
    virtual ~ElectricPokemon() = default;
};

// 파이어 타입 포켓몬 클래스 정의
class FirePokemon : public Pokemon {
public:
    virtual ~FirePokemon() = default;
};

// 구체적인 포켓몬 클래스 정의
class Pikachu : public ElectricPokemon {
public:
    void speak() { cout << "Pika Pika!" << endl; }
};

class Charmander : public FirePokemon {
public:
    void speak() { cout << "Char Char!" << endl; }
};

class Pikamander : public ElectricPokemon {
public:
    void speak() { cout << "Pikamander sounds!" << endl; }
};

// 사용자 정의 예외 클래스 정의 (전역 범위에 정의)
class MyException : public std::exception {
    int index, size;
    std::string message;
public:
    MyException(int index, int size) : index(index), size(size) {
        message = "MyException: Index " + std::to_string(index) + " is out of the array of size " + std::to_string(size);
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// SimpleVector 템플릿 클래스 정의
template <typename T>
class SimpleVector {
private:
    T* array;
    int size;
    int capacity;

public:
    SimpleVector(std::initializer_list<T> elements) : size(elements.size()), capacity(elements.size()) {
        array = new T[capacity];
        int i = 0;
        for (auto element : elements) {
            array[i++] = element;
        }
    }

    ~SimpleVector() {
        delete[] array;
    }

    // SimpleVector의 operator[] 정의
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw MyException(index, size); // 사용자 정의 예외 발생
        }
        return array[index];
    }
};

int main() {
    // 타입 캐스팅 예제
    ElectricPokemon* elecPokemon = new Pikachu();
    
    // C-style cast: 위험한 캐스팅
    Charmander* charmander = (Charmander*)elecPokemon;  // 잘못된 캐스팅이지만 컴파일러는 오류를 발생시키지 않음
    
    // static_cast 예제
    double pi = 3.14159;
    int intPi = static_cast<int>(pi);  // pi의 정수 부분만 intPi에 저장
    cout << "Static cast: " << intPi << endl;  // Output: 3

    // Upcasting: 자식 클래스에서 부모 클래스로의 캐스팅 (암시적 캐스팅)
    Pikachu pikachu;
    ElectricPokemon* pokemon = static_cast<ElectricPokemon*>(&pikachu);  // OK

    // Downcasting: 부모 클래스에서 자식 클래스로의 캐스팅
    Pikachu* downcastedPikachu = static_cast<Pikachu*>(elecPokemon);  // OK
    downcastedPikachu->speak();  // Output: Pika Pika!
    
    // 잘못된 다운캐스팅 (컴파일 오류는 발생하지 않지만, 런타임에 문제가 발생할 수 있음)
    Pikamander* pikamander = static_cast<Pikamander*>(elecPokemon);  // 논리적으로 틀린 캐스팅이지만 컴파일러는 통과시킴
    
    // dynamic_cast 예제
    Pikachu* dynamicPikachu = dynamic_cast<Pikachu*>(pokemon);  // OK
    if (dynamicPikachu) {
        dynamicPikachu->speak();  // Output: Pika Pika!
    } else {
        cout << "Dynamic cast failed" << endl;
    }

    Pikamander* dynamicPikamander = dynamic_cast<Pikamander*>(pokemon);  // 실패, nullptr 반환
    if (!dynamicPikamander) {
        cout << "Dynamic cast failed, returned nullptr" << endl;  // Expected output
    }

    // const_cast 예제
    const string str = "Hello";
    string& nonConstStr = const_cast<string&>(str);  // const_cast를 통해 const 속성을 제거
    nonConstStr += " World";
    cout << "Const cast result: " << nonConstStr << endl;  // Output: Hello World

    // 예외 처리 예제
    SimpleVector<int> vec{1, 2};
    int idx, value;
    cout << "Enter an index and value: ";
    cin >> idx >> value;  // 예: 10 5
    try {
        vec[idx] = value;  // 인덱스가 범위를 벗어나면 예외 발생
    } catch (MyException& e) {
        cout << "Out of range exception: " << e.what() << endl;
    }

    // 사용자 정의 예외 처리 예제
    try {
        SimpleVector<int> vec2{1, 2};
        vec2[10] = 5;  // 인덱스가 범위를 벗어나면 사용자 정의 예외 발생
    } catch (MyException& e) {
        cout << e.what() << endl;  // 사용자 정의 예외 메시지 출력
    }

    // 메모리 해제
    delete elecPokemon;

    return 0;
}
