NAME = libftprintf.a

SRCS =	ft_atoi.c \
		ft_convert1016.c\
		ft_convertdigits.c\
		ft_convertoctal.c\
		ft_convertunsi.c\
		ft_dexeptions.c\
		ft_dznak.c\
		ft_fexepbig.c\
		ft_memory.c\
		ft_printf.c\
		ft_recconver.c\
		ft_record1.c\
		ft_record2.c\
		ft_supfun1.c\
		ft_supfun1f.c\
		ft_supfun2.c\
		ft_supfun2f.c\
		ft_supprint1d.c\
		ft_supprint1f.c\
		ft_supprint1o.c\
		ft_supprint1s.c\
		ft_supprint1x.c\
		ft_supprint2d.c\
		ft_supprint2f.c\
		ft_supprint2s.c\
		ft_supprint2x.c\
		ft_supprint3d.c\
		ft_supprint3f.c\
		ft_supprint4d.c\
		ft_supprint4f.c\
		ft_supprint5f.c\
		ft_supprintadr.c\
		ft_supprintox.c\
		ft_uexeption.c

OBJ = $(SRCS:.c=.o)

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): %.o : %.c
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
