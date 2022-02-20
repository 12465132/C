//#include <conio.h>
#include <iostream>
#include "cordnate.h"
#include <bits/stdc++.h>
using namespace std;


//COLORREF backgroundColor = RGB(255, 255, 255);


int main()
{
double x = -100;
double d = 100;
double mindist1=1,maxdist1=10000;
//array
if(!(x==d)){
    if((x!=-1)&&((x<mindist1)||(x>maxdist1))){
        x=-1;
        if((d>mindist1)&&(d<maxdist1)){
            if (x==-1){
                x=d;
        }else{
            if (x>d){
                x=d;
            }}}
    }else{
        if((d>mindist1)&&(d<maxdist1)){
            if (x==-1){
                x=d;
        }else{
            if (x>d){
                x=d;
    }}}}}
std::cout << x << std::endl;
//array

return 0;
}
