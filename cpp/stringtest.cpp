#include <iostream>
#include <string>
#include "cordnate3.h"
#include <bits/stdc++.h>
using namespace std;


int main () {
int count=10,count2=100;
string output[count];


for (int i = 0; i < count; i++)
{
for (int j = 0; j < count2; j++)
{
   output[i]=output[i]+char(j); 
}}
for (int i = 0; i < count; i++)
{
std::cout << output[i]<<"\n";
}


return 0;
}