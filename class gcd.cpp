#include <iostream>
using namespace std;

class Fraction {
public:
    int top;    // صورت کسر
    int bottom; // مخرج کسر

    // سازنده ساده
    Fraction(int t = 0, int b = 1) {
        top = t;
        bottom = b;
        if (bottom == 0) bottom = 1; // جلوگیری از مخرج صفر
    }

    // نمایش کسر
    void show() {
        cout << top << "/" << bottom;
    }

    // جمع دو کسر
    Fraction add(Fraction other) {
        Fraction result;
        result.top = top * other.bottom + other.top * bottom;
        result.bottom = bottom * other.bottom;
        return result;
    }

    // ضرب دو کسر
    Fraction multiply(Fraction other) {
        Fraction result;
        result.top = top * other.top;
        result.bottom = bottom * other.bottom;
        return result;
    }
};

int main() {
    Fraction a(1, 2); // کسر 1/2
    Fraction b(1, 3); // کسر 1/3

    cout << "a: ";
    a.show();
    cout << endl;

    cout << "b: ";
    b.show();
    cout << endl;

    Fraction c = a.add(b);
    cout << "a + b = ";
    c.show();
    cout << endl;

    Fraction d = a.multiply(b);
    cout << "a * b = ";
    d.show();
    cout << endl;

    return 0;
}
