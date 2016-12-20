#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdarg.h>
#define	PFC(...)														\
	printf("  printf(" #__VA_ARGS__ ")\n=====> ");					\
printf(__VA_ARGS__)
#define ERR -1


int		main(void)
{
	printf("coucou %5% %   %2dtoi\n", 5);
	return (0);
}
