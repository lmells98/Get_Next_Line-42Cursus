CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

NAME1	= test1
NAME2	= test2
SRCS	= get_next_line.c get_next_line_utils.c
MAIN	= main.c
OBJS 	= ${SRCS:.c=.o}
SUB		= get_next_line_utils.c

$(NAME1): $(SRCS)
	${CC} $(CFLAGS) -I . $(SRCS) $(MAIN) -o $(NAME2)

$(NAME2): $(SUB)
	${CC} $(CFLAGS) -I . $(SUB) $(MAIN) -o $(NAME1)

all:
	$(NAME1) $(NAME2)

clean:
	rm -f $(NAME1)
	rm -f $(NAME2)

fclean: clean

re: all fclean clean
