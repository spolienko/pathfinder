#include "pathfinder.h"

char** mx_dup_path(char*** arr_path) {
	int i = 0;
	int j = 0;
	char** is_dup = (char**)malloc(sizeof(char*) * 1);

	is_dup[0] = NULL;
	while(arr_path[i] != NULL) {
		is_dup[j] = arr_path[i][0];
		j++;
		is_dup = (char**)mx_realloc((void*)is_dup, (j + 1) * sizeof(is_dup));
		is_dup[j] = arr_path[i][1];
		j++;
		is_dup = (char**)mx_realloc((void*)is_dup, (j + 1) * sizeof(is_dup));
		is_dup[j] = NULL;
		i++;
	}
	is_dup[j] = NULL;
	return is_dup;
}
