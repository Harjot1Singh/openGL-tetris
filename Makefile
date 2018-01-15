# the name of the executable created
PROGRAM_NAME = cs324_coursework

# Modify this variable as appropriate as you add .cpp files to
# your project
SRCS = main.cpp Game.cpp Grid.cpp Board.cpp Tetromino.cpp Block.cpp utils.cpp

# you shouldn't need to modify below here, but you can
# if you know what you're doing
CXXFLAGS= -O3 -std=c++11 -I/modules/cs324/glew-1.11.0/include
LDFLAGS= $(CXXFLAGS) $(LIBDIRS) -std=c++11 -L/usr/X11R6/lib -L/modules/cs324/glew-1.11.0/lib -Wl,-rpath=/modules/cs324/glew-1.11.0/lib
LDLIBS = -lglut -lGL -lGLU -lGLEW -lm -lX11
OBJS=$(SRCS:%.cpp=%.o)

default: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	-@rm $(OBJS) $(PROGRAM_NAME)

.PHONY: default clean
