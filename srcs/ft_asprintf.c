/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:13 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/22 17:36:11 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

#include <stdio.h>

static void	remove_double_percent(char *s)
{
	if (!(s = ft_strstr(s, "%%")))
		return ;
	ft_memmove(s, s + 1, ft_strlen(s));
	remove_double_percent(s + 1);
}

static char	*interpret_arg(t_conv *conv, va_list ap)
{
	char	*ret;

	if (conv->conversion == '%')
		ret = (*get_handler(conv))(conv, "");
	else
		ret = (*get_handler(conv))(conv, va_arg(ap, void *));
	return (ret);
}

int			ft_vasprintf(char **ret, const char *format, va_list ap)
{
	char	*start;
	char	*end;
	char	*interpret;
	t_conv	*conv;
	int		find;

	if (!(*ret = ft_strdup(format)))
		return (ERR);
	while ((find = find_next_conversion(*ret, &start, &end)))
	{
		if (find == ERR	|| !(conv = new_conversion(start, end - start + 1)))
			return (ERR);
		interpret = interpret_arg(conv, ap);
		free(conv);
		if (!interpret || !(*ret = ft_insert_str(*ret, start, end + 1, interpret)))
			return (ERR);
		free(interpret);
	}
	remove_double_percent(*ret);
	return (ft_strlen(*ret));
}

int			ft_asprintf(char **ret, const char *format, ...)
{
	va_list		ap;
	int			res;

	va_start(ap, format);
	res = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (res);
}
