#ifndef DECODE_DHT
#define DECODE_DHT

#include "jpeg_context.h"

struct huffman_table {
	uint16_t lenght;
	uint8_t acdc_table_index; /*hight nibble DC(0) AC(1) low nibble index of table */
	struct htable htable;
}__attribute__((packed));

struct jpeg_context;
int decode_dht(struct jpeg_context *);
void print_dht(struct htable *);

#endif
