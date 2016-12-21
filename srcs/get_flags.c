/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:49:14 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/21 21:31:54 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#define FLAG_LIST "-+ #0"
#define FLAG_ALTERNATE (1 << 0)
#define FLAG_SPACE (1 << 1)
#define FLAG_ZERO (1 << 2)
#define FLAG_MINUS (1 << 3)
#define FLAG_PLUS (1 << 4)
#define NON_ALTERNABLE "cdinpsu"

#include <stdio.h>

//static int	is_alternable(char *s)
//{
//	return (!ft_strchr(NON_ALTERNABLE, s[ft_strlen(s) - 1]));
//}

int			get_flags(char *s)
{
	int		res;
	int		i;

	res = 0;
	if (ft_strchr(s, '#'))
		res |= FLAG_ALTERNATE;
	if (ft_strchr(s, ' '))
		res |= FLAG_SPACE;
	i = 0;
	while (s[i] && !ft_isdigit(s[i]))
		++i;
	if (s[i] == '0' && get_precision(s) == ERR)
		res |= FLAG_ZERO;
	if (ft_strchr(s, '-'))
	{
		res |= FLAG_MINUS;
		res &= ~FLAG_ZERO;
	}
	if (ft_strchr(s, '+'))
	{
		res |= FLAG_PLUS;
		res &= ~FLAG_SPACE;
	}
//	printf("spec = %s\n", s);
//	printf("alternate = %d\n", FLAG_ALTERNATE);
//	printf("opposite = %d\n", FLAG_ALTERNATE & ~FLAG_ALTERNATE);
	return (res);
}