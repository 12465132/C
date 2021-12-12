#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
//input

	int n;

		printf("Function: \n"); //function display
		printf("Enter value: ");

	scanf("%d", &n); //

	printf("Entered value: %d\n", n); //value output

	 printf("\n\n"); //output text

//input

	int arsz = 2*n-1;	//making the array
  	int map[arsz][arsz];	//making the array
printf("\n\n");
	  

	 	//variables

for(int i = 0; i < arsz; i++)// printing the grid
{
	 printf("%d", i);
	for(int j = 0; j < arsz; j++) {
		printf("%d ", j);
	}
	printf("\n");
} 

	return 0;

}