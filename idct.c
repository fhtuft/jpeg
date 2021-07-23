#include <stdio.h>
#include <math.h>

#include "idct.h"


//static float dcti_lookup[8][8] __attribute__ ((alligned(32))) = {
//{},
//{},
//{},
//{},
//{},
//{},
//{},
//{}
//};

/* 
 	naive implementation of	idct from itu-t81 A.3.3 
*/
void idct(uint8_t *in, uint8_t *out)  {
	for(int i = 0; i < 64; i++) {
		float s = 0f;
		for(int u = 0; u < 8; u++) {
			for(int v = 0; v < 8; v++) {
				s += ((!u && !v) : 0.5f : 1.0f)in[u*8 + v]*cos()
			}
		}
	}
}
