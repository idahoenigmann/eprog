//
// Created by ida on 26.11.20.
//

#include <stdio.h>
#include <math.h>
#include <assert.h>

// :-(

double f(double x) {
    return 5;
}

double trapezoidalRule(double (*f)(double), double a, double b, double tau) {
    int n = 0;
    double h = (b - a) / n;
    double i = 0;
    double i_prev = 0;

    assert(tau > 0);

    while (1) {

        i_prev = i;
        i = f(a);

        for (int j = 1; j < n - 1; ++j) {
            i += f(a + j * h) + f(b);
        }
        i *= 2;
        i *= h / 2;

        if (fabs(i) <= tau) {
            if (fabs(i - i_prev) <= tau) {
                break;
            }
        } else {
            if (fabs(i - i_prev) <= tau * fabs(i)) {
                break;
            }
        }
    }
    return i;
}

int main() {
    printf("Approximate the integral of a function f(x).\n");

    double a = 0;
    double b = 0;
    double tau = 0;

    printf("Please enter a value for a: ");
    scanf("%lf", &a);

    printf("Please enter a value for b: ");
    scanf("%lf", &b);

    printf("Please enter a value for tau: ");
    scanf("%lf", &tau);

    double res = trapezoidalRule(f, a, b, tau);

    printf("%f\n", res);

    return 0;
}