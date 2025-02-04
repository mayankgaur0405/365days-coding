#include <iostream>
using namespace std;

class BaseA {
public:
    void foo() {
        cout << "BaseA's foo()" << endl;
    }
};

class BaseB {
public:
    void foo() {
        cout << "BaseB's foo()" << endl;
    }
};

class Derived : public BaseA, public BaseB {
};

int main() {
    Derived derived;
    
    // derived.foo(); // Ambiguity here!

    derived.BaseA::foo(); // Calls BaseA's foo()
    derived.BaseB::foo(); // Calls BaseB's foo()
    
    return 0;
}
