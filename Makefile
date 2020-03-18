##
## EPITECH PROJECT, 2019
## lemin
## File description:
## Makefile
##

NAME	= my_rpg

CC	= gcc -g

RM	= rm -f

TESTS	= $(wildcard src/*.g*)

GAME	=	src/game/init_gameplay.c				\
			src/game/draw_player.c					\

MAP		= 	src/map/map_generator/map_generator.c	\
			src/map/getting_map.c					\
			src/map/init_map.c						\
			src/map/print_map.c						\

ENEMY 	= 	src/enemy/draw_enemys.c 	\
			src/enemy/init_enemy.c 		\
			src/enemy/move_enemy.c 		\

ACHIVEMENT 	= 	src/achievement/draw_achivement.c 	\
				src/achievement/draw_indicators.c 	\
				src/achievement/init_achivement.c 	\

MY 	= 		src/my/convert.c 					\
			src/my/my_strdup.c					\
			src/my/get_next_line.c				\
			src/my/my_revstr.c 					\
			src/my/my_strlen.c 					\
			src/my/my_str_to_word_array.c		\

SRCS	= 	src/main.c 							\
			src/open_window.c 					\
			src/capture_event.c 				\
			src/start_menu/display.c 			\
			src/start_menu/highlight.c          \
			src/start_menu/init.c               \
			src/pause_menu/display.c 			\
			src/pause_menu/highlight.c          \
			src/pause_menu/init.c               \
			$(MAP)								\
			$(ENEMY)							\
			$(MY)								\
			$(ACHIVEMENT)						\
			$(GAME)								\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -Wno-deprecated

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lm -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(TESTS)
tests_run:
	@make -C tests/ tests_run

re: fclean all

.PHONY: all clean fclean re
