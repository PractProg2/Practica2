CC=gcc
CFLAGS=-Wall -ggdb
IFLAGS=-I./
LDFLAGS=-L./
LDLIBS=-lstack_fp
# -lm enlaza la biblioteca matematica, -pthread enlaza la biblioteca de hilos
LIBS = -lm -pthread

all: p2_e1

######################################################################
# $@ es el item que aparece a la izquierda de ':'
# $< es el primer item en la lista de dependencias
# $^ son todos los archivos que se encuentran a la derecha de ':' (dependencias)
########################################################################

p2_e1: p2_e1.o libstack_fp.a
	$(CC) -o $@ $< $(LDFLAGS) $(LDLIBS) $(LIBS)

p2_e1.o: p2_e1.c
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)
