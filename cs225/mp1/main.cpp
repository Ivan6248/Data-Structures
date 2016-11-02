/*
 * @file main.cpp
 * A simple C++ program that manipulates an image.
 */
#include <algorithm>
#include <iostream>

#include "rgbapixel.h"
#include "png.h"

using namespace std;
int main()
{
    // Open a new PNG image from the file sample.png.
    PNG input("in.png");
	int width = input.width();
	int height = input.height();
	PNG output(width,height);

	for (size_t x=0;x<output.width();x++){
		for(size_t y=0;y<output.height();y++){ 	//code here
	size_t outX =input.width()-1-x;
	size_t outY =input.height()-1-y;
	
	RGBAPixel *inputP = input(x,y);
	RGBAPixel *outputP = output(outX, outY);

		outputP->red=inputP->red;
		outputP->blue=inputP->blue;
		outputP->green=inputP->green;
		outputP->alpha=inputP->alpha;
}
}
 
  

    // Save the modified image to a file called output.png, overwriting the file
    // if it already exists.
     output.writeToFile("out.png");

    return 0;
}
