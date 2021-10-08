#ifndef OPTIONS_H
#define OPTIONS_H


struct options {

	int print_huffman_tables;
	int print_quantization_tables;

};


void init_options(struct options *options);
int parse_args(int argc, char **argv);


#endif
