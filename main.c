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
	int	ret;
	int	rot;

	setlocale(LC_ALL, "");
	ret = printf("cc_d = |% Zoooo|\n==========\n");
	printf(" ret = %d\n==========\n", ret);
	rot = ft_printf("ft_d = |% Zoooo|\n==========\n");
	printf(" rot = %d\n==========\n", rot);
	return (0);
}
