#include<iostream>
#include<string>
using namespace std;

class Point {
public:
    int x, y;
};

// عملگر << به صورت Global Function
ostream& operator<<(ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out; // برای زنجیره‌ای کردن (مثل cout << p1 << p2)
}

class Student {
public:
    string name;
    int id;

    // عملگر == به صورت Member Function
    bool operator==(const Student &other) {
        return (name == other.name && id == other.id);
    }
};
class Array {
private:
    int data[5];
public:
    int& operator[](int index) {
        if (index < 0 || index >= 5)
            throw out_of_range("Index out of bounds!");
        return data[index]; // بازگشت به صورت ارجاع (برای تغییر مقدار)
    }
};

class Multiplier {
public:
    int operator()(int a, int b) {
        return a * b;
    }
};
class Vector {
public:
    int x, y;

    // عملگر + به صورت Member Function
    Vector operator+(const Vector &other) {
        Vector result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
};

int main() {
    Vector v1 = {1, 2};
    Vector v2 = {3, 4};
    Vector v3 = v1 + v2; // v3.x = 4, v3.y = 6
    Point p = {5, 10};
    cout << p; // خروجی: (5, 10)
    Student s1 = {"Ali", 100};
    Student s2 = {"Ali", 100};
    if (s1 == s2) // true
       cout << "Equal!";
    Array arr;
    arr[0] = 10; // استفاده از عملگر []
    cout << arr[0]; // 10
    Multiplier multiply;
    cout << multiply(3, 4); // 12 (مثل یک تابع رفتار می‌کند)


}
