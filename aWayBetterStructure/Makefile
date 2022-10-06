FLAGS = -lglut -lGL -lGLU
utilsPath = ./utils/
collectionsPath = ./collections/


output: main.o collections.o usefullcallbacks.o
	gcc main.o collections.o usefullcallbacks.o -o output.exe $(FLAGS)

main.o: main.c
	gcc -c main.c

usefullcallbacks.o:$(utilsPath)usefullcallbacks.c
	gcc -c $(utilsPath)usefullcallbacks.c

collections.o:$(collectionsPath)collections.c
	gcc -c ./collections/collections.c


clean:
	rm *.o *.exe 

