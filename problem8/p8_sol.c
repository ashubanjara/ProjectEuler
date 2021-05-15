#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Solution for problem eight of Project Euler
 *
 * Find n adjacent digits in the 1000-digit number that have the greatest 
 * product.
 */

// Returns the greatest adjacent product of a given char array num and
// the number of adjacent digits to consider (num_adj), also takes the number
// of digits in the array num. 
long int greatest_adj_product(char * num, int num_adj, int num_digits){
    long int greatest = 1;
    long int product = 1;
    for(int i = 0; i < (num_digits - (num_adj + 1)); i++){
        product = 1;
        for (int j = 0; j < num_adj; j++){
            product *= (num[i+j] - '0');
            if (product > greatest){
                greatest = product;
            }
        }
    }
    return greatest;
}

// Load the 1000 digit number into a char array from a given file
void load_data(char * filename, char * num, int num_digits){
    FILE *f1 = fopen(filename, "r");
    if (f1 == NULL) {
        perror("fopen");
        exit(1);
    }

    for(int i = 0; i < num_digits; i++){
        if (fscanf(f1, "%c", &num[i]) != 1){
            printf("Error: read");
        }
    }

    fclose(f1);
}


int main(int argc, char **argv) {

if (argc > 4){
    fprintf(stderr, "valid usage: soln filename num_digits num_adjacent");
}
// Get user provided input
char * filename = argv[1];
int num_digits = strtol(argv[2], NULL, 10);
int num_adjacent = strtol(argv[3], NULL, 10);

char num_array[num_digits];

// Load the file with num_digits digit number
load_data(filename, num_array, num_digits);

long int answer = greatest_adj_product(num_array, num_adjacent, num_digits);

printf("greatest adjacent product = %ld\n", answer);

return 0;
}