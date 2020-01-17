#include "pathfinder.h"

void mx_check_num(char*** arr_path) {
	int i = 0;
	int m = 0;

	while (arr_path[i] != NULL) {
		m = 0;
		while (arr_path[i][2][m]) {
			if (mx_isdigit(arr_path[i][2][m]) == 0) {
				mx_print_error_str(i + 2);
				exit(-1);
			}
			m++;
		}	
		i++;
	}
}
