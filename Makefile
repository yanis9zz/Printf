NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)
HEADERS = ft_printf.h ft_printf_utils.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	rm -f $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all
