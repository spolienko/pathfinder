#include "pathfinder.h"

int mx_first_line(char** arr) {
    int m = 0;

    if (arr[0][0] == '\0') {
    	mx_print_error_str(1);
            exit(-1);
    }
    for (; arr[0][m] != '\0'; m++) {
        if (mx_isdigit(arr[0][m]) == 0) {
            mx_print_error_str(1);
            exit(-1);
        }
    }
    return mx_atoi(arr[0]);
}
