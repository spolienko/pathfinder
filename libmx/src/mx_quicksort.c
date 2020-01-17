#include "libmx.h"

static void swap_str(char **str1, char** str2);
static void check_str(int *last, int* first, char** arr, char* str3);
static void main_job(char **arr, int *first, int *last, int *swap);

int mx_quicksort(char **arr, int left, int right) {
    int first = left;
    int last = right;
    char* middle = NULL;
    int swap = 0;

    if (!arr)
        return -1;
    if (left < right) {
        middle = arr[(left + (right - left) / 2)];
        while (first <= last) {
        check_str(&last, &first, arr, middle);
        main_job(arr, &first, &last, &swap);
    }
}  
    if (left < last)
        swap += mx_quicksort(arr, left, last);
    if (first < right)
        swap += mx_quicksort(arr, first, right);
    return swap;
}

static void swap_str(char **str1, char** str2) {
    char *temp = *str1; 
    *str1 = *str2; 
    *str2 = temp; 
}

static void check_str(int *last, int* first, char** arr, char* str3) {
    while (mx_strlen(arr[*first]) < mx_strlen(str3))
        (*first)++;
    while (mx_strlen(arr[*last]) > mx_strlen(str3))
        (*last)--;
}

static void main_job(char **arr, int *first, int *last, int *swap) {
    if (*first <= *last) {
        if ((*first != *last) &&
        (mx_strlen(arr[*first]) != mx_strlen(arr[*last]))) {
            swap_str(&arr[*first], &arr[*last]);
            (*swap)++;
        }
        (*first)++;
        (*last)--;
    }
}
