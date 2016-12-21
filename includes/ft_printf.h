/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:01 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/21 21:30:36 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# define CONVERSIONS "sSpdDioOuUxXcC%"
# define ERR -1

enum				e_modif
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
};

typedef union		u_types
{
	void			*generic;
	signed char		hhd;
//	signed char		hhi;
	short			hd;
//	short			hi;
	int				d;
//	int				i;
	long			ld;
//	long			li;
	long long		lld;
//	long long		lli;
//	intmax_t		jd;
//	intmax_t		ji;
//	ssize_t			zd;
//	ssize_t			zi;
	char			*s;
}					t_types;

typedef struct		s_conv
{
	int				flags;
	int				width;
	int				precision;
	enum e_modif	modifier;
	char			conversion;
}					t_conv;

typedef char 		*t_handler(t_conv *, void *);

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_asprintf(char **ret, const char *format, ...);
int					ft_vasprintf(char **ret, const char *format, va_list ap);
int					find_next_conversion(char *format, char **start, char **end);
//char				*interpret_arg(void *arg, char *spec);
t_conv				*new_conversion(char *start, int len);
t_handler			*get_handler(t_conv *conv);
int					get_modifier(char *s);
int					get_flags(char *s);
int					get_precision(char *s);
int					get_width(char *s);
