#include "pathfinder.h"

static int check_flag(int i, char** is_dup);


char** mx_uniq_path(char** is_dup) {
	int i = 0;
	int k = 0;
	char** uniq_elem = (char**)malloc(sizeof(char*) * 1);
	int flag = 1;

	uniq_elem[0] = NULL;
	while (is_dup[i] != NULL) {
		flag = check_flag(i, is_dup);
		if (flag == 1) {
			uniq_elem[k] = is_dup[i];
			k++;
			uniq_elem = (char**)mx_realloc((void*)uniq_elem,
				(k + 1) * sizeof(uniq_elem));
		}
		i++;
	}
	uniq_elem[k] = NULL;
	return uniq_elem;
}

static int check_flag(int i, char** is_dup) {
	int flag = 1;
	
	for (int j = i; j >= 0; j--) {
		if (mx_strcmp(is_dup[i], is_dup[j]) == 0 && i != j) {
			flag--;
		}
	}
	return flag;
}
