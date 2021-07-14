#include <stdio.h>



#include "rle.h"
#include "jpeg_contex.h"
#include "huffman.h"


void get_rle(uint8_t **stream,  struct huffman_table *htbale, struct rle *rle) {
	rle->code  = decode_symbole(stream, htable);
	rle->value = decode_symbole(stream, htable);
}


