#include <iostream>
using namespace std;

class Array {
private:
    int *data;
    int size;
public:
    // سازنده
    Array(int s = 10) : size(s) {
        data = new int[size];
        for(int i = 0; i < size; i++)
            data[i] = 0;
    }

    // سازنده کپی
    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for(int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    // مخرب
    ~Array() {
        delete[] data;
    }

    // سربارگذاری عملگر = (انتساب)
    Array& operator=(const Array& other) {
        if(this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for(int i = 0; i < size; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    // سربارگذاری عملگر [] (دسترسی به عناصر)
    int& operator[](int index) {
        if(index < 0 || index >= size) {
            cerr << "خطا: خارج از محدوده آرایه!" << endl;
            exit(1);
        }
        return data[index];
    }

    // سربارگذاری عملگر + (جمع دو آرایه)
    Array operator+(const Array& other) const {
        if(size != other.size) {
            cerr << "خطا: اندازه آرایه‌ها برابر نیست!" << endl;
            exit(1);
        }
        Array result(size);
        for(int i = 0; i < size; i++)
            result.data[i] = data[i] + other.data[i];
        return result;
    }

    // سربارگذاری عملگر - (تفریق دو آرایه)
    Array operator-(const Array& other) const {
        if(size != other.size) {
            cerr << "خطا: اندازه آرایه‌ها برابر نیست!" << endl;
            exit(1);
        }
        Array result(size);
        for(int i = 0; i < size; i++)
            result.data[i] = data[i] - other.data[i];
        return result;
    }

    // سربارگذاری عملگر == (بررسی تساوی)
    bool operator==(const Array& other) const {
        if(size != other.size) return false;
        for(int i = 0; i < size; i++)
            if(data[i] != other.data[i])
                return false;
        return true;
    }

    // سربارگذاری عملگر ++ پیشوندی
    Array& operator++() {
        for(int i = 0; i < size; i++)
            ++data[i];
        return *this;
    }

    // سربارگذاری عملگر ++ پسوندی
    Array operator++(int) {
        Array temp = *this;
        for(int i = 0; i < size; i++)
            data[i]++;
        return temp;
    }

    // سربارگذاری عملگر * (ضرب اسکالر)
    Array operator*(int scalar) const {
        Array result(size);
        for(int i = 0; i < size; i++)
            result.data[i] = data[i] * scalar;
        return result;
    }

    // سربارگذاری عملگر << (چاپ آرایه)
    friend ostream& operator<<(ostream& os, const Array& arr) {
        os << "[ ";
        for(int i = 0; i < arr.size; i++)
            os << arr.data[i] << " ";
        os << "]";
        return os;
    }

    // سربارگذاری عملگر >> (ورود مقادیر به آرایه)
    friend istream& operator>>(istream& is, Array& arr) {
        cout << "مقادیر آرایه (" << arr.size << " عدد): ";
        for(int i = 0; i < arr.size; i++)
            is >> arr.data[i];
        return is;
    }
};
