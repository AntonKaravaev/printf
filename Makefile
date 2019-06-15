NAME = libftprintf.a

SRCS = *.c

OBJ = *.o

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SRCS) -I $(HEADER)
	@gcc -o printf $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
