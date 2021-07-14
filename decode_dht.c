#include <stdio.h>
#include <string.h>

#include "jpeg_context.h"
#include "decode_dht.h"

#define ERROR_RETURN(STR)   (fprintf(stderr, (STR)), -1)




void print_dht(struct htable *htable) {
	int count = 0;
	for(int i = 0; i < 16; i++) {
		fprintf(stdout, "%d : %hhu\n", i, htable->code_counts[i]);
		count += htable->code_counts[i];
	}
	if(count > 256) return;
	for(int i = 0; i< count; i++) {
		fprintf(stdout, "%hhX\n", htable->symbols[i]);
	}	
}

int decode_dht(struct jpeg_context *ctx) {
	fprintf(stdout, "decode_dht\n");
	
	const uint8_t *jpeg = ctx->jpeg;
	struct huffman_table *table = (struct huffman_table *)(jpeg + ctx->offset);
	print_dht(&table->htable);	
	const uint8_t is_ac = table->acdc_table_index >> 4;
	if(!(is_ac == 0 || is_ac == 1)) 
		return -1;
	const uint8_t index = table->acdc_table_index & 0x0F;
	if(index >= 4) 
		return -1;
			
	int code_count = 0;
	for(int i = 0; i < 16; i++)	{
		code_count += table->htable.code_counts[i];
	}
	if(code_count > 256)
		return -1;

	ctx->acdc_table &= ~(0x40U >> index);
	ctx->acdc_table |= is_ac >> index;	
	struct htable *htable = &ctx->htable[index];
	memcpy(htable->code_counts, table->htable.code_counts, sizeof(htable->code_counts));
	memcpy(htable->symbols, table->htable.symbols, code_count);
	
	return 0;
}
