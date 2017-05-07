#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
ReadImage -> input is pnm file, reads pixel data, creates Image object


*/

typedef struct{
//3 bytes
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Pixel;

typedef struct{
//16 bytes
	Pixel *pixel;
	int height, width;
} Image;

Image * ReadImage(char *filename)
{
	/**** REMEMBER TO FREE THE 2 MALLOCS WHEN YOU CALL THIS FUNCTION !!!! ********/
	Image *image;
	image = malloc(sizeof(Image)); //16 bytes
	
	FILE *f_in = fopen(filename, "r");
	char magicNum[128];
	int width, height, maxval;
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);

	image->height = height;
	image->width = width;
	//printf("height: %d, width: %d\n", height, width);
	image->pixel = malloc(height * width * sizeof(Pixel));

	if (f_in == NULL){
		printf("unable to open file %s\n", filename);
	}
	fread(image->pixel, sizeof(Pixel), height*width, f_in);
	/*
	for (int i = 0; i<height*width; i++){
		printf("red value is: %d, green value is: %d, blue value is: %d\n", image->pixel[i].r, image->pixel[i].g, image->pixel[i].b);
	}*/
	fclose(f_in);
	return image;
}


int MapToElevation(Pixel pixel){
	// get pixel's  R, G, and B values
	//convert them to an elevation point
	// red = 50
	// blue = 1, etc, something like that
	//return an int, the elevation point
}


void WriteData(Image *img, char *filename)
{
	// open the writing file
	FILE *f_out = fopen(filename, "w");

	//for every pixel in the Image (there are width*height of them)
	for (int i = 0; i < img->width*img->height; i++){
		// get the pixel's elevation data point
		int elev = MapToElevation(img->pixel[i]);
		//write it to the txt file
		fprintf(f_out, "%d", elev);
	}
	fclose(f_out);
}


int main(int argc, char *argv[])
{
	Image * first;
	first = ReadImage(argv[1]);

	free(first->pixel);
	free(first);	
	return 0;
}
