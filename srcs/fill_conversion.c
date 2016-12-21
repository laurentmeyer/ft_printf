/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:07 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/21 19:15:31 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

#include <stdio.h>


static int		get_modifier(char *s)
{
	char			mod[3];
	enum e_modif	a;

	(void)s;
	a = ll;
	ft_putstr("modifier = ");
	ft_putnbr(a);
	return (1);
}

static t_conv	*new_conversion(char *start, int len)
{
	t_conv	*new;
	char	*s;

	if (!(s = ft_strndup(start, len)))
		return (NULL);
	if ((new = (t_conv *)malloc(sizeof(t_conv))))
	{
		new->conv_type = s[ft_strlen(s) - 1];
		new->length_mod = get_modifier(s);
	}
	free(s);
	return (new);
}
