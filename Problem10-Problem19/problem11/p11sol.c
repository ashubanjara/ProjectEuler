#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Solution for problem eleven of Project Euler
 *
 * Find n unidirectional digits in an 20 x 20 grid that has the greatest 
 * product.
 */

// redefine long int as num
typedef long int bignum;
int GRID_SIZE = 20;

// Load the size x size grid into a char array from a given file
void load_data(char * filename, int num_array[GRID_SIZE][GRID_SIZE]){
    FILE *f1 = fopen(filename, "r");
    if (f1 == NULL) {
        perror("fopen");
        exit(1);
    }

    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++) {
            if (fscanf(f1, "%d", &num_array[i][j]) != 1){
            printf("Error: read");
            }
        }
    }

    fclose(f1);
}


// Returns the greatest product in the horizontal axis of the grid.
bignum greatest_h_product(int num_array[GRID_SIZE][GRID_SIZE], int num_ints){
    bignum greatest = 1;
    bignum product = 1;
    for (int i = 0; i < GRID_SIZE - num_ints; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            product = 1;
            for(int k = 0; k < num_ints; k++){
                product *= num_array[i][j+k];
                if (product > greatest){
                    greatest = product;
                }
            }
        }
    }
    return greatest;
}


int main(int argc, char **argv) {

if (argc > 3){
    fprintf(stderr, "valid usage: soln filename num_unidirectional");
}
// Get user provided input
char * filename = argv[1];
int num_ints = strtol(argv[2], NULL, 10);

int num_array[GRID_SIZE][GRID_SIZE];

load_data(filename, num_array);

bignum greatest_horizontal = greatest_h_product(num_array, num_ints);
printf("greatest_horizontal: %ld\n", greatest_horizontal);

return 0;
}