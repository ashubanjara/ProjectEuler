#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Solution for problem nine of Project Euler
 *
 * Given that there exists a Pythagorean triplet for which a + b + c = n.
 * Find the product abc.
 */

int is_triplet(int a, int b);

int pythagorean_prod(int n){

    for (int i = 1; i <= (n/2); i++){
        for (int j = (i+1); j <= n; j++){
            int k = is_triplet(i, j);
            if(k > 0 && (i + j + k == n)){
                return i*j*k;
            }
        }
    }
    return 0;
}

// returns the value of c if c*c is a whole number, else returns 0
int is_triplet(int a, int b){
    double c = sqrt((a*a) + (b*b));
    if (c == (int)c){
        return (int)c;
    }
    return 0;
}


int main(int argc, char **argv) {

if (argc > 2){
    fprintf(stderr, "valid usage: soln pythagorean_sum");
}
int n = strtol(argv[1], NULL, 10);

int answer = pythagorean_prod(n);

printf("product = %d\n", answer);

return 0;
}