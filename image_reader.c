#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;

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
	//convert them to an elevation point
	// red = 50
	// blue = 1, etc, something like that
	//return an int, the elevation point
	if (pixel.g == 0){
		if (25 <= pixel.r && pixel.r <= 50){
			if (140 < pixel.b  && pixel.b< 170){
				return 0;
			}
			if (180 < pixel.b && pixel.b< 205){
				return 9; // should be 8.5
			}
		}
		if (55 < pixel.r && pixel.r < 60){
			if (220 < pixel.b && pixel.b< 250){
				return 17;
			}
			if (250 < pixel.b && pixel.b< 255){
				return 43; //should be 42.5
			}
		}
		if (60 < pixel.r && pixel.r< 65){
			if (250 < pixel.b && pixel.b< 255){
				return 26; //should be 25.5
			}
		}
	}
	else if (55 < pixel.g && pixel.g< 80){
		if (35 < pixel.r && pixel.r< 45){
			if (250 < pixel.b && pixel.b< 255){
				return 51;
			}
		}
	}
	else if (110 < pixel.g && pixel.g< 122){
		if (pixel.r == 0){
			if (250 < pixel.b && pixel.b< 255){
				return 60; //should be 59.5
			}
		}
	}
	else if (150 < pixel.g && pixel.g< 120){
		if (pixel.r == 0){
			if (250 < pixel.b && pixel.b< 255){
				return 68;
			}
		}
	}
	else if (185 < pixel.g && pixel.g< 197){
		if (pixel.r == 0){
			if (250 < pixel.b && pixel.b< 255){
				return 77; //should be 76.5
			}
		}
	}
	else if (225 < pixel.g && pixel.g< 235){
		if (pixel.r == 0){
			if (250 < pixel.b && pixel.b< 255){
				return 85;
			}
		}
	}
	else if (pixel.g == 255){
		if (pixel.r == 0){
			if (250 < pixel.b && pixel.b< 255){
				return 94; //should be 93.5
			}
			if (200 < pixel.b && pixel.b< 235){
				return 102;
			}
			if (170 < pixel.b && pixel.b< 200){
				return 111; //should be 110.5
			}
			if (145 < pixel.b && pixel.b< 165){
				return 119;
			}
		}
		if (pixel.r < 70){
			if (120 < pixel.b && pixel.b< 140){
				return 128; //should be 127.5
			}
		}
	}
	else if (251 <= pixel.g && pixel.g <= 254  &&  157 <= pixel.r && pixel.r<=168  &&  93 <= pixel.b && pixel.b<= 107){
		return 136;
	}
	else if (186<= pixel.r && pixel.r <=194  &&  251<=pixel.g && pixel.g<=254  &&  72<=pixel.b && pixel.b <=85){
		return 145; //should be 144.5
	}
	else if (218<= pixel.r && pixel.r <=225  &&  251<=pixel.g && pixel.g<=255  &&  60<=pixel.b && pixel.b<=67){
		return 153;
	}
	else if (250<= pixel.r && pixel.r<=255  &&  249<=pixel.g && pixel.g<=253  &&  56<=pixel.b && pixel.b <=59){
		return 162; //should be 161.5
	}
	else if (242<= pixel.r && pixel.r<=255  &&  212<=pixel.g && pixel.g<=230  &&  47<=pixel.b && pixel.b <=54){
		return 170;
	}
	else if (241<= pixel.r && pixel.r<=255  &&  180<=pixel.g && pixel.g<=194  &&  42<=pixel.b && pixel.b <=70){
		return 179; //should be 178.5
	}
	else if (250<= pixel.r && pixel.r<=255  &&  150<=pixel.g && pixel.g<=166  &&  38<=pixel.b && pixel.b<=43){
		return 187;
	}
	else if (237<= pixel.r && pixel.r<=255  &&  124<=pixel.g && pixel.g<=138  &&  30<=pixel.b && pixel.b <=40){
		return 196; //should be 195.5
	}
	else if (240<= pixel.r && pixel.r<=255  &&  91<=pixel.g && pixel.g<=100  &&  29<=pixel.b && pixel.b<=35){
		return 204;
	}
	else if (241<= pixel.r && pixel.r<=255  &&  60<=pixel.g && pixel.g<=70  &&  25<=pixel.b && pixel.b<=32){
		return 213; //should be 212.5
	}
	else if (250<= pixel.r && pixel.r<=255  &&  30<=pixel.g && pixel.g<=37  &&  25<=pixel.b && pixel.b<=34){
		return 221;
	}
	else if (225<= pixel.r && pixel.r<=250  &&  10<=pixel.g && pixel.g<=20  &&  27<=pixel.b && pixel.b<=29){
		return 230; //should be 229.5
	}
	else if (200<= pixel.r && pixel.r<=225  &&  8<=pixel.g && pixel.g<=11  &&  25<=pixel.b && pixel.b<=27){
		return 238;
	}
	else if (180<= pixel.r && pixel.r<=200  &&  5<=pixel.g && pixel.g<=5  &&  15<=pixel.b && pixel.b<=25){
		return 247; //should be 246.5
	}
	else if (pixel.r < 5 && pixel.g < 5 && pixel.b < 5){
		return 0;
	}
	else if (250 <= pixel.r && 250 <= pixel.g && 250 <= pixel.b){
		return 255;
	}
	else{
		count++;
		return 100;
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
