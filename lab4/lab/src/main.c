/* Code to simulate rolling three six-sided dice (D6)
 * User first types in seed value
 * Use seed value as argument to srand()
 * Call roll_three to generate three integers, 1-6
 * Print result "%d %d %d "
 * If triple, print "Triple!\n"
 * If it is not a triple but it is a dobule, print "Double!\n"
 * Otherwise print "\n"
 */

#include <stdio.h>
#include <stdlib.h>
#include "dice.h"

int main () {
  int s;
  int num_one;
  int num_two;
  int num_three;

  printf("Enter Seed: \n");

  scanf("%d", &s);
  
  srand(s);
  
  roll_three(&num_one, &num_two, &num_three); 
  
  if(num_one == num_two && num_two == num_three)
     {
       printf("%d %d %d Triple!\n", num_one, num_two, num_three);
     }  
 
   else if(num_one == num_two || num_one == num_three || num_two == num_three)
     { 
       printf("%d %d %d Double!\n", num_one, num_two, num_three);
     }
 
  else
     {
       printf("%d %d %d\n", num_one,  num_two,  num_three);
     }

return 0;

}
 
  
