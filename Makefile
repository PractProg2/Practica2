CC=gcc
CFLAGS=-Wall -ggdb
IFLAGS=-I./
LDFLAGS=-L./
LDLIBS=-lstack_fp
# -lm enlaza la biblioteca matematica, -pthread enlaza la biblioteca de hilos
LIBS = -lm -pthread

all: p2_e1 p2_e2 p2_e0_a p2_e0_b p2_e3_a p2_e3_b

######################################################################
# $@ es el item que aparece a la izquierda de ':'
# $< es el primer item en la lista de dependencias
# $^ son todos los archivos que se encuentran a la derecha de ':' (dependencias)
########################################################################

p2_e1: p2_e1.o libstack_fp.a
	$(CC) -o $@ $< $(LDFLAGS) $(LDLIBS) $(LIBS)

p2_e1.o: p2_e1.c
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)

p2_e2: p2_e2.o libstack_fp.a
	$(CC) -o $@ $< $(LDFLAGS) $(LDLIBS) $(LIBS)

p2_e2.o: p2_e2.c
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)

p2_e0_a: p2_e0_a.o libstack_fp.a node.o
	$(CC) -o $@ $< $(LDFLAGS) $(LDLIBS) $(LIBS)
 
p2_e0_a.o: p2_e0_a.c node.h
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)

p2_e0_b: p2_e0_b.o libstack_fp.a node.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)
 
p2_e0_b.o: p2_e0_b.c node.h
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)

node.o: node.c node.h types.h
	$(CC) $(CFLAGS) -c node.c

p2_e3_a: p2_e3_a.o stack.o element.o
	$(CC) $(CFLAGS) p2_e3_a.o stack.o element.o -o p2_e3_a

p2_e3_a.o: p2_e3_a.c stack.h 
	$(CC) $(CFLAGS) -c p2_e3_a.c 

p2_e3_b: p2_e3_b.o stack.o element.o
	$(CC) $(CFLAGS) p2_e3_b.o stack.o element.o -o p2_e3_b

p2_e3_b.o: p2_e3_b.c stack.h 
	$(CC) $(CFLAGS) -c p2_e3_b.c 

stack.o: stack.c stack.h element.h
	$(CC) $(CFLAGS) -c stack.c

element.o: element.c element.h types.h
	$(CC) $(CFLAGS) -c element.c
	
clean:
	rm -f *.o p2_e1 p2_e2 p2_e0_a p2_e0_b p2_e3_a p2_e3_b