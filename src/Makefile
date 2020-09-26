all: Tokenizer

main.o: tokenizer.h
tokenizer.o: tokenizer.h

Tokenizer: main.o tokenizer.o
	gcc -o $@ $^

clean:
	rm *.o *~ Tokenizer
