#ifndef HUFFMAN
#define HUFFMAN


#include "jpeg_context.h"


struct huffman_table;

int init_huffman_tables(struct huffman_table **, struct jpeg_context *);
int free_huffman_tables(struct jpeg_context *);
void print_huffman_table(struct huffman_table *);

uint8_t decode_symbole(uint16_t **, struct huffman_table *);


#endif
