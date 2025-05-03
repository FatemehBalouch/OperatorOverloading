#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    // اعلان تابع gcd به عنوان تابع دوست
    friend int gcd(const Fraction& f1, const Fraction& f2);

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

// پیاده‌سازی تابع gcd
int gcd(const Fraction& f1, const Fraction& f2) {
    int a = f1.denominator;
    int b = f2.denominator;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    Fraction frac1(3, 6);
    Fraction frac2(2, 8);

    int commonDivisor = gcd(frac1, frac2);
    cout << "GCD of denominators: " << commonDivisor << endl;

    return 0;
}
