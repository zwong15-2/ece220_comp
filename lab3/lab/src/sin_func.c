#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

/*
 * main
 *  DESCRIPTION: compute a set of points of a function and print the results
 *  INPUTS: console (int, float float) -- equation related constants
 *  OUTPUTS: console (x, f(x)) -- sequence of values to be printed
 *  RETURN VALUE: 0
 *  SIDE EFFECTS: none
 */
int main()
{
    // Declare variables
    float omega1, omega2;
    int n, i;
    float x_i;
    float f_x;

    // Prompt user for input
    printf("Enter the values of n, omega1, and omega2 in that order: \n");
    

    // Get user input
    scanf("%d", &n);
    scanf("%f", &omega1);
    scanf("%f", &omega2);
   


    // Compute function output
    /* for i from 0 to n-1
     *     compute and print xi and f(xi)
     *     use sin() function from math.h
     */
    
    for(i = 0; i <= (n-1); i++){

    x_i = (i*(M_PI))/n;

    f_x = sin(omega1 * x_i) + (0.5)*(sin(omega2 * x_i));

    printf("(%f, %f)\n", x_i, f_x);

    }
    return 0;
}

