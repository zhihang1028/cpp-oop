#include <iostream>
using namespace std;

class Foo {
    private:
    int *xptr;

    public:
    Foo(){xptr = new int; *xptr = 0;}
    Foo(const Foo& p){  // Copy constructor
        xptr = new int;
        *xptr = p.get();
    }
    ~Foo(){delete xptr;}
    void set(int x = 0){*xptr = x;}
    int get()const {return *xptr;}
    //void print()const {cout << *xptr << endl;}
};

int main(){
    Foo f;
    f.set(12);

    Foo g = f;
    g.set(11);

    cout << f.get() << " " << g.get() << endl;

    return 0;
}