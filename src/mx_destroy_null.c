#include "pathfinder.h"

void mx_destroy_null(int** matrix, int count) {
	int i = 0;
	int j = 0;

	for (i = 0; i < count; i++) {
		for (j = 0; j < count; j++) {
			if (i != j && matrix[i][j] == 0) {
				matrix[i][j] = MAX_INT;
			}
		}
	}
}
