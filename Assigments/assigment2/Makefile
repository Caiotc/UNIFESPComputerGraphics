FLAGS = -lglut -lGL -lGLU -lm
CommonPath = ./Common/
ListsPath = ./Lists/
TreesPath = ./Trees/
UtilsPath = ./utils/
BasicShapeDrawerPath = $(UtilsPath)BasicShapeDrawer/
PrimitivesPath = $(UtilsPath)MyPrimitives/
GameObjectPath = $(UtilsPath)GameObject/
CollisorPath = $(UtilsPath)Collisor/


all: main.o  LinkedList.o Node.o Queue.o BinarySearchTree.o BasicShapeDrawer.o Cat.o GameObject.o Collisor.o
	gcc main.o  $(ListsPath)LinkedList.o $(CommonPath)Node.o $(ListsPath)Queue.o  $(TreesPath)BinarySearchTree.o $(BasicShapeDrawerPath)BasicShapeDrawer.o $(PrimitivesPath)Cat.o $(GameObjectPath)GameObject.o $(CollisorPath)Collisor.o -o output.exe $(FLAGS)

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
Cat.o: $(PrimitivesPath)Cat.c 
	gcc -c $(PrimitivesPath)Cat.c -o  $(PrimitivesPath)Cat.o
GameObject.o: $(GameObjectPath)GameObject.c
	gcc -c $(GameObjectPath)GameObject.c -o $(GameObjectPath)GameObject.o
Collisor.o:$(CollisorPath)Collisor.c
	gcc -c $(CollisorPath)Collisor.c -o $(CollisorPath)Collisor.o
main.o: main.c
	gcc -c main.c