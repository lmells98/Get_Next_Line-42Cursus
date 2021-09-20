CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

TEST	= test
DEBUG	= debug.out
BONUS	= bonus.out

SRCS	= get_next_line.c get_next_line_utils.c
MAIN	= main.c
DBUG	= ./debug/debug_gnl.c ./debug/debug.c
DHEAD	= ./debug/debug_get_next_line.h
SUB		= get_next_line_utils.c

BONUSSRCS	= ./bonus/*.c

$(TEST): $(SRCS)
	${CC} $(CFLAGS) -I . $(SRCS) $(MAIN) -o test.out

$(DEBUG): $(SRCS)
	${CC} $(CFLAGS) -I $(DHEAD) $(SUB) $(MAIN) $(DBUG) -o debug.out

$(BONUS): $(BONUSSRCS)
	${CC} $(CFLAGS) -I . $(BONUSSRCS) -o $(BONUS)

all: $(TEST) $(DEBUG) $(BONUS)

clean:
	rm -f test.out
	rm -f debug.out
	rm -f bonus.out

fclean: clean

norm: 
	norminette *_lin*.[ch]

re: norm all fclean clean
