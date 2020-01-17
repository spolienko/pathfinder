#include "pathfinder.h"

void  mx_matrix_path(int** matrix_path, int** matrix, int count) {
	int i = 0;
	int j = 0;
	int n = count;

	for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix_path[i][j] = matrix[i][j];
        }
	}
}
