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
    gvect g,s,sun;

  sun.setvect (-10, -10, 50);
  sun.setcord (-10, -10, 50);
    cam.setvect(2,2,-1);
    cam.setcord(0,0,0);
    sphere.setvect(5,5,0);
    sphere.setradius(3);

//inputs

//clock
//#include <bits/stdc++.h>
   clock_t start, end;
   start = clock();
   std::cout << setprecision(15);
//clock

//main
   // camr.printvect();
   // camr.printcord();
   // cam.printvect();
   // cam.printcord();
   sphere.cameraintersect(&cam,&g);
   sphere.normalofray(&g,&s);
   g.printvect();
   g.printcord();
   sphere.printvect();
   s.printvect();
   s.printcord();

            if(((g.z<=0))){
               std::cout << "+1";
            }else{
               std::cout << "-1";
            }
            if(sphere.intersect(&cam)){
               std::cout << "+12";
            }else{
               std::cout << "-12";
            }
            std::cout << (s.anglevect(&sun)/19);

//  std::cout << "\nworking\n";
//     for (double i = 20; i > -20; i=i-1)
//     {
//         for (double j = -80;j < 80; j++){


//            cam.ofsetto(&camray,j/80,i/40);
   
//             if(sphere.intersect(&camray)){
//                std::cout << "+";
//             }else{
//                std::cout << "-";
//             }
//          }
//       std::cout << "\n";
//     }


 
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
 


 std::cout << "complete";
return 0;
}