#include <iostream>

#include "IntVector.h"
#include "Factorization.h"

using namespace std;

int gcd(int a, int b) {
    Factorization a_factorization = Factorization(a);
    Factorization b_factorization = Factorization(b);

    // Iterate from back to front, returning if found.
    for (int i = (int) (a_factorization.getPrimeFactorCnt()) - 1; i >= 0; --i) {
        unsigned int current_prime_factor_a = a_factorization.getPrimeFactor(i);

        for (int j = 0; j < b_factorization.getPrimeFactorCnt(); ++j) {
            unsigned int current_prime_factor_b = b_factorization.getPrimeFactor(j);

            if (current_prime_factor_a == current_prime_factor_b) {
                unsigned int current_multiplicity_a = a_factorization.getMultiplicity(i);
                unsigned int current_multiplicity_b = b_factorization.getMultiplicity(j);

                if (current_multiplicity_a < current_multiplicity_b) {
                    return (int) (current_prime_factor_b * current_multiplicity_a);
                } else {
                    return (int) (current_prime_factor_b * current_multiplicity_b);
                }
            }
        }
    }

    return 1;
}

int lcm(int a, int b) {
    int acc_a = a;
    int acc_b = b;

    while (1) {
        if (acc_a == acc_b) {
            return acc_a;
        } else if (acc_a < acc_b) {
            acc_a += a;
        } else {
            acc_b += b;
        }
    }
}

int main() {
    cout << "Hello, World!" << endl;

    {
        IntVector vector;
        cout << vector.getLength() << endl;
        try {
            vector.setCoefficient(0, 1);
        } catch (logic_error &error) {
            cout << error.what() << endl;
        }
    }

    {
        IntVector vector = IntVector((unsigned int) 3, 42);
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
        cout << "prime numbers <= 42: ";
        for (int i = 0; i < vector.getLength(); i++) {
            cout << vector.getCoefficient(i) << ", ";
        }
        cout << endl;
    }

    {
        Factorization factorization = Factorization(8);
        cout << factorization.recomposeInteger() << endl;
        factorization.setNumber(42);
        cout << factorization.recomposeInteger() << endl;
    }

    cout << gcd(12, 4) << endl;
    cout << gcd(42, 5) << endl;

    cout << lcm(8 * 3, 8 * 5) << endl;

    return 0;
}
