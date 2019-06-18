NAME = libftprintf.a

SRCS = *.c

OBJ = $(SRCS:.c=.o)

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SRCS) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@gcc -o printf $(OBJ)


clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f printf

re: fclean all
