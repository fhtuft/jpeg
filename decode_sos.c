#include <stdio.h>

#include "jpeg_context.h"
#include "decode_sos.h"



static void decode_block() {
	
}



void decode_sos(struct jpeg_context *ctx) {
	

	for(int y_muc = 0; y_muc < ctx->muc_hight; y_muc++) {
		for(int x_muc = 0; x_muc < ctx->muc_width; x_muc++) {
			for(int i = 0; i < ctx->ncomp; i++) {
				for(int sy = 0; sy < ctx->ssy ; sy++) {
					for(int sx = 0; sx < ctx->ssx; sx++) {
						decode_block();
					}
				}
			}
		}

	}


}

