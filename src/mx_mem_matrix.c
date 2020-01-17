#include "pathfinder.h"

int** mx_mem_matrix(int count) {
	int **matrix = ((int **) malloc(sizeof(int *) * count));

    for (int i = 0; i < count; i++) {
        matrix[i] = (int *) malloc(sizeof (int) * count);
	    for(int j = 0; j < count; j++)
		    matrix[i][j] = 0;
	}
	return matrix;
}
