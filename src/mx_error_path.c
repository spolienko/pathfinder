#include "pathfinder.h"

void mx_error_path(char*** arr_path) {
	int i = 0;
	int j = 0;

	while(arr_path[i] != NULL) {
		if(mx_isletter(arr_path[i][0]) == 0) {
			mx_print_error_str(i + 2);
			exit(-1);
		}
		if(mx_isletter(arr_path[j][1]) == 0) {
			mx_print_error_str(j + 2);
			exit(-1);
		}
		i++;
	}
}
