#include <stdio.h>
int main()
{
//inputs cpp
int int1;
std::cout << "\n" << "function:/*function of program*/"  /*function of program*/
 << "\n" << "Enter value: ";
std::cin << int1;
std::cout <<"Entered value:" << int1 << "\n\n";
//inputs cpp

//inputs c
int str1;
        printf("\n"); //function display
        printf("Enter value: ");  
        scanf("%d", &str1); //
        printf("Entered value: %d\n", str1); //value output
        printf("\n\n"); //output text
        printf("var: %d\n", str1);
//inputs c
  // Notice the use of & before var
  printf("address of var: %p", &str1);  
  return 0;
}
