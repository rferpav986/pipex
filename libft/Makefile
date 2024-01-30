NAME = libft.a
FLAGS = -Wall -Wextra -Werror

FILES = boolean/ft_isalpha.c \
		boolean/ft_isdigit.c \
		boolean/ft_isalnum.c \
		boolean/ft_isascii.c \
		boolean/ft_isprint.c\
		str/ft_strlen.c \
		mem/ft_memset.c \
		mem/ft_bzero.c \
		mem/ft_memcpy.c \
		mem/ft_memmove.c \
		str/ft_strlcpy.c\
		str/ft_strlcat.c \
		uplow/ft_toupper.c \
		uplow/ft_tolower.c \
		str/ft_strchr.c \
		str/ft_strrchr.c \
		str/ft_strncmp.c\
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		str/ft_strnstr.c \
		num/ft_atoi.c \
		mem/ft_calloc.c \
		str/ft_strdup.c\
		str/ft_substr.c\
		str/ft_strjoin.c\
		str/ft_strtrim.c\
		str/ft_split.c\
		num/ft_itoa.c\
		str/ft_strmapi.c\
		str/ft_striteri.c\
		print_fd/ft_putchar_fd.c\
		print_fd/ft_putstr_fd.c\
		print_fd/ft_putendl_fd.c\
		print_fd/ft_putnbr_fd.c\
		\
		get_next_line/get_next_line.c\
		\
		ft_printf/ft_printf.c\
		ft_printf/putnumbers.c\
		ft_printf/char.c\
		ft_printf/hex.c\
		ft_printf/pointer.c\

OBJS = $(FILES:.c=.o)

BONUS=	bonus/ft_lstnew_bonus.c\
		bonus/ft_lstadd_front_bonus.c\
		bonus/ft_lstsize_bonus.c\
		bonus/ft_lstlast_bonus.c\
		bonus/ft_lstadd_back_bonus.c\
		bonus/ft_lstdelone_bonus.c\
		bonus/ft_lstclear_bonus.c\
		bonus/ft_lstiter_bonus.c\
		bonus/ft_lstmap_bonus.c\

BOBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

bonus: $(NAME) $(BOBJS)
	ar -rcs $(NAME) $(BOBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus