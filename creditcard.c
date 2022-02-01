#include <stdio.h>

long long pow10(int n);
long long digits(long long id,int n);
long long numDigits(long long n);
int main()
{
//input
long long b;
printf("Function: \n"); //function display
printf("Enter value: ");
scanf("%lld", &b); 
printf("Entered value: %lld\n", b); //value output
printf("Entered value: %lld\n", b); //value output

for(int a = 0; a <numDigits(b); a++ )
{
   printf("value of a: %lld\n",digits(b,a));
}

	return 0;
}

long long digits(long long id,int n)
{
return id/pow10(n) % 10;//gets in divisual value using mod 10 once shifted
}

long long pow10(int n){
    long long result = 1;

    for(int x=0;x<n;x++)// counts down amount of multiplacation
    {
        result*=10; // result * 10 = result
    }

    return result; //return
}
long long numDigits(long long n)
{
    if (n < 10) return 1;
    return 1 + numDigits(n / 10);
}
