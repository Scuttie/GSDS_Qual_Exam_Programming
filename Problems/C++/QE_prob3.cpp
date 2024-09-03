class Number {
public:
    // Constructor to initialize the value
    Number(int v) : val(v) {}

    // Member function to add two Number objects
    Number add(Number n) {
        return Number(val + n.val);
    }

    // Member function to get the value of the Number
    int get_number() const {
        return val;
    }

private:
    int val; // private data member to store the integer value
};

int main() {
    Number n1(1), n2(2);
    Number n3 = n1.add(n2);
    std::cout << n3.get_number() << std::endl; // Output should be 3
    return 0;
}
