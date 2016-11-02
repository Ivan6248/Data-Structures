/**
 * @file quadtree.cpp
 * Quadtree class implementation.
 * @date Spring 2008
 */
 #include "quadtree.h"
 #include <iostream>
 #include <math.h>
 using namespace std;


Quadtree::QuadtreeNode::QuadtreeNode() //QuadtreeNode constructor
{
	nwChild = NULL;
    neChild = NULL;
    swChild = NULL;
    seChild = NULL;

}

Quadtree::QuadtreeNode::QuadtreeNode(const RGBAPixel &source)
{
	nwChild = NULL;
    neChild = NULL;
    swChild = NULL;
    seChild = NULL;
    element=source;
}

Quadtree::Quadtree() //Empty constructor
{
	root=NULL;
	resolution=0;
}

Quadtree::Quadtree(PNG const&source, int resolution) //Constructor
{
	root=NULL;
	buildTree(source, resolution);

}

Quadtree::Quadtree(Quadtree const &other) //Copy Constructor
{
	copy(other);
}

void Quadtree::copy(const Quadtree &other) //Copy function
{
	if(other.root!=NULL)
	{
		copy(other.root, root);
		resolution=other.resolution;
	}
	else{
		resolution =0;
		root=NULL;
	}
}

void Quadtree::copy(Quadtree::QuadtreeNode * orig, QuadtreeNode * & newCopy) //Copy helper function
{
	newCopy = new QuadtreeNode(orig->element);
	if(orig->nwChild!=NULL)
		copy(orig->nwChild,newCopy->nwChild);
	if(orig->neChild!=NULL)
		copy(orig->neChild,newCopy->neChild);
	if(orig->swChild!=NULL)
		copy(orig->swChild,newCopy->swChild);
	if(orig->seChild!=NULL)
		copy(orig->seChild,newCopy->seChild);
}

Quadtree::~Quadtree() //destructor
{
	clear(root);
}

void Quadtree::clear(QuadtreeNode * &subRoot)//destructor helper
{ 
	if(subRoot!=NULL)
	{
		clear(subRoot->nwChild);
		clear(subRoot->neChild);
		clear(subRoot->swChild);
		clear(subRoot->seChild);
		delete subRoot;
		subRoot=NULL;
	}
	
}

Quadtree Quadtree::operator =(const Quadtree &other) //assignment operator
{
	if(this==&other)
		return *this;
	else
	{
		clear(root);
		copy(other);
		return *this;
	}
}

void Quadtree::buildTree(PNG const&source, int res) 
{
	clear(root);
	resolution = res;
	root = new QuadtreeNode();
	root->nodeRes=resolution;
	build(root, source, resolution);
}

void Quadtree::build(QuadtreeNode* &subRoot, PNG const&source, int resolution) //buildTree helper function
{
	if(resolution == 1)
	{
		subRoot->element = (*source(subRoot->x,subRoot->y));
		return;
	}

	//makes each child of the split up quadtree
	//set the value of the node's x and y values to make it easier for later functions
	//store the resolution of each node 
	subRoot->nwChild = new QuadtreeNode(); 
	subRoot->nwChild->x= subRoot->x; 
	subRoot->nwChild->y= subRoot->y;
	subRoot->nwChild->nodeRes=resolution/2;

	subRoot->neChild = new QuadtreeNode();
	subRoot->neChild->x= subRoot->x+resolution/2;
	subRoot->neChild->y= subRoot->y;
	subRoot->neChild->nodeRes=resolution/2;

	subRoot->swChild = new QuadtreeNode();
	subRoot->swChild->x= subRoot->x;
	subRoot->swChild->y= subRoot->y+resolution/2;
	subRoot->swChild->nodeRes=resolution/2;

	subRoot->seChild = new QuadtreeNode();
	subRoot->seChild->x= subRoot->x+resolution/2;
	subRoot->seChild->y= subRoot->y+resolution/2;
	subRoot->seChild->nodeRes=resolution/2;

	build(subRoot->nwChild, source, resolution/2);
	build(subRoot->neChild, source, resolution/2);
	build(subRoot->swChild, source, resolution/2);
	build(subRoot->seChild, source, resolution/2);

	//store the average of the pixels into the pixel's element

	(subRoot->element).red=(((subRoot->nwChild->element).red) + ((subRoot->neChild->element).red) + ((subRoot->swChild->element).red) + ((subRoot->seChild->element).red))/4;
	(subRoot->element).green=(((subRoot->nwChild->element).green) + ((subRoot->neChild->element).green) + ((subRoot->swChild->element).green) + ((subRoot->seChild->element).green))/4;
	(subRoot->element).blue=(((subRoot->nwChild->element).blue) + ((subRoot->neChild->element).blue) + ((subRoot->swChild->element).blue) + ((subRoot->seChild->element).blue))/4;

	
}


RGBAPixel Quadtree::getPixel(int x, int y) const
{
	if(root==NULL)
	{
		return RGBAPixel();
	}

	if(x>resolution || y>resolution) //check to see if valid resolutions
	{
		return RGBAPixel();
	}
	return getPixel(x, y, root); //helper function call
}

RGBAPixel Quadtree::getPixel(int x, int y, QuadtreeNode * curr)const
{
	
	if(curr->nwChild != NULL) //checks if each node is a leaf
	{
		/*cout<<"test"<<endl;
		return RGBAPixel();
		*/
		/*cout<<"x:"<<curr->x<<endl;
		cout<<"y:"<<curr->y<<endl;
		*/
		//check to see which node is within the range of the resolution
		if(x>=curr->nwChild->x && x<(curr->nwChild->x+curr->nwChild->nodeRes) && y>=curr->nwChild->y && y<(curr->nwChild->y+curr->nwChild->nodeRes))
		{
			return getPixel(x, y, curr->nwChild);
		}
		if(x>=curr->neChild->x && x<(curr->neChild->x+curr->neChild->nodeRes) && y>=curr->neChild->y && y<(curr->neChild->y+curr->neChild->nodeRes))
		{
			return getPixel(x, y, curr->neChild);
		}
		if(x>=curr->swChild->x && x<(curr->swChild->x+curr->swChild->nodeRes) && y>=curr->swChild->y && y<(curr->swChild->y+curr->swChild->nodeRes))
		{
			return getPixel(x, y, curr->swChild);
		}
		if(x>=curr->seChild->x && x<(curr->seChild->x+curr->seChild->nodeRes) && y>=curr->seChild->y && y<(curr->seChild->y+curr->seChild->nodeRes))
		{
			return getPixel(x, y, curr->seChild);
		}
	}
		return curr->element;


}

PNG Quadtree::decompress() const
{
	if(root==NULL)
	return PNG();
		else{

			PNG image (resolution, resolution); //makes a new image and sets dimmensions
			for(int i=0;i<resolution;i++)
			{
				for(int k=0;k<resolution;k++)
				{
					*image(i,k)=getPixel(i,k);
				}
			}
			return image; //loads the image with each pixel 
		}
}

void Quadtree::clockwiseRotate()
{
	clockwiseRotater(root);
}

void Quadtree::clockwiseRotater(QuadtreeNode * subRoot)
{
	if(subRoot->nwChild==NULL || subRoot == NULL)
		return;

	//makes pointers to each new rotated chlid
	//change each x and y values of the children

	QuadtreeNode* temp = subRoot->nwChild;
	subRoot->nwChild = subRoot->swChild;
	subRoot->swChild = subRoot->seChild;
	subRoot->seChild = subRoot->neChild;
	subRoot->neChild = temp;
	temp = NULL;

    subRoot->nwChild->x = subRoot->x;
    subRoot->nwChild->y = subRoot->y;

    subRoot->neChild->x = subRoot->x + subRoot->nodeRes/2;
    subRoot->neChild->y = subRoot->y;
    
    subRoot->swChild->x = subRoot->x;
    subRoot->swChild->y = subRoot->y + subRoot->nodeRes/2;
    
    subRoot->seChild->x = subRoot->x + subRoot->nodeRes/2;
    subRoot->seChild->y = subRoot->y + subRoot->nodeRes/2;

	//recursive call
	clockwiseRotater(subRoot->nwChild);
	clockwiseRotater(subRoot->neChild);
	clockwiseRotater(subRoot->swChild);
	clockwiseRotater(subRoot->seChild);

}

void Quadtree::prune (int tolerance)
{
	pruneHelper(tolerance, root);
}

void Quadtree::pruneHelper(int tolerance, QuadtreeNode* subRoot)
{
	if(subRoot->nwChild==NULL)
		return;
	if(isPruneable(tolerance, subRoot, subRoot))
	{
		clear(subRoot->nwChild);
		clear(subRoot->neChild);
		clear(subRoot->swChild);
		clear(subRoot->seChild);
		
		return;
	}
	pruneHelper(tolerance, subRoot->nwChild);
	pruneHelper(tolerance, subRoot->neChild);
	pruneHelper(tolerance, subRoot->swChild);
	pruneHelper(tolerance, subRoot->seChild);
}

bool Quadtree::isPruneable(int tolerance, QuadtreeNode* subRoot, QuadtreeNode* child) const
{
	if(subRoot->nwChild == NULL) //we found a leaf
	{
		int difference = pow((subRoot->element.red - child->element.red), 2)
		+ pow((subRoot->element.green - child->element.green), 2)
		+ pow((subRoot->element.blue - child->element.blue), 2);

		if(difference<=tolerance)
			return true;
		else return false;
	}
	//if all 4 children are prunable, return true
	return 	(isPruneable(tolerance, subRoot->nwChild, child) && isPruneable(tolerance, subRoot->neChild, child)
				&& isPruneable(tolerance, subRoot->swChild, child) && isPruneable(tolerance, subRoot->seChild, child));
		
}


int Quadtree::pruneSize (int tolerance) const
{
	return pruneSizeFinder(tolerance, root);
}

int Quadtree::pruneSizeFinder(int tolerance, QuadtreeNode* subRoot)const
{
	if(subRoot==NULL)
		return 0;
	if(subRoot->nwChild==NULL)
		return 1;
	if(isPruneable(tolerance, subRoot, subRoot->element))
		return 1;

	return pruneSizeFinder(tolerance, subRoot->nwChild)+ pruneSizeFinder(tolerance, subRoot->neChild) + pruneSizeFinder(tolerance, subRoot->swChild) + pruneSizeFinder(tolerance, subRoot->seChild);

}

bool Quadtree::isPruneable(int tolerance, QuadtreeNode* subRoot, RGBAPixel temp)const
{
	if(subRoot == NULL)
		return false;
	if(subRoot->nwChild == NULL) //we found a leaf
	{
		int difference = pow((subRoot->element.red - temp.red), 2)
		+ pow((subRoot->element.green - temp.green), 2)
		+ pow((subRoot->element.blue - temp.blue), 2);

		if(difference<=tolerance)
			return true;
		else return false;
	}
	else{
	//if all 4 children are prunable, return true
	bool pruneable = isPruneable(tolerance, subRoot->nwChild, temp) && isPruneable(tolerance, subRoot->neChild, temp)
						&& isPruneable(tolerance, subRoot->swChild, temp) && isPruneable(tolerance, subRoot->seChild, temp);
		return pruneable;
	}
}

int Quadtree::idealPrune (int numLeaves) const
{
	if(root==NULL)
		return 0;
	int min = 0;
	int max = 195075; //will always prune at this tolerance
	int mid = (min+max)/2;
	return idealPruneHelper(min, max, mid, numLeaves);
}

int Quadtree::idealPruneHelper(int min, int max, int mid, int numLeaves)const
{
	if(min>=max)
		return min;
	int avg = (min+max)/2;
	int size = pruneSize(avg);
	if(numLeaves>=size)
		max=avg;
	else
		min=1+avg;
	return idealPruneHelper(min, max, avg, numLeaves);

}
















