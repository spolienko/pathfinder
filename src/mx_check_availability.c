#include "pathfinder.h"

static void print_no_file_error(char *str) {
	mx_print_error("error: file ");
	mx_print_error(str);
	mx_print_error(" does not exist\n");
}

static void print_empty_file_error(char *str) {
	mx_print_error("error: file ");
	mx_print_error(str);
	mx_print_error(" is empty\n");
}

void mx_check_availability(int i, char* str ) {
	char* path = NULL;
	int fd;

	if (i != 2) {
		mx_print_error("usage: ./pathfinder [filename]\n");
		exit(-1);
	}
	if ((fd = open(str, O_RDONLY)) <= 0) {
		print_no_file_error(str);
		exit(-1);
	}
	close(fd);
	path = mx_file_to_str(str);
	if (path == NULL) {
		print_empty_file_error(str);
		mx_strdel(&path);
		exit(-1);
	}
	mx_strdel(&path);
}
