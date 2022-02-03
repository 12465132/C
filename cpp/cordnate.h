// name file cordnate.h
#ifndef cordnate_H
#define cordnate_H
#define PI 3.1415926535897932384626433832795028
#include <iostream>
#include <cmath>

long long pow10(int n);
long long digits(long long id,int n);
long long numDigits(long long n);

class ClassA {
public:
    void printval(void);
    void inputval(void);
    void setval(int x1,int y1,int z1);
    double x;
    double y;
    double z;
};

class pvect : public ClassA {
public:
void pvect2vect(class  vect * c);
void printvaldegree(void);

//    float b;
};

class vect : public ClassA {
public:
void vect2pvect(class  pvect * c);
};

class cord : public ClassA {
public:
//float d;

};

class camerav : public vect, public cord {
    
};
class sphere : public vect {
float d;
};

void ClassA::printval(){
    std::cout << "x : " << x << "\n";
    std::cout << "y : " << y << "\n";
    std::cout << "z : " << z << "\n";
}
void ClassA::inputval(void){
    std::cout << "\n" << "x :";
    std::cin >> x ;
    std::cout << "y :";
    std::cin >> y ;
    std::cout << "z :";
    std::cin >> z ;
    std::cout << "\n";
}
void pvect::pvect2vect(vect * c) {
      c->x = sin(y) * cos (x);
      c->y = sin(y) * sin (x);
      c->z = cos(y);
}
void vect::vect2pvect(pvect * c){
    c->x= sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    c->y=  atan2(y,z);
    c->z= atan(sqrt(pow(x,2)+pow(y,2))/z);
}
void ClassA::setval(int x1,int y1,int z1){
    x=x1;
    y=y1;
    z=z1;
}
void pvect::printvaldegree(){
    std::cout << "x : " << x << "\n";
    std::cout << "y : " << (y * 180)/PI << "\n";
    std::cout << "z : " << (z * 180)/PI  << "\n";
}


long long digits(long long id,int n)
{
return id/pow10(n) % 10;//gets in divisual value using mod 10 once shifted
}
long long pow10(int n){
    long long result = 1;

    for(int x=0;x<n;x++)// counts down amount of multiplacation
    {
        result*=10; // result * 10 = result
    }

    return result; //return
}
long long numDigits(long long n)
{
    if (n < 10) return 1;
    return 1 + numDigits(n / 10);
}

#endif