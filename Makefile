all:
	gcc image_reader.c
run:
	./a.out original.pnm my_output
	pnmtopng < my_output > my_output.png
	open my_output.png
