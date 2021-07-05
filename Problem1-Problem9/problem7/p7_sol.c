#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Solution for problem seven of Project Euler
 *
 * Find the n'th prime number
 */

int is_prime(int n);

// Finds the n'th prime number.

int nth_prime(int n) {
    int curr_num = 1;
    int prime_order = 0;

    while (prime_order <= n) {
        if (is_prime(curr_num)){
            prime_order += 1;
        }
        curr_num += 1;
    }
    return curr_num - 1;
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
    fprintf(stderr, "valid usage: p6_sol number");
}
int n = strtol(argv[1], NULL, 10);

int answer = nth_prime(n);

printf("%dth prime = %d\n", n, answer);

return 0;
}