#ifndef DECODE_SOF
#define DECODE_SOF

struct jpeg_sof {
	uint16_t length;
	uint8_t P; /*Sample precision in bits*/
	uint16_t heigth;
	uint16_t width;
	uint8_t components;
	/*The following variables contain information about
	 *the different components of the image.  There is 1 component
	 *for a grayscale image and 3 components for a color image.
	 *ID variable: The ID of the component
	 *HVSample: Horizontal sampling rate (high nibble) and vertical
	 *sampling rate (low nibble)
	 *QTable: Quantization table number*/
	/*NOTE: YCbCr color used*/
	uint8_t c1ID;
	uint8_t c1HVSample;
	uint8_t c1QTable;
	uint8_t c2ID;
	uint8_t c2HVSample;
	uint8_t c2QTable;
	uint8_t c3ID;
	uint8_t c3HVSample;
	uint8_t c3QTable;

}__attribute__((packed));


struct jpeg_context;
void decode_sof(struct jpeg_context *);

#endif
