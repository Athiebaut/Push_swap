SRC =	ft_printf.c \
	ft_print_parse.c \
	ft_print_char.c \
	ft_print_str.c \
	ft_print_nbrs.c \
	ft_print_ptr.c \
	ft_print_hexa.c \
	ft_printf_utils.c

OBJS = ${SRC:.c=.o}
NAME = libftprintf.a
LIBC = ar -rcs
CC = cc 
RM = rm -f
FLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${FLAGS} -c $< -o${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS} 

all: ${NAME}
	
clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
