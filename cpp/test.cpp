//#include <conio.h>
#include <iostream>
#include "cordnate.h"
#include <bits/stdc++.h>
using namespace std;


//COLORREF backgroundColor = RGB(255, 255, 255);


int
main ()
{

// //inputs cpp

// //inputs cpp

//inputs

  camerav cam;
  camerav camr;
  sphere sphere[3];
  gvect g, s, sun;

  sun.setvect(0,0,1);
  cam.setvect(-1, -1, -1);
  cam.setcord(15,15,15);
  cam.camreasetpixel(3,2);
  sphere[0].setvect(3,3, 1);
  sphere[0].setradius(2);
  sphere[1].setvect(-3,-3, 1);
  sphere[1].setradius(2);
  sphere[2].setvect(-4,4, -1);
  sphere[2].setradius(2.5);
  sphere[3].setvect(4,-4, -1);
  sphere[3].setradius(2.5);
  sun.normalize();
int numberofspheres = sizeof(sphere)/sizeof(sphere[0]),sphereindex=-1;
double distancefromcam = -1;
//inputs

//clock
//#include <bits/stdc++.h>
  clock_t start, end;
  start = clock ();
  std::cout << setprecision (15);
//clock

//main
  // cam.ofsetto(&camr,0,0);
  // camr.printvect();
  // camr.printcord();
  // cam.printvect();
  // cam.printcord();




  std::cout << "\nworking\n";
  std::cout << setprecision(3);
  for (double i = cam.py; i > -cam.py; i = i - 1){
    for (double j = -cam.px; j < cam.px; j++){
	  cam.ofsetto (&camr, j / cam.px, i / (cam.py*2.11764706));
    for (int k = 0; k < numberofspheres; k++){
        	  if (sphere[k].cameraintersect(&camr, &g)){
	          sphere[k].normalofray (&g, &s);
              if(!(distancefromcam==g.scalar)){
                  if((distancefromcam!=-1)&&((distancefromcam<camr.mindist)||(distancefromcam>camr.maxdist))){
                      distancefromcam=-1;
                      if((g.scalar>camr.mindist)&&(g.scalar<camr.maxdist)){
                          if (distancefromcam==-1){
                              distancefromcam=g.scalar;
                              sphereindex=k;
                              
                      }else{
                          if (distancefromcam>g.scalar){
                              distancefromcam=g.scalar;
                              sphereindex=k;
                              
                          }}}
                  }else{
                      if((g.scalar>camr.mindist)&&(g.scalar<camr.maxdist)){
                          if (distancefromcam==-1){
                              distancefromcam=g.scalar;
                              sphereindex=k;
                              
                      }else{
                          if (distancefromcam>g.scalar){
                              distancefromcam=g.scalar;
                              sphereindex=k;
                              
              }}}}}
	      
	    }
    }
	  if (sphereindex!=-1){
        sphere[sphereindex].cameraintersect(&camr, &g);
	      sphere[sphereindex].normalofray (&g, &s);
	       std::cout << shadowascii(((s.anglevect(&sun)/256)*90),90);
	      
	    }else{
	        std::cout << char(176);
        }
    }
std::cout << "\n";
}
    
    
//     char ascii2[69] =
// {46, 39, 96, 94, 34, 44, 58, 59, 73, 108, 33, 105, 62, 60, 126, 43, 95, 45, 63,
// 93, 91, 125, 123, 49, 41, 40, 124, 92, 47, 116, 102, 106, 114, 120, 110, 117,
// 118, 99, 122, 88,89, 85, 74, 67, 76, 81, 48, 79, 90, 109, 119, 113, 112, 100,
// 98, 107, 104, 97, 111, 42, 35, 77,87, 38, 56, 37, 66, 64, 36};
//   std::cout << "\n" << shadowascii(1.879898,10) << ascii2[1] << ascii2[3] << ascii2[59];
// for (double i=0;i<90;i++) {
// std::cout <<char(raylight(i))<<"\n";
// }
//$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'.

//main

//clock end
  end = clock ();
  // Calculating total time taken by the program.
  double time_taken = double (end - start) / double (CLOCKS_PER_SEC);
  cout << "\nTime taken by program is : " << fixed
    << time_taken << setprecision (5);
  cout << " sec " << endl;
//clock end



  std::cout << "done";
  return 0;
}



















// //#include <conio.h>
// #include <iostream>
// #include "cordnate.h"
// #include <bits/stdc++.h>
// using namespace std;


// //COLORREF backgroundColor = RGB(255, 255, 255);


// int main()
// {

// // //inputs cpp
// // int int1;
// // int int2;
// // char int3;
// // char int4;
// // std::cout << "\n" << "function:/*function of program*/"  /*function of program*/
// //  << "\n" << "Enter value: \n";
// //  std::cout <<"Entered x:";
// // std::cin >> int1;
// //  std::cout <<"Entered y:";
// // std::cin >> int2;
// //  std::cout <<"Entered n:";
// // std::cin >> int3;
// //  std::cout <<"Entered n:";
// // std::cin >> int4;
// // std::cout
// //  <<"Entered value:" << int1 << "\n"
// //  <<"Entered value:" << int2 << "\n"
// //  <<"Entered value:" << int3 << "\n""\n";
// // //inputs cpp

// //inputs

//     camerav cam;
//     camerav camr;
//     sphere sphere;
//     gvect g,s,sun;

//   sun.setvect (-10, -10, 10);
//   sun.setcord (-10, -10, 10);
//     cam.setvect(2,2,-1);
//     cam.setcord(0,0,0);
//     sphere.setvect(5,5,0);
//     sphere.setradius(3);

// //inputs

// //clock
// //#include <bits/stdc++.h>
//    clock_t start, end;
//    start = clock();
//    std::cout << setprecision(15);
// //clock

// //main
//    // camr.printvect();
//    // camr.printcord();
//    // cam.printvect();
//    // cam.printcord();
//    sphere.cameraintersect(&cam,&g);
//    sphere.normalofray(&g,&s);
//    g.printvect();
//    g.printcord();
//    sphere.printvect();
//    s.printvect();
//    s.printcord();

//             if(((g.z<=0))){
//                std::cout << "+1";
//             }else{
//                std::cout << "-1";
//             }
//             if(sphere.intersect(&cam)){
//                std::cout << "+12";
//             }else{
//                std::cout << "-12";
//             }
//             double speed =(s.anglevect(&sun));
//             std::cout << speed;

// //  std::cout << "\nworking\n";
// //     for (double i = 20; i > -20; i=i-1)
// //     {
// //         for (double j = -80;j < 80; j++){


// //            cam.ofsetto(&camray,j/80,i/40);
   
// //             if(sphere.intersect(&camray)){
// //                std::cout << "+";
// //             }else{
// //                std::cout << "-";
// //             }
// //          }
// //       std::cout << "\n";
// //     }


 
// // sphere.cameraintersect(&cam,&g);
// //     g.printcord();
// //     g.printvect();
// //     sphere.printradius();

// //main
 
// //clock end
//    end = clock();
//     // Calculating total time taken by the program.
//    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
//    cout << "\nTime taken by program is : " << fixed
//     << time_taken << setprecision(5);
//    cout << " sec " << endl;
// //clock end
 


//  std::cout << "complete";
// return 0;
// }