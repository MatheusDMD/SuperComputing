CXX=g++
CXXFLAGS=-std=c++11 -Wall
LXXFLAGS=-lm
OBJCMD=$(CXX) $(CXXFLAGS) -c $<
OBJS=main.o
EXEC=main

all: $(EXEC)

main: $(OBJS)
	$(CXX) -o $@ $^ $(LXXFLAGS)

main.o: main.cxx ordset.cxx ordset.hxx
	$(OBJCMD)

clean:
	rm -f $(OBJS)

destroy: clean
	rm -f $(EXEC)
