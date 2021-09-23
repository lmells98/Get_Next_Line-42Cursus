CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

<<<<<<< HEAD
TEST	= m
DEBUG	= d
BONUS	= b
=======
TEST	= test
DEBUG	= debug.out
BONUS	= bonus.out
>>>>>>> 690a764c885b1bd382243f3163cf1c4ad2a72c48

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
	${CC} $(CFLAGS) -I . $(BONUSSRCS) -o bonus.out

all: $(TEST) $(DEBUG) $(BONUS)

clean:
	rm -f test.out
	rm -f debug.out
	rm -f bonus.out

fclean: clean

norm: 
	norminette *_lin*.[ch]

re: norm all fclean clean
