#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include <arpa/inet.h>

#include "jpeg_context.h"
#include "decode_jpeg.h"
#include "decode_sof.h"
#include "decode_dht.h"
#include "decode_dqt.h"
#include "decode_sos.h"

/* JFIF markers, all start with 0xFF */
#define SOI    0xD8
#define SOF0   0xC0
#define DHT    0xC4
#define DQT    0xDB
#define DRI    0xDD
#define SOS    0xDA
#define EOI    0xD9

#define SIZEOF_JFIF_MARKER 2
#define JFIF_MAGIC "JFIF"

#define SIZEOF_SEGMENT(SEGMENT) (ntohs(*((uint16_t*)(SEGMENT))))


bool is_valid_jfif(const uintptr_t *ptr) {
	return true; 
}

int decode_jpeg(struct jpeg_context *const ctx) {

	fprintf(stdout, "decod_jpeg\n");	
	const uint8_t *jpeg = ctx->jpeg;
	const size_t fsize = ctx->fsize;
		
	struct jpeg_jfif *header = (struct jpeg_jfif *)(jpeg + ctx->offset) ;
	if(strncmp((const char *)header->identifier, JFIF_MAGIC, 5)) {
		fprintf(stdout, "not a jifi file \n");
		return -1; 
	}
		

	ctx->version = ntohs(header->version);
	ctx->Xdensity = ntohs(header->Xdensity);
	ctx->Ydensity = ntohs(header->Ydensity);	

	ctx->offset += SIZEOF_SEGMENT((jpeg + ctx->offset));
	fprintf(stdout, "is a jfifi file offset : %lu fsize  : %lu \n", ctx->offset, fsize);
	
	while(ctx->offset < fsize) {
		fprintf(stdout, "while offset : %lu lese then fsize : %lu\n", ctx->offset, fsize);
		if(*(uint8_t*)(jpeg + ctx->offset) != 0xff) {
			fprintf(stderr, "Non marker segment found where marker should be\n");
			return -1;
		}
		ctx->offset += 2;
		switch(((uint8_t *)(jpeg + ctx->offset))[-1]) {
			case SOF0: /* Start of Frame*/
				decode_sof(ctx);
				ctx->offset += SIZEOF_SEGMENT((jpeg + ctx->offset));
				fprintf(stdout, "after sof ctx->offset %lu\n", ctx->offset);
				break;
			case DHT: /* Huffman table*/
				decode_dht(ctx);
				ctx->offset += SIZEOF_SEGMENT((jpeg + ctx->offset));
				break;
			case DQT: /* Quantization table*/
				decode_dqt(ctx);
				ctx->offset += SIZEOF_SEGMENT((jpeg + ctx->offset));
				fprintf(stdout, "after dqt ctx->offset %lu\n", ctx->offset);
				break;
#if 0
			case DRI:
				decode_DRI(ctx);
				ctx->offset += SIZEOF_SEGMENT((jpeg + ctx->offset));
				break;
#endif
			case SOS: /* Start of scan */
				decode_sos(ctx);
				ctx->offset += SIZEOF_SEGMENT((jpeg + ctx->offset));
				fprintf(stdout, "after sos ctx->offset %lu\n", ctx->offset);
				break;
#if 0
			case EOI: /* End of Image */
				decode_EOI(ctx);
				ctx->offset += SIZEOF_SEGMENT((jpeg + ctx->offset));
				break;
#endif
			case 0x0:
				printf("0x0 marker \n");
				ctx->offset += 2;  // 
				break;
			default:
				fprintf(stdout, "unknow marker %X\n", ((uint8_t *)(jpeg + ctx->offset))[-1]);
				ctx->offset += SIZEOF_SEGMENT((jpeg + ctx->offset));

		}
	}	

	return 0;
}

