//#include <conio.h>
#include <iostream>
#include "cordnate.h"
#include <bits/stdc++.h>
using namespace std;



int main()
{



//inputs


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
for (int i = 0; i < 200; i++)
{
   for (int i = 0; i <1600; i++)
   {
      std::cout << "M";
   }
   std::cout << "\n";
}


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