/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:35 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/02 20:58:29 by lmeyer           ###   ########.fr       */
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

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


int		main(void)
{
	int	ret;
	int	rot;

	setlocale(LC_ALL, "");
	//ret = printf("cc_d = |%.4c|\n==========\n");
	ret = printf("j'aime le " RED "rouge " RESET " et le bleu" RESET "\n===\n");
	printf(" ret = %d\n==========\n", ret);
	//rot = ft_printf("ft_d = |%.4c|\n==========\n", 0);
	rot = printf("j'aime le " RED "rouge " RESET " et le bleu" RESET "\n===\n");
	printf(" rot = %d\n==========\n", rot);
	return (0);
}
