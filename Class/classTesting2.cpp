#include <iostream>
using namespace std;

class Square{
    private:
    int length;

    protected:
    int height;

    public:
    Square(int _length = 0, int _height = 0){length = _length; height = _height;}
    void setLength(int i = 0){length = i;}
    int getLength()const {return length;}

    int getArea()const {return length * length;}
    void printArea()const {cout << "Area of Square: " << getArea() << endl;}

    int getVolume()const {return getArea() * height;}
    void printVolume()const {cout << "Volume of Square(Cube): " << getVolume() << endl;}
};

class Rectangle : public Square{
    private:
    int width;

    public:
    Rectangle(int _length = 0, int _width = 0, int _height = 0){setLength(_length); width = _width; height = _height;}
    void setWidth(int i = 0){width = i;}
    int getWidth()const {return width;}

    int getArea()const {return getLength() * width;}
    void printArea()const {cout << "Area of Rectangle: " << getArea() << endl;}

    int getVolume()const {return getArea() * height;}
    void printVolume() const {cout << "Volume of Rectangle(Cuboid): " << getVolume() << endl;}

};

int main(){

    cout << "Main started." << endl;

    Square s1;
    s1.setLength(4);
    s1.printArea();

    Rectangle r1;
    r1.setLength(6);
    r1.setWidth(3);
    r1.printArea();

    Square s2;
    s2.printArea();

    Square s3(100);
    s3.printArea();

    Rectangle r2(10, 5);
    r2.printArea();

    Square s4(3, 3);    // Actually no need pass height parameter bcs Cube same length all sides, but for demo purpose of proctected keyword.
    s4.printVolume();

    Rectangle r3(3, 4, 5);
    r3.printVolume();

    //cin.ignore();
    //cin.get();
    return 0;
}