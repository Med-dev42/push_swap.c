NAME= push_swap
CC= cc
CFLAGS= -Werror -Wall -Wextra
SRCS= push_swap.c
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
