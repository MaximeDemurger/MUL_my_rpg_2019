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

DUNGEON =	src/dungeon/get_path.c					\
			src/dungeon/init_dungeon.c				\

GAME	=	src/game/init_gameplay.c				\
			src/game/draw_player.c					\

KEY 	=	src/keys/init_keys.c 					\
			src/keys/draw_keys.c					\
			src/keys/pick_up_keys.c 				\

INVENTORY 	=	src/inventory/init_inventory.c 		\
				src/inventory/draw_inventory.c 		\

MAP		= 	src/map/map_generator/map_generator.c	\
			src/map/getting_map.c					\
			src/map/init_map.c						\
			src/map/print_map.c						\
			src/map/print_minimap.c					\
			src/map/check_map.c						\
			src/map/map_generator/put_donjon.c		\

ENEMY 	= 	src/enemy/draw_enemys.c 	\
			src/enemy/init_enemy.c 		\
			src/enemy/move_enemy.c 		\
			src/enemy/kill_enemys.c 	\

FOOD	= 	src/food/init_food.c 		\
			src/food/draw_food.c 		\
			src/food/pick_up_food.c 	\

ANCIENT = 	src/ancient/do_interaction.c 	\
			src/ancient/draw_ancient.c 		\
			src/ancient/init_ancient.c		\

SELECTION = 	src/lvl_selection/init_selection.c 		\
				src/lvl_selection/display_selection.c 	\

ACHIVEMENT 	= 	src/achievement/draw_achivement.c 	\
				src/achievement/draw_indicators.c 	\
				src/achievement/init_achivement.c 	\

HIGHSCORE = 	src/highscore/add_score.c 			\
				src/highscore/get_high_scores.c 	\
				src/highscore/final_score.c 		\

MY 	= 		src/my/convert.c 					\
			src/my/my_strdup.c					\
			src/my/get_next_line.c				\
			src/my/my_revstr.c 					\
			src/my/my_strlen.c 					\
			src/my/my_str_to_word_array.c		\
			src/my/convert_int_to_string.c 		\
			src/my/my_atoi.c 					\
			src/my/my_int_cmp.c 				\

PLAYER =	src/player/player_move.c 			\
			src/player/move_rect.c 				\
			src/player/player_life.c 			\
			src/player/player_remove_life.c		\
			src/player/attack_player.c			\

SCORE = 	src/score_game/init_score_game.c	\
			src/score_game/score.c				\

SRCS	= 	src/main.c 							\
			src/open_window.c 					\
			src/capture_event.c 				\
			src/start_menu/display.c 			\
			src/start_menu/highlight.c          \
			src/start_menu/init.c               \
			src/pause_menu/display.c 			\
			src/pause_menu/highlight.c          \
			src/pause_menu/init.c               \
			src/settings/init.c           		\
			src/settings/display.c 				\
			src/settings/drag_sound.c           \
			src/settings/sound.c           \
			$(MAP)								\
			$(ENEMY)							\
			$(MY)								\
			$(ACHIVEMENT)						\
			$(GAME)								\
			$(KEY)								\
			$(INVENTORY)						\
			$(DUNGEON)							\
			$(PLAYER)							\
			$(ANCIENT)							\
			$(SELECTION)						\
			$(SCORE)							\
			$(HIGHSCORE)						\
			$(FOOD) 							\

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
