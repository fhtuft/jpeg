#ifndef RLE_H
#define RLE_H
/*
	Run Length Encoding 
*/

struct rle {
	uint8_t code;
	uint8_t value;
};

#define GET_RUNLENGTH(RLE) ((RLE)->code >> 4)
#define GET_SIZE(RLE) ((RLE)->code & 0x0FU)
#define GET_VALUE(RLE) ((RLE->value))


void get_rle(struct jpeg_context *, struct rlc *);

#endif
