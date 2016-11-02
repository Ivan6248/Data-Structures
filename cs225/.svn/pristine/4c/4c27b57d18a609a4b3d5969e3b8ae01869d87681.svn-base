#include "scene.h"
#include <iostream>
using namespace std;

Scene::Scene (int x)
{
	max = x;
	imageArr = new Image*[max];
	xcoords = new int[max];
	ycoords = new int[max];
	for (int i=0;i<max;i++){
		imageArr[i]=NULL;
	}
	
}

Scene::~Scene(){

	clear();
}


void Scene::clear(){
	delete [] xcoords;
	xcoords=NULL;
	delete [] ycoords;
	ycoords=NULL;
	for(int i=0;i<max;i++){
		if(imageArr[i]!=NULL){
			delete imageArr[i];
			imageArr[i]=NULL;
		}
	}
	delete [] imageArr;
	imageArr=NULL;
}

Scene::Scene(const Scene & source)
{
	copy(source);
}

void Scene::copy(const Scene & source)
{
	max=source.max;
	imageArr= new Image *[max];
	xcoords = new int [max];
	ycoords = new int [max];
	for(int i=0;i<max;i++){
		if(source.imageArr[i]!=NULL){
			imageArr[i]=new Image();
			imageArr[i]->resize(source.imageArr[i]->width(),source.imageArr[i]->height());
			for(size_t x=0;x<imageArr[i]->width();x++){
				for(size_t y=0;y<imageArr[i]->height();y++){
					(*imageArr[i])(x,y)->red=(*source.imageArr[i])(x,y)->red;
					(*imageArr[i])(x,y)->green=(*source.imageArr[i])(x,y)->green;
					(*imageArr[i])(x,y)->blue=(*source.imageArr[i])(x,y)->blue;
		
		}
	}
	}
		else{
			imageArr[i]=NULL;
		}
	for (int i=0;i<max;i++){
		xcoords[i]=source.xcoords[i];
		ycoords[i]=source.ycoords[i];
		}
 
	}
}

const Scene & Scene::operator= (const Scene & source)
{
	if(this==&source){
		return *this;
	}
	else{
		clear();
		copy(source);
		return *this;
	}

}

void Scene::changemaxlayers(int newmax)
{
	Image** newArr= new Image*[newmax];

	if(max>newmax){
		for (int i=newmax;i<max-1;i++){	//if there is a non-null pointer outside the range
			if(imageArr[i]!=NULL){
				cout<<"invalid newmax"<<endl;
				return;
			}
		}

		for (int i=0;i<newmax-1;i++){
			if(imageArr[i]!=NULL){
				newArr[i]=imageArr[i];
			}
			else
				newArr[i]=NULL;
			
		}

	}
	
	if(newmax>max){
		for (int i=0;i<newmax-1;i++){
			if(imageArr[i]!=NULL){
				newArr[i]=imageArr[i];
			}
			else
				newArr[i]=NULL;


		}
}
	clear();
}

void Scene::addpicture(const char* Filename, int index, int x, int y)
{
	if(index>max-1 || index<0){
		cout<<"index out of bounds<<"<<endl;
		return;
	}
	Image* newImage = new Image;
	newImage ->readFromFile(Filename);
	imageArr[index]=newImage;

	xcoords[index]=x;
	ycoords[index]=y;
	
}

void Scene::changelayer(int index, int newindex)
{
	if(newindex>max-1 || newindex<0 || index>max-1 || index<0){
		cout<<"invalid index"<<endl;
	}

	if(newindex==index){
		return;
	}
	if(imageArr[newindex]!=NULL){
		delete imageArr[newindex];
		

	}
		imageArr[newindex]=imageArr[index];
		xcoords[newindex]=xcoords[index];
		ycoords[newindex]=ycoords[index];
		imageArr[index]=NULL;
		xcoords[index]=0;
		ycoords[index]=0;


}

void Scene::translate(int index, int xcoord, int ycoord)
{
	if( index<0 || index>(max-1) || (imageArr[index]==NULL)){
		cout<<"invalid index"<<endl;
		return;
	}
	xcoords[index]=xcoord;
	ycoords[index]=ycoord;

}

void Scene::deletepicture(int index)
{
	if((index>max-1)||(index<0)||(imageArr[index]==NULL)){
		cout<<"invalid index"<<endl;
		return;
	}
	
	delete imageArr[index];
	imageArr[index]=NULL;

}

Image * Scene::getpicture(int index) const
{
	if ((index>max-1) || (index<0) || (imageArr[index]==NULL)){
		cout<<"invalid index"<<endl;
		return NULL;
	}
	return imageArr[index];
}

Image Scene::drawscene() const
{
	unsigned int width=0;
	unsigned int height=0;
	Image newImage;
	for(int i=0;i<max;i++){
		if(imageArr[i]!=NULL){
			if((xcoords[i]+imageArr[i]->width())>width){
				width=xcoords[i]+imageArr[i]->width();
			}
			if((ycoords[i]+imageArr[i]->height())>height){
				height=ycoords[i]+imageArr[i]->height();
			}
		}
	}
	newImage.resize(width,height);
	for(int i=0;i<max;i++){
		if(imageArr[i]!=NULL){
			for(size_t x=0;x<imageArr[i]->width();x++){
				for(size_t y=0;y<imageArr[i]->height();y++){
					newImage(x+xcoords[i],y+ycoords[i])->red=(*imageArr[i])(x,y)->red;
					newImage(x+xcoords[i],y+ycoords[i])->green=(*imageArr[i])(x,y)->green;
					newImage(x+xcoords[i],y+ycoords[i])->blue=(*imageArr[i])(x,y)->blue;
		}
	}
	}

}


return newImage;

}


