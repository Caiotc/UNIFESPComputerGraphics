FLAGS = -lglut -lGL -lGLU -lm
CommonPath = ./Common/
ListsPath = ./Lists/
TreesPath = ./Trees/


allconsole: main.o  LinkedList.o Node.o Queue.o BinarySearchTree.o
	gcc main.o  LinkedList.o Node.o Queue.o  BinarySearchTree.o -o output.exe

 main.o: main.c
	gcc -c main.c

buildOpengl: openglTest.o  LinkedList.o Node.o Queue.o BinarySearchTree.o
	gcc openglTest.o  $(ListsPath)LinkedList.o $(CommonPath)Node.o  $(ListsPath)Queue.o $(TreesPath)BinarySearchTree.o -o openglTest.exe $(FLAGS)

openglTest.o: openglTest.c
	gcc -c openglTest.c

LinkedList.o: $(ListsPath)LinkedList.c
	gcc -c $(ListsPath)LinkedList.c -o $(ListsPath)LinkedList.o 

Node.o: $(CommonPath)Node.c
	gcc -c $(CommonPath)Node.c -o $(CommonPath)Node.o 

Queue.o: $(ListsPath)Queue.c
	gcc -c $(ListsPath)Queue.c -o $(ListsPath)Queue.o 

 BinarySearchTree.o: $(TreesPath)BinarySearchTree.c
	gcc -c $(TreesPath)BinarySearchTree.c -o $(TreesPath)BinarySearchTree.o 

