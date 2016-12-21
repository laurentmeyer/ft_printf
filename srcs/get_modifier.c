#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#define MODIFIERS "hljz"

#include <stdio.h>


static int		interpret_modifier(char mod[3])
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
	char			mod[3];
	int				i;

	ft_bzero(mod, sizeof(mod));
	i = 0;
	while (s[i] && !ft_strchr(MODIFIERS, s[i]))
			++i;
	if (!ft_strchr(MODIFIERS, s[i]))
		return (0);
	mod[0] = s[i++];
	if (mod[0] && s[i] == mod[0])
		mod[1] = s[i++];
	++i;
	if (s[i] != '\0')
		return (ERR);
	return (interpret_modifier(mod));
}
