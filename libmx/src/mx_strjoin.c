#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	int i = 0;
	int j = 0;
	
	if (s1 == NULL)
		return mx_strdup(s2);
	if (s2 == NULL)
        return mx_strdup(s1);
	int len1 = mx_strlen(s1);
	int len2 = mx_strlen(s2);
	char* str = mx_strnew(len1 + len2);
    if (!str)
		return NULL;
	for (; s1[i] != '\0'; i++) {
		str[i] = s1[i];
	}
	for (; s2[j] != '\0'; j++) {
		str[i] = s2[j];
		i++;
	}
	return str;
}
