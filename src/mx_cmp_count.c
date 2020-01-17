#include "pathfinder.h"

int mx_cmp_count(char** uniq_elem, int count) {
	int sum = mx_sum_path(uniq_elem);

	if(count != sum) {
		mx_print_error("error: invalid number of island\n");
		exit(-1);
	}
	return sum;
}
