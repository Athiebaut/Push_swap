NAME = push_swap
NAMEB = checker
PRINTF = libftprintf.a
LIBFT = libft.a

SRC_FILES = 	push_swap.c check_args.c t_stack.c \
		init_stack.c sort.c push.c rotate.c \
		reverse_rotate.c simple_sort.c swap.c \
		big_sort.c big_sort_utils.c loop_instructions.c \

SRCB_FILES =	check_args.c t_stack.c \
		init_stack.c sort.c push.c rotate.c \
		reverse_rotate.c swap.c simple_sort.c \
		big_sort.c big_sort_utils.c loop_instructions.c \

SRCBB_FILES = checker.c 
		
SRC = ${addprefix Src/, ${SRC_FILES}}
SRCB = ${addprefix Src/, ${SRCB_FILES}}
SRCBB = ${addprefix Bonus/, ${SRCBB_FILES}}
OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}
OBJBB = ${SRCBB:.c=.o}
CC = cc 
FLAGS = -Wall -Werror -Wextra
RM = rm -f 

${NAME}: ${OBJ}
	@make -C Printf 
	@cp Printf/libftprintf.a .
	@make -C Libft 
	@cp Libft/libft.a .
	${CC} ${FLAGS} ${OBJ} -I Inc ${PRINTF} ${LIBFT} -o ${NAME}


all: ${NAME}
	${CC} ${FLAGS} ${OBJ} -I Inc ${PRINTF} ${LIBFT} -o ${NAME}

bonus: checker

checker: ${OBJB} ${OBJBB}
	@make -C Printf 
	@cp Printf/libftprintf.a .
	@make -C Libft 
	@cp Libft/libft.a .
	${CC} ${FLAGS} ${OBJB} ${OBJBB} -I Inc ${PRINTF} ${LIBFT} -o ${NAMEB}

clean:
	@make clean -C Printf
	@make clean -C Libft
	${RM} ${OBJ} ${OBJBB}

fclean: clean
	@make fclean -C Printf
	@make fclean -C Libft
	${RM} ${NAME}
	${RM} ${NAMEB}
	${RM} ${PRINTF} ${LIBFT}

re: fclean
	make all

.PHONY: all clean fclean re 