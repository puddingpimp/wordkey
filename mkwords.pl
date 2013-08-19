#!/usr/bin/perl -w
use strict;
open WORDS,"<", "/usr/share/dict/words";
my @words = <WORDS>;
close WORDS;
chomp @words;
my @deck;
print "const char *words[] = {\n";

while (@words) {
	my $w = splice(@words, int(rand($#words)),1);
	push @deck, $w if(length $w <= 8);
}

for(my $i=0;$i<(4096/8);$i++) {
	print("\t".join(", ", map({"\"" .$_. "\"" } splice(@deck, 0, 8))).",\n");
}
print "};\n";
