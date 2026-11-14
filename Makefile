NAME = libftprintf.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror 

AR = ar 
ARFLAGS = rcs 

RM = rm -f 

SRCS = ft_handle_format.c ft_print_char.c ft_print_nbr.c \
		ft_print_str.c ft_print_unsigned.c ft_printf_hex.c\
		ft_printf.c ft_putchar.c ft_putnbr_base.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re