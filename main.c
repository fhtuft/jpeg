
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jfif.h"


int main(int argc, char *argv[])  {
    
    if(argc < 2) {
        fprintf(stderr, "wrong number of args\n");
        exit(EXIT_FAILURE);
    }
    
    FILE *f = fopen(argv[1], "rb");
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    uint8_t * buf = (int8_t*)malloc(size);
    fseek(f, 0, SEEK_SET);
    size = fread(buf, 1, size, f);
    fclose(f);

    print_appo_marker(stdout, buf + 6);
    free(buf);



}
