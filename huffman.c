
#include <stdio.h>
#include <assert.h>

#include "jpeg_context.h"
#include "huffman.h"

#define HUFF_MAX_CODE_BITS 16
#define HUFF_PREFIX_CODE_BITS 9
#define HUFF_BTREE_CODE_BITS (HUFF_MAX_CODE_BITS - HUFF_PREFIX_CODE_BITS)
#define HUFF_PREFIX_CODE_COUNT (1 << HUFF_PREFIX_CODE_BITS)
#define HUFF_TABLE_LENGTH 2


#define LOG2_BASE(X) (8*sizeof (x) - __builtin_clz((x)))



struct prefix_code {
	uint16_t symbole; 
	uint8_t clength;
	struct prefix_node *table; /* NULL signals code is in the prefix table */		
};

struct huffman_table {
	struct prefix_code ptable[HUFF_PREFIX_CODE_COUNT];	
};

static void inline print_node(struct prefic_code *code, const uint16_t code) {
		fprintf(stdout, "code : %hX  symbole : %hu code length : %hhu \n", code, code->symbole, code->clength);		
}

static void print_table_code(struct prefix_code *table, const uint16_t prev_code) {
		for(int i = 0; i < 2; i++) {
			const prefic_code *t = table[i];
			const uint16_t code = current_code << 1 + i;
			if(t->table ) {
				print_table_code(code, t->table);
				continue;
			}
			print_node(code, t);
		}
}

void print_huffman_table(struct huffman_table *htable) {
	
	struct prefic_code *ptable = htable->ptable;
	fprintf(stdout, "lookup table\n");
	for(uint16_t i = 0; i < HUFF_PREFIX_CODE_COUNT; i++) {
			if(ptable[i].table || !ptable[i].clength ) {
				continue;
			}
			print_node(i, &ptable[i]);
	}
	fprintf(stdout, "table code\n");
	for(uint16_t i  = 0; i < HUFF_PREFIX_CODE_COUNT) {
		if(!ptable[i].table) {
			continue;
		}
		print_table_code(&ptable[i], i);
	}
}

void alloc_huffman_table(struct jpeg_context *ctx) {
	const size_t hsize = HTABLE_COUNT*sizeof(struct huffman_table);
	struct huffman_table *tables = malloc(hsize);	
	memset(tables, 0, hsize); 
	ctx->huffman_table = tables;
}


static void inline add_lookup_code(const uint16_t code,  const uint8_t symbole, const uint8_t clength, struct prefix_code ptable[HUFF_PREFIX_CODE_COUNT] ) {
	
	for(uint16_t i = 1 << clength; i < HUFF_PREFIX_CODE_COUNT; i++) {
		const uint16_t len = LOG_2_BASE(i);
		if(code == i >> (len - clength)) {
			ptable[i] = (struct prefix_code){.symbole = symbole, .clength = clength};
		} 
	}
	
}

static void inline add_table_code(const uint16_t code, const uint8_t symbole, const uint8_t clength, struct prefix_code *prefix_node){
	uint8_t clen = HUFF_PREFIX_CODE_COUNT;
	struct prefix_code *node = prefix_node;
	do {
		if(!node->table) {
			const size_t psize = 2*sizeof(struct prefix_code);
			node->table = malloc(psize);
			memset(node->table, 0, psize);
		}
		node = &node->table[(code & (1 << (clen - 1))  ) ? 1 : 0]; // TODO check it out	
		if(node->clenght){
			clen++;
			continue;
		}
		*node = (struct prefic_code){ .symbole = symbole, .clength = clength};
			
	}while(0);
}

int init_huffman_tables(struct huffman_table *table, struct htable *htable) {	

	uint8_t code = 0, index = 0;
	for(uint8_t i = 0; i < HUFF_PREFIX_CODE_BITES; i++) {
		for(uint8_t j = htable.code_count[j]; j; j--) {
			add_lookup_code(code++, htable.symboles[index++], i, table->ptable);	
		}		
		code <<= 1;
	}	
	for(uint8_t i = HUFF_PREFIX_CODE_BITS; i < HUFF_MAX_CODE_BITS; i++) {
		for(uint8_t j = htable.code_count[j]; j ; j--) {
			add_table_code(code++, htable.symboles[index++], i, table->ptable);
		}		
		code <<= 1;
	}

	return 0;
}

void free_huffman_table(struct huffman_table *table, struct jpeg_context *ctx) {
	/* TODO free huffman tree's*/
	
	free(*ctx->huffman_table)

}

/*  Backing memory for  stream, need to be alloced at least 16 alligned. 
	To ensure that decoding on end of stream do not go outside alloced memory
*/
uint8_t decode_symbole(uint16_t **stream, struct huffman_table *htable) {
	
	const uint16_t pre_code = **stream;
		
	struct prefic_code *node = htable->ptable[pre_code >> HUFF_BTREE_CODE_BITS];		
	for(uint8_t len = 9; node->table; len++) {
		node = node->table[pre_code & 1 << len];
	}

	*stream = &stream[node->clength]
	return node->symbole;
}

