#include <iostream>
using namespace std;

class Foo {
    private:
    int *ptr;
    int size;

    public:
    Foo(int _s){size = _s; ptr = new int[size];}
    ~Foo(){delete ptr;}

    void setValues(int index, int values){ptr[index] = values;}
    int getSize(){return size;}
    int getValues(int index){return ptr[index];}

};

int main(){

    Foo f(2);
    f.setValues(0, 12);
    f.setValues(1, 7);

    cout << "Value in f is: " << f.getValues(1) << endl;
    cout << "Size of f is: " << f.getSize() << endl;

    return 0;
}