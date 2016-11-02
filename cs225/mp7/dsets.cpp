/* Your code here! */
#include "dsets.h"

void DisjointSets::addelements(int num)
{
	for(int i =0; i<num;i++)
	vec.push_back(-1);
}

int DisjointSets::find(int elem)
{
	if(vec[elem]<0)
		return elem;
	else return vec[elem] = find(vec[elem]);
}

void DisjointSets::setunion(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	int newSize = vec[rootA] + vec[rootB];

	if(vec[rootA] <= vec[rootB])
	{
		vec[rootB]= rootA;
		vec[rootA]= newSize;
	}
	else
	{
		vec[rootA]= rootB;
		vec[rootB]= newSize;
	}
}
void DisjointSets::remove()
{
	vec.clear();
}


