FLAGS = -lglut -lGL -lGLU -lm
utilsPath = ./utils/
collectionsPath = ./collections/
structsPath = ./structs/


all:main.c $(utilsPath)usefullcallbacks.c $(collectionsPath)collections.c $(structsPath)types_and_consts.c
	gcc main.c $(collectionsPath)collections.c $(utilsPath)usefullcallbacks.c $(structsPath)types_and_consts.c -o output.exe $(FLAGS)

build: main.o collections.o usefullcallbacks.o types_and_consts.o
	gcc main.o $(collectionsPath)collections.o $(utilsPath)usefullcallbacks.o $(structsPath)types_and_consts.o -o output.exe $(FLAGS)


main.o: main.c
	gcc -c main.c 

usefullcallbacks.o:$(utilsPath)usefullcallbacks.c
	gcc -c $(utilsPath)usefullcallbacks.c -o $(utilsPath)usefullcallbacks.o

collections.o:$(collectionsPath)collections.c
	gcc -c $(collectionsPath)collections.c -o $(collectionsPath)collections.o

types_and_consts.o: $(structsPath)types_and_consts.c
	gcc -c  $(structsPath)types_and_consts.c -o $(structsPath)types_and_consts.o




clean:
	rm *.o *.exe 

