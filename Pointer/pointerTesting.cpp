#include <iostream>
using namespace std;

int main(){

    int x = 100;
    double y = 2.7;
    double *p;
    int *q;
    double *r;
    double z = 1.75;
    p = &z; // Assign memory address of z to p
    q = &x;
    double sum = 0;
    r = &sum;

    cout << "The memory address of x is: "<< &x << endl;
    cout << "The value of x is: "<< x << endl;
    cout << "The size of x is: "<< sizeof(x) << "\n" << endl;

    cout << "The memory address of y is: "<< &y << endl;
    cout << "The value of y is: "<< y << endl;
    cout << "The size of y is: "<< sizeof(y) << endl;

    cout << "Address of p: " << p << "\nAdress of z: " << &z << endl;
    cout << "Content at address p: " << *p << endl; // Access content at memory address p;

    *p = 100.1; // Changed value of z from 1.75 to 100.1
    cout << "Content at p: " << *p << ", " << z << endl;

    *r = *q + *p;   // sum = x + z; (100 + 100.1)
    cout << "Sum of x and z is: " << sum << endl;

    p = nullptr;    // Dereferencing
    q = nullptr;
    r = nullptr;

    cout << "Address stored in p is: " << p << endl;

    return 0;
}