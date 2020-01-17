#include "libmx.h"

char	*mx_strdup(const char *str) {
	int	i = 0;
	char *buf = NULL;

	if(str == NULL)
		return NULL;
	i = mx_strlen(str);
	buf = mx_strnew(i);
	if (buf)
	{
		mx_strcpy(buf, str);
		return buf;
	}
	return NULL;
}
