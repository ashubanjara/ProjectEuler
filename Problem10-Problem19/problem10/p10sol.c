#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Solution for problem ten of Project Euler
 *
 * Find the sum of all the primes below a given integer n.
 */

int is_prime(int n);

long int sum_primes(int n){
    long int sum = 0;
    for (int i = 2; i < n; i++){
        if (is_prime(i)){
            sum += i;
        }
    }
    return sum;
}

// Returns 1 if number is prime, else returns 0.
int is_prime(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0 && i != n){
            return 0;
        }
    }
    return 1;
}


int main(int argc, char **argv) {

if (argc > 2){
    fprintf(stderr, "valid usage: ./soln n");
}
int n = strtol(argv[1], NULL, 10);

long int answer = sum_primes(n);

printf("sum = %ld\n", answer);

return 0;
}