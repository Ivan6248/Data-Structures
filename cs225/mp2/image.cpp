#include "image.h"
#include <iostream>

void Image::flipleft()
{
	int width = this->width();
	int height = this->height();	
	RGBAPixel pixel = *(*this)(0,0);
	for (int x=0;x<width/2;x++){
		for(int y=0;y<height;y++){ 	
			pixel = *(*this)(x,y);
			(*(*this)(x,y))= (*(*this)((width-1-x),y));
			(*(*this)((width-1-x),y))=pixel;
	}
	}
}

void Image::adjustbrightness(int r, int g, int b)
{
int width = this->width();
int height = this->height();

for (int x=0;x<width;x++){
	for (int y=0; y<height;y++){

	RGBAPixel *pixel = (*this)(x,y);

	if(pixel->red+r<0){
	pixel->red=0;
	}
	else if (pixel->red+r>255){
	pixel->red=255;
	}
	else pixel->red = pixel->red + r;

	
	if(pixel->green+g<0){
	pixel->green=0;
	}
	else if(pixel->green+g>255){
	pixel->green=255;
	}
	else pixel->green = pixel->green + g;

	
	if(pixel->blue+b<0){
	pixel->blue=0;
	}
	else if(pixel->blue+b>255){
	pixel->blue=255;
	}
	else pixel->blue = pixel->blue + b;
	}	
}
}

void Image::invertcolors()
{
	int width = this->width();
	int height = this->height();
	
	for (int x=0; x<width; x++){
		for (int y=0;y<height; y++){
		RGBAPixel *pixel = (*this)(x,y);	
		pixel->red = 255-pixel->red;
		pixel->green = 255-pixel->green;
		pixel->blue = 255-pixel->blue;
	
		}
	}

}