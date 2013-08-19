CFLAGS = -O3 -std=gnu99

all: wordkey

wordkey: wordkey.c words.h
	$(CC) $(CFLAGS) -o $@ $<
words.h: mkwords.pl
	perl mkwords.pl >words.h
clean:
	rm wordkey
