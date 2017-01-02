#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#define MODIFIERS "hljz"
#define MAXMODIFIERS 2


static int		interpret_modifier(char *mod)
{
	enum e_modif	e;

	if (ft_strequ(mod, "ll"))
		e = ll;
	else if (ft_strequ(mod, "l"))
		e = l;
	else if (ft_strequ(mod, "hh"))
		e = hh;
	else if (ft_strequ(mod, "h"))
		e = h;
	else if (ft_strequ(mod, "j"))
		e = j;
	else if (ft_strequ(mod, "z"))
		e = z;
	else
		e = none;
	return (e);
}

int		get_modifier(char *s)
{
	char	*rev;
	int		i;
	char	*mod;
	int		ret;

	if (!(rev = ft_strnew(MAXMODIFIERS + 1)))
		return (ERR);
	i = ft_strlen(s) - 1;
	while (i > 0 && !ft_strchr(MODIFIERS, s[i]))
		--i;
	if (!ft_strchr(MODIFIERS, s[i]))
		return (0);
	rev[0] = s[i--];
	if (rev[0] && i >= 0 && s[i] == rev[0])
		rev[1] = s[i--];
	if (!(mod = ft_strrev(rev)))
		return (ERR);
	ret = interpret_modifier(mod);
	free(rev);
	free(mod);
	return (ret);
}
