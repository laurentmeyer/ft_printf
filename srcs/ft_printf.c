#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>


int				print_without_percent(const char *s)
{
	char	*pos;

	if (!(pos = ft_strstr(s, "&&")))
		ft_putstr(s);
	else
	{
		write(1, s, pos - s);
		ft_putstr(pos + 1);
	}
	return (0);
}

const char		*next_single_percent(const char * s)
{
	if (s[0] == '%' && s[1] != '%')
		return ((const char *)s);
	else if (*s == '\0')
		return (NULL);
	else if (s[0] == '%' && s[1] == '%')
		return (next_single_percent(s + 2));
	else
		return (next_single_percent(s + 1));
}

int				ft_vprintf(const char * restrict format, va_list args)
{
	const char	*end;

	if (!(end = next_single_percent(format)))
		return (print_without_percent(format, ft_strchr(format, '\0')));
	// ICI ICI ICI
}

int		ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	const char	*s;


	va_start(ap, format);
	s = format;
	while (ft_vprintf(s, va_arg(ap, char *)))
		s = next_single_percent(s) + 1;
	va_end(ap);
	return (0);
}

int		main(void)
{
//	printf("%%coucou\n");
	printf("%s\n", next_single_percent(("c'es%c cool!%c")));
//	ft_printf("%c'es%c cool!%c", 'C', 't', '\n');
	return (0);
}
