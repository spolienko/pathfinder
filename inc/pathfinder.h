#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <fcntl.h>
#include <malloc/malloc.h>
#include "libmx/inc/libmx.h"

#define MAX_INT 21474836
#define DELIM_BLOCK "========================================\n"
#define NEW_LINE "\n"
#define EMPTY_LINE ""
#define PATH "Path: "
#define ROUTE "Route: "
#define EQUALITY " = "
#define PLUS " + "
#define ARROW " -> "
#define DISTANCE "Distance: "

typedef struct		s_route
{
    int			size;
    int*		route;
    int 		count;
}				t_route;

typedef struct  s_graph
{
	int 		size;
	int** 		matrix;
	int** 		path_matrix;
	char**		uniq;
}				t_graph;

int 			mx_atoi(const char *str);
int 			mx_count_path(const char *str, char c, char b);
char** 			mx_dup_path(char*** arr_path);
int 			mx_cmp_count(char** uniq_elem, int count);
bool 			mx_isdigit(char c);
char*** 		mx_pars_path(char** arr);
void 			mx_print_error(const char* str);
char** 			mx_split_path(const char *s, char c, char b);
int 			mx_sum_path(char** uniq_elem);
char** 			mx_uniq_path(char** is_dup);
void 			mx_matrix(char** uniq_elem, char*** arr_path, int count, int **matrix);
void 			mx_error_symbol(char** arr);
void 			mx_print_error_str(int i);
char** 			mx_pars_arr(int fd);
void 			mx_error_path(char*** arr_path);
bool 			mx_isletter(char* str);
void 			mx_check_num(char*** arr_path);
int 			mx_first_line(char** arr);
int 			mx_end_line(const char *file);
void 			mx_dejkstry( int **matrix, int count);
int** 			mx_mem_matrix(int count);
void  			mx_matrix_path(int** matrix_path, int** matrix, int count);
void 			mx_main_algo(int** matrix_path, int count);
void 			mx_destroy_null(int** matrix, int count);
void 			mx_all_routes(t_graph *graph, int start, int end);
void 			mx_backtrack(int **matrix, int **matrix_path, t_route *route, t_graph *g);
void 			mx_all_routes(t_graph *graph, int start, int end);
int* 			mx_mem_int_arr(int count);
void 			mx_print_error_islands();
t_graph 		*mx_new_graph(int **matrix, int **path_matrix, int size, char **uniq);
void 			mx_check_availability(int i, char* str );
void			mx_error_handling_1(char** arr);
void 			mx_error_handling_2(char*** arr_path);
void 			mx_del_intarr(int ***matrix, int count);

#endif
