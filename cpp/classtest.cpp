//#include <conio.h>
#include <iostream>

using namespace std;


class ClassA {
public:
    int x;
    int y;
    int z;
};

int main()
{
 
    ClassA obj;
    obj.x = 10; 
    obj.y = 10;
    obj.z = 10;
 
    std::cout << "\n x from ClassB  : " << obj.x;
    std::cout << "\n y from ClassC  : " << obj.y;
    std::cout << "\n z from ClassC  : " << obj.z;
 
    return 0;

}