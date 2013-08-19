This is a simple tool to create a strong passphrase by concatenating
dictionary words. 

It iterates over 12-bit portions of the internally generated key and
uses these as indexes into a table of 4096 (0x400) words. By this
method, the pass phrase is ensured to contain the same entropy as the
key (hardcoded to 256 bits for now). 

Note that if a weak hash is used on the passphrase in your
cryptosystem's implementation it will not preserve the entire entropy
of the key. It is unlikely that even strong hashes preserve the entire
entropy of the key, though this is difficult to (dis)prove, and
applies almost equally well to any random passphrase scheme with
sufficient entropy. 

You can do whatever you want with this. I'm pretty sure this or a
similar method has been previously used by Bell Labs, though this
implementation is entirely my own work.
