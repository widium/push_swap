
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
			  ft_atol.c \
			  candidate.c



OBJS			= $(SRCS:.c=.o)
CC				= clang
FLAGS 			= -g
SANITIZE		= -fsanitize=address

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
sanitize : 		
				$(CC) $(FLAGS) $(SANITIZE) $(OBJS) libft/libft.a -o $(NAME)
				

test : 
				./$(NAME) `python3 generator.py 0 1000 5`

re : fclean all
.PHONY			: all clean fclean re
