CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

TEST	= test
DEBUG	= debug

SRCS	= get_next_line.c get_next_line_utils.c
MAIN	= main.c
DBUG	= debug_gnl.c debug.c
OBJS 	= ${SRCS:.c=.o}
SUB		= get_next_line_utils.c

$(TEST): $(SRCS)
	${CC} $(CFLAGS) -I . $(SRCS) $(MAIN) -o test.out

$(DEBUG): $(SRCS)
	${CC} $(CFLAGS) -I . $(SUB) $(MAIN) $(DBUG) -o debug.out

all: $(TEST) $(DEBUG)

clean:
	rm -f test.out
	rm -f debug.out

fclean: clean

re: all fclean clean
