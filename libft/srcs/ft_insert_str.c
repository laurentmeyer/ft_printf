#include "libft.h"
#include <stdlib.h>

char	*ft_insert_str(char *dst, char *start, char *end, char *src)
{
	char	*new;

	if ((new = (char *)malloc(ft_strlen(dst) + ft_strlen(src) - (end - start))))
	{
		ft_strncpy(new, dst, start - dst);
		ft_strcpy(new + (start - dst), src);
		ft_strcpy(new + (start - dst) + ft_strlen(src), end + 1);
		free(dst);
	}
	return (new);
}
