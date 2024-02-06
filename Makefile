NAME = pipex
FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a

COLOUR_RED=\033[0;31m
COLOUR_GREEN=\033[0;32m

FILES = pipex.c\

UTILS = pipex_utils.c\
		pipex_error.c\
		ft_split_pipex.c\
		ft_printfd2.c\

OBJS = $(FILES:.c=.o) $(UTILS:.c=.o)

BONUS=	pipex_bonus.c\

BOBJS = $(BONUS:.c=.o) $(UTILS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make all -C LIBFT > /dev/null
	@echo "$(COLOUR_GREEN)Compiled: libft"

$(NAME): $(OBJS) $(LIBFT)
	@cc $(FLAGS) $(OBJS) -Llibft -lft -o $(NAME)

%.o: %.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_GREEN)Compiled: $<"

bonus: $(BOBJS) $(LIBFT)
	@cc $(FLAGS) $(BOBJS) -Llibft -lft -o $(NAME)
	@echo "$(COLOUR_GREEN)Compiled bonus: $<"

clean:
	@rm -f $(OBJS) $(BOBJS)
	@make clean -C libft > /dev/null
	@echo "$(COLOUR_RED)Cleaned: $(OBJS) $(BOBJS)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft > /dev/null
	@echo "$(COLOUR_RED)Cleaned: $(NAME)"

re: fclean all

norminette:
	norminette $(FILES) $(UTILS) $(BONUS)

.PHONY: all, clean, fclean, re, bonus, norminette