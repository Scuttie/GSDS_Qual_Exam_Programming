#include <iostream>
#include <initializer_list>
#include <memory> // For std::unique_ptr
using namespace std;

// SimpleVector 클래스 템플릿 정의
template <typename T> 
class SimpleVector {
private: 
    T* array;        // 배열 포인터
    int size;        // 현재 요소의 개수
    int capacity;    // 배열의 용량

public:
    // initializer_list를 사용하는 생성자
    SimpleVector(std::initializer_list<T> elements)
        : size(0), capacity(elements.size()) {
        array = new T[capacity]; // 용량 크기의 배열 동적 할당
        for (auto element : elements) {
            addElement(element); // 각 요소를 배열에 추가
        }
    }

    // 소멸자: 동적 할당된 배열 메모리 해제
    ~SimpleVector() {
        delete[] array;
    }

    // capacity 값을 반환하는 함수
    int getCapacity() const;

    // 배열에 요소를 추가하는 함수
    void addElement(int element) {
        if (size == capacity) {
            resize(); // 용량이 가득 찼을 경우 크기 조절
        }
        array[size] = element;
        size++;
    }

    // 배열의 크기를 두 배로 늘리는 함수
    void resize() {
        capacity = capacity * 2;
        T* newArray = new T[capacity]; // 새 배열 동적 할당
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i]; // 기존 배열 요소 복사
        }
        delete[] array; // 기존 배열 메모리 해제
        array = newArray; // 새로운 배열로 교체
    }

    // 현재 배열에 저장된 요소의 개수를 반환하는 함수
    int getSize() const {
        return size;
    }

    // 마지막 요소를 삭제하는 함수
    void deleteLastElement() {
        if (size > 0) {
            array[size - 1] = T(); // 타입에 맞게 초기화
            size--;
        }
    }
};

// SimpleVector 클래스의 getCapacity 함수 정의 (클래스 외부)
template <typename T> 
int SimpleVector<T>::getCapacity() const {
    return capacity;
}

int main() {
    // 일반 포인터를 사용한 SimpleVector 객체 생성 및 삭제
    SimpleVector<int>* vec1 = new SimpleVector<int>({2, 3, 4});
    delete vec1;

    // 스마트 포인터(unique_ptr)를 사용한 SimpleVector 객체 생성
    std::unique_ptr<SimpleVector<int>> vec2(new SimpleVector<int>({2, 3, 4}));

    // make_unique를 사용하여 unique_ptr 객체 생성 (C++14 이상에서 지원)
    auto vec3 = std::make_unique<SimpleVector<int>>(std::initializer_list<int>{2, 3, 4});

    // vec2를 통해 SimpleVector 클래스의 멤버 함수 호출
    vec2->addElement(2);
    vec2->addElement(3);
    vec2->deleteLastElement();

    // vec2의 현재 크기를 출력
    cout << "Current size of vec2: " << vec2->getSize() << endl;

    // vec3을 통해 SimpleVector 클래스의 멤버 함수 호출
    vec3->addElement(5);
    cout << "Current size of vec3: " << vec3->getSize() << endl;

    return 0;
}
