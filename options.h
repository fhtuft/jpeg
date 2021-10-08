#ifndef OPTIONS_H
#define OPTIONS_H

#include <limits.h>
#include <stdbool.h>

struct print_options {
	bool huffman_tables;
	bool quantization_tables;
};

struct options {
	struct print_options print;
	char input_file_path[PATH_MAX + 1];
};


void init_options(struct options *options);
int parse_args(int argc, char **argv, struct options *options);


#endif
