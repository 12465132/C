//#include <conio.h>
#include <iostream>
#include "cordnate.h"
#include <bits/stdc++.h>
using namespace std;



int main () {


//inputs
  camerav cam;
  camerav camr;
  sphere sphere[25];
  gvect g, s, sun;

  sun.setvect(1,-1,10);
  cam.setvect(-1, -1, -1);
  cam.setcord(50,50,50);
  cam.camreasetpixel(900,200);
  sphere[0].setvect(-2,2, -4);
  sphere[0].setradius(7);
  sphere[1].setvect(2,-2,-4.5);
  sphere[1].setradius(7);
int numberofspheres = sizeof(sphere)/sizeof(sphere[0]),sphereindex=-1;
double distancefromcam = -1;
for (int i = 2; i < numberofspheres-2; i++){sphere[i].setvect(0,0, i+1);sphere[i].setradius(4);}
//inputs

//clock start
//#include <bits/stdc++.h>
  clock_t start, end;
  start = clock ();
  std::cout << setprecision (15);
//clock start

//main




  std::cout << "\nworking\n";
  std::cout << setprecision(3);
  for (double i = cam.py; i > -cam.py; i = i - 1){
    for (double j = -cam.px; j < cam.px; j++){
	  cam.ofsetto (&camr, j / cam.px, i / (cam.py*2.11764706));
    sphereindex = -1;
    distancefromcam = -1;
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