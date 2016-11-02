EXENAME = testimage 
OBJS = image.o png.o rgbapixel.o testimage.o
EXENAME2= testscene
OBJS2= image.o png.o rgbapixel.o testscene.o scene.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi

all : $(EXENAME) $(EXENAME2)

testscene : $(OBJS2)
	$(LD) $(OBJS2) $(LDFLAGS) -o testscene

testimage : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o testimage

scene.o : scene.cpp scene.h image.h rgbapixel.h png.h
	$(CXX) $(CXXFLAGS) scene.cpp
	
testimage.o : testimage.cpp image.h png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) testimage.cpp

testscene.o : testscene.cpp scene.h image.h rgbapixel.h png.h
	$(CXX) $(CXXFLAGS) testscene.cpp

image.o : image.cpp image.h png.o rgbapixel.o
	$(CXX) $(CXXFLAGS) image.cpp

png.o : png.cpp png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) rgbapixel.cpp

clean :
	-rm -f *.o $(EXENAME) $(EXENAME2)
