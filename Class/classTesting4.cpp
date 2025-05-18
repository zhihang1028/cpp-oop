#include <iostream>
using namespace std;

class Integer{
    private:
    int num; 

    public:
    Integer(int _num = 0){num = _num;}
    void setInt(int i){num = i;}
    int getInt()const {return num;}
    void print()const {cout << "The integer number is: " << num << endl;}

};

class Operation{
    private:
    int num1;
    int num2;

    public:
    Operation(int _num1 = 0, int _num2 = 0){num1 = _num1; num2 = _num2;}
    void setValues(int x, int y){num1 = x; num2 = y;}
    int add()const {return (num1 + num2);}
    int sub()const {return (num1 - num2);}
    int mul()const {return (num1 * num2);}
    int div()const {return (num1 / num2);}
};

class Shared{
    private:
    static int sharedInt;

    public:
    Shared(){}
    void setInt(int x = 0){sharedInt = x;}
    int getInt()const {return sharedInt;}
    void print()const {cout << "The shared integer is: " << sharedInt << endl;}
    void increment(){sharedInt++;}

    static int retrieveShared(){return sharedInt;}
    static void presetShared(int x = 0){sharedInt = x;}
};

int Shared::sharedInt = 0;  // Definition for static members

int main(){

    Shared::presetShared(1000);
    cout << "Retrive static shared integer with static function: " << Shared::retrieveShared() << endl;

    Integer obj1, obj2;
    obj1.setInt(13);
    obj1.print();
    obj2.setInt(12);
    obj2.print();

    int offset = 11;

    Operation op1;
    op1.setValues(obj1.getInt(), obj2.getInt());
    cout << "The sum of obj1 and obj2 is: " << op1.add() << endl;

    Shared shared1, shared2;
    shared1.setInt(123);
    shared1.print();

    shared2.setInt(100);
    shared1.print();
    shared2.print();

    Operation op2;
    op2.setValues(shared1.getInt(), offset);
    cout << "The sum of shared integer and offset is: " << op2.add() << endl;

    shared1.increment();
    shared1.print();

    return 0;
}