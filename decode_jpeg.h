#ifndef _DECODE_JPEG
#define _DECDOE_JPEG

#include <stdint.h>

struct jpeg_jfif{
	uint16_t length;
	uint8_t identifier[5]; /*Should read JFIF\0 */
	uint8_t version;	
	uint8_t units;
	/*As quoted from the web site about the units variable:
	 *0 => no units, X and Y specify pixel aspect ratio
	 *1 => X and Y are dots per inch
	 *2 => X and Y are dots per cm  */
	uint16_t Xdensity;
	uint16_t Ydensity;
	uint8_t Xthumbnail;
	uint8_t Ythumbnail;
} __attribute__((packed));


struct jpeg_context;
int decode_jpeg(struct jpeg_context *);

#endif
