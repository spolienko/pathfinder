#include "pathfinder.h"

static void fiil_zero(int** matrix, int count);
static int lol_func(char* point, char** uniq_elem, int new_index, int count);

void mx_matrix(char** uniq_elem, char*** arr_path, int count, int **matrix) {
	int old_index = 0;
	int new_index = 0;

	fiil_zero(matrix, count);
	for (int i = 0; i < count; i++) {
		old_index = i;
		for (int j = 0; arr_path[j] != NULL; j++) {
			for (int k = 0; k <= 1; k++) {
				if (mx_strcmp(arr_path[j][k], uniq_elem[i]) == 0) {
					new_index = lol_func(mx_strdup(arr_path[j][1 - k]),
						uniq_elem, new_index, count);
					matrix[new_index][old_index] = mx_atoi(arr_path[j][2]);
					matrix[old_index][new_index] = mx_atoi(arr_path[j][2]);
				}
			}
		}
	}
}

static void fiil_zero(int** matrix, int count) {
	int i = 0;
	int j = 0;

	for(; i < count; i++) {
		for(; j < count; j++) {
			matrix[i][j] = 0;
		}
	}
}

static int lol_func(char* point, char** uniq_elem, int new_index, int count) {
	int m = 0;

 	for (; m < count; m++) {
		if (mx_strcmp(point, uniq_elem[m]) == 0) {
			new_index = m;
		}
	}
	mx_strdel(&point);
	return new_index;
}
