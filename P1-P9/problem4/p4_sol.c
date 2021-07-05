#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Solution for problem four of Project Euler
 * Find the largest palindrome made from the product of two n-digit numbers.
 */

int is_palindrome(int n, int limit);

// Returns the largest palindrome made from the product of two n-digit numbers.

int largest_palindrome(int num_digits){
    int largest = 0;
    
    int lower = 1;
    int upper = 10;

    for (int i = 1; i < num_digits; i++){
        lower *= 10;
        upper *= 10;
    }

    for (int i = lower; i <= upper; i++){
        for (int j = lower; j <= i; j++){
            if (is_palindrome(i*j, upper*upper) && i*j > largest){
                largest = i*j;
            }
        }
    }
    return largest;
}

// Returns 1 if the number is a palindrome
int is_palindrome(int n, int limit){

    char buf[limit + 1];
    char reverse[limit + 1];

    sprintf(buf, "%d", n);

    int k = strlen(buf) - 1;

    for (int i = 0; i <= limit; i++){
        reverse[i] = buf[k];
        k -= 1;
    }

    reverse[strlen(buf)] = '\0';

    return !(strncmp(buf, reverse, strlen(buf)));
}


int main(int argc, char **argv) {

if (argc > 2){
    fprintf(stderr, "valid usage: p3_sol number");
}
int n = strtol(argv[1], NULL, 10);

int palindrome = largest_palindrome(n);

printf("Largest Palindrome: %d\n", palindrome);

return 0;
}