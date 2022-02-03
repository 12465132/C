//#include <conio.h>
#include <iostream>
#include "cordnate.h"

using namespace std;



int main()
{
    int a=100000;//vsc array limit :294||
    vect arr2;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0;j < a; j++){
            arr2.addval(rand(),rand(),rand());
        }
    }
    
//    arr.inputval();
//    arr.printval();
//    arr.vect2pvect(&ar);
//    ar.printval();
//    ar.printvaldegree();
 printf("complete");
    return 0;

}