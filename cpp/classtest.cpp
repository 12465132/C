#include <conio.h>
#include <iostream>
class ClassA {
public:
    int x;
    int y;
    int z;
};
 
class ClassB : public ClassA {
public:
    int b;
};
class ClassC : public ClassA {
public:
    int c;
};
 
class ClassD : public ClassB, public ClassC {
public:
    int d;
};
 
int main()
{
 
    ClassD obj;
 
    // obj.a = 10;                   //Statement 1, Error
    // obj.a = 100;                 //Statement 2, Error
 
    obj.ClassA::x = 10; // Statement 3
    obj.ClassA::y = 10;
    obj.ClassA::z = 10;
 
    obj.b = 20;
    obj.c = 30;
    obj.d = 40;
 
    std::cout << "\n x from ClassB  : " << obj.ClassA::x;
    std::cout << "\n y from ClassC  : " << obj.ClassA::y;
    std::cout << "\n z from ClassC  : " << obj.ClassA::z;
 
    std::cout << "\n B : " << obj.b;
    std::cout << "\n C : " << obj.c;
    std::cout << "\n D : " << obj.d;
    return 0;
}