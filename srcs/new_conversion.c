#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#define MODIFIERS "hljz"

#include <stdio.h>

t_conv			*new_conversion(char *start, int len)
{
	t_conv	*new;
	char	*s;

	if (!(s = ft_strndup(start, len)))
		return (NULL);
	if ((new = (t_conv *)malloc(sizeof(t_conv))))
	{
		new->conversion = s[ft_strlen(s) - 1];
		new->modifier = get_modifier(s);
		new->flags = get_flags(s);
		new->precision = get_precision(s);
		new->width = get_width(s);
		printf("flags = %d\n", new->flags);
		printf("precision = %d\n", new->precision);
		printf("width = %d\n", new->width);
		printf("modifier = %d\n", new->modifier);
	}
	free(s);
	return (new);
}
