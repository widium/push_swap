# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 14:19:55 by ebennace          #+#    #+#              #
#    Updated: 2022/04/22 09:53:30 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS		= 	main.c \
				./command_42/42_function_part_1.c \
				./command_42/42_function_part_2.c \
				./utils/utils.c \
				./utils/display.c \
				./utils/math_utils.c \
				./utils/get.c \
				./utils/compare.c \
				./utils/ft_atol.c \
				./utils/free_all.c \
				./sorting_function/sorting_function.c \
				./sorting_function/sorting.c \
				./sorting_function/choose_rotate.c \
				./sorting_function/candidate.c \
				./sorting_function/split_stack.c \
				./manage_input/create.c \
				./manage_input/assign_stack.c \
				./manage_input/check.c \
				./manage_input/connect.c \
				./manage_input/manage_args.c \

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
				/bin/rm -rf $(OBJS)

fclean : clean
				make fclean -C libft
				/bin/rm -rf $(NAME)
sanitize : 		$(OBJS)
				$(CC) $(FLAGS) $(SANITIZE) $(OBJS) libft/libft.a -o $(NAME)
				./$(NAME) 3 2 1
				

test : 
				./$(NAME)  `python3 visualiser_generator/generator.py 0 1000 200`

lldb:
				$(CC) -g $(SRCS) libft/libft.a -o $(NAME)
				lldb $(NAME)

re : fclean all
.PHONY			: all clean fclean re
