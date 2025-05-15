#include <iostream>
using namespace std;

class Square{
    private:
    int length;

    public:
    Square(int _length = 0){length = _length;}
    void setLength(int i = 0){length = i;}
    int getLength(){return length;}
    int getArea(){return length * length;}
    void printArea(){cout << "Area of Square: " << getArea() << endl;}
};

class Rectangle : public Square{
    private:
    int width;

    public:
    Rectangle(int _width = 0){width = _width;}
    void setWidth(int i = 0){width = i;}
    int getWidth(){return width;}
    int getArea(){return getLength() * width;}
    void printArea(){cout << "Area of Rectangle: " << getArea() << endl;}

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
    

    //cin.ignore();
    //cin.get();
    return 0;
}