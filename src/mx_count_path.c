#include "pathfinder.h"

int mx_count_path(const char *str, char c, char b) {
    int res = 0;
    int word = 0;

    if(str == NULL){
        res--;
        return res;
    }
    for ( ; *str; ++str) {
        if (*str != c && *str != b) {
            if (word == 0) {
                word = 1;
                res++;
            }
        }
        else if (word) {
            word = 0;
        }
    }
    return res;
}
