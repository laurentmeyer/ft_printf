#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdarg.h>
#define	PFC(...)														\
	printf("  printf(" #__VA_ARGS__ ")\n=====> ");					\
printf(__VA_ARGS__)
#define ERR -1

char	*next_conversion_start(char *format)
{
	char *s;

	if (!(s = ft_strchr(format, '%')))
		return (NULL);
	return (s[1] == '%' ? next_conversion_start(s + 2) : s);
}

char	*next_conversion_end(char *format)
{
	int		i;

	format = next_conversion_start(format);
	i = 1;
	while (format[i] && !(format[i] == '%' && format[i + 1] != '%'))
		if ((ft_strchr(CONVERSIONS, format[i++])))
			return (format + i - 1);
	return (NULL);
}

int		number_conversions(char *format)
{
	char *s;

	if (!(s = next_conversion_start(format)))
		return (0);
	return (1 + number_conversions(s + 1));
}

char	*insert_string(char *dst, char *start, char *end, char *src)
{
	char	*new;

	if ((new = (char *)malloc(ft_strlen(dst) + ft_strlen(src) - (end - start))))
	{
		ft_strncpy(new, dst, start - dst);
		ft_strcpy(new + (start - dst), src);
		ft_strcpy(new + (start - dst) + ft_strlen(src), end + 1);
		free(dst);
	}
	return (new);
}

//CECI EST LA FONCTION LA PLUS IMPORTANTE DU MONDE !!!!!!!!!!!!!!!!!!!!
char	*interpret_arg(void *arg, char *spec)
{
	if (spec[ft_strlen(spec) - 1] == 's')
		return (ft_strdup((char *)arg));
	return (NULL);
}

char	*ft_vasprintf(char *format, va_list ap)
{
	char	*start;
	char	*end;
	char	*spec;
	char	*interpret;

	while (next_conversion_start(format))
	{
		if (!(start = next_conversion_start(format))
				|| !(end = next_conversion_end(format))
				|| !(spec = ft_strndup(start, end - start + 1))
				|| !(interpret = interpret_arg(va_arg(ap, void *), spec))
				|| !(format = insert_string(format, start, end, interpret)))
			return (NULL);
		free(spec);
		free(interpret);
	}
	return (format);
}

int		ft_asprintf(char **ret, const char *format, ...)
{
	va_list		ap;
	char		*cpy;

	va_start(ap, format);
	if (!(cpy = ft_strdup(format))
			|| !(cpy = ft_vasprintf(cpy, ap)))
		return (-1);
	va_end(ap);
	*ret = cpy;
	return (ft_strlen(cpy));
}

//#define 
int		main(void)
{
	char	*ret;
	//	setlocale(LC_ALL, "");
	if (ft_asprintf(&ret, "cou %s cou %a1.1s cou %s", "pouet", "salut", " alors") == ERR)
	//if (ft_asprintf(&ret, "cou s cou a1.1s cou s") == ERR)
		printf("ERREUR\n");
	printf("%s\n", ret);
	free(ret);
	return (0);
}
