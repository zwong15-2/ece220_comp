//The desired purpose of this program is to correctly
//produce the specific row index values of Pascal's
//Triangle according to user input. The algorithm I used
//for this program was reliant on the formula used for
//finding Pascal's Triangle values, binomial expansion formula.

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int row;                       //Configures user input to ask which
                                 //row index values the user wants

  printf("Enter a row index: ");
  scanf("%d",&row);

          
  int i;                        //Initalization of variables
  int k = 1;
  unsigned long n;
  
  if(row == 0)                  //Correctly prints the row index values
    {                           //if the user input is 0. I decided to 
  	 printf("1");           //brute force this row because it did 
    }                           //necessarily follow the formula configuration
 
 else
    {    
         printf("1");          //Correctly prints out the beginning value 
                               //(1) for any row index values.
         printf(" ");
         
         i = ( (row + 1 - k) / k );  //Begins the formula for the binomial
                                     //expansion for Pascal's Triangle values.
         n = i; k++;                 //This is the same formula given in problem
                                     
         printf("%d", i);            //Sets-up the second value for the desired
                                     //row index and the loop
         printf(" ");
 
         for(k = 2; k <= row; k++)
            {
                n = ( ( n * (row + 1 - k) ) / k );  //Follows binomial expansion
                printf("%lu", n);                   //formula by calculating next values
                printf(" ");                        //using the previous values of
                                                    //itself
            }           
    }
  printf("\n");
  return 0;
}
