#ifndef DECODE_H
#define DECODE_H

struct jpeg_contex;

void decodeSOI(struct jpeg_context *ctx);
void decodeSOF0(struct jpeg_context *ctx);
void decodeDHT(struct jpeg_context *ctx);
void decodeDQT(struct jpeg_context *ctx);
void decodeDRI(struct jpeg_context *ctx);
void decodeSOS(struct jpeg_context *ctx);
void decodeRST(struct jpeg_context *ctx);
void decodeAPP(struct jpeg_context *ctx);
void decodeCOM(struct jpeg_context *ctx);
void decodeEOI(struct jpeg_context *ctx);


#endif
