// Constructor Call Order MCQ
// What is the order of constructor calls when you create an ElectricCar object?

// class Vehicle {
// public:
//     Vehicle() {
//         cout << "Vehicle constructor" << endl;
//     }
//     void start() {
//         cout << "Vehicle started" << endl;
//     }
// };

// class Car : public Vehicle {
// public:
//     Car() {
//         cout << "Car constructor" << endl;
//     }
//     void start() {
//         cout << "Car started" << endl;
//     }
// };

// class ElectricCar : public Car {
// public:
//     ElectricCar() {
//         cout << "ElectricCar constructor" << endl;
//     }
//     void start() {
//         cout << "ElectricCar started" << endl;
//     }
// };



// Select the correct option.
// Vehicle constructor -> Car constructor -> ElectricCar constructor
// ElectricCar constructor -> Car constructor -> Vehicle constructor
// ElectricCar constructor -> Vehicle constructor -> Car constructor
// Car constructor -> ElectricCar constructor -> Vehicle constructor


// The correct output sequence is:

// ✅ Vehicle constructor → Car constructor → ElectricCar constructor

