//name file cordnate.h
#ifndef cordnate_H
#define cordnate_H
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
class ClassA {
public:
    void printvect(void);
    void inputvect(void);
    void setvect(float x1,float y1,float z1);
    void addvect(float x1,float y1,float z1);
    void printcord(void);
    void inputcord(void);
    void setcord(float x1,float y1,float z1);
    void addcord(float x1,float y1,float z1);
    float dist(ClassA * c);
    void pdist(ClassA * c);
    void normalizeto(ClassA * c);
    float dotproduct(ClassA * c);
    float tdotproduct(float x1,float y1,float z1);
    void normalize(void);

    float x  = 0;
    float y  = 0;
    float z  = 0;
    float cx = 0;
    float cy = 0;
    float cz = 0;
    float scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
};

class pvect : public ClassA {
public:
void pvect2vect(class  vect * c);
void printvaldegree(void);

//    float b;
};

class vect : public ClassA {
public:
void vect2pvect(class  pvect * c);
};

class gvect : public vect {
    public:
    float anglevect(gvect * s);
    float anglevect(gvect ** s);
    
};

class camerav : public vect{
    public:
    float px=40,py=160;
    float fovx,fovy;
    float mindist=1,maxdist=10000;
    void ofsetto(camerav * s,float x1,float y1);
    void camreaprint();
    void camreasetpixel(float z1,float w1);
    void camreasetfov(float z1,float w1);
    void camreainputvect(void);
    float distfromgvects(gvect * m);
   };

class sphere : public vect {
    public:
float r;
float dist;
bool intersect(class  camerav * c);
bool cameraintersect(class  camerav * c,class  gvect * t);
void printradius(void);
void inputradius(void);
void setradius(float r1);
void printdist();
void ofsetcam(float x1,float y1);
void normalofray(gvect * c,gvect * n);
};

class light : public vect {
    public:

};

void ClassA::printvect(){
    std::cout << "x : " << x << "\n";
    std::cout << "y : " << y << "\n";
    std::cout << "z : " << z << "\n";
}
void ClassA::inputvect(void){
    std::cout << "\n" << "x :";
    std::cin >> x ;
    std::cout << "y :";
    std::cin >> y ;
    std::cout << "z :";
    std::cin >> z ;
    std::cout << "\n";
    scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
}
void ClassA::setvect(float x1,float y1,float z1){
    x=x1;
    y=y1;
    z=z1;
    scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
}
void ClassA::addvect(float x1,float y1,float z1){
    x+=x1;
    y+=y1;
    z+=z1;
    scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
}
void ClassA::printcord(){
    std::cout << "cx : " << cx << "\n";
    std::cout << "cy : " << cy << "\n";
    std::cout << "cz : " << cz << "\n";
}
void ClassA::inputcord(void){
    std::cout << "\n" << "cx :";
    std::cin >> cx ;
    std::cout << "cy :";
    std::cin >> cy ;
    std::cout << "cz :";
    std::cin >> cz ;
    std::cout << "\n";
    scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
}
void ClassA::setcord(float x1,float y1,float z1){
    cx=x1;
    cy=y1;
    cz=z1;
    scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
}
void ClassA::addcord(float x1,float y1,float z1){
    cx+=x1;
    cy+=y1;
    cz+=z1;
    scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
}
void pvect::pvect2vect(vect * c) {
      c->x = sin(y) * cos (x);
      c->y = sin(y) * sin (x);
      c->z = cos(y);
}
void vect::vect2pvect(pvect * c){
    c->x= sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    c->y=  atan2(y,z);
    c->z= atan(sqrt(pow(x,2)+pow(y,2))/z);
}
void pvect::printvaldegree(){
    std::cout << "x : " << x << "\n";
    std::cout << "y : " << (y * 180)/PI << "\n";
    std::cout << "z : " << (z * 180)/PI  << "\n";
}
float ClassA::dist(ClassA * c){
   return sqrt((pow((x-c->x),2)+pow((y-c->y),2)+pow((z-c->z),2)));
}
void ClassA::pdist(ClassA * c){
   std::cout << sqrt((pow((x-c->x),2)+pow((y-c->y),2)+pow((z-c->z),2)));
}
bool sphere::cameraintersect(class  camerav * c,class  gvect * t){

float N = c->scalar;
float DT = dotproduct(c);
float sx = (x-c->cx);
float sy = (y-c->cy);
float sz = (z-c->cz);
float s2x = ((DT*(c->x))/(pow(N,2)));
float s2y = ((DT*(c->y))/(pow(N,2)));
float s2z = ((DT*(c->z))/(pow(N,2)));
float s3x = sx - s2x;
float s3y = sy - s2y;
float s3z = sz - s2z;
float final = sqrt(pow(s3x,2) + pow(s3y,2) + pow(s3z,2));
float BS = sqrt( pow(r,2) - pow(sqrt(pow(s3x,2) + pow(s3y,2) + pow(s3z,2)) ,2));
float s4x = (((DT*(c->x))/(pow(N,2)))-((BS*(c->x))/N));
float s4y = (((DT*(c->y))/(pow(N,2)))-((BS*(c->y))/N));
float s4z = (((DT*(c->z))/(pow(N,2)))-((BS*(c->z))/N));

////////////////////////////////////////

////////////////////////////////////////

if(
(std::signbit(c->x)==std::signbit(s4x)) && 
(std::signbit(c->y)==std::signbit(s4y)) && 
(std::signbit(c->z)==std::signbit(s4z))){

t->setvect( s4x , s4y , s4z );
t->setcord(c->cx,c->cy,c->cz);
dist = c->vect::dist(t);

if (final<r){
    return true;
}else{
    return false;
}
}else{
t->setvect( NAN, NAN, NAN);
t->setcord( NAN, NAN, NAN);
dist = c->vect::dist(t);
return false;

}

// debug code (put in debug spot first)
/*

////////////////////////////////////////
std::cout << "\n" << pow(s3x,2);
std::cout << "\n" << pow(s3y,2);
std::cout << "\n" << pow(s3z,2) << "\n";
std::cout << "\n" << (c->x);
std::cout << "\n" << (c->y);
std::cout << "\n" << (c->z) << "\n";
std::cout << "\nsx= " << sx;
std::cout << "\nsy= " << sy;
std::cout << "\nsz= " << sz << "\n";
std::cout << "\ns2x= " << s2x;
std::cout << "\ns2y= " << s2y;
std::cout << "\ns2z= " << s2z << "\n";
std::cout << "\ns3x= " << s3x;
std::cout << "\ns3y= " << s3y;
std::cout << "\ns3z= " << s3z << "\n";
std::cout << "\ns4x= " << s4x;
std::cout << "\ns4y= " << s4y;
std::cout << "\ns4z= " << s4z << "\n";
std::cout << "\nN= " << N << "\nN^2= " << (pow(N,2)) << "\nDT= " << DT << "\nBS= " << BS << "\n";
std::cout << "\nis same sign of x= " << (samesign(s4x,c->x));
std::cout << "\nis same sign of y= " << (samesign(s4y,c->y));
std::cout << "\nis same sign of z= " << (samesign(s4z,c->z)) << "\n";
std::cout << "\nintersect= " << (((DT*(c->x))/(pow(N,2)))-((BS*(c->x))/N));
std::cout << "\nintersect= " << (((DT*(c->y))/(pow(N,2)))-((BS*(c->y))/N));
std::cout << "\nintersect= " << (((DT*(c->z))/(pow(N,2)))-((BS*(c->z))/N)) << "\n";
//////////////////////////////////

*/
}
bool sphere::intersect(class  camerav * c){
float DT = dotproduct(c);
float final =sqrt(
    pow(((x-c->cx) - ((DT*(c->x))/(pow(c->scalar,2)))),2) + 
    pow(((y-c->cy) - ((DT*(c->y))/(pow(c->scalar,2)))),2) + 
    pow(((z-c->cz) - ((DT*(c->z))/(pow(c->scalar,2)))),2));

if (final<r){
    return true;
}else{
    return false;
}
}
float ClassA::dotproduct(ClassA * c){
return (((x-c->cx)*c->x) + ((y-c->cy)*c->y) + ((z-c->cz)*c->z));
}

float ClassA::tdotproduct(float x1,float y1,float z1){
return ((x*x1) + (y*y1) + (z*z1));
}
void ClassA::normalizeto(ClassA * c){
float store = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
c->x = (x/store);
c->y = (y/store);
c->z = (z/store);
}
void ClassA::normalize(void){
float store = sqrt((pow(x,2))+pow(y,2)+pow(z,2)); 
x = (x/store);
y = (y/store);
z = (z/store);
}
void sphere::printradius(){
    std::cout << "radius : " << r << "\n";
}
void sphere::inputradius(void){
    std::cout << "\n" << "radius : " << "\n";;
    std::cin >> r ;
    scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
}
void sphere::setradius(float r1){
    r=r1;
}
void sphere::printdist(){
    std::cout << "dist : " << dist << "\n";
}
void camerav::camreaprint(){
    std::cout << "px   :" << px << "\n";
    std::cout << "py   :" << py << "\n";
    std::cout << "fovx :" << fovx << "\n";
    std::cout << "fovy :" << fovy << "\n";
}
void camerav::camreainputvect(void){
    std::cout << "\npx   :" <<  "\n";
    std::cin >> px;
    std::cout << "py   :" <<  "\n";
    std::cin >> py;
    std::cout << "fovx :" <<  "\n";
    std::cin >> fovx;
    std::cout << "fovy :" <<  "\n";
    std::cin >> fovy;
}
void camerav::camreasetpixel(float x1,float y1){
px =  x1;
py =  y1;
}
void camerav::camreasetfov(float z1,float w1){
fovx =  z1;
fovy =  w1;
}
// void camerav::camreaaddvect(float x1,float y1,float z1){}
void camerav::ofsetto(camerav * s,float xs,float ys){

float v  = sqrt((x*x) + (y*y));
float v2 = sqrt((x*x) + (y*y) + (z*z));

    s->x  = x + ((((-1)*(x*z))*(ys))/(v*v2)) - ((y*xs)/v);
    s->y  = y + ((((-1)*(y*z))*(ys))/(v*v2)) + ((x*xs)/v);
    s->z  = z + (( v * ys )/ v2);
    s->cx = cx;
    s->cy = cy;
    s->cz = cz;
    s->scalar = sqrt((pow(s->x,2))+pow(s->y,2)+pow(s->z,2));
    
}
void sphere::normalofray(gvect * c,gvect * n){
float storex = (c->x+c->cx - x);
float storey = (c->y+c->cy - y);
float storez = (c->z+c->cz - z);


n->setvect(storex , storey , storez);
n->setcord( x , y , z );
}

float gvect::anglevect(gvect * s){

float m2 = s->scalar;
float m1 = scalar;
float DP = dotproduct(s);
float angle=DP/(m1*m2);
if(angle>-1&&angle<1){return (rad2degree(acos(DP/(m1*m2))));}
else if(angle<=-1){return 180;}
else if(angle>=1){return 0;}
else{return 0;} 
}
float camerav::distfromgvects(gvect * m){
float storex = (m->x+m->cx - cx);
float storey = (m->y+m->cy - cy);
float storez = (m->z+m->cz - cz);

    return sqrt(pow(storex,2)+pow(storey,2)+pow(storez,2));
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
int light[4]={219,222,221,63};
if (angle<=90){
return char(light[int(angle/30)]);  
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
#endif