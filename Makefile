OUT = meincrack
CXX = g++
SDL = -lSDL2
GL	= -L/usr/lib64/ -lGLEW -lGLU -lGL

OBJECTS = main.o Geometry.o

all:	$(OUT)
$(OUT):	$(OBJECTS)
	$(CXX) -o $@ $^ ${SDL} ${GL} -Wall
