#ifndef JIFI_H
#define JIFI_H

#include <stdint.h>


/* Start Of Frame marker, non-differential, Huffman coding  */
#define JIFI_SOF0  0xFFC0
#define JIFI_SOF1  0xFFC1
#define JIFI_SOF2  0xFFC2
#define JIFI_SOF3  0xFFC3
/* Start Of Frame marker, non-differential, Huffman coding  */
#define JIFI_SOF5  0xFFC5
#define JIFI_SOF6  0xFFC6
#define JIFI_SOF7  0xFFC7
/* Start Of Frame marker, non-differential, aritmetic coding  */
#define JIFI_JPG   0xFFC8
#define JIFI_SOF9  0xFFC9
#define JIFI_SOF10 0xFFCA
#define JIFI_SOF11 0xFFCB
/* Start Of Frame marker, differential, aritmetic coding  */
#define JIFI_SOF13  0xFFCD
#define JIFI_SOF14  0xFFCE
#define JIFI_SOF15  0xFFCF
/* Huffman table specification */
#define JIFI_DHT 0xFFC4
/* Arithmetic coding conditioning specification */
#define JIFI_DAC 0xFFCC
/* Restart interval terminination */
#define JIFI_RST0 0xFFD0
#define JIFI_RST1 0xFFD1
#define JIFI_RST2 0xFFD2
#define JIFI_RST3 0xFFD3
#define JIFI_RST4 0xFFD4
#define JIFI_RST5 0xFFD5
#define JIFI_RST6 0xFFD6
#define JIFI_RST7 0xFFD7

/* Other */
#define JIFI_SIO 0xFFD8
#define JFII_EOI 0XFFD9
#define JIFI_SOS 0XFFDA
#define JFII_DQT 0XFFDB
#define JIFI_DNL 0XFFDC
#define JIFI_DRI 0XFFDD

/* JIFI */
#define JIFI_APP0 0XFFE0
    

struct jfif_appo_marker {
    uint8_t id[5];
    uint8_t major_version;
    uint8_t minor_version;
    uint16_t Xdensity;
    uint16_t Ydensity;
    uint8_t Xthumbnail;
    uint8_t Ythumbnail;
    uint8_t thumbnail_data[0];
};

static inline void print_appo_marker(FILE *stream, struct jfif_appo_marker *marker) {
    fprintf(stream, "identifier : %s\n", marker->id);
}

#endif
