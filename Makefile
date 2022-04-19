
NAME = push_swap

SRCS		= manage_args.c \
			  main.c \
			  42_function_part_1.c \
			  42_function_part_2.c \
			  utils.c \
			  sorting_function.c \
			  display.c \
			  create.c \
			  assign_stack.c \
			  connect.c \
			  split_stack.c \
			  math_utils.c \
			  compare.c \
			  get.c \
			  choose_rotate.c \
			  sorting.c \
			  check.c \
			  ft_atol.c



OBJS			= $(SRCS:.c=.o)
CC				= clang
FLAGS 			= -g 

$(NAME) : 		$(OBJS)
				make -C libft
				$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

all : 			$(NAME)

%.o: %.c
				$(CC) -c $(FLAGS) -o $@ $^

clean :
				make clean -C libft
				/bin/rm -rf *.o

fclean : clean
				make fclean -C libft
				/bin/rm -rf $(NAME)

re : fclean all
.PHONY			: all clean fclean re
