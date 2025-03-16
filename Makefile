SRCS 			= push_swap.c error_checkers_pt_one.c error_checkers_pt_two.c args_to_linked_list.c \
					utils_pt_one.c utils_pt_two.c get_digit_pt_one.c get_digit_pt_two.c \
					instructions_pt_one.c instructions_pt_two.c instructions_pt_three.c instructions_pt_four.c \
					sort_stack_pt_one.c sort_stack_pt_two.c sort_stack_pt_three.c sort_stack_pt_four.c \

NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

all: $(NAME)

$(NAME): $(SRCS)
	${CC} ${CFLAGS} -o $(NAME) $(SRCS)

clean:
			$(RM) $(NAME)

fclean:		clean

re:			clean all

.PHONY:		all clean fclean re