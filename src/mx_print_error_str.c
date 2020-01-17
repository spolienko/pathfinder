#include "pathfinder.h"

void mx_print_error_str(int i) {
	char* str = mx_itoa(i);

	mx_print_error("error: line ");
	mx_print_error(str);
	mx_print_error(" is not valid");
	write(2, "\n", 1);
}
