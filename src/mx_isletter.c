#include "pathfinder.h"

bool mx_isletter(char* str) {
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] >= 65 && str[i] <= 90) || 
			(str[i] >= 97 && str[i] <= 122))
			i++;
		else
			return 0;
	}
	return 1;
}
