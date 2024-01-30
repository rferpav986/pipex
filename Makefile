NAME = pipex
FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a

FILES = pipex.c\

UTILS = pipex_utils.c\
		pipex_error.c\
		ft_split_pipex.c\
		ft_printfd2.c\

OBJS = $(FILES:.c=.o) $(UTILS:.c=.o)

BONUS=	bonus.c\

BOBJS = $(BONUS:.c=.o) $(UTILS:.c=.o)

all: $(NAME)

$(LIBFT):
	make all -C LIBFT

$(NAME): $(OBJS) $(LIBFT)
	cc $(FLAGS) $(OBJS) -Llibft -lft -o $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

bonus: $(BOBJS) $(LIBFT)
	cc $(FLAGS) $(BOBJS) -Llibft -lft -o $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)
	make fclean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all, clean, fclean, re, bonus