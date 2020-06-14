# Simple Makefile with variables (compiler+flags+include)
# and explicit paths on targets + dependencies
#
#
# Author: R. Coelho

CC := g++
CCFLAGS := -std=c++14
ROOT_FLAGS := $(shell echo $$(root-config --cflags --libs) )
INCLUDE := ../src
VEC := ../../exercicio41/src

#--- VPATH contains the search path for the src files !
VPATH = ../../exercicio41/src ../src:../serie_problemas

#--- Now find & list all cpp files on directories
SOURCES := $(wildcard ../../exercicio41/src/*.cpp ../src/*.cpp ../serie_problemas/*.cpp)

#--- But object files should not have the full path of
#--- the SOURCES when we replace the .cpp by .o !
OBJECTS := $(notdir $(SOURCES:.cpp=.o))


#####################################################

all: ../bin/hello
	../bin/hello #run

../bin/hello: $(OBJECTS)
	@echo $(OBJECTS)
	$(CC) -o $@ $^ $(ROOT_FLAGS) -I $(VEC) -I $(INCLUDE)

#--- Now every .cpp file can easily be found from VPATH !
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^ $(ROOT_FLAGS) -I $(VEC) -I $(INCLUDE)

clean:
	rm *.o ../bin/hello
