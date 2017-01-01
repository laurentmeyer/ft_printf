#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static char *apply_padding(t_conv *conv, char *s)
{
	char	*position;

//	printf("len = %zu\n", ft_strlen(s));
	position = s;
	if (conv->flags & FLAG_MINUS) 
		position = ft_strlast(s) + 1;
	while ((int)ft_strlen(s) < conv->width)
	{
//		printf("re-len = %zu\n", ft_strlen(s));
		s = ft_insert_str(s, position, position, " ");
		position = s;
		if (conv->flags & FLAG_MINUS) 
			position = ft_strlast(s) + 1;
	}
	return (s);
}

//static char	*handler_long_char(t_conv *conv, void *arg)
//{
//	t_types	u;
//
//	(void)conv;
//	u.generic = arg;
//	return (ft_wcrtoutf(u.lc));
//}
//
//static char	*handler_short_char(t_conv *conv, void *arg)
//{
//	t_types	u;
//	char	*res;
//
//	(void)conv;
//	u.generic = arg;
//	if ((res = (char *)malloc(2)))
//	{
//		res[0] = (unsigned char)u.c;
//		res[1] = '\0';
//	}
//	return (res);
//}

char		*handler_char(t_conv *conv, void *arg)
{
	char	*res;
	t_types	u;

	(void)conv;
	u.generic = arg;
//	if (u.c == 0)
//		res = ft_wcrtoutf(0xFEFF);
	if (u.c != 0 && conv->modifier == l)
		res = ft_wcrtoutf(u.lc);
	else
	{
		if (!(res = (char *)malloc(2)))
			return (NULL);
		res[0] = u.c != 0 ? (unsigned char)u.c : 0xFF;
		res[1] = '\0';
	}
	res = apply_padding(conv, res);
	return (res);
}
