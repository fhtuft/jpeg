#include <stdio.h>
#include <math.h>

#include "idct.h"

double dtc_lookup[8][8]  __attribute__ ((alligned(32))) =	
   { 0.353553f, 0.353553f, 0.353553f, 0.353553f, 0.353553f, 0.353553f, 0.353553f, 0.353553f}, 
   { 0.500000f, 0.415735f, 0.191342f, -0.097545f, -0.353553f, -0.490393f, -0.461940f, -0.277785f}, 
   { 0.500000f, 0.277785f, -0.191342f, -0.490393f, -0.353553f, 0.097545f, 0.461940f, 0.415735f}, 
   { 0.500000f, 0.097545f, -0.461940f, -0.277785f, 0.353553f, 0.415735f, -0.191342f, -0.490393f}, 
   { 0.500000f, -0.097545f, -0.461940f, 0.277785f, 0.353553f, -0.415735f, -0.191342f, 0.490393f}, 
   { 0.500000f, -0.277785f, -0.191342f, 0.490393f, -0.353553f, -0.097545f, 0.461940f, -0.415735f}, 
   { 0.500000f, -0.415735f, 0.191342f, 0.097545f, -0.353553f, 0.490393f, -0.461940f, 0.277785f}, 
   { 0.500000f, -0.490393f, 0.461940f, -0.415735f, 0.353553f, -0.277785f, 0.191342f, -0.097545f}
};

void idct(uint8_t *mcu) {
	double out[8*8];
	
	for(int i = 0; i < 64; i+=8) {
		for(int j = 0; j < 8; j++) {
			double tmp = 0.0;
			for(int k = 0; k < 8; k++) {
				tmp += mcu[i + k] * coefficents[k*8 + j];
			}
			out[i + j] = tmp;
		}
	}

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
		double tmp = 0.0;
		for(int k = 0; k < 64; k += 8) {
			tmp += coefficients[k + i] * out[k + j]; 
		} 
		mcu[i*8 + j] = floor(tmp + 0.5);
		}
	}

}


/* 
 	naive implementation of	idct from itu-t81 A.3.3 
*/
void idct_naive(uint8_t *in, uint8_t *out)  {
	for(int i = 0; i < 64; i++) {
		float s = 0f;
		for(int u = 0; u < 8; u++) {
			for(int v = 0; v < 8; v++) {
				s += ((!u && !v) : 0.5f : 1.0f)in[u*8 + v]*cos()
			}
		}
	}
}
