#include <stdio.h>

#include "jpeg_context.h"
#include "decode_sos.h"



static void decode_block() {
	
	int coef = 0;
	uint8_t code = 0;
	do {
	//uint8_t value = get_vlc(ctx, &code);
		coef += (code >> 4) + 1;
		fprintf(stdout, "  %hhx  ", code);
	}while(coef < 63);
	fprintf(stdout, "\n");
}



void decode_sos(struct jpeg_context *ctx) {
	

	for(int y_mcu = 0; y_mcu < ctx->mcu_hight; y_mcu++) {
		for(int x_mcu = 0; x_mcu < ctx->mcu_width; x_mcu++) {
			for(int i = 0; i < ctx->ncomp; i++) {
				for(int sy = 0; sy < ctx->comp[i].ssy ; sy++) {
					for(int sx = 0; sx < ctx->comp[i].ssx; sx++) {
						decode_block();
					}
				}
			}
		}

	}


}

