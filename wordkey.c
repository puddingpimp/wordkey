// Wordkey, by Dave Cameron 2013
// you are free to do whatever you want with this
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <err.h>

#include "words.h"

int foo(int a)
{
	return a+1;
}

bool
gen_key(unsigned char *key, size_t length, const char *path)
{
	FILE *f;
	f = fopen(path, "r");
	if(!f) return 1;
	if(fread(key, length, 1, f)==EOF)
		return 1;
	if(fclose(f)==EOF) return 1;
	return 0;
}

const char *
keyword(const unsigned char *key, size_t keylength, size_t offset_bits)
{
	int idx;
	idx = key[offset_bits/8] >> offset_bits%8;
	if((offset_bits/8)+1<keylength) {
		idx |= key[(offset_bits/8)+1] << 8-(offset_bits%8);
	}
	idx &= 0x3ff;
	return words[idx];
}

bool
print_key(const unsigned char *key, size_t keylength)
{
	for(size_t i=0;i<keylength*8;i+=12) {
		if(fputs(keyword(key,keylength,i), stdout)==EOF) return 1;
		if(fputc(' ', stdout)==EOF) return 1;
	}
	if(puts("")==EOF) return 1;
	return 0;
}

int
main(int argc, char **argv)
{
	unsigned char key[256/8];
	const size_t keylength = sizeof(key);
	const char *random_file = "/dev/urandom";
	if(gen_key(key, keylength, random_file))
		err(1, "gen_key");
	if(print_key(key, keylength))
		err(1, "print_key");
	memset(key, 0, keylength);
	return 0;
}
