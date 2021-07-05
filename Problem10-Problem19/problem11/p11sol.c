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
typedef long int num;
int grid_size = 20;

// Load the size x size grid into a char array from a given file
void load_data(char * filename, int num_array[grid_size][grid_size]){
    FILE *f1 = fopen(filename, "r");
    if (f1 == NULL) {
        perror("fopen");
        exit(1);
    }

    for(int i = 0; i < grid_size; i++){
        printf("\n");
        for(int j = 0; j < grid_size; j++) {
            if (fscanf(f1, "%d", &num_array[i][j]) != 1){
            printf("Error: read");
            }
            printf("%d ", num_array[i][j]);
        }
    }

    fclose(f1);
}


int main(int argc, char **argv) {

if (argc > 3){
    fprintf(stderr, "valid usage: soln filename grid_size num_unidirectional");
}
// Get user provided input
char * filename = argv[1];
int num_unidirectional = strtol(argv[2], NULL, 10);

int num_array[grid_size][grid_size];

load_data(filename, num_array);

return 0;
}