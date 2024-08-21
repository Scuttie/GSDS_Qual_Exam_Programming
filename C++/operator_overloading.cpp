#include <iostream>
#include <initializer_list>

using namespace std;

template <typename T>
class SimpleVector {
private:
    T* array;      // 동적 배열 포인터
    int size;      // 현재 요소의 개수
    int capacity;  // 배열의 용량

public:
    // 기본 생성자: 주어진 크기의 배열을 생성
    SimpleVector(int size)
        : size(size), capacity(size) {
        array = new T[capacity];
    }

    // 초기화 리스트를 사용한 생성자
    SimpleVector(std::initializer_list<T> elements)
        : size(0), capacity(elements.size()) {
        array = new T[capacity];
        for (auto element : elements) {
            addElement(element);
        }
    }

    // 소멸자: 동적 배열 메모리를 해제
    ~SimpleVector() {
        delete[] array;
    }

    // 배열의 크기를 두 배로 늘리는 함수
    void resize() {
        capacity = capacity * 2;
        T* newArray = new T[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    // 배열에 요소를 추가하는 함수
    void addElement(T element) {
        if (size == capacity)
            resize();
        array[size] = element;
        size++;
    }

    // 현재 배열에 저장된 요소의 개수를 반환하는 함수
    int getSize() const {
        return size;
    }

    // 원소에 접근하기 위한 [] 연산자 오버로딩
    T& operator[](int index);

    // 전위 증가 연산자 오버로딩
    SimpleVector<T>& operator++();

    // 후위 증가 연산자 오버로딩
    SimpleVector<T> operator++(int);

    // 벡터 간 요소별 덧셈 연산을 위한 + 연산자 오버로딩
    SimpleVector<T> operator+(SimpleVector& rhs);

    // 벡터 간 요소별 덧셈 후 결과를 저장하는 += 연산자 오버로딩
    SimpleVector<T>& operator+=(SimpleVector& rhs);

    // 요소를 추가하는 << 연산자 오버로딩
    SimpleVector<T>& operator<<(const T& element);

    // 두 벡터가 같은지 비교하는 == 연산자 오버로딩
    bool operator==(SimpleVector& rhs);

    // 두 벡터의 크기를 비교하는 < 연산자 오버로딩
    bool operator<(SimpleVector& rhs);

    // 벡터가 비어 있는지 확인하는 bool 변환 연산자 오버로딩
    operator bool() const;

    // range-based for loop을 사용하기 위한 begin() 및 end() 함수
    T* begin() { return array; }
    T* end() { return array + size; }
};

// 배열 요소에 접근하기 위한 [] 연산자 오버로딩
template <typename T>
T& SimpleVector<T>::operator[](int index) {
    return array[index];
}

// 전위 증가 연산자 오버로딩: 모든 요소를 증가시킴
template <typename T>
SimpleVector<T>& SimpleVector<T>::operator++() {
    for (int i = 0; i < size; ++i) {
        ++array[i];
    }
    return *this;
}

// 후위 증가 연산자 오버로딩: 증가 전 상태의 복사본을 반환
template <typename T>
SimpleVector<T> SimpleVector<T>::operator++(int) {
    SimpleVector<T> temp(size);
    for (int i = 0; i < size; ++i) {
        temp.addElement(array[i]);
        ++array[i];
    }
    return temp;
}

// 요소별 덧셈을 위한 + 연산자 오버로딩
template <typename T>
SimpleVector<T> SimpleVector<T>::operator+(SimpleVector& rhs) {
    SimpleVector<T> result(size); // 결과를 저장할 SimpleVector 객체 생성
    for (int i = 0; i < size; ++i) {
        result.addElement(array[i] + rhs[i]); // lhs와 rhs의 배열 요소를 더함
    }
    return result;
}

// += 연산자 오버로딩: 해당 객체에 덧셈 결과를 반영
template <typename T>
SimpleVector<T>& SimpleVector<T>::operator+=(SimpleVector& rhs) {
    for (int i = 0; i < size; ++i) {
        array[i] += rhs[i];
    }
    return *this;
}

// << 연산자 오버로딩: 요소를 벡터에 추가
template <typename T>
SimpleVector<T>& SimpleVector<T>::operator<<(const T& element) {
    addElement(element);
    return *this;
}

// == 연산자 오버로딩: 두 벡터가 같은지 비교
template <typename T>
bool SimpleVector<T>::operator==(SimpleVector& rhs) {
    if (size != rhs.getSize()) return false;
    for (int i = 0; i < size; ++i) {
        if (array[i] != rhs[i]) return false;
    }
    return true;
}

// < 연산자 오버로딩: 벡터의 크기를 비교
template <typename T>
bool SimpleVector<T>::operator<(SimpleVector& rhs) {
    return size < rhs.getSize();
}

// bool 변환 연산자 오버로딩: 벡터가 비어 있지 않으면 true 반환
template <typename T>
SimpleVector<T>::operator bool() const {
    return size > 0;
}

// 외부에서 사용하는 << 연산자 오버로딩: 벡터를 연결
template <typename T>
SimpleVector<T>& operator<<(SimpleVector<T>& lhs, SimpleVector<T>& rhs) {
    for (int i = 0; i < rhs.getSize(); ++i) {
        lhs.addElement(rhs[i]);
    }
    return lhs;
}

int main() {
    // SimpleVector 객체 생성 및 연산자 오버로딩 테스트
    SimpleVector<int> vec1 = {1, 2, 3};
    SimpleVector<int> vec2 = {4, 5};
    
    // vec1에 vec2를 추가
    vec1 << vec2;
    
    // vec1의 모든 요소를 출력
    for (int i = 0; i < vec1.getSize(); ++i) {
        cout << vec1[i] << " ";
    }
    cout << endl;
    // Output: 1 2 3 4 5

    // ++ 연산자 테스트
    ++vec1;
    for (int i = 0; i < vec1.getSize(); ++i) {
        cout << vec1[i] << " ";
    }
    cout << endl;
    // Output: 2 3 4 5 6

    return 0;
}
