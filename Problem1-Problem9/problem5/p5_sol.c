#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Solution for problem five of Project Euler
 *
 * Find the smallest positive number that is evenly divisible by all of the 
 * numbers from 1 to n.
 */

// Returns the smallest possible integer that is divisible by all integers
// from 1 to given number n.

int smallest_divisible(int n){
    int num = n;
    int divisible = 1;

    while(1){
        divisible = 1;
        for (int i = 1; i <= n; i++){
            if (num % i != 0){
                divisible = 0;
            }
        }
        if (divisible == 1){
            return num;
        }
        num += n;
    }
    // shouldn't get here
    return num;
}


int main(int argc, char **argv) {

if (argc > 2){
    fprintf(stderr, "valid usage: p5_sol number");
}
int n = strtol(argv[1], NULL, 10);

int smallest_num = smallest_divisible(n);

printf("Smallest Divisible: %d\n", smallest_num);

return 0;
}