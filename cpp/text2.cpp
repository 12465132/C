#include <iostream>
#include <cordnate_H>
using namespace std;


class ClassA {
public:
    int x;
    int y;
    int z;
};

class ClassB : public ClassA {
public:
    int w;
};
int main()
{
 
    vect obj;
    obj.x = 10; 
    obj.y = 10;
    obj.z = 10;
 
    std::cout << "\n x from ClassB  : " << obj.x;
    std::cout << "\n y from ClassB  : " << obj.y;
    std::cout << "\n z from ClassB  : " << obj.z;
 
    return 0;

}

class ClassA {
public:
    void printval(void);
    void inputval(void);
    double x;
    double y;
    double z;
};

class pvect : public ClassA {
public:
void pvect2vect(class vect c);
//    float b;
};

class vect : public ClassA {
public:
void vect2pvect(class pvect c);
};

class cord : public ClassA {
public:
//    float d;

};

void ClassA::printval(){
    std::cout << "x : " << x << "\n";
    std::cout << "y : " << y << "\n";
    std::cout << "z : " << z << "\n";
    }
void ClassA::inputval(void){

    std::cout << "\n" << "x :";
    std::cin >> x ;
    std::cout << "\n" << "y :";
    std::cin >> y ;
    std::cout << "\n" << "z :";
    std::cin >> z ;
    std::cout << "\n";
    }
void pvect::pvect2vect(vect c) {
      c.x = sin(y) * cos (x);
      c.y = sin(y) * sin (x);
      c.z = cos(y);
    }
void vect::vect2pvect(pvect c){
    c.x= atan(sqrt(pow(x,2)+pow(y,2))/z);
    c.y= atan(y/z);
    c.z= sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    }
