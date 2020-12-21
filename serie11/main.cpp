#include <iostream>

#include "Polynomial.h"

using namespace std;

int main() {
    cout << "                         _            __ \n"
            "                        (_)          /_ |\n"
            "   _____  _____ _ __ ___ _ ___  ___   | |\n"
            "  / _ \\ \\/ / _ \\ '__/ __| / __|/ _ \\  | |\n"
            " |  __/>  <  __/ | | (__| \\__ \\  __/  | |\n"
            "  \\___/_/\\_\\___|_|  \\___|_|___/\\___|  |_|\n" << endl;

    Polynomial p1(3, 1);
    Polynomial p2(p1);

    p2 = p1;

    cout << p1.degree() << endl;
    cout << p2.degree() << endl;

    cout << p1[1] << endl;

    p1[1] = -25.5;

    cout << p1 << endl;

    cout << "                         _            ___  \n"
            "                        (_)          |__ \\ \n"
            "   _____  _____ _ __ ___ _ ___  ___     ) |\n"
            "  / _ \\ \\/ / _ \\ '__/ __| / __|/ _ \\   / / \n"
            " |  __/>  <  __/ | | (__| \\__ \\  __/  / /_ \n"
            "  \\___/_/\\_\\___|_|  \\___|_|___/\\___| |____|\n" << endl;

    cout << p1 + p2 << endl;
    cout << p1 + 42.314 << endl;
    cout << 42.314 + p1 << endl;

    return 0;
}
