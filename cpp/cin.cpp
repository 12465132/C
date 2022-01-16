#include <iostream>

#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
double ad1 = 6;
double ad2 = 6;
double ad3 = 6;
double fad1;
double fad2;
double fad3;

fad1 = atan(sqrt(pow(ad1,2)+pow(ad2,2))/ad3);
if(ad1==0){
if(ad2>0){
fad2 = M_PI/2;
}else if (ad2<0){
fad2 =  3*M_PI/2;
}
}else if(ad1>0){
fad2 = atan(ad2/ad1);
}else if ( ad1<0){
fad2 = atan(ad2/ad1) + M_PI;
}
fad3 = sqrt(pow(ad1,2)+pow(ad2,2)+pow(ad3,2));
std::cout << "\n" << fad1 << "\n" << fad2 << "\n" << fad3 << "\n" << M_PI;
}