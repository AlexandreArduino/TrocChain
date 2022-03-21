SOURCES = $(shell find ./ -type f -name '*.cpp')

FLAGS =
OBJECTS = $(SOURCES:.cpp=.o)
BUILD_OBJECTS = $(addprefix build/,$(OBJECTS))

COMPILER = g++
LINKER = ld

EXECUTABLE = main

%.o: %.cpp
	mkdir -p build/$(@D)
	$(COMPILER) $(FLAGS) -c $< -o build/$@

all: clean $(OBJECTS)
	$(COMPILER) -o $(EXECUTABLE) $(BUILD_OBJECTS) $(FLAGS)
clean:
	rm -f $(EXECUTABLE)
	rm -Rf build/
	mkdir build/