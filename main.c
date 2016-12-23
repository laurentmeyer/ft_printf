/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:35 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/23 15:49:19 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#define	PFC(...)														\
	printf("  printf(" #__VA_ARGS__ ")\n=====> ");					\
printf(__VA_ARGS__)
#define ERR -1


int		main(void)
{
//	char	*s;
//
//	s = ft_strdup("coucou");
//	printf("%s\n", ft_insert_str(s, s, s, "aaa"));
	printf("cc_d = |%-5%|\n=====\n");
	ft_printf("ft_d = |%-5%|\n=====\n");

	return (0);
}
