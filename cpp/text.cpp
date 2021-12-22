        
#include <stdio.h>
int main()
{

int str1;
        printf("\n"); //function display
        printf("Enter value: ");  
        scanf("%d", &str1); //
        printf("Entered value: %d\n", str1); //value output
        printf("\n\n"); //output text
        printf("var: %d\n", str1);

  // Notice the use of & before var
  printf("address of var: %p", &str1);  
  return 0;
}