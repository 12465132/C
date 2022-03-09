//#include <conio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char hatch(int i,int j,int value){
int light[8]={219,222,221,63};
if((i%2==0)^(j%2==0)){
return char(light[(value/4)%4]);
}else if(((i%2==0)^!(j%2==0))||(!(i%2==0)^(j%2==0))){
return char(light[value%4]);
}else if((i%2==0)^!(j%2==0)){
return char(light[value%4]); 
}}


int main () {

// for(int x=0;x<256;x++){
// for (int i = 0; i < 40/2.11764706; i++){
//     for (int j = 0; j < 255; j++){
//         // if((i%2==0)^(j%2==0)){
//         // std::cout << char(178);
//         // }else if((i%2==0)^!(j%2==0)){
//         // std::cout << char(176);
//         // }else if(!(i%2==0)^(j%2==0)){
//         // std::cout << char(176);
//         // }else if((i%2==0)^!(j%2==0)){
//         // std::cout << char(176);
//         // }
//     std::cout << char(x);
//     }
//     std::cout << "\n";
// }}
int light[4]={219,222,221,63};
for(int x=0;x<4;x++){
for (int i = 0; i < 40/2.11764706; i++){
    for (int j = 0; j < 255; j++){
    std::cout << char(light[x]);
    }
    std::cout << "\n";
}}
// for (float i=0;i<256;i++) {
// std::cout << i << ":" <<char((i))<<"\n";
// }
//$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'.




    return 0;
}


// char brightness(int x,int y,int i){

//     return;    
// }