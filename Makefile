
SRCS	= push_swap.c checkers.c utils.c main.c swapers.c utils_push_swap.c\
			move_stacks.c move_b.c move_b_part_2.c move_b_part_3.c \
			move_stacks_sort.c

LIBFT_PATH	= libft/

CFLAGS	=  -Wall -Werror -Wextra

NAME	= push_swap

RM		= rm -f

AR		= ar rc

GC 		= gcc

all:		${NAME}	

${NAME}:	
			${MAKE} -C ./libft all
			${GC} ${CFLAGS} ${SRCS} -I ${LIBFT_PATH}libft.h -L${LIBFT_PATH} -lft -o ${NAME}  


clean:		
			${MAKE} -C ./libft clean

			${RM} ${OBJS} 

fclean:		clean
			${MAKE} -C ./libft fclean
			${RM} ${NAME}

re:			fclean all




