.SILENT:

RED =`tput setaf 1`
GREEN =`tput setaf 2`
CLEAR =`tput sgr0`

NAME= libftprintf.a

SRCS =	ft_printf.c \
			ft_c.c \
			ft_di.c \
			ft_p.c \
			ft_prc.c \
			ft_s.c \
			ft_u.c \
			ft_x.c \
			ft_xx.c \
			err_functions.c \
			libft_functions.c \
			parse_functions.c \
			struct_functions.c \
			supp_functions.c \
			xtoa_functions.c \
			xtoa_necessaries.c

OBJS =	$(SRC:.c=.o)
SRCS_PATH = Sources/

SRC = $(addprefix $(SRCS_PATH),$(SRCS))

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM=	rm -rf


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Include/ft_printf.h
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "$(GREEN)$(NAME) compiled with succes.$(CLEAR)"

clean:
	$(RM) $(OBJS)
	echo "$(RED)object files removed.$(CLEAR)"

fclean: clean
	$(RM) $(NAME)
	echo "$(RED)$(NAME) removed.$(CLEAR)"

re: fclean all