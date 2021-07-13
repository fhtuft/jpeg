#include <stdio.h>

#include <arpa/inet.h>

#include "jpeg_context.h"
#include "decode_sof.h"



void decode_sof(struct jpeg_context *ctx) {
	
	fprintf(stdout, "decode_sof\n");
	const uint8_t *jpeg = ctx->jpeg;
	
	struct jpeg_sof *sof = (struct jpeg_sof *)(jpeg + ctx->offset);
	
	ctx->sample_precision = sof->P;
	ctx->heigth = ntohs(sof->heigth);
	ctx->width  = ntohs(sof->width);
	ctx->ncomp = sof->components;

	
}

