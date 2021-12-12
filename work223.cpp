#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

int n;
int offset=0;
int arsz = 2*n-1;	
int map[arsz][arsz];

//input
printf("Function: \n"); //function display
printf("Enter value: ");
scanf("%d", &n); //
printf("Entered value: %d\n", n); //value output
printf("\n\n"); 
//input

for (int num = n; num > 0; num--)//sets input number for grid
{

    for(int prnt1 = offset; prnt1 < arsz-offset; prnt1++)//sets x-axis for grid
    {    
	    for(int prnt2 = offset; prnt2 < arsz-offset; prnt2++)//sets y-axis for grid
        {
		map[prnt1][prnt2] = num;
	    }
    } 
	offset++;
}

for(int x = 0; x < arsz; x++)//prints x-axis for grid
{
	for(int y = 0; y < arsz; y++) //prints y-axis for grid
	{
		printf("%d ", map[x][y]);
	}	
	printf("\n");
} 

return 0;

}