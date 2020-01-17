#include "pathfinder.h"

int mx_end_line(const char *file) {
	char* line = NULL;
	int n = 0;
	int i = 0;
	int len = 0;

	line = mx_file_to_str(file);
	len = mx_strlen(line);
	while (line[i] != '\0') {
		if (line[i] == '\n')
			n++;
		i++;
	}
	if (line[len - 1] != '\n') {
		mx_print_error_str(n + 1);
		mx_strdel(&line);
		exit(-1);
	}
	if(line != NULL)
		mx_strdel(&line);
	return n;
}
