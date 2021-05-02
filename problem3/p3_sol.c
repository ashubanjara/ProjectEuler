#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Solution for problem three of Project Euler
 * Find the largest prime factor of the given number.
 */

// Returns the largest prime factor of a given number n 
int is_prime(long int n);


long int largest_prime_factor(long int n){

    for (long int i = n; i > 0; i--){
        if (n % i == 0) {
            if (is_prime(i)){
                return i;
            }
        }
    }
    return 1;
}

// Returns 1 if number is prime, else returns 0.
int is_prime(long int n){
    for (long int i = 2; i <= sqrt(n); i++){
        if (n % i == 0 && i != n){
            return 0;
        }
    }
    return 1;
}


  int main(int argc, char **argv) {

    if (argc > 2){
        fprintf(stderr, "valid usage: p3_sol number");
    }
    long int n = strtol(argv[1], NULL, 10);

    long int prime_factor = largest_prime_factor(n);

    printf("Largest Prime Factor: %ld\n", prime_factor);

    return 0;
}