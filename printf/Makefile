NAME = libftprintf.a

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror -I$(HEADER)

SRCS = ft_printf.c ft_printf_utils.c ft_work_chars.c ft_work_nbr.c ft_work_unbr.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

bonus : all

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus


