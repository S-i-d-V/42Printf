NAME= libftprintf.a

SRCS=	Sources/*.c

OBJS=	*.o

HEADER= Include/ft_printf.h
	
FLAGS= 	-Wall -Werror -Wextra

RM=	rm -rf

all: $(NAME)

$(NAME): objs $(HEADER)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

objs:
	gcc $(FLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

reset: fclean
	$(RM) test

test: all
	gcc main.c  $(NAME) -o test
	./test

re: fclean all