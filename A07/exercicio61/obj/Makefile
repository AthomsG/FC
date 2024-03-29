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
FCMATRIX := ../../exercicio43/src
EQSOLVER := ../../exercicio44/src
INTERPOLATOR := ../../exercicio45/src
FUNC1D := ../../exercicio49/src
DERIVATOR := ../../exercicio50/src
INTEGRATOR := ../../exercicio51/src
FCRAND := ../../exercicio53/src

#--- VPATH contains the search path for the src files !
VPATH = ../../exercicio41/src ../../exercicio43/src ../../exercicio44/src ../../exercicio45/src ../../exercicio49/src ../../exercicio50/src ../../exercicio51/src ../../exercicio53/src ../src:../serie_problemas

#--- Now find & list all cpp files on directories
SOURCES := $(wildcard ../../exercicio41/src/*.cpp ../../exercicio43/src/*.cpp ../../exercicio44/src/*.cpp ../../exercicio45/src/*.cpp ../../exercicio49/src/*.cpp ../../exercicio50/src/*.cpp ../../exercicio51/src/*.cpp ../../exercicio53/src/*.cpp ../src/*.cpp ../serie_problemas/*.cpp)

#--- But object files should not have the full path of
#--- the SOURCES when we replace the .cpp by .o !
OBJECTS := $(notdir $(SOURCES:.cpp=.o))


#####################################################

all: ../bin/hello
	../bin/hello #run

../bin/hello: $(OBJECTS)
	@echo $(OBJECTS)
	$(CC) -o $@ $^ $(ROOT_FLAGS) -I $(VEC) -I $(FCMATRIX) -I $(EQSOLVER) -I $(INTERPOLATOR) -I $(FUNC1D) -I $(DERIVATOR) -I $(INTEGRATOR) -I $(FCRAND) -I $(INCLUDE)

#--- Now every .cpp file can easily be found from VPATH !
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^ $(ROOT_FLAGS) -I $(VEC) -I $(FCMATRIX) -I $(EQSOLVER) -I $(INTERPOLATOR) -I $(FUNC1D) -I $(DERIVATOR) -I $(INTEGRATOR) -I $(FCRAND) -I $(INCLUDE)

clean:
	rm *.o *.eps ../bin/hello
