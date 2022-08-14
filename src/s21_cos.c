// by weaveryu
#include <math.h>
#include <stdio.h>

#define EPS 1e-17
#define S21_M_PI 3.14159265358979323846264338327950288

long double s21_cos(double x) {
    x = fmod(x, S21_M_PI);
    long double result = 1;
    long double xx = x*x;
    long double fact = 2;
    long double fact_mul = 2;
    long double add = 1;
    int sign = -1;
    int i = 1;
    while (fabs(add) > EPS) {
        add = sign*(pow(xx, i))/(fact);
        result += add;
        sign *= -1;
        fact *= ++fact_mul;
        fact *= ++fact_mul;
        i++;
    }
    return result;
}

int main() {
    double xx = 0.1111111111111111;
    for (int i = 0; i < 17; i++) {
        printf("%24lf : %10Lf %10lf\n", xx, s21_cos(xx), cos(xx));
        xx *= 10;
    }
    xx = 0.9999999999999999;
    for (int i = 0; i < 17; i++) {
        printf("%24lf : %10Lf %10lf\n", xx, s21_cos(xx), cos(xx));
        xx *= 10;
    }
    xx = 0.1;
    for (int i = 0; i < 17; i++) {
        printf("%24lf : %10Lf %10lf\n", xx, s21_cos(xx), cos(xx));
        xx *= 10;
    }
    return 0;
}
