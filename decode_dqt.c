#include <stdio.h>
#include <string.h>

#include "jpeg_context.h"
#include "decode_dqt.h"

#define QSTRIDE 8


void print_dqt(uint8_t const*const qtable) {
	for(int i = 0; i< QSTRIDE; i++) {
		for(int j = 0; j < QSTRIDE; j++) 
			fprintf(stdout, " %hhu  ",*(qtable  + i*QSTRIDE + j));
		fprintf(stdout, "\n");
	}
}

void decode_dqt(struct jpeg_context * const ctx) {

	fprintf(stdout, "decode_dqt\n");	
	const uint8_t *jpeg = ctx->jpeg;
	struct jpeg_qtb *qtb = (struct jpeg_qtb *)(jpeg + ctx->offset);
		
	print_dqt(qtb->qValues);
	const uint8_t index = qtb->PqTq & 0x0F;
	memcpy(ctx->qtables + QTABLE_ELEMENT_COUNT*index, qtb->qValues, QTABLE_ELEMENT_COUNT);
	
	fprintf(stdout, "dqt : index : %hhu  \n", index);
	print_dqt(ctx->qtables + QTABLE_ELEMENT_COUNT*index);	
}

