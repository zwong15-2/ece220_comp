//Function for generating three d6 rolls

#include <stdlib.h>
#include <stdio.h>
#include "dice.h"

void roll_three(int* one, int* two, int* three){

int i;

int n = 3;

for( i = 0; i < n; i++)
   {
     if(i == 0)
       { 
         *one = rand() % (6 + 1 - 1) + 1;
       }    
     if(i == 1)
       {
        *two = rand() % (6 + 1 - 1) + 1;
       }  
     if(i == 2)
       {
        *three = rand() % (6 + 1 - 1) +1;
       }     
          
   }
}
