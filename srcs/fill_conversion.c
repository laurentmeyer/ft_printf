/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:07 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/21 12:51:00 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#define FLAG_ALTERNATE (1L << 1)
#define NON_ALTERNABLE "cdinpsu"

static char		*handler_percent(void *arg)
{
	(void)arg;
	return (ft_strdup("%%"));
}

static char		*handler_string(void *arg)
{
	return (ft_strdup((char *)arg));
}

static t_handler	*get_handler(t_conv *conv)
{
	t_handler	*tab[127];

	tab[(int)'s'] = &handler_string;
	tab[(int)'%'] = &handler_percent;
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
	char	*ret;

	if (!(conv = new_conversion(spec)))
		return (NULL);
	ret = (*get_handler(conv))(arg);
	free(conv);
	return (ret);
}
