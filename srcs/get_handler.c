/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:07 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/21 19:56:49 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static char		*handler_percent(t_conv *conv, void *arg)
{
	(void)arg;
	(void)conv;
	return (ft_strdup("%%"));
}

static char		*handler_string(t_conv *conv, void *arg)
{
	(void)conv;
	return (ft_strdup((char *)arg));
}

static char		*handler_integer(t_conv *conv, void *arg)
{
	t_types	u;

	(void)conv;
	u.generic = arg;
	return (ft_itoa(u.d));
}

t_handler	*get_handler(t_conv *conv)
{
	t_handler	*tab[127];

	tab[(int)'s'] = &handler_string;
	tab[(int)'%'] = &handler_percent;
	tab[(int)'d'] = &handler_integer;
	tab[(int)'i'] = &handler_integer;
	tab[(int)'o'] = &handler_integer;
	return (tab[(int)(conv->conversion)]);
}
