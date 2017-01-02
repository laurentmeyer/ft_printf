#include "libft.h"
#include "ft_printf.h"

char		*handler_pointer(t_conv *conv, void *arg)
{
	char	*res;
	t_types u;

	(void)conv;
	u.generic = arg;
	res = ft_itoa_base_max_unsigned((uintmax_t)(u.llu), 16);
	res = ft_insert_str(res, res, res, "0X");
	ft_strtolower(res);
	return (res);
}
