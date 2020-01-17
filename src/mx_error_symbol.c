#include "pathfinder.h"

static void count_symbol(char** arr, int j);
static void index_symbol(char** arr, int j);

void mx_error_symbol(char** arr) {
	int j = 1;
	
	while (arr[j] != NULL) {
		index_symbol(arr, j);
		count_symbol(arr, j);
		j++;
	}
}

static void count_symbol(char** arr, int j) {
	int h = mx_count_substr(arr[j], "-");
	int m = mx_count_substr(arr[j], ",");

	if (h > 1 || h == 0) {
			mx_print_error_str(j + 1);
			exit(-1);
		}
	if (m > 1 || m == 0) {
			mx_print_error_str(j + 1);
			exit(-1);
		}
}

static void index_symbol(char** arr, int j) {
	int i = mx_get_char_index(arr[j], '-');
	int m = mx_get_char_index(arr[j], ',');

	if (m < i) {
			mx_print_error_str(j + 1);
			exit(-1);
	}
	if (m == mx_strlen(arr[j]) - 1) {
			mx_print_error_str(j + 1);
			exit(-1);
	}
	if (i == 0) {
		mx_print_error_str(j + 1);
			exit(-1);
	}

}
