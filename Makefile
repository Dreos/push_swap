NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -g3
INC			=	-I ./inc
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/push_swap.c  \
				src/utils.c \
				src/parsing.c \
				src/utils2.c \
				src/reverse_rotate.c \
				src/rotate.c \
				src/sorting.c \
				src/sort_little.c \
				src/sorting_set_up.c \
				src/swap_and_push.c \
				src/stack.c 
 
all:		obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)
obj:	
	@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@rm -rf $(OBJ) obj

100:	ARG=($(shuf -i 0-5000 -n 100))
	
500:
fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
