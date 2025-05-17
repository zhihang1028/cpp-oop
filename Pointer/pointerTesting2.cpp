#include <iostream>
using namespace std;

void Foo(int *ptr){
    cout << "\nFunction pointer: " << ptr << ", Function Content: " << *ptr << endl;
    *ptr = 123;
    cout << "Modified funtion pointer content: " << *ptr << endl;
}

void Swap(int *&p, int *&q){
    int *temp = p;
    p = q;
    q = temp;
}

int main(){

    int array[] = {1, 2, 4, 7, 5};  // Static/constant, once declared, cannot change the address (ie. array = &num);
    int num = 3;
    int *p = &num;  // But p can be modified (ie. p = array;)

    cout << "array: " << array << endl;
    cout << "p: " << p << endl;  // Both printing array and p gives the memory address. (array and pointer p stores addresses.)

    p = array;
    cout << "Modified p address: " << p << endl;

    cout << "Access values/elements at p: " << p[1] << endl;    // p[1] = *(p + 1)
    cout << "Access values/elements at p: " << *(p + 1) << endl;
    cout << "Access default value in p: " << *p << endl;    // *p = p[0] = *a = a[0] = *(a + 0)

    p = nullptr;
    p = array;

    for (int i = 0; i < 6; i++){
        cout << "for-loop p: " << *p << endl; // print content of p
        p++;    // add 4 bytes, sizeof(int), to pointer p (memory address)
    };

    // Initialisation of pointers
    double *dptr = nullptr;
    double d = 37.5;

    dptr = &d;

    float f = 1.75;
    float *fptr = nullptr;
    fptr = &f;

    int a[3] = {2, 6, 9};
    int *aptr = nullptr;
    aptr = a;

    if (aptr[0] < aptr[1]){
        cout << &aptr[0] << " is smaller than (comes before) " << &aptr[1] << endl;
    };

    int random = 10;
    int *randomPtr = &random;

    Foo(randomPtr);
    cout << "Content in random: " << random << endl;

    int num1 = 33, num2 = 77;
    int *ptr1 = &num1, *ptr2 = &num2;

    cout << "(Before swaping pointer) ptr1: " << *ptr1 << ", ptr2: " << *ptr2 << endl;
    Swap(ptr1, ptr2);
    cout << "(After swaping pointer) ptr1: " << *ptr1 << ", ptr2: " << *ptr2 << endl;
    

    return 0;
}