#include <stdio.h>
#include <math.h>

double math(double n);


int main()
{



        double str1;
     
        printf("Function: \n"); //function display
        printf("Enter value: ");
        
        scanf("%lf", &str1); //

        


        printf("Entered value: %lf\n", str1); //value output




			
    
    
     printf("\n%lf\n",math(str1)); //output text
     

    
    return 0;
} 

double math(double n){

if (n > 1) {
             n + (n - 1);
        }
        else {
	           return 1;
        }


}



