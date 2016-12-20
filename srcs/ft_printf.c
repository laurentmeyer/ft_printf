int		ft_vprintf(const char *format, va_list ap)
{
	char		*cpy;
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*ret;
	char		*cpy;

	va_start(ap, format);
	if (!(cpy = ft_strdup(format))
			|| !(ret = ft_vasprintf(cpy, ap)))
		return (ERR);
	if (ft_vasprintf(&ret, ) == ERR)
		printf("ERREUR\n");
	printf("%s\n", ret);
	free(ret);

	va_start(ap, format);
		return (-1);
	va_end(ap);
	*ret = cpy;
	return (ft_strlen(cpy));

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
				|| !(format = ft_insert_str(format, start, end, interpret)))
			return (NULL);
		free(spec);
		free(interpret);
	}
	return (format);
}

int		ft_printf(char **ret, const char *format, ...)
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
