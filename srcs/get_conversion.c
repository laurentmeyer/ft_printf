/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:27 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/22 15:04:29 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include <stdio.h>

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
	return (ERR);
}
