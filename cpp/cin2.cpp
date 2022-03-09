//#include <conio.h>
#include <iostream>
#include "cordnate2.h"
#include <bits/stdc++.h>
using namespace std;



int main () {


//inputs
struct sphere sphere[125];
struct g sun;

initialize(sphere);
initialize(sun);
Global.sky = RGBT(50,60,250)
//inputs
for (int i = 0; i < 125; i++){
set(sphere[i].c,
2*(round((i)%5)       ),
2*(round(int(i*.2)%5 )),
2*(round(int(i*.04)%5)));
sphere[i].setradius(.5);
}
//clock start
//#include <bits/stdc++.h>
  clock_t start, end;
  start = clock ();
  std::cout << setprecision (15);
//clock start

//main





    
//     char ascii2[69] =
// {46, 39, 96, 94, 34, 44, 58, 59, 73, 108, 33, 105, 62, 60, 126, 43, 95, 45, 63,
// 93, 91, 125, 123, 49, 41, 40, 124, 92, 47, 116, 102, 106, 114, 120, 110, 117,
// 118, 99, 122, 88,89, 85, 74, 67, 76, 81, 48, 79, 90, 109, 119, 113, 112, 100,
// 98, 107, 104, 97, 111, 42, 35, 77,87, 38, 56, 37, 66, 64, 36};
//   std::cout << "\n" << shadowascii(1.879898,10) << ascii2[1] << ascii2[3] << ascii2[59];
// for (float i=0;i<90;i++) {
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