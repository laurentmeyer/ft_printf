#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

char	*ft_vasprintf(const char *format, va_list ap)
{
	char	*start;
	char	*end;
	char	*spec;
	char	*interpret;
	char	*cpy;

	if (!(cpy = ft_strdup(format)))
		return (NULL);
	while (next_conversion_start(cpy))
	{
		if (!(start = next_conversion_start(cpy))
				|| !(end = next_conversion_end(cpy))
				|| !(spec = ft_strndup(start, end - start + 1))
				|| !(interpret = interpret_arg(va_arg(ap, void *), spec))
				|| !(cpy = ft_insert_str(cpy, start, end, interpret)))
			return (NULL);
		free(spec);
		free(interpret);
	}
	return (cpy);
}

int		ft_asprintf(char **ret, const char *format, ...)
{
	va_list		ap;
	char		*cpy;

	va_start(ap, format);
	if (!(cpy = ft_vasprintf(cpy, ap)))
		return (-1);
	va_end(ap);
	*ret = cpy;
	return (ft_strlen(cpy));
}
