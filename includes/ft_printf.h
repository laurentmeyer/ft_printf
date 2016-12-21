/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:01 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/20 16:40:07 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# define CONVERSIONS "sSpdDioOuUxXcC%"
# define ERR -1

enum				e_modif
{
	hh,
	h,
	none,
	l,
	ll,
	j,
	z
};

typedef struct		s_conv
{
	int				flags;
	int				min_width;
	int				precision;
	enum e_modif	length_mod;
	char			conv_type;
}					t_conv;

typedef char 		*t_handler(void *);

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_asprintf(char **ret, const char *format, ...);
int					ft_vasprintf(char **ret, const char *format, va_list ap);
int					find_next_conversion(char *format, char **start, char **end);
char				*interpret_arg(void *arg, char *spec);
