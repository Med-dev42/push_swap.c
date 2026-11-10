NAME= push_swap
CC= cc
CFLAGS= -Werror -Wall -Wextra
SRCS= mandatory_part/push_swap.c \
              mandatory_part/parse_args.c \
              mandatory_part/ft_atoi.c \
              helper_functions/swap.c \
              helper_functions/push.c \
              helper_functions/rotate.c \
              helper_functions/reverse_rotate.c \
              helper_functions/list_utils.c \
              helper_functions/is_sorted.c \
              helper_functions/assign_index.c \
              Simple_algorithm/selection_sort.c \
              Medium_algorithm/chunk_sort.c \
              Complex_algorithm/radix_sort.c \
              adaptive_algorithm/adaptive.c
OBJS= $(SRCS:.c=.o)
HEADER= push_swap.h

#BONUS_NAME= checker
#HEADER_BONUS= push_swap_bonus.h
#SRCS_BONUS= checker.c
#OBJS_BONUS= $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#bonus: $(BONUS_NAME)

#$(BONUS_NAME): $(OBJS_BONUS)
#	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean 
.SECONDARY: $(OBJS) $(OBJS_BONUS)
