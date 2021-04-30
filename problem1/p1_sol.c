#include <stdlib.h>
#include <stdio.h>

/* Solution for problem one of Project Euler

   Find the sum of multiples of 3 and 5 below 1000.
 */

 /* 
 Returns the sum of multiples of 3 and 5 below a given number n.
  */
int multiples(int n){
    int sum = 0;

    for(int i = 0; i < n; i++){
        if (i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }
    
    return sum;
}

int main(int argc, char **argv) {

    if (argc > 2){
        fprintf(stderr, "valid usage: p1_sol num");
    }
    int number = strtol(argv[1], NULL, 10);

    int sum_of_multiples = multiples(number);

    printf("sum: %d\n", sum_of_multiples);
    return 0;
}