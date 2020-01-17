#include "pathfinder.h"

static int mx_double_arr_len(char **arr) {
	int i = 0;

	while(arr[i] != NULL)
		i++;
	return i;
}

char*** mx_pars_path(char** arr) {
	int arr_len = mx_double_arr_len(arr);
	char*** arr_path = (char***)malloc(sizeof(char**) * (arr_len + 1));
	int j = 1;

	for ( ; arr[j] != NULL; j++) {
		arr_path[j - 1] = mx_split_path(arr[j], '-', ',');
	}
	arr_path[j - 1] = NULL;
	return arr_path;
}
