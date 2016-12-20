#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#define FLAG_ALTERNATE (1L << 1)
#define NON_ALTERNABLE "cdinpsu"

static char		*handler_string(void *arg)
{
	return (ft_strdup((char *)arg));
}

static t_handler	*get_handler(t_conv *conv)
{
	t_handler	*tab[127];

	tab[(int)'s'] = &handler_string;
	return (tab[(int)(conv->conv_type)]);
}

//int		get_flag(char s, t_conv *conv)
//{
//	conv->flags == 0;
//	while (*s)
//	{
//		if (*s == '#' && !ft_strchr(NON_ALTERNABLE, conv->conv_type))
//			conv->flag |= FLAG_ALTERNATE;
//}

static t_conv	*new_conversion(char *s)
{
	t_conv	*new;

	if ((new = (t_conv *)malloc(sizeof(t_conv))))
	{
		new->conv_type = s[ft_strlen(s) - 1];
	}
	return (new);
}

char	*interpret_arg(void *arg, char *spec)
{
	t_conv	*conv;

	if (!(conv = new_conversion(spec)))
		return (NULL);
	return ((*get_handler(conv))(arg));
}
