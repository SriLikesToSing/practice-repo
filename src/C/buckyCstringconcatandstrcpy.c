#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int main()
{

  char a = 'a';
  char b = 'F';
  char c = '7';
  //toupper makes it into uppercase
  printf("%c \n", toupper(a) );

  char sed[100] = "THERE";
  char ham[100] = "Hey ";
  //first parameter and second parameter
  strcat(ham, "Bucky ");
  printf("%s \n", ham);

  //strcpy replaces one string with another string
  strcpy(ham, "Bucky is Awesome! ");
  printf("%s", ham);
  strcat(ham, sed);
  printf("%s", ham);





  return 0;
}
