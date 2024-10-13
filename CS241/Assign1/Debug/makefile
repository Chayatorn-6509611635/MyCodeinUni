CC = gcc
CFLAGS = -L/opt/homebrew/opt/flex/lib -lfl

all: main

parse.tab.c parse.tab.h: parse.y
	bison -d parse.y

lex.yy.c: lex-2.l
	flex lex-2.l

main: clean parse.tab.c lex.yy.c main.c
	$(CC) $(CFLAGS) -o main main.c parse.tab.c lex.yy.c 
 
clean:
	rm -rf main lex.yy.c parse.tab.c parse.tab.h

.PHONY: clean