#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include "options.h"


#ifndef OPTIONS_PRINT_HUFF
#define OPTIONS_PRINT_HUFF 0
#endif
#ifndef OPTIONS_PRINT_QUANT
#define OPTIONS_PRINT_QUANT 0
#endif

#define MAX_LEN_OPTARGS 2000 /* */


static char tmp_optarg[MAX_LEN_OPTARGS];


static void print_info(void) {
	fprintf(stdout, "Test program for decoding jpeg\n");
}

static void print_help(void) {
	print_info();
	fprintf(stdout, "usage stuff [options]\n");
} 

void init_options(struct options *options) {
	memset(options, 0, sizeof(*options));
	options->print.huffman_tables = OPTIONS_PRINT_HUFF;
	options->print.quantization_tables = OPTIONS_PRINT_QUANT;
}

static int parse_print_optarg(char *optarg, struct print_options *options) {
	memset(tmp_optarg, 0, sizeof(tmp_optarg));	
	for(char *token =  NULL ;;)  {
		token = strtok		
	}

}


int parse_args(int argc, char **argv, struct options *options) {
		
	static struct option args_options[] = {
		{"file",  required_argument, 0, 'f'},
		{"print", required_argument, 0, 'p'},
		{"help" , no_argument,       0, 'h'},
		{0}
	};

	for(int c = -1;;) {
		int options_index = 0;		
			
		c = getopt_long(argc, argv, "", args_options, &options_index);
		if(c == -1) {
			break;
		}

		switch(c) {
			case 'f':
				strncpy(options->input_file_path, optarg, sizeof(options->input_file_path));
				break;
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
	return 0;
}
