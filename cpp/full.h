#include "cordnate.h"


void rendersphere(camerav * cam,sphere * sphere,gvect * sun,char backgroundColor){
     gvect g, s;
     camerav camr;
      std::cout << "\nworking\n";
    int sphereindex = -1;
    double distancefromcam = -1;
    int numberofspheres = sizeof(sphere)/sizeof(sphere[0]);
  for (double i = cam->py; i > -cam->py; i = i - 1){
    for (double j = -cam->px; j < cam->px; j++){
	  cam->ofsetto (&camr, j / cam->px, i / (cam->py*2.11764706));
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
	       std::cout << shadowascii(((s.anglevect(sun)/256)*90),90);
	      
	    }else{
	        std::cout << backgroundColor;
        }
    }
std::cout << "\n";
}
}