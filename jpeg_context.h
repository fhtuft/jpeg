#ifndef JPEG_CONTEXT
#define JPEG_CONTEXT

#include "jpeg.h"

#define HTABLE_CODE_COUNT  16
#define HTABLE_MAX_SYMBOLS 		 256
#define HTABLE_COUNT               4

struct htable {
	uint8_t code_counts[HTABLE_CODE_COUNT];
	uint8_t symbols[HTABLE_MAX_SYMBOLS];
}__attribute__((packed));

struct nj_cmp {
    int cid;
    int ssx, ssy;
    int width, height;
    int stride;
    int qtsel;
    int actabsel, dctabsel;
    int dcpred;
    unsigned char *pixels;
};

struct jpeg_context {
	uint8_t *jpeg;
	size_t offset;
	size_t fsize;

	uint16_t version;
	uint16_t Xdensity;
	uint16_t Ydensity;

	/* from SOF header */
	uint8_t sample_precision;
	uint16_t heigth;
	uint16_t width;
	uint16_t mcu_hight;
	uint16_t mcu_width;
	uint8_t ncomp;
	struct nj_cmp comp[3];

	/* from qtc header */
	uint8_t qtables[QTABLE_COUNT * QTABLE_ELEMENT_COUNT];

	/* Huffman */
	uint8_t	acdc_table; /* hight nibble,  ac table dc table selector */
	struct htable htable[HTABLE_COUNT];
	struct huffman_table *huffman_table;	
};

void init_jpeg_context(struct jpeg_context **);
void free_jpeg_context(struct jpeg_context *);

#endif
