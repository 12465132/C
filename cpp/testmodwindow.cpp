//#include <conio.h>
#include <iostream>
#include "cordnate.h"
#include <bits/stdc++.h>
using namespace std;


//COLORREF backgroundColor = RGB(255, 255, 255);


int main()
{

// //inputs cpp
// int int1;
// int int2;
// char int3;
// char int4;
// std::cout << "\n" << "function:/*function of program*/"  /*function of program*/
//  << "\n" << "Enter value: \n";
//  std::cout <<"Entered x:";
// std::cin >> int1;
//  std::cout <<"Entered y:";
// std::cin >> int2;
//  std::cout <<"Entered n:";
// std::cin >> int3;
//  std::cout <<"Entered n:";
// std::cin >> int4;
// std::cout
//  <<"Entered value:" << int1 << "\n"
//  <<"Entered value:" << int2 << "\n"
//  <<"Entered value:" << int3 << "\n""\n";
// //inputs cpp

//inputs

    camerav cam;
    camerav camr;
    sphere sphere;
    gvect g,s;

    cam.setvect(-1,1,0);
    cam.setcord(10,0,0);
    sphere.setvect(5,5,1);
    sphere.setradius(1);

//inputs

//clock
//#include <bits/stdc++.h>
   clock_t start, end;
   start = clock();
   std::cout << setprecision(15);
//clock

//main
   // cam.ofsetto(&camr,0,0);
   // camr.printvect();
   // camr.printcord();
   // cam.printvect();
   // cam.printcord();



   //          if(sphere.intersect(&camr)){
   //             std::cout << "+";
   //          }else{
   //             std::cout << "-";
   //          }
   //          if(sphere.intersect(&cam)){
   //             std::cout << "+";
   //          }else{
   //             std::cout << "-";
   //          }
    for (double i = 200; i > -200; i=i-1)
    {
        for (double j = -800;j < 800; j++){


           cam.ofsetto(&camr,j/800,i/200);
   
            if(sphere.cameraintersect(&camr,&g)){
               sphere.cameraintersect(&camr,&g);
                sphere.normalofray(&g,&s);
               if(((s.z<=0))){
                  SetPixel(hdc,j,i,shadow);
               }else{
                  SetPixel(hdc,j,i,sphere1);
               }
            }else{
               if(camr.z<=0){
                  SetPixel(hdc,j,i,floor);
               }else{
                  SetPixel(hdc,j,i,sky);
               }
            }
         }
    }


 
// sphere.cameraintersect(&cam,&g);
//     g.printcord();
//     g.printvect();
//     sphere.printradius();

//main
 
//clock end
   end = clock();
    // Calculating total time taken by the program.
   double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
   cout << "\nTime taken by program is : " << fixed
    << time_taken << setprecision(5);
   cout << " sec " << endl;
//clock end
