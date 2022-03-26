SOURCES = $(shell find ./ -type f -name '*.cpp')

FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
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
	rm -Rf .cache/
	mkdir build/
	mkdir .cache/
video:
	gource -1280x720 --title "TrocChain" --hide progress --max-user-speed 500 --seconds-per-day 0.25 -e 0.005 --bloom-intensity 0.05 --hide filenames -o - | ffmpeg -y -r 60 -f image2pipe -vcodec ppm -i - -vcodec libx264 -crf 19 -threads 0 -bf 0 gource.mp4

clean_users:
	rm -Rf blockchain/identity
	mkdir blockchain/identity