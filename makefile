CFLAGS = -Wall -g 
CC = gcc
LD = gcc
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
GRAPH = graph
CLEAN_FILES = main $(OBJS) $(wildcard $(GRAPH).*)
FILENAME = catalogues/viz.txt

.PHONY: all
all: main

main: $(OBJS)
	$(LD) $(OBJS) -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: vis 
vis: main
	./main $(FILENAME) > $(GRAPH).dot
	dot -Tpdf $(GRAPH).dot -o $(GRAPH).pdf
	open $(GRAPH).pdf

.PHONY: clean
clean:
	rm -f $(CLEAN_FILES)