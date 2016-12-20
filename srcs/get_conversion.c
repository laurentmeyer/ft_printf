#include "libft.h"
#include "ft_printf.h"

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
//
//int		count_conversions(char *format)
//{
//	char *s;
//
//	if (!(s = next_conversion_start(format)))
//		return (0);
//	return (1 + number_conversions(s + 1));
//}
