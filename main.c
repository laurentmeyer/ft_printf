/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:35 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/21 12:26:27 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdarg.h>
#define	PFC(...)														\
	printf("  printf(" #__VA_ARGS__ ")\n=====> ");					\
printf(__VA_ARGS__)
#define ERR -1


int		main(void)
{
	char	*ret;

	if (ft_asprintf(&ret, "percents = %   %    %%, arg1 = %  s, arg2 = %s\n", "arg1", "arg2") == ERR)
		printf("ERREUR\n");
	else
		ft_putstr(ret);
	free(ret);
//	if (ft_printf("%%%%%%\n") == ERR)
//		ft_putstr("Erreur\n");
//	if (ft_printf("percents = %   %    %%, arg1 = %  s, arg2 = %s\n", "arg1", "arg2") == ERR)
//		ft_putstr("Erreur\n");
	while (42)
		;
	return (0);
}
