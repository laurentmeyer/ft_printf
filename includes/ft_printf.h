# include <stdarg.h>
# define CONVERSIONS "sSpdDioOuUxXcC"
# define TEST "42"

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

int					ft_asprintf(char **ret, const char *format, ...);
char				*ft_vasprintf(char *format, va_list ap);
char				*next_conversion_start(char *format);
char				*next_conversion_end(char *format);
char				*interpret_arg(void *arg, char *spec);
