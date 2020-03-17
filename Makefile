##
## EPITECH PROJECT, 2019
## lemin
## File description:
## Makefile
##

NAME	= my_rpg

CC	= gcc

RM	= rm -f

TESTS	= $(wildcard src/*.g*)

SRCS	= 	src/main.c 							\
			src/open_window.c 					\
			src/capture_event.c 				\
			src/start_menu/display.c 			\
			src/start_menu/highlight.c          \
			src/start_menu/init.c               \
			src/my/convert.c 					\
			src/my/my_revstr.c 					\
			src/my/my_strlen.c 					\
			src/achievement/draw_achivement.c 	\
			src/achievement/draw_indicators.c 	\
			src/achievement/init_achivement.c 	\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -Wno-deprecated

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(TESTS)
tests_run:
	@make -C tests/ tests_run

re: fclean all

.PHONY: all clean fclean re
