# makefile for text_adventure

text_adventure.o: text_adventure.c location.h
	gcc -c text_adventure.c

location.o: location.c misc.h object.h location.h
	gcc -c location.c

object.o: object.c object.h
	gcc -c object.c

misc.o: misc.c misc.h object.h
	gcc -c misc.c

text_adventure: text_adventure.o location.o object.o misc.o
	gcc text_adventure.o location.o object.o misc.o -o text_adventure
