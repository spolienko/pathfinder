#include "pathfinder.h"

void mx_main_algo(int** matrix_path, int count) {
	int min_dist = 0;

	for (int k = 0; k < count; k++) {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                min_dist = matrix_path[i][k] + matrix_path[k][j];
                if (min_dist < matrix_path[i][j]) {
                    matrix_path[i][j] = min_dist;
                }
            }
        }
    }
}
