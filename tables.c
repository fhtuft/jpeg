
#include <stdint.h>


/*
* Lookup table for idct generated by dct_table_generator.py
*/
float dtc_lookup[8][8]  __attribute__ ((alligned(32))) = {	
   { 0.353553f, 0.353553f, 0.353553f, 0.353553f, 0.353553f, 0.353553f, 0.353553f, 0.353553f}, 
   { 0.500000f, 0.415735f, 0.191342f, -0.097545f, -0.353553f, -0.490393f, -0.461940f, -0.277785f}, 
   { 0.500000f, 0.277785f, -0.191342f, -0.490393f, -0.353553f, 0.097545f, 0.461940f, 0.415735f}, 
   { 0.500000f, 0.097545f, -0.461940f, -0.277785f, 0.353553f, 0.415735f, -0.191342f, -0.490393f}, 
   { 0.500000f, -0.097545f, -0.461940f, 0.277785f, 0.353553f, -0.415735f, -0.191342f, 0.490393f}, 
   { 0.500000f, -0.277785f, -0.191342f, 0.490393f, -0.353553f, -0.097545f, 0.461940f, -0.415735f}, 
   { 0.500000f, -0.415735f, 0.191342f, 0.097545f, -0.353553f, 0.490393f, -0.461940f, 0.277785f}, 
   { 0.500000f, -0.490393f, 0.461940f, -0.415735f, 0.353553f, -0.277785f, 0.191342f, -0.097545f}
};


uint8_t zig_zag[64] = {  0,  1,  8, 16,  9,  2,  3, 10, 
					    17, 24, 32, 25, 18, 11,  4,  5,
						12, 19, 26, 33, 40, 48, 41, 34, 
						27, 20, 13,  6,  7, 14, 21, 28, 
						35, 42, 49, 56, 57, 50, 43, 36, 
						29, 22, 15, 23, 30, 37, 44, 51, 
						58, 59, 52, 45, 38, 31, 39, 46, 
						53, 60, 61, 54, 47, 55, 62, 63
						 };
