CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror
NAME =		libftprintf.a
TEMP =		temp.a
BUILDDIR =	srcs
SOURCEDIR =	srcs
HEADERDIR = includes

LFTPATH =	./libft
LIBFT = 	$(LFTPATH)/libft.a

CCHEADERS = -I./$(HEADERDIR)	\
			-I$(LFTPATH)/includes

SRCFILES =	ft_printf.c			\
			ft_asprintf.c		\
			get_conversion.c	\
			new_conversion.c	\
			get_handler.c		\
			get_modifier.c		\
			get_flags.c			\
			get_precision.c		\
			get_width.c

SOURCES =	$(SRCFILES:%.c=$(SOURCEDIR)/%.c)
OBJECTS =	$(SOURCES:$(SOURCEDIR)/%.c=$(BUILDDIR)/%.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(MAKE) -C $(LFTPATH)
	ar rcs $(TEMP) $(OBJECTS)
	libtool -static -o $(NAME) $(LIBFT) $(TEMP)
	rm $(TEMP)
	#ar -t libftprintf.a

$(BUILDDIR)/%.o : $(SOURCEDIR)/%.c
	$(CC) $(CFLAGS) $(CCHEADERS) -c $< -o $@

clean:
	$(MAKE) -C $(LFTPATH) clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LFTPATH) fclean
	rm -f $(NAME)

re: fclean all
	

#################ENLEVER LES COMMENTAIRES / VERIFS ####################
