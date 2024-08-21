#include <iostream>
#include <initializer_list>
#include <map>

using namespace std;

template <typename T>
class SimpleVector {
private:
    T* array;          // 동적 배열 포인터
    int size;          // 현재 요소의 개수
    int capacity;      // 배열의 용량

public:
    // static 멤버 변수: 클래스의 모든 인스턴스에서 공유됩니다.
    static std::map<T, int> elementCount;

    // 생성자: 초기 용량을 설정하여 벡터를 초기화합니다.
    SimpleVector(int init_capacity) : size(0), capacity(init_capacity) {
        array = new T[capacity];
    }

    // 초기화 리스트를 사용한 생성자
    SimpleVector(std::initializer_list<T> elements) : size(0), capacity(elements.size()) {
        array = new T[capacity];
        for (auto element : elements) {
            addElement(element);
        }
    }

    // 복사 생성자: 다른 SimpleVector 객체로부터 복사하여 생성합니다.
    SimpleVector(const SimpleVector<T>& other)
        : size(0), capacity(other.capacity), array(new T[other.capacity]) {
        for (int i = 0; i < other.size; ++i) {
            addElement(other.array[i]);
        }
    }

    // 이동 생성자: rvalue 참조를 통해 임시 객체로부터 이동하여 생성합니다.
    SimpleVector(SimpleVector<T>&& other) noexcept
        : array(other.array), size(other.size), capacity(other.capacity) {
        other.array = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // 소멸자: 동적 메모리를 해제합니다.
    ~SimpleVector() {
        delete[] array;
    }

    // static 메서드: 모든 인스턴스에서 공유되는 데이터를 출력합니다.
    static void printElementCount() {
        for (auto pair : elementCount) {
            cout << pair.first << ":" << pair.second << endl;
        }
    }

    // 현재 벡터의 크기를 반환합니다.
    int getSize() const {
        return size;
    }

    // 현재 벡터의 용량을 반환합니다.
    int getCapacity() const {
        return capacity;
    }

    // 복사 할당 연산자: 다른 SimpleVector 객체로부터 데이터를 복사합니다.
    SimpleVector<T>& operator=(const SimpleVector<T>& other) {
        if (this != &other) {
            delete[] array;

            capacity = other.capacity;
            array = new T[capacity];
            size = 0;
            for (int i = 0; i < other.size; ++i) {
                addElement(other.array[i]);
            }
        }
        return *this;
    }

    // 이동 할당 연산자: 다른 SimpleVector 객체로부터 데이터를 이동합니다.
    SimpleVector<T>& operator=(SimpleVector<T>&& other) noexcept {
        if (this != &other) {
            delete[] array;
            array = other.array;
            size = other.size;
            capacity = other.capacity;

            other.array = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // range-based for loop을 지원하기 위한 begin() 및 end() 메서드
    T* begin() { return array; }
    T* end() { return array + size; }

    // [] 연산자 오버로딩: 벡터의 특정 인덱스에 접근합니다.
    T& operator[](int i) {
        return array[i];
    }

    // 배열의 크기를 두 배로 늘리는 메서드
    void resize() {
        capacity = capacity * 2;
        T* newArray = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    // 배열에 요소를 추가하는 메서드
    void addElement(T element) {
        if (size == capacity)
            resize();
        array[size] = element;
        size++;
        elementCount[element]++;
    }
};

// static 멤버 변수 초기화
template <typename T>
std::map<T, int> SimpleVector<T>::elementCount = {};

int main() {
    // SimpleVector 객체 생성
    SimpleVector<int> vec1{1, 2, 3};
    SimpleVector<int> vec2{2, 3, 4};

    // static 메서드를 사용하여 elementCount 출력
    SimpleVector<int>::printElementCount();
    cout << "Number of unique elements: " << SimpleVector<int>::elementCount.size() << endl;

    // 복사 생성자 테스트
    SimpleVector<int> vec3 = vec1;
    // 복사 생성자는 기존 요소들의 개수를 증가시킵니다.

    // 이동 생성자 테스트
    SimpleVector<int> vec4 = std::move(vec2);
    // 이동 생성자는 elementCount에 영향을 미치지 않습니다.

    // 복사 할당 연산자 테스트
    vec3 = vec4;
    // 복사 할당 연산자는 요소의 개수를 증가시킵니다.

    // 이동 할당 연산자 테스트
    vec4 = std::move(vec1);
    // 이동 할당 연산자는 elementCount에 영향을 미치지 않습니다.

    // 복사 및 이동 후 elementCount 다시 출력
    SimpleVector<int>::printElementCount();
    cout << "Number of unique elements after operations: " << SimpleVector<int>::elementCount.size() << endl;

    return 0;
}
