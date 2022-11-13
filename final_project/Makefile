# name of our executable
EXENAME = bbis
# name of the obj files, main included for running main.cpp
OBJS = main.o bbis.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp graph.h
	$(CXX) $(CXXFLAGS) main.cpp

bbis.o : graph.cpp graph.h
	$(CXX) $(CXXFLAGS) graph.cpp

catchmain.o : catchmain.cpp catch.hpp
	$(CXX) $(CXXFLAGS) catchmain.cpp

clean:
	-rm -f *.o $(EXENAME)

# write for unit test file later (we can "test" with main.cpp using this file)
