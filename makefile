prog:main.o menu.o 
	gcc main.o menu.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
menu.o:menu.c
	gcc -c menu.c -g
