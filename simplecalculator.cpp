#include<iostream>
using namespace std;

// Base class 1: BasicOperations - Handles basic arithmetic operations
class BasicOperations {
public:
    double add(double a, double b) {
        return a + b;
    }

    double sub(double a, double b) {
        return a - b;
    }

    double mul(double a, double b) {
        return a * b;
    }

    double div(double a, double b) {
        if (b == 0) {
            return -1; // Error case: division by zero
        } else {
            return a / b;
        }
    }
};

// Base class 2: UserInput - Handles user input and interaction
class UserInput {
public:
    double getFirstNumber() {
        double n1;
        cout << "Enter the first number: ";
        cin >> n1;
        return n1;
    }

    double getSecondNumber() {
        double n2;
        cout << "Enter the second number: ";
        cin >> n2;
        return n2;
    }

    int getChoice() {
        int choice;
        cout << "\nSelect an operation from the following:" << endl;
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "Select the operation to be performed corresponding to the number: ";
        cin >> choice;
        return choice;
    }
};

// Derived class: Calculator - Inherits from both BasicOperations and UserInput
class Calculator : public BasicOperations, public UserInput {
public:
    void performOperation() {
        double n1 = getFirstNumber();
        double n2 = getSecondNumber();
        int choice = getChoice();

        double res;
        switch(choice) {
            case 1:
                res = add(n1, n2);
                cout << "Addition of " << n1 << " and " << n2 << " = " << res << endl;
                break;
            case 2:
                res = sub(n1, n2);
                cout << "Subtraction of " << n1 << " and " << n2 << " = " << res << endl;
                break;
            case 3:
                res = mul(n1, n2);
                cout << "Multiplication of " << n1 << " and " << n2 << " = " << res << endl;
                break;
            case 4:
                res = div(n1, n2);
                if(res == -1) {
                    cout << "Error! Denominator cannot be zero." << endl;
                } else {
                    cout << "Division of " << n1 << " and " << n2 << " = " << res << endl;
                }
                break;
            default:
                cout << "Invalid choice! Please select a valid operation from the given operations." << endl;
        }
    }
};

int main() {
    Calculator calc;  // Create an instance of the Calculator class
    cout << "This is a program that calculates the basic arithmetic operations (+, -, *, /)!" << endl;
    calc.performOperation();  // Perform the operation
    return 0;
}
