all: hamming

hamming: $(OBJS)
	gcc -o hamming hamming.c

clean:
	rm -f hamming
