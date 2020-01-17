#include "libmx.h"

static char** split_word(const char *s, char c, char ** arr);

char **mx_strsplit(const char *s, char c) {
    int count = mx_count_words(s, c);
    char** arr = (char**)malloc(sizeof(char*) * count + 1);

    if(!s)
        return NULL;
    if (count == 1) {
        arr[0] =  mx_strdup(s);
        arr[1] = NULL;
        return arr;
    }
    return split_word(s, c, arr);
}

static char** split_word(const char *s, char c, char **arr) {
    int j = 0;
    int letters = 0;
    int word = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        while (s[i] != c && s[i] != '\0') {
             word = 1;
             letters++;
             i++;
        }
        if (word) {
            arr[j] = mx_strnew(letters);
            arr[j] = mx_strncpy(arr[j], s + i - letters, letters);
            word = 0;
            letters = 0;
            j++;
        }
    }
    arr[j] = NULL;
    return arr;
}
