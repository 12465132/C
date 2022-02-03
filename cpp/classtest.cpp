//#include <conio.h>
#include <iostream>
#include "cordnate.h"

using namespace std;



int main()
{
 
    vect arr;
    pvect ar;
    arr.inputval();
    arr.printval();
    arr.vect2pvect(&ar);
    ar.printval();
    ar.printvaldegree();
    
 
    return 0;

}