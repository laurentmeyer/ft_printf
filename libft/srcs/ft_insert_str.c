/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:30:28 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/22 17:17:22 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_insert_str(char *dst, char *start, char *end, char *src)
{
	char	*new;

	if ((new = (char *)malloc(ft_strlen(dst) + ft_strlen(src) - (end - start) + 1)))
	{
		ft_strncpy(new, dst, start - dst);
		ft_strcpy(new + (start - dst), src);
		ft_strcpy(new + (start - dst) + ft_strlen(src), end);
		free(dst);
	}
	return (new);
}
