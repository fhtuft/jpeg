#include <stdio.h>

#include <unistd.h>
#include <getopt.h>

#include "options.h"

#ifndef OPTIONS_PRINT_HUFF
#define OPTIONS_PRINT_HUFF 0
#endif
#ifndef OPTIONS_PRINT_QUANT
#define OPTIONS_PRINT_QUANT 0
#endif


static void print_info(void) {
	fprintf(stdout, "Test program for decoding jpeg\n");
}

static void print_help(void) {
	print_info();
	fprintf(stdout, "usage stuff [options]\n");
} 

void init_options(struct options *options) {
	options->print_huffman_tables = OPTIONS_PRINT_HUFF;
	options->print_quantization_tables = OPTIONS_PRINT_QUANT;
}

int parse_args(int argc, char **argv) {
		
	static struct option options[] = {
		{"print", required_argument, 0, 'p'},
		{"help" , no_argument,       0, 'h'},
		{0}
	};

	for(int c = -1;;) {
		int options_index = 0;		
			
		c = getopt_long(argc, argv, "", options, &options_index);
		if(c == -1) {
			break;
		}

		switch(c) {
			case 'p':
				break;
			case 'h':
				print_help();
				break;
			case '?':
				break;
			default:
				fprintf(stderr, "ops\n");
		}
	}

}
