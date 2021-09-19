CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

TEST	= test
DEBUG	= debug
BONUS	= bonus.out

SRCS	= get_next_line.c get_next_line_utils.c
MAIN	= main.c
DBUG	= debug_gnl.c debug.c
SUB		= get_next_line_utils.c

BONUSSRCS	= ./bonus/*.c

$(TEST): $(SRCS)
	${CC} $(CFLAGS) -I . $(SRCS) $(MAIN) -o test.out

$(DEBUG): $(SRCS)
	${CC} $(CFLAGS) -I . $(SUB) $(MAIN) $(DBUG) -o debug.out

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
