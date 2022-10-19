# make       -> compile the shared library "libfoo.so"
# make clean -> remove the library file and all object files (.o)
# make all   -> clean and compile
CC = gcc
SONAME  = output
SRC     = ./Common/Node.c \
          ./Lists/LinkedList.c \
          ./Lists/Queue.c \
		  ./Trees/BinarySearchTree.c \
          ./utils/BasicShapeDrawer/BasicShapeDrawer.c \
		  ./utils/Collisor/Collisor.c \
		  ./utils/GameObject/GameObject.c \
		  ./utils/MyPrimitives/Cat.c \
		  ./utils/MyPrimitives/Ball.c \
		  ./utils/Transform/Transform.c \
		  ./utils/VectorOperations/VectorOperations.c \
		  	main.c
# compilation options
CFLAGS  = -Wall -g -lglut -lGL -lGLU -lm

LDFLAGS = -shared -Wl,-soname,$(SONAME)

# how to compile individual object files
OBJS    = $(SRC:.c=.o)
.c.o:
	$(CC) -c $< -o $@

.PHONY: all clean

# library compilation
$(SONAME): $(OBJS) $(SRC)
	$(CC) $(OBJS) -o $(SONAME) $(CFLAGS)

# cleaning rule
clean:
	rm -f $(OBJS) $(SONAME) *~

# additional rule
all: clean lib