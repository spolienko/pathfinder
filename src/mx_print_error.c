#include "pathfinder.h"

void mx_print_error(const char* str) {
	 write(2, str, mx_strlen(str));
}
