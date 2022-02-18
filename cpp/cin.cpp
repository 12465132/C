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
  sphere sphere;
  gvect g, s, sun;

  sun.inputvect();
  cam.setvect(1, 1, 0);
  cam.setcord(0, 0, 0);
  cam.camreasetpixel(100,25);
  sphere.setvect(5, 5, .5);
  sphere.setradius(2);
  sun.normalize();
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
  for (double i = cam.py; i > -cam.py; i = i - 1)
    {
      for (double j = -cam.px; j < cam.px; j++)
	{


	  cam.ofsetto (&camr, j / cam.px, i / (cam.py*2));

	  if (sphere.cameraintersect(&camr, &g))
	    {
	      sphere.cameraintersect (&camr, &g);
	      sphere.normalofray (&g, &s);
	      s.normalize();
	       std::cout << shadowascii(((s.anglevect(&sun)/128)*69),69);
	      
	    }
	  else
	    {
	      if (camr.z < 0)
		{
		  std::cout << "8";
		}
	      else
		{
		  std::cout << "1";
		}
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