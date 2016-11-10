#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>


int				print_without_percent(char *start, char *end)
{
	char	*pos;

	if (!(pos = ft_strstr(start, "&&")))
		write(1, start, end - start);
	else
	{
		write(1, start, pos - start);
		write(1, pos + 1, end - pos - 1);
	}
	return (0);
}

char		*next_single_percent(char * s)
{
	if (s[0] == '%' && s[1] != '%')
		return (s);
	else if (*s == '\0')
		return (NULL);
	else if (s[0] == '%' && s[1] == '%')
		return (next_single_percent(s + 2));
	else
		return (next_single_percent(s + 1));
}

int				ft_vprintf(const char * restrict format, va_list ap)
{
	char		*s;
	char		*end;
	char		param;

	s = (char *)format; 
	write(1, s, (end = next_single_percent(s)) ? end - po
	if (!)
	while (*s)
	{
		if (!(end = next_single_percent(s)))
			return (print_without_percent(s, ft_strchr(s, '\0')));
		else
		{
			print_without_percent(s, end);
			param = va_arg(ap,int);
			s = next_single_percent(s) + 1;
		}
	}
	return (0);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list		ap;


	va_start(ap, format);
	ft_vprintf(format, ap);
	va_end(ap);
	return (0);
}

int		main(void)
{
	//	printf("%%coucou\n");
	//	printf("%s\n", next_single_percent(("c'es%c cool!%c")));
	ft_printf("%c'es%c cool!%c", 'C', 't', '\n');
	return (0);
}
