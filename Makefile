CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

TEST	= m
DEBUG	= d
BONUS	= b

SRCS	= get_next_line.c get_next_line_utils.c
MAIN	= main.c
DBUG	= ./debug/debug_gnl.c ./debug/debug.c
DHEAD	= ./debug/debug_get_next_line.h
BHEAD	= get_next_line_bonus.h
SUB		= get_next_line_utils.c

BONUSSRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c

$(TEST): $(SRCS)
	${CC} $(CFLAGS) -I . $(SRCS) $(MAIN) -o test.out

$(DEBUG): $(SRCS)
	${CC} $(CFLAGS) -I $(DHEAD) $(SUB) $(MAIN) $(DBUG) -o debug.out

$(BONUS): $(BONUSSRCS)
	${CC} $(CFLAGS) -I $(BHEAD) $(BONUSSRCS) $(MAIN) -o bonus.out

all: $(TEST) $(DEBUG) $(BONUS)

clean:
	rm -f test.out
	rm -f debug.out
	rm -f bonus.out

fclean: clean

norm: 
	norminette *_line*.[ch]

re: norm all fclean clean
