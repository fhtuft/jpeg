#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jpeg.h"
#include "jpeg_context.h"


void inti_jpeg_context(struct jpeg_context **ctx) {
	*ctx = (struct jpeg_context *)malloc(sizeof(**ctx));
	memset(*ctx, 0, sizeof(**ctx));
}

void free_jpeg_context(struct jpeg_context *ctx) {
	free(ctx);
}
