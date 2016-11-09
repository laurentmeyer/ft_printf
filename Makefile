OBJECTS =	ft_printf.o

NAME = ft_printf

LIBFT = ./libft/

CCHEADERS = -I ./includes/			\
			-I $(LIBFT)includes/

CCSOURCES = ./srcs/

CCLIBS = -L$(LIBFT) -lft

CFLAGS = -Wall -Wextra -Werror

SOURCES = $(OBJECTS:%.o=$(CCSOURCES)%.c)

all : $(NAME)
.PHONY: all

$(NAME) : libs
	gcc $(CFLAGS) -o $(NAME) $(CCHEADERS) $(CCLIBS) $(SOURCES)

libs: 
	$(MAKE) -C $(LIBFT)
.PHONY: libs

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJECTS)
.PHONY: clean

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
