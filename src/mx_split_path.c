#include "pathfinder.h"

static char **one_line(char **result, const char *s);
static int get_index(const char *s, char c, char b);

char **mx_split_path(const char *s, char c, char b) {
    int size_arr = mx_count_path(s, c, b);
    int counter = 0;
    char **result = (char**)malloc(sizeof(char*) * (size_arr + 1));
    int len = mx_strlen(s);
    int index = 0;

    if (size_arr == 1)
        return one_line(result, s);
    for (int i = 0; i < len; i++) {
        index = get_index(s, c, b);
        if (index) {
            result[counter] = mx_strndup(s, index);
            s += mx_strlen(result[counter]) - 1;
            i += mx_strlen(result[counter]) - 1;
            counter++;
        }
        s++;
    }
    result[size_arr] = NULL;
    return result;
}

static char **one_line(char **result, const char *s) {
        result[0] = mx_strdup(s);
        result[1] = NULL;
        return result;
}

static int get_index(const char *s, char c, char b) {
    int index = 0;

    index = mx_get_char_index(s, c);
    if(index < 0)
        index = mx_get_char_index(s, b);
    index = index == -1 ? mx_strlen(s) : index;
    return index;
}
