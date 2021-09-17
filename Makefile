CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

TEST	= test
DEBUG	= debug
UTILS	= utils

SRCS	= get_next_line.c get_next_line_utils.c
MAIN	= main.c
UTIL	= utils-main.c
DBUG	= debug.c
OBJS 	= ${SRCS:.c=.o}
SUB		= get_next_line_utils.c

$(TEST): $(SRCS)
	${CC} $(CFLAGS) -I . $(SRCS) $(MAIN) -o test.out

$(DEBUG): $(SRCS)
	${CC} $(CFLAGS) -I . $(SRCS) $(MAIN) $(DBUG) -o debug.out

$(UTILS): $(SUB)
	${CC} $(CFLAGS) -I . $(SUB) $(UTIL) $(DBUG) -o utils.out

all: $(TEST) $(DEBUG) $(UTILS)

clean:
	rm -f test.out
	rm -f utils.out
	rm -f debug.out

fclean: clean

re: all fclean clean
