OUT = meincrack
CXX = g++
SDL = -lSDL2
GL	= -L/usr/lib64/ -lGLEW -lGLU -lGL

OBJECTS = main.o Geometry.o Scene.o Triangle.o

all:	$(OUT)
$(OUT):	$(OBJECTS)
	$(CXX) -o $@ $^ ${SDL} ${GL} -Wall


clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
