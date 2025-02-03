#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() { // Make sound() virtual for polymorphism
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override { // Use 'override' to indicate this function overrides a base class function
        cout << "Dog barks" << endl;
    }
};

int main() {
    Animal* animal = new Animal(); // Create an Animal object
    Animal* dog = new Dog();       // Create a Dog object as an Animal pointer

    animal->sound(); // Calls Animal's sound()
    dog->sound();    // Calls Dog's sound() due to polymorphism

    // Clean up dynamically allocated memory
    delete animal;
    delete dog;

    return 0;
}
