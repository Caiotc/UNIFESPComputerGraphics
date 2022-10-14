FLAGS = -lglut -lGL -lGLU -lm
CommonPath = ./Common/
ListsPath = ./Lists/
TreesPath = ./Trees/
UtilsPath = ./utils/
BasicShapeDrawerPath = $(UtilsPath)BasicShapeDrawer/


all: main.o  LinkedList.o Node.o Queue.o BinarySearchTree.o BasicShapeDrawer.o Cat.o
	gcc main.o  $(ListsPath)LinkedList.o $(CommonPath)Node.o $(ListsPath)Queue.o  $(TreesPath)BinarySearchTree.o $(BasicShapeDrawerPath)BasicShapeDrawer.o $(UtilsPath)Cat.o -o output.exe $(FLAGS)

LinkedList.o: $(ListsPath)LinkedList.c
	gcc -c $(ListsPath)LinkedList.c -o $(ListsPath)LinkedList.o 

Node.o: $(CommonPath)Node.c
	gcc -c $(CommonPath)Node.c -o $(CommonPath)Node.o 

Queue.o: $(ListsPath)Queue.c
	gcc -c $(ListsPath)Queue.c -o $(ListsPath)Queue.o 

BinarySearchTree.o: $(TreesPath)BinarySearchTree.c
	gcc -c $(TreesPath)BinarySearchTree.c -o $(TreesPath)BinarySearchTree.o 

BasicShapeDrawer.o: $(BasicShapeDrawerPath)BasicShapeDrawer.o
	gcc -c $(BasicShapeDrawerPath)BasicShapeDrawer.c -o $(BasicShapeDrawerPath)BasicShapeDrawer.o
Cat.o: $(UtilsPath)Cat.c 
	gcc -c $(UtilsPath)Cat.c -o  $(UtilsPath)Cat.o
	
main.o: main.c
	gcc -c main.c