#ifndef DECODE_QTB
#define DECODE_QTB

#define QTABLE_ELEMENT_COUNT 64  // TODO refactor this into common file ??

struct jpeg_qtb{
	uint16_t length;
	uint8_t PqTq; /*Precision higher four bits, index lower four bits*/
	uint8_t qValues[QTABLE_ELEMENT_COUNT]; /*Quantization table, stored in zigzag format*/
} __attribute__((packed));

struct jpeg_context;
void decode_dqt(struct jpeg_context *);

#endif
