#include "pathfinder.h"

void mx_del_intarr(int ***matrix, int count) {
	int **m = *matrix;
	
	for (int i = 0; i < count; i++) {
		free(m[i]);
	}
	free(*matrix);
}
