NAME= push_swap
CC= cc
CFLAGS= -Werror -Wall -Wextra
SRCS= mandatory_part/main.c \
              helper_functions/swap.c \
              helper_functions/push.c \
              helper_functions/rotate.c \
              helper_functions/reverse_rotate.c \
              helper_functions/sorting_number.c \
              helper_functions/size_list.c \
              helper_functions/new_node.c \
	      helper_functions/move_numb.c \
	      helper_functions/is_sorted.c \
	      helper_functions/is_number.c \
	      helper_functions/give_node_index.c \
	      helper_functions/ft_strjoin.c \
	      helper_functions/ft_strdup.c \
	      helper_functions/ft_split.c \
	      helper_functions/ft_atol.c \
	      helper_functions/free_stack.c \
	      helper_functions/find_max_min.c \
	      helper_functions/file_engine.c \
	      helper_functions/error.c \
	      helper_functions/double_number.c \
	      helper_functions/alot_flags.c  \
	      helper_functions/add_back.c  \
	      helper_functions/ft_strlen.c \
	      helper_functions/print_bench.c \
	      helper_functions/ops_bench.c \
	      helper_functions/ft_strncmp.c \
	      helper_functions/ft_putstr_fd.c \
	      helper_functions/ft_putnbr_fd.c \
	      helper_functions/ft_putchar_fd.c \
              Simple_algorithm/selection_sort.c \
              Medium_algorithm/chunk_based.c \
	      adaptive_algorithm/compute_disorder.c\
	      adaptive_algorithm/alghrithm_use.c \
              Complex_algorithm/radix_sort.c
OBJS= $(SRCS:.c=.o)
HEADER= push_swap.h

BONUS_NAME= checker
HEADER_BONUS= push_swap_bonus.h
COMMON_SRC	= helper_functions/file_engine.c helper_functions/error.c \
		  helper_functions/add_back.c helper_functions/new_node.c \
		  helper_functions/is_number.c helper_functions/double_number.c \
		  helper_functions/is_sorted.c helper_functions/free_stack.c \
		  helper_functions/ft_atol.c helper_functions/ft_split.c \
		  helper_functions/ft_strdup.c helper_functions/ft_strjoin.c \
		  helper_functions/ft_strlen.c helper_functions/ft_strncmp.c \
		  helper_functions/swap.c helper_functions/push.c \
		  helper_functions/rotate.c helper_functions/reverse_rotate.c
SRCS_BONUS= bonus_part/checker_bonus.c \
	    bonus_part/error_bonus.c
OBJS_BONUS= $(SRCS_BONUS:.c=.o) $(COMMON_SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus re clean fclean 
