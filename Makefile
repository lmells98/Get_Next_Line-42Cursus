CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

NAME1	= test
NAME2	= utils
SRCS	= get_next_line.c get_next_line_utils.c
MAIN	= main.c
OBJS 	= ${SRCS:.c=.o}
SUB		= get_next_line_utils.c

$(NAME1): $(SRCS)
	${CC} $(CFLAGS) -I . $(SRCS) $(MAIN) -o test.out

$(NAME2): $(SUB)
	${CC} $(CFLAGS) -I . $(SUB) $(MAIN) -o utils.out

all:
	$(NAME1) $(NAME2)

clean:
	rm -f test.out
	rm -f utils.out

fclean: clean

re: all fclean clean
