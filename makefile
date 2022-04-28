game:main.o menu.o minimap.o
	gcc main.o menu.o minimap.o -o game -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer -lSDL_gfx
menu.o:menu.c
	gcc -c menu.c -g
minimap.o:minimap.c
	gcc -c minimap.c -g
main.o:main.c
	gcc -c main.c -g

