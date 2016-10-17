all: main

main: $(OBJS)
	gcc -o main main.c

clean:
	rm -f main
