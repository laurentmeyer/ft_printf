/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:07 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/22 15:26:27 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

char		*handler_null(t_conv *conv, void *arg)
{
	char	*s;

	(void)arg;
	(void)conv;
	s = ft_strdup("(null)");
	return (s);
}

t_handler	*get_handler(t_conv *conv)
{
	t_handler	*tab[127];

	tab[(int)'%'] = &handler_percent;
	tab[(int)'s'] = &handler_null;
	tab[(int)'S'] = &handler_null;
	tab[(int)'p'] = &handler_null;
	tab[(int)'d'] = &handler_integers;
	tab[(int)'D'] = &handler_integers;
	tab[(int)'i'] = &handler_integers;
	tab[(int)'o'] = &handler_integers;
	tab[(int)'O'] = &handler_integers;
	tab[(int)'u'] = &handler_integers;
	tab[(int)'U'] = &handler_integers;
	tab[(int)'x'] = &handler_integers;
	tab[(int)'X'] = &handler_integers;
	tab[(int)'c'] = &handler_char;
	tab[(int)'C'] = &handler_char;
	return (tab[(int)(conv->conversion)]);
}
