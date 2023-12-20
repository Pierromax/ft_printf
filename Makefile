CC	= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_printf_utils.c ft_putestr.c ft_putchar.c ft_strlen.c ft_printoa_base.c ft_printf.c ft_unitoa_base.c ft_putaddr.c
OBJS	= $(SRCS:.c=.o)
RM  	= rm -rf
NAME	= libftprintf.a

.o : .c
	$(CC) $(CFLAGS) -c $@ -o $< -I .

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

all 	: $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

compil : 
	@echo "Compiling...\n"
	@$(CC) $(CFLAGS) -g -o a.out $(SRCS)
	@./a.out

re : fclean all
