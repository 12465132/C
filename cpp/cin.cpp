#include <iostream>

#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
double ad1 = 3;
double ad2 = 3;
double ad3 = 3;
double fad1;
double fad2;
double fad3;

fad1 = arctan(sqrt(ad1^2+ad2^2)/ad3);
fad2 = sin(ad2) * sin (ad1);
fad3 = sqrt(ad1^2+ad2^2+ad3^2);
std::cout << "/n" << fad1 << "/n" << fad2 << "/n" << fad3;
}