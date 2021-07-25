CC = gcc 
LD = gcc 
CFLAGS = -Wall -g -std=c11 -pedantic 
CFLAGS += `pkg-config --cflags gtk+-2.0` 
LDFLAGS = `pkg-config --libs gtk+-2.0`

%.o : %.c
	$(CC) $< $(CFLAGS) -c -o $@


test : jpeg_context.o tables.o idct.o  huffman.o  decode_sos.o decode_sof.o decode_dqt.o decode_dht.o decode_jpeg.o main.o
	$(LD)  $^ $(LDFLAGS) -o $@ 



.PHONY: clean
clean : 
	rm -f *.o
	rm -f test
