#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
    return x * exp(-x * x);
}

double df(double f(double), double x) {
    double h = 0.01;
    return (f(x + h) - f(x - h)) / (2 * h);

}

int main() {
    double x0 = 0.7;

    while (df(f, x0) >= 0.001) {
        x0 += 0.01;
    }
    double f_pol = f(x0) / 2;
    double x1 = 0.1;
    double x2 = x0;
    double x3 = x0;
    double x4 = 2;

    while (std::abs(x1 - x2) >= 1e-8) {
        double c = (x1 + x2) / 2;
        if ((f(x1) - f_pol) * (f(c) - f_pol) < 0) {
            x2 = c;
        }
        if (((f(x2) - f_pol) * (f(c) - f_pol)) < 0) {
            x1 = c;
        }
    }

    while (std::abs(x3 - x4) >= 1e-8) {
        double c = (x3 + x4) / 2;
        if ((f(x3) - f_pol) * (f(c) - f_pol) < 0) {
            x4 = c;
        }
        if (((f(x4) - f_pol) * (f(c) - f_pol)) < 0) {
            x3 = c;
        }
    }


    std::cout << std::fixed << std::setprecision(3) << "x1=" << x1 << " " << "x2=" << x3 << " " << "detltaX="
              << x3 - x1 << std::endl;


}



