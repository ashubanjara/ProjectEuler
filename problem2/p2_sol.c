#include <stdlib.h>
#include <stdio.h>

/* Solution for problem two of Project Euler

   Find the terms in the Fibonacci sequence whose values do not exceed 
   four million, find the sum of the even-valued terms.
 */

 /* 
 Returns sum of even-valued terms of fibonacci sequence below a certain
 threshold number n.
  */
long int fibonacci_limit(long int n){
    int sum = 0;

    // variables to hold the previous 2 terms
    int prev_term = 0;
    int prev_prev_term = 1;

    // variable to hold the current term
    int current_term = 1;

    // update the variables for each iteration until it reached the max value
    while (current_term < n){
        current_term = prev_term + prev_prev_term;
        prev_prev_term = prev_term;
        prev_term = current_term;

        if (current_term % 2 == 0){
            sum += current_term;
        }
    }
    return sum;
}

int main(int argc, char **argv) {

    if (argc > 2){
        fprintf(stderr, "valid usage: p2_sol limit_num");
    }
    int number = strtol(argv[1], NULL, 10);

    int sum_of_even_fib = fibonacci_limit(number);

    printf("sum: %d\n", sum_of_even_fib);
    return 0;
}