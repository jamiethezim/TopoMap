#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;

int ctr = 0;

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
	fscanf(f_in, "%s\n%d %d\n%d", magicNum, &width, &height, &maxval);

	image->height = height;
	image->width = width;
	printf("height: %d, width: %d\n", height, width);
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

int MapEpsilon(unsigned char r, unsigned char g, unsigned char b){

}
int MapToElevation(Pixel pixel){

	// get pixel's  R, G, and B values
	// convert them to an elevation point
	// red = 50
	// blue = 1, etc, something like that
	// return an int, the elevation point


	if ((0 <= pixel.r) && (pixel.r <= 5)) {
		// return 0;
		if ((0 <= pixel.g) && (pixel.g <= 20)) {
			if ((0 <= pixel.b) && (pixel.b <= 180)) {
				return 0;
			}
			else if ((181 <= pixel.b) && (pixel.b <= 215)) {
				return 9;
			}
			else if ((216 <= pixel.b) && (pixel.b <= 225)) {
				return 17;
			}
			else if ((226 <= pixel.b) && (pixel.b <= 255)) {
				return 26;
			}
			else {
				ctr++;
				printf("MISSED PIXELS: %d", ctr);

			}
		}
		else {	// 20 <= pixel.g <= 255
			if ((0 <= pixel.g) && (pixel.g <= 35)) {
				return 34;
			}
			else if ((36 <= pixel.g) && (pixel.g <= 70)) {
				return 43;
			}
			else if ((71 <= pixel.g) && (pixel.g <= 100)) {
				return 51;
			}
			else if ((101 <= pixel.g) && (pixel.g <= 145)) {
				return 60;
			}
			else if ((146 <= pixel.g) && (pixel.g <= 170)) {
				return 68;
			}
			else if ((171 <= pixel.g) && (pixel.g <= 255)) {	// fix me
				return 77;
			}
			else {
				ctr ++;
				printf("MISSED PIXELS: %d", ctr);

			}
		}
	}

	if ((6 <= pixel.r) && (pixel.r <= 10)) {
		// return 94;
		if ((0 <= pixel.g) && (pixel.g <= 200)) {
			return 85;
		}
		else {
			return 94;
		}
	}

	else if ((10 <= pixel.r) && (pixel.r <= 65)) {
		if ((0 <= pixel.b) && (pixel.b <= 200)) {	// fix me
			return 111;
		}
		else if ((201 <= pixel.b) && (pixel.b <= 255)) {
			return 102;
		}
		else {
			ctr++;
			printf("MISSED PIXELS: %d", ctr);

		}
	}

	else if ((66 <= pixel.r) && (pixel.r <= 200)) {
		if ((0 <= pixel.g) && (pixel.g <= 200)) {	// fix me
			return 247;
		}

		else {
			if ((0 <= pixel.b) && (pixel.b <= 70)) {
				return 145;
			}
			else if ((71 <= pixel.b) && (pixel.b <= 100)) {
				return 136;
			}
			else if ((101 <= pixel.b) && (pixel.b <= 145)) {
				return 128;
			}
			else if ((146 <= pixel.b) && (pixel.b <= 255)) {
				return 119;
			}
			else {
				ctr++;
				printf("MISSED PIXELS: %d", ctr);
			}
		}

	}

	else if ((201 <= pixel.r) && (pixel.r <= 245)) {
		if ((0 <= pixel.g) && (pixel.g <= 10)) {
			return 238;
		}
		else if ((10 <= pixel.g) && (pixel.g <= 255)) {		// fix me
			return 153;
		}
		else {
			ctr++;
			printf("MISSED PIXELS: %d", ctr);

		}
	}

	else if ((246 <= pixel.r) && (pixel.r <= 255)) {
		if ((0 <= pixel.g) && (pixel.g <= 30)) {
			return 221;
		}
		else if ((31 <= pixel.g) && (pixel.g <= 70)) {
			return 213;
		}
		else if ((71 <= pixel.g) && (pixel.g <= 100)) {
			return 204;
		}
		else if ((101 <= pixel.g) && (pixel.g <= 145)) {
			return 196;
		}
		else if ((146 <= pixel.g) && (pixel.g <= 165)) {
			return 187;
		}
		else if ((166 <= pixel.g) && (pixel.g <= 200)) {
			return 179;
		}
		else if ((201 <= pixel.g) && (pixel.g <= 230)) {
			return 170;
		}
		else if ((231 <= pixel.g) && (pixel.g <= 255)) {
			return 162;
		}
		else {
			ctr++;
			printf("MISSED PIXELS: %d", ctr);

		}
	}
	else if (pixel.r < 5 && pixel.g < 5 && pixel.b < 5){
		return 0;
	}
	else if (250 <= pixel.r && 250 <= pixel.g && 250 <= pixel.b){
		return 255;
	}
	else {
		ctr ++;
		printf("MISSED PIXELS: %d", ctr);

	}

}



void WriteData(Image *img, char *filename)
{
	// open the writing file
	FILE *f_out = fopen(filename, "w");

	fprintf(f_out, "%s\n%d %d\n%d\n", "P6", img->width, img->height, 255);
	//for every pixel in the Image (there are width*height of them)
	for (int i = 0; i < img->width*img->height; i++){
		// get the pixel's elevation data point
		unsigned char elev = (unsigned char) MapToElevation(img->pixel[i]);
		//write it to the txt file
		fprintf(f_out, "%c%c%c", elev, elev, elev);
	}
	fclose(f_out);
	fprintf(stdout, "failures: %d, the error rate is %f\n", count, count/(img->width*img->height));
}


int main(int argc, char *argv[])
{
	Image * first;
	first = ReadImage(argv[1]);
	WriteData(first, argv[2]);
	free(first->pixel);
	free(first);	
	return 0;

}
