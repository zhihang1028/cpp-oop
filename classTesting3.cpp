#include <iostream>
using namespace std;

class Base{
    private:
    int a, b;

    public:
    Base() {a = 0; b = 0; cout << "Base constructor." << endl;}
    Base(int x, int y) {a = x; b = y; cout << "Base constructor." << endl;}
    ~Base() {cout << "Base destructor." << endl;}

    void print()const {cout << "The value of a is: " << a << ", The value of b is: " << b << endl;}

};

class Derived : public Base{
    private:
    int c;
    using Base::Base; // Inherit constructor from Base??

    public:
    Derived(int q, int r, int s) : Base(q, r) {c = s; cout << "Derived constructor." << endl;}
    ~Derived() {cout << "Derived destructor." << endl;}

    int getS()const {return c;}

};

int main(){

    //Derived *d = new Derived;
    //delete d;
    Derived d(8, 5, 3);
    d.print();
    cout << "The value of s (or c) is: " << d.getS() << endl;

    Derived b1(1, 2);
    Derived b2;

    b1.print();
    b2.print();

    //cin.ignore();
    //cin.get();
    return 0;
}