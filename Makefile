NAME= libftprintf.a

SOURCES=	flag_c.c \
		flag_d.c \
		flag_i.c \
		flag_s.c \
		flag_u.c \
		flag_x.c \
		flag_xx.c \
		utils_libft.c \
		utils_supp.c \
		ft_printf.c \

OBJS=		flag_c.o \
		flag_d.o \
		flag_i.o \
		flag_s.o \
		flag_u.o \
		flag_x.o \
		flag_xx.o \
		utils_libft.o \
		utils_supp.o \
		ft_printf.o \	

HEADER= ft_printf.h

SRCS_PATH= 		Sources/
INCLUDE_PATH=		Include/

SRCS=		$(addprefix $(SRCS_PATH), $(SOURCES))
INCLUDE=	$(addprefix $(INCLUDE_PATH), $(HEADER))
	
FLAGS= 	-Wall -Werror -Wextra
RM=	rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all
