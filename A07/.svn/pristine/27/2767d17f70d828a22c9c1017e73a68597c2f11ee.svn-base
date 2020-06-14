# Simple Makefile with variables (compiler+flags+include)
# and explicit paths on targets + dependencies
#
#
# Author: R. Coelho

CC := g++
CCFLAGS := -std=c++14
ROOT_FLAGS := $(shell echo $$(root-config --cflags --libs) )
INCLUDE := ../src

#--- VPATH contains the search path for the src files !
VPATH = ../src:../main

#--- Now find & list all cpp files on directories
SOURCES := $(wildcard ../src/*.cpp ../main/*.cpp)

#--- But object files should not have the full path of
#--- the SOURCES when we replace the .cpp by .o !
OBJECTS := $(notdir $(SOURCES:.cpp=.o))


#####################################################

all: ../bin/hello
	../bin/hello #run

../bin/hello: $(OBJECTS)
	@echo $(OBJECTS)
	$(CC) -o $@ $^ $(ROOT_FLAGS) -I $(INCLUDE)

#--- Now every .cpp file can easily be found from VPATH !
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^ $(ROOT_FLAGS) -I $(INCLUDE)

clean:
	rm *.o ../bin/hello

cleang:
	rm ../*.png
