all:
	bin/Signal_and_DFT.exe #run

bin/Signal_and_DFT.exe: $(OBJECTS)
	@echo $(OBJECTS)
	$(CC) -o $@ $^ $(ROOT_FLAGS) -I $(INCLUDE)

#--- Now every .cpp file can easily be found from VPATH !
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^ $(ROOT_FLAGS) -I $(INCLUDE)

clean:
	rm *.o bin/Signal_and_DFT.exe

