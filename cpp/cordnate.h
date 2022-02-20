//name file cordnate.h
#ifndef cordnate_H
#define cordnate_H
#define PI 3.1415926535897932384626433832795028
#include <iostream>
#include <cmath>

long long pow10(int n);
long long digits(long long id,int n);
long long numDigits(long long n);
double dpow10(int n);
double roundn(double x,int n);
bool samesign(double sx,double sy);
double rad2degree(double degree);
double degree2rad(double degree);
void praylight(double angle);
char shadowascii(double l,double rfz);
char raylight(double angle);
class ClassA {
public:
    void printvect(void);
    void inputvect(void);
    void setvect(double x1,double y1,double z1);
    void addvect(double x1,double y1,double z1);
    void printcord(void);
    void inputcord(void);
    void setcord(double x1,double y1,double z1);
    void addcord(double x1,double y1,double z1);
    double dist(ClassA * c);
    void pdist(ClassA * c);
    void normalizeto(ClassA * c);
    double dotproduct(ClassA * c);
    double tdotproduct(double x1,double y1,double z1);
    void normalize(void);

    double x  = 0;
    double y  = 0;
    double z  = 0;
    double cx = 0;
    double cy = 0;
    double cz = 0;
    double scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
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
    double anglevect(gvect * s);
    
    
};

class camerav : public vect{
    public:
    double px=40,py=160;
    double fovx,fovy;
    double mindist=1,maxdist=10000;
    void ofsetto(camerav * s,double x1,double y1);
    void camreaprint();
    void camreasetpixel(double z1,double w1);
    void camreasetfov(double z1,double w1);
    void camreainputvect(void);
    double distfromgvects(gvect * m);
   };

class sphere : public vect {
    public:
double r;
double dist;
bool intersect(class  camerav * c);
bool cameraintersect(class  camerav * c,class  gvect * t);
void printradius(void);
void inputradius(void);
void setradius(double r1);
void printdist();
void ofsetcam(double x1,double y1);
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
void ClassA::setvect(double x1,double y1,double z1){
    x=x1;
    y=y1;
    z=z1;
    scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
}
void ClassA::addvect(double x1,double y1,double z1){
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
void ClassA::setcord(double x1,double y1,double z1){
    cx=x1;
    cy=y1;
    cz=z1;
    scalar = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
}
void ClassA::addcord(double x1,double y1,double z1){
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
double ClassA::dist(ClassA * c){
   return sqrt((pow((x-c->x),2)+pow((y-c->y),2)+pow((z-c->z),2)));
}
void ClassA::pdist(ClassA * c){
   std::cout << sqrt((pow((x-c->x),2)+pow((y-c->y),2)+pow((z-c->z),2)));
}
bool sphere::cameraintersect(class  camerav * c,class  gvect * t){

double N = c->scalar;
double DT = dotproduct(c);
double sx = (x-c->cx);
double sy = (y-c->cy);
double sz = (z-c->cz);
double s2x = ((DT*(c->x))/(pow(N,2)));
double s2y = ((DT*(c->y))/(pow(N,2)));
double s2z = ((DT*(c->z))/(pow(N,2)));
double s3x = sx - s2x;
double s3y = sy - s2y;
double s3z = sz - s2z;
double final = sqrt(pow(s3x,2) + pow(s3y,2) + pow(s3z,2));
double BS = sqrt( pow(r,2) - pow(sqrt(pow(s3x,2) + pow(s3y,2) + pow(s3z,2)) ,2));
double s4x = (((DT*(c->x))/(pow(N,2)))-((BS*(c->x))/N));
double s4y = (((DT*(c->y))/(pow(N,2)))-((BS*(c->y))/N));
double s4z = (((DT*(c->z))/(pow(N,2)))-((BS*(c->z))/N));

////////////////////////////////////////

////////////////////////////////////////

if(
(samesign(s4x,c->x)) && 
(samesign(s4y,c->y)) && 
(samesign(s4z,c->z))){

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
double N = c->scalar;
double DT = dotproduct(c);
double sx = (x-c->cx);
double sy = (y-c->cy);
double sz = (z-c->cz);
double s2x = ((DT*(c->x))/(pow(N,2)));
double s2y = ((DT*(c->y))/(pow(N,2)));
double s2z = ((DT*(c->z))/(pow(N,2)));
double s3x = sx - s2x;
double s3y = sy - s2y;
double s3z = sz - s2z;
double final = sqrt(pow(s3x,2) + pow(s3y,2) + pow(s3z,2));

if (final<r){
    return true;
}else{
    return false;
}
}
double ClassA::dotproduct(ClassA * c){
return (((x-c->cx)*c->x) + ((y-c->cy)*c->y) + ((z-c->cz)*c->z));
}
double ClassA::tdotproduct(double x1,double y1,double z1){
return ((x*x1) + (y*y1) + (z*z1));
}
void ClassA::normalizeto(ClassA * c){
double store = sqrt((pow(x,2))+pow(y,2)+pow(z,2));
c->x = (x/store);
c->y = (y/store);
c->z = (z/store);
}
void ClassA::normalize(void){
double store = sqrt((pow(x,2))+pow(y,2)+pow(z,2)); 
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
void sphere::setradius(double r1){
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
void camerav::camreasetpixel(double x1,double y1){
px =  x1;
py =  y1;
}
void camerav::camreasetfov(double z1,double w1){
fovx =  z1;
fovy =  w1;
}
// void camerav::camreaaddvect(double x1,double y1,double z1){}
void camerav::ofsetto(camerav * s,double xs,double ys){

double v  = sqrt((x*x) + (y*y));
double v2 = sqrt((x*x) + (y*y) + (z*z));

    s->x  = x + ((((-1)*(x*z))*(ys))/(v*v2)) - ((y*xs)/v);
    s->y  = y + ((((-1)*(y*z))*(ys))/(v*v2)) + ((x*xs)/v);
    s->z  = z + (( v * ys )/ v2);
    s->cx = cx;
    s->cy = cy;
    s->cz = cz;
    s->scalar = sqrt((pow(s->x,2))+pow(s->y,2)+pow(s->z,2));
    
}
void sphere::normalofray(gvect * c,gvect * n){
double storex = (c->x+c->cx - x);
double storey = (c->y+c->cy - y);
double storez = (c->z+c->cz - z);


n->setvect(storex , storey , storez);
n->setcord( x , y , z );
}
double gvect::anglevect(gvect * s){

double angle;
double m2 = s->scalar;
double m1 = scalar;
double DP = dotproduct(s);
    
return (rad2degree(acos(DP/(m1*m2))));
    
}
double camerav::distfromgvects(gvect * m){
double storex = (m->x+m->cx - cx);
double storey = (m->y+m->cy - cy);
double storez = (m->z+m->cz - cz);

    return sqrt(pow(storex,2)+pow(storey,2)+pow(storez,2));
}




char shadowascii(double l,double rfz){
char ascii[69] =
{46, 39, 96, 94, 34, 44, 58, 59, 73, 108, 33, 105, 62, 60, 126, 43, 95, 45, 63,
93, 91, 125, 123, 49, 41, 40, 124, 92, 47, 116, 102, 106, 114, 120, 110, 117,
118, 99, 122, 88, 89, 85, 74, 67, 76, 81, 48, 79, 90, 109, 119, 113, 112, 100,
98, 107, 104, 97, 111, 42, 35, 77,87, 38, 56, 37, 66, 64, 36};
double storeascii = ((l/rfz)*69);
return ascii[(int)storeascii];
}

void praylight(double angle){
if (angle<=90){
std::cout << shadowascii(((angle/90)*256),256);  
}else{
std::cout << " ";
    return;
}}
char raylight(double angle){
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

    for(int x=0;x<n;x++)
        result*=10;
    }

    return result;
}
long long numDigits(long long n)
{
    if (n < 10) return 1;
    return 1 + numDigits(n / 10);
}
double dpow10(int n){
    double result = 1;

    for(int x=0;x<n;x++)
    {
        result*=10; 
    }

    return result; 
}
double roundn(double x,int n){
long long result = 0;
return (ceil(x * dpow10(n)) / dpow10(n));
}
double sdotproduct(double sx,double sy,double sz,double cx,double cy,double cz,double ccx,double ccy,double ccz){
return (((sx-ccx)*cx) + ((sy-ccy)*cy) + ((sz-ccz)*cz));
}
bool samesign(double sx,double sy)
{
    return ((fabs(sx)/sx)==(fabs(sy)/sy));
}
double degree2rad(double degree){
    return ((PI*degree)/180);
}
double rad2degree(double degree){
    return ((180*degree)/PI);
}
#endif