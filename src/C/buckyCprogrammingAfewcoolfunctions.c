#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int main()
{

  int tuna = 5;
  //is alpha sees if variable is in the alphabet
  if( isalpha(tuna)){
      printf(" %c is a letter", tuna);
  }else{

      if ( isdigit(tuna)){
          printf(" %c is a number", tuna);
      }else{
          printf("%c what the fudge is that", tuna);
      }
    }


  return 0;
}
