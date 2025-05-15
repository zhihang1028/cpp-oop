#include <iostream>
#include <string>
using namespace std;

class Foo{
    private:
    int x;

    public:
    Foo(int i = 0){x = i;}
    void addX(int _x){x = _x;}
    int getX(){return x;}

};

class Bar : public Foo{
    private:
    int y;

    public:
    Bar(int i = 0){y = i;}
    void addY(int i){y = i;}
    int getY () {return y;}
    void printAll () {cout << "X: " << getX() << ", Y: " << y << endl;}
    int getSum () {return (getX() + y);}
    void printSum(){cout << "Sum of X and Y: " << getSum() << endl;}

};

int main(){

    cout << "Hello World!" << endl;
    Foo f;
    f.addX(10);

    Bar b;
    b.addX(100);
    b.addY(100);

    cout << f.getX() << endl;
    cout << b.getX() << endl;
    cout << b.getY() << endl;
    
    b.printAll();
    b.printSum();

    //cin.ignore();
    //cin.get();
    return 0;
}