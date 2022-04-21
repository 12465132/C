#ifndef structr_H
#define structr_H
#define PI 3.1415926535897932384626433832795028

#include <iostream>
#include <cmath>

long long pow10(int n);
long long digits(long long id,int n);
long long numDigits(long long n);
float dpow10(int n);
float roundn(float x,int n);
bool samesign(float sx,float sy);
float rad2degree(float degree);
float degree2rad(float degree);
void praylight(float angle);
char shadowascii(float l,float rfz);
char raylight(float angle);
float fast_inv_sqrt(float x);
float inv_fast(float x);
void update(struct c l);
void update(struct v l);
void update(struct g l);
void update(struct sphere l);
void normalize(struct c l);
void normalize(struct v l);
void normalize(struct g l);
void set(struct v l,float x,float y,float z);
void set(struct c l,float x,float y,float z);
void set(struct g l,int a,float x,float y,float z);
void set(struct sphere l,int r=1);
void setpixel(struct cam l,int spx,int spy);
float dot(struct camera c,struct sphere s);

struct v{float x,y,z,scalar,length;};
struct g{struct v v;struct v c;};
struct RGB{int R,G,B;};
struct camera {
struct v v;
struct v c;
struct RGB RGB;
    int px=80,py=60;
    float fovx,fovy;
    float mindist=1,maxdist=10000;
    float distancefromcam = -1;
    int sphereindex=-1;
}cam;
struct cameraray {
struct v v;
struct v c;
struct RGB RGB;
    int px=80,py=60;
    float fovx,fovy;
    float mindist=1,maxdist=10000;
    float distancefromcam = -1;
    int sphereindex=-1;
}camr;
struct sphere{
struct RGB RGB;
float r;
bool reflect;
struct v c;
};
struct global {
int bouncestep=2;
struct RGB sky;
struct RGB floor;
struct v sun;
}Global;





void update(struct v l){
l.scalar = fast_inv_sqrt((pow(l.x,2))+pow(l.y,2)+pow(l.z,2));
l.length = sqrt((pow(l.x,2))+pow(l.y,2)+pow(l.z,2));}
void update(struct g l){update(l.v);update(l.c);}
void update(struct sphere l){update(l.c);}

void initialize(struct RGB l){ l.R=0; l.G=0; l.B=0; }
void initialize(struct v l){
l.x=0;l.y=0;l.z=0;
l.scalar=0;
l.length=0;}
void initialize(struct g l){initialize(l.v);initialize(l.c);}
void initialize(struct sphere l){initialize(l.c);initialize(l.RGB);l.r=0;l.reflect=0;}

void normalize(struct v l){
l.scalar = fast_inv_sqrt((pow(l.x,2))+pow(l.y,2)+pow(l.z,2));
l.length = sqrt((pow(l.x,2))+pow(l.y,2)+pow(l.z,2));
l.x = l.x*l.scalar; l.y = l.y*l.scalar; l.z = l.z*l.scalar; }
// void normalize(struct v l){
// l.scalar = fast_inv_sqrt((pow(l.x,2))+pow(l.y,2)+pow(l.z,2));
// l.length = sqrt((pow(l.x,2))+pow(l.y,2)+pow(l.z,2));
// l.x = l.x*l.scalar; l.y = l.y*l.scalar; l.z = l.z*l.scalar; }
void normalize(struct g l){normalize(l.v);}

void set(struct g l,int a,float x,float y,float z){
if(a==1){set(l.v,x,y,z);}else if(a==0)
{set(l.c,x,y,z);}else{return;}update(l);} //a=1=vector,a=0=cord
void set(struct v * l,float x,float y,float z){l.x=x;l.y=y;l.z=z;update(l);}
void set(struct sphere l,float r){l.r=r;}
void setColor(struct RGB l,int r,int g,int b){l.R=r;l.G=g;l.B=b;};
void setpixel(struct camera l,int spx,int spy){l.px=spx,l.py=spy;}
void set(struct camera l,int spx,int  spy,float sfovx,float  sfovy,float  smindist, float smaxdist){
  l.px=spx,l.py=spy;
  l.fovx=sfovx,l.fovy=sfovy;
  l.mindist=smindist,l.maxdist=smaxdist;  
}

RGB RGBT(int R,int G,int B){struct RGB l;l.R=R;l.G,l.B=G;return l;}
RGB RGBaverage(struct RGB C1,struct RGB C2){struct RGB l; l.R=((C1.R+C2.R)*.5); l.G=((C1.G+C2.G)*.5); l.B=((C1.B+C2.B)*.5);
   return l;}
float dot(struct v i,struct v o)
{return ((i.x*o.x)+(i.y*o.y)+(i.z*o.z));}
float dot(struct camera c,struct sphere s)
{return (((s.c.x-c.c.x)*c.v.x) + ((s.c.y-c.c.y)*c.v.y) + ((s.c.z-c.c.z)*c.v.z));}

void offset(struct camera c,struct cameraray cr,float xs,float ys){
float v  = fast_inv_sqrt((c.v.x*c.v.x) + (c.v.y*c.v.y));
float v2 = fast_inv_sqrt((c.v.x*c.v.x) + (c.v.y*c.v.y) + (c.v.z*c.v.z));
    cr.v.x  = c.v.x + (0-(c.v.y*xs)-(c.v.x*c.v.z*ys*v2))*v;
    cr.v.y  = c.v.y + (0+(c.v.x*xs)-(c.v.y*c.v.z*ys*v2))*v;
    cr.v.z  = c.v.z + (inv_fast(v) * ys * v2);
    cr.c.x = c.c.x;
    cr.c.y = c.c.y;
    cr.c.z = c.c.z;
}
//void offset(camera,float xs,float ys){}
bool Qintersectsphere(struct camera c,struct sphere s){
float DT = dot(c,s);
float final =sqrt(
    pow((s.c.x-c.c.x) - (DT*c.v.x*c.v.scalar*c.v.scalar),2) + 
    pow((s.c.y-c.c.y) - (DT*c.v.y*c.v.scalar*c.v.scalar),2) + 
    pow((s.c.z-c.c.z) - (DT*c.v.z*c.v.scalar*c.v.scalar),2));

if (final<s.r){return true;}else{return false;}
}
bool intersectsphere(struct camera c,struct sphere s,struct g g){
float N = c.v.scalar;
float DT = dot(c,s);
float store =
  ((s.c.x-c.c.x) - ((DT*c.v.x*N*N))*((s.c.x-c.c.x) - (DT*c.v.x*N*N))) + 
  ((s.c.y-c.c.y) - ((DT*c.v.y*N*N))*((s.c.y-c.c.y) - (DT*c.v.y*N*N))) + 
  ((s.c.z-c.c.z) - ((DT*c.v.z*N*N))*((s.c.z-c.c.z) - (DT*c.v.z*N*N))) ;
float final = sqrt(store);
float BS = sqrt((s.r*s.r) - abs(store));
  
float s4x = ((DT*c.v.x*N*N)-(BS*c.v.x*N));
float s4y = ((DT*c.v.y*N*N)-(BS*c.v.y*N));
float s4z = ((DT*c.v.z*N*N)-(BS*c.v.z*N));

if(
(std::signbit(c.v.x)==std::signbit(s4x)) && 
(std::signbit(c.v.y)==std::signbit(s4y)) && 
(std::signbit(c.v.z)==std::signbit(s4z))){

set(g.c,c.c.x,c.c.y,c.c.z);
set(g.v, s4x , s4y , s4z );
if (final<s.r){
    return true;
}else{
    return false;
}
}else{
set(g.v, NAN, NAN, NAN);
set(g.c, NAN, NAN, NAN);
return false;
}
}
bool intersectsphere(struct cameraray c,struct sphere s,struct g g){
float N = c.v.scalar;
float DT = dot(c.v,s.c);
  
float store =
  ((s.c.x-c.c.x) - ((DT*c.v.x*N*N))*((s.c.x-c.c.x) - (DT*c.v.x*N*N))) + 
  ((s.c.y-c.c.y) - ((DT*c.v.y*N*N))*((s.c.y-c.c.y) - (DT*c.v.y*N*N))) + 
  ((s.c.z-c.c.z) - ((DT*c.v.z*N*N))*((s.c.z-c.c.z) - (DT*c.v.z*N*N))) ;
float final = sqrt(store);
float BS = sqrt((s.r*s.r) - abs(store));
  
float s4x = ((DT*c.v.x*N*N)-(BS*c.v.x*N));
float s4y = ((DT*c.v.y*N*N)-(BS*c.v.y*N));
float s4z = ((DT*c.v.z*N*N)-(BS*c.v.z*N));

if(
(std::signbit(c.v.x)==std::signbit(s4x)) && 
(std::signbit(c.v.y)==std::signbit(s4y)) && 
(std::signbit(c.v.z)==std::signbit(s4z))){

set(g.c,c.c.x,c.c.y,c.c.z);
set(g.v, s4x , s4y , s4z );
if (final<s.r){
    return true;
}else{
    return false;
}
}else{
set(g.v, NAN, NAN, NAN);
set(g.c, NAN, NAN, NAN);
return false;
}
}
struct RGB trace(struct cameraray c,struct sphere s[],struct global p){
int numberofspheres = sizeof(sphere)/sizeof(sphere[0]),sphereindex=-1, bounce=0;
float distancefromcam = -1,N,dtn,store;
float s4x,s5x,s6cx,s6vx,DT;
float s4y,s5y,s6cy,s6vy,final;
float s4z,s5z,s6cz,s6vz,BS;
struct g g,g2,g3;
struct cameraray camr;
initialize(g);
for (int i = 0; i < numberofspheres; i++){
 N = c.v.scalar;
 DT = dot(c.v,s[i].c);
  store =
  ((s[i].c.x-c.c.x) - ((DT*c.v.x*N*N))*((s[i].c.x-c.c.x) - (DT*c.v.x*N*N))) + 
  ((s[i].c.y-c.c.y) - ((DT*c.v.y*N*N))*((s[i].c.y-c.c.y) - (DT*c.v.y*N*N))) + 
  ((s[i].c.z-c.c.z) - ((DT*c.v.z*N*N))*((s[i].c.z-c.c.z) - (DT*c.v.z*N*N))) ;
 final = sqrt(store);
 s4x = (DT*c.v.x*N*N);
 s4y = (DT*c.v.y*N*N);
 s4z = (DT*c.v.z*N*N);

if (
(std::signbit(c.v.x)==std::signbit(s4x)) &&
(std::signbit(c.v.y)==std::signbit(s4y)) &&
(std::signbit(c.v.z)==std::signbit(s4z)) &&
(final<s[i].r)){

BS = sqrt((s[i].r*s[i].r) - abs(store));
s5x = (s4x-(BS*c.v.x*N));
s5y = (s4y-(BS*c.v.y*N));
s5z = (s4z-(BS*c.v.z*N));
set(g,-1,s5x,s5y,s5z);
    if(!(distancefromcam==g.v.length)){
        if((distancefromcam!=-1)&&((distancefromcam<c.mindist)||(distancefromcam>c.maxdist))){
            distancefromcam=-1;
            if((g.v.length>c.mindist)&&(g.v.length<c.maxdist)){
                if (distancefromcam==-1){
                    distancefromcam=g.v.length;
                    sphereindex=i;

            }else{
                if (distancefromcam>g.v.length){
                    distancefromcam=g.v.length;
                    sphereindex=i;

                }}}
        }else{
            if((g.v.length>c.mindist)&&(g.v.length<c.maxdist)){
                if (distancefromcam==-1){
                    distancefromcam=g.v.length;
                    sphereindex=i;

            }else{
                if (distancefromcam>g.v.length){
                    distancefromcam=g.v.length;
                    sphereindex=i;

    }}}}}}}
if (sphereindex!=-1){
if ((s[sphereindex].reflect==1) && (p.bouncestep>0)){
    intersectsphere(c,s[sphereindex],g);
    set(g2.v ,g.c.x+g.v.x-s[sphereindex].c.x ,g.c.y+g.v.y-s[sphereindex].c.y ,g.c.z+g.v.z-s[sphereindex].c.z );
    normalize(g2.v);
    dtn = 2*dot(g.v,g2.v);
    //initialize(camr);
    set(camr.v, g.v.x-(g2.v.x*dtn), g.v.y-(g2.v.y*dtn), g.v.z-(g2.v.z*dtn));
    set(camr.c, g.v.x+s[sphereindex].c.x, g.v.y+s[sphereindex].c.y, g.v.z+s[sphereindex].c.z);
    p.bouncestep = p.bouncestep-1;
  return RGBaverage(s[sphereindex].RGB,trace(camr,s,p));
 }else{
  return s[sphereindex].RGB;
 } 
	    }else{
//////////////////////////////////// work needed
        return p.sky;
//////////////////////////////////// work needed
        }
}

char shadowascii(float l,float rfz){
char ascii[69] =
{46, 39, 96, 94, 34, 44, 58, 59, 73, 108, 33, 105, 62, 60, 126, 43, 95, 45, 63,
93, 91, 125, 123, 49, 41, 40, 124, 92, 47, 116, 102, 106, 114, 120, 110, 117,
118, 99, 122, 88, 89, 85, 74, 67, 76, 81, 48, 79, 90, 109, 119, 113, 112, 100,
98, 107, 104, 97, 111, 42, 35, 77,87, 38, 56, 37, 66, 64, 36};
float storeascii = ((l/rfz)*69);
return ascii[(int)storeascii];
}

void praylight(float angle){
if (angle<=90){
std::cout << shadowascii(((angle/90)*256),256);  
}else{
std::cout << " ";
    return;
}}
char raylight(float angle){
if (angle<=90){
return shadowascii(((angle/90)*256),256);  
}else{
return char(32);
}}
long long digits(long long id,int n)
{
return id/pow10(n) % 10;//gets in divisual value using mod 10 once shifted
}
long long pow10(int n){
    long long result = 1;

    for(int x=0;x<n;x++){
        result*=10;
    }

    return result;
}
long long numDigits(long long n)
{
    if (n < 10) return 1;
    return 1 + numDigits(n / 10);
}
float dpow10(int n){
    float result = 1;

    for(int x=0;x<n;x++)
    {
        result*=10; 
    }

    return result; 
}
float roundn(float x,int n){
long long result = 0;
return (ceil(x * dpow10(n)) / dpow10(n));
}
float sdotproduct(float sx,float sy,float sz,float cx,float cy,float cz,float ccx,float ccy,float ccz){
return (((sx-ccx)*cx) + ((sy-ccy)*cy) + ((sz-ccz)*cz));
}
bool samesign(float sx,float sy)
{
    return ((fabs(sx)/sx)==(fabs(sy)/sy));
}
float degree2rad(float degree){
    return ((PI*degree)/180);
}
float rad2degree(float degree){
    return ((180*degree)/PI);
}
float fast_inv_sqrt(float x)
{
    float y = x; // y holds the current guess for 1/sqrt(x)
    uint32_t *i = reinterpret_cast<uint32_t *>(&y); // i points to current guess y
    const uint32_t exp_mask = 0x7F800000; // 0xFF<<23
    const uint32_t magic_number = 0x5f000000; // 190<<23

    // initial guess using magic number
    *i = magic_number - ((*i >> 1) & exp_mask);

    // refine guess using small number of Newton iterations
    const size_t num_newton_iter = 2;
    for (size_t i = 0; i < num_newton_iter; ++i)
    {
        y = (x * y * y + 1) / (2 * x * y);
    }

    return y;
}
float inv_fast(float x) {
    union { float f; int i; } v;
    float w, sx;
    int m;

    sx = (x < 0) ? -1:1;
    x = sx * x;

    v.i = (int)(0x7EF127EA - *(uint32_t *)&x);
    w = x * v.f;

    // Efficient Iterative Approximation Improvement in horner polynomial form.
    v.f = v.f * (2 - w);     // Single iteration, Err = -3.36e-3 * 2^(-flr(log2(x)))
    v.f = v.f * ( 4 + w * (-6 + w * (4 - w)));  // Second iteration, Err = -1.13e-5 * 2^(-flr(log2(x)))
    v.f = v.f * (8 + w * (-28 + w * (56 + w * (-70 + w *(56 + w * (-28 + w * (8 - w)))))));  // Third Iteration, Err = +-6.8e-8 *  2^(-flr(log2(x)))

    return v.f * sx;
}
    #endif
