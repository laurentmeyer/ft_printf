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

t_handler	*get_handler(t_conv *conv)
{
	t_handler	*tab[127];

	tab[(int)'%'] = &handler_percent;
	tab[(int)'s'] = &handler_string;
//	tab[(int)'S'] = &handler_string;
//	tab[(int)'p'] = &handler_string;
	tab[(int)'d'] = &handler_integers;
	tab[(int)'D'] = &handler_integers;
	tab[(int)'i'] = &handler_integers;
	tab[(int)'o'] = &handler_integers;
	tab[(int)'O'] = &handler_integers;
	tab[(int)'u'] = &handler_integers;
	tab[(int)'U'] = &handler_integers;
	tab[(int)'x'] = &handler_integers;
	tab[(int)'X'] = &handler_integers;
//	tab[(int)'c'] = &handler_string;
//	tab[(int)'C'] = &handler_string;
	return (tab[(int)(conv->conversion)]);
}
