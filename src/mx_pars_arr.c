#include "pathfinder.h"

char** mx_pars_arr(int fd) {
	char* path = NULL;
	char** arr = (char**)malloc(sizeof(char*) * 1);
	int i = 0;
	int read = 0;

	arr[0] = NULL;
	while((read = mx_read_line(&path, 1, '\n', fd)) != -1) {
		if(path != NULL) {
			arr[i] = mx_strdup(path);
			mx_strdel(&path);
		}
		i++;
		arr = (char**)mx_realloc((void*)arr, (i + 1) * sizeof(arr));
		arr[i] = NULL;
	}
	mx_strdel(&path);
	arr[i] = NULL;
	return arr;
}
