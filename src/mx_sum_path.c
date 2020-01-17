#include "pathfinder.h"

int mx_sum_path(char** uniq_elem) {
	int i = 0;

	while (uniq_elem[i] != NULL)
		i++;
	return i;
}
