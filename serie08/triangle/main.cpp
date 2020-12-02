//
// Created by ida on 02.12.20.
//

#include <iostream>
#include "triangle.h"

using std::cout;
using std::endl;
using std::boolalpha;
using std::noboolalpha;

int main() {
    Triangle triangle;
    triangle.setX(0.0, 1.0);
    triangle.setY(0.0, 0.5);
    triangle.setZ(0.0, -0.5);

    cout << "Triangle perimeter: " << triangle.getPerimeter() << endl;
    cout << "Is triangle equilateral: " << boolalpha << triangle.isEquilateral() << noboolalpha << endl;
    return 0;
}