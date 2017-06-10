final_renders/ -> directory of mental-ray rendered images saved from Maya displacement mapping.

image_reader.c -> this tool reads in a PNM file of a colored elevation map and produces a PNM file of a height map version.

Makefile -> Usage: type "make", and then "make run". The output of this program is my_output.png

my_output -> PNM file is output of image_reader.c

my_output.png -> converted from my_output pnm

original.pnm -> PNM file is input to image_reader.c (command line argument 1)

original.png -> PNG version of original.pnm (available primarily for viewing)

color_points.xlsx -> Excel document describing which pixel scales get mapped to their new shade of black in heat map output.
