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
#include <unistd.h>
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
//	wchar_t		*c;
	char		c[] = { 0xE2, 0xFF, 0xAC, 0x0 };

	setlocale(LC_ALL, "");
	printf("length = %zu\n", ft_strlen(c));
	printf("cc_d = |%8C|\n=====\n", 0x0);
	ft_printf("ft_d = |%8C|\n=====\n", 0x0);
	return (0);
}
