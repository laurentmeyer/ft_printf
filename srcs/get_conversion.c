#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#define MODIFIERS "hljz"

#include <stdio.h>

static char		*requalify_conversion(char *s)
{
	char	*conv;

	conv = ft_strlast(s);
	if (*conv == 'i')
		return (ft_insert_str(s, conv, conv + 1, "d"));
	if (*conv == 'D')
		return (ft_insert_str(s, conv, conv + 1, "ld"));
	else if (*conv == 'U')
		return (ft_insert_str(s, conv, conv + 1, "lu"));
	else if (*conv == 'O')
		return (ft_insert_str(s, conv, conv + 1, "lo"));
	else if (*conv == 'S')
		return (ft_insert_str(s, conv, conv + 1, "ls"));
	else if (*conv == 'C')
		return (ft_insert_str(s, conv, conv + 1, "lc"));
	else
		return (s);
}

t_conv			*new_conversion(char *start, int len)
{
	t_conv	*new;
	char	*s;

	if (!(s = ft_strndup(start, len)) || !(s = requalify_conversion(s)))
		return (NULL);
	if ((new = (t_conv *)malloc(sizeof(t_conv))))
	{
//		printf("full conversion = %s\n", s);
		new->conversion = *(ft_strlast(s));
		new->modifier = get_modifier(s);
		new->flags = get_flags(s);
		new->precision = get_precision(s);
		new->width = get_width(s);
//		printf("conversion = %c\n", new->conversion);
//		printf("flags = %d\n", new->flags);
//		printf("precision = %d\n", new->precision);
//		printf("width = %d\n", new->width);
//		printf("modifier = %d\n", new->modifier);
	}
	free(s);
	return (new);
}

int		find_next_conversion(char *format, char **start, char **end)
{
	char	*tmp;
	int		i;

	if (!(tmp = ft_strchr(format, '%')))
		return (0);
	if (tmp[1] == '%')
		return (find_next_conversion(tmp + 2, start, end));
	i = 1;
	while (tmp[i])
		if ((ft_strchr(CONVERSIONS, tmp[i++])))
		{
			*start = tmp;
			*end = tmp + i - 1;
			return (1);
		}
	ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
	return (0);
}
