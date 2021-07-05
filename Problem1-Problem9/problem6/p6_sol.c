#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Solution for problem six of Project Euler
 *
 * Find the difference between the sum of the squares of the first 
 * n natural numbers and the square of the sum.
 */


// Returns the difference between the sum of the squares of the first 
// n natural numbers and the square of the sum.
int sum_diff(int n){
    int sum = 0;
    int sum_squares = 0;

    for (int i = 1; i <= n; i++){
        sum += i;
        sum_squares += i*i;
    }
    printf("%d\n", sum_squares);
    printf("%d\n", sum);

    return ((sum*sum) - sum_squares);
}


int main(int argc, char **argv) {

if (argc > 2){
    fprintf(stderr, "valid usage: p6_sol number");
}
int n = strtol(argv[1], NULL, 10);

int answer = sum_diff(n);

printf("Sum_diff: %d\n", answer);

return 0;
}