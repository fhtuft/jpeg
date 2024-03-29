#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <gtk/gtk.h>

#include "jpeg.h"
#include "options.h"
#include "jpeg_context.h"
#include "decode_jpeg.h"



int main(int argc, char *argv[]) {
    	

	struct options options;
	init_options(&options);
	
	parse_args(argc, argv, &options);

	fprintf(stderr, "file : %s\n", options.input_file_path);	
	FILE *fp;
	fp = fopen(options.input_file_path, "r");
	if(!fp) {
		fprintf(stderr, "error opning file\n");
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0, SEEK_END);
	const size_t fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	fprintf(stdout, "fsize :%lu\n", fsize);

	uint8_t *jpeg = (uint8_t*)malloc(fsize);
	fread(jpeg, fsize, 1, fp); //TODO 
	
	struct jpeg_context *ctx = (struct jpeg_context *)malloc(sizeof(struct jpeg_context));
	memset(ctx, 0, sizeof(*ctx));
	ctx->jpeg = jpeg;	
	ctx->fsize = fsize;
	ctx->offset = 4;
	decode_jpeg(ctx);	

		
	/*	
	GtkWidget *window;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_show(window);

	gtk_main();
*/

	free(jpeg);

}






