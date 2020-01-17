#include "pathfinder.h"

static void find_all_graph_routes(int **matrix, int **matrix_path, int count, char **uniq) {
	t_graph *graph = mx_new_graph(matrix, matrix_path, count, uniq);

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (i < j) {
				mx_all_routes(graph, i, j);
			}
		}
	}
	free(graph);
}

static char** check_arg_availability(int argc, char *argv) {
	mx_check_availability(argc, argv);
	int fd = open(argv, O_RDONLY);
	char** arr = mx_pars_arr(fd);

	close(fd);
	return arr;
}

static char*** parth_path(char **arr, char *argv) {
	char*** arr_path = NULL;

	mx_error_handling_1(arr);
	arr_path = mx_pars_path(arr);
	mx_error_handling_2(arr_path);
	mx_end_line(argv);
	return arr_path;
}

static void work_with_path(int num, char ***arr_path, char **dup) {
	char** uniq =  mx_uniq_path(dup);
	int count = mx_cmp_count(uniq, num);
	int **matrix = mx_mem_matrix(count);
	int **matrix_path = NULL;

	mx_matrix(uniq, arr_path, count, matrix);
	mx_destroy_null(matrix, count);
	matrix_path = mx_mem_matrix(count);
	mx_matrix_path(matrix_path, matrix, count);
	mx_main_algo(matrix_path, count);
	find_all_graph_routes(matrix, matrix_path, count, uniq);
	mx_del_intarr(&matrix, count);
	mx_del_intarr(&matrix_path, count);
	free(uniq);
}

int main(int argc, char *argv[]) {
	char **arr = check_arg_availability(argc, argv[1]);
	int num = mx_first_line(arr);
	char*** arr_path = parth_path(arr, argv[1]);
	char** dup = mx_dup_path(arr_path);

	work_with_path(num, arr_path, dup);
	//system("leaks -q pathfinder");
}
