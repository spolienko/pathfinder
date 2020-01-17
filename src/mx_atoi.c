#include "pathfinder.h"

int mx_atoi(const char *str) {
    int i = 0;
    int flag = 1;
    int res = 0;
    
    if(str[0] == '-') {
        flag = -1;
        i++;
    }
    while (mx_isspace(str[i]))
        i++;
    while (str[i] && mx_isdigit(str[i])) {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res * flag;
}
