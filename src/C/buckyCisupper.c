#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int main()
{

  int tuna = 'b';
  //is alpha sees if variable is in the alphabet
  if( isalpha(tuna)){

      if( isupper(tuna)){
        printf("%c is an upper case letter", tuna);
      }else{
          printf("%c is a lowercase letter");
        }


  }else{

      if ( isdigit(tuna)){
          printf(" %c is a number", tuna);
      }else{
          printf("%c what the fudge is that", tuna);
      }
    }


  return 0;
}
