#include <iostream>

#include "IntVector.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    {
        IntVector vector;
        cout << vector.getLength() << endl;
    }

    {
        IntVector vector = IntVector((unsigned int)3, 42);
        cout << vector.getLength() << endl;
        cout << vector.getCoefficient(0) << ", ";
        cout << vector.getCoefficient(1) << ", ";
        cout << vector.getCoefficient(2) << endl;
        try {
            cout << vector.getCoefficient(3) << endl;
        } catch (logic_error &error) {
            cout << error.what() << endl;
        }
    }

    {
        IntVector vector = IntVector(42);
        cout << "prime factors of 42: ";
        for (int i=0; i < vector.getLength(); i++) {
            cout << vector.getCoefficient(i) << ", ";
        }
        cout << endl;
    }

    return 0;
}
