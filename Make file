CC     = gcc
FLAGS  = -Wall -Wextra -I src

all: fliptech

fliptech:
	$(CC) $(FLAGS) -o fliptech \
	src/main.c \
	src/deck/deck.c \
	src/utils/random.c \
	src/player/player.c \
	src/rules/rules.c \
	src/game/game.c \
	src/game/round.c \
	src/ui/display.c \
	src/ui/input.c \
	src/save/save.c \
	src/stats/stats.c

clean:
	rm -f fliptech
