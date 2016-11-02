/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
#include <iostream>
using namespace std;
template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if(first[curDim]<second[curDim])
        return true;
    else if(first[curDim]>second[curDim])
        return false;
    return first<second;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    int currentDistance=0;
    int potentialDistance=0;
    for(int i=0;i<Dim;i++)
    {
        currentDistance += (currentBest[i]-target[i])*(currentBest[i]-target[i]);
    }
    for(int i=0;i<Dim;i++)
    {
        potentialDistance += (potential[i]-target[i])*(potential[i]-target[i]);
    }
    if(potentialDistance<currentDistance)
        return true;
    else if(potentialDistance>currentDistance)
        return false;
    return potential<currentBest;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     points = newPoints;
     if(newPoints.size()!=0)
        build(points,0,newPoints.size()-1,0);
}

template<int Dim>
void KDTree<Dim>::build(vector< Point<Dim> > & newPoints, int left, int right, int curDim)
{
    if(left==right)
        return; //base case
    int dimension = curDim%Dim; //set dimension
    int mid = (left+right)/2; //find the median 
    quickSelect(newPoints,left,right,mid,dimension);
    if(left<mid)
        build(newPoints,left,mid-1,curDim+1);
    if(right>mid)
        build(newPoints,mid+1,right,curDim+1);
}

template<int Dim>
void KDTree<Dim>:: quickSelect(vector< Point<Dim> > & newPoints,int left, int right,int pivot,int dimension)
{
    if(left==right)
        return;
    int j = partition(newPoints,left, right, pivot, dimension);
    if(pivot==j)
        return;
    else if(pivot<j)
    {
        quickSelect(newPoints,left,j-1,pivot,dimension);
    }
    else
        quickSelect(newPoints,j+1,right,pivot,dimension);
}

template<int Dim>
int KDTree<Dim>:: partition(vector< Point<Dim> > & newPoints,int low, int high,int pivot,int dimension)
{
    //swap the values of the pivot and the high value
    Point<Dim> pivotValue = newPoints[pivot];
    Point<Dim> temp = newPoints[high];
    newPoints[high] = newPoints[pivot];
    newPoints[pivot] = temp;
    int lo = low;

    for(int i =low; i<high;i++)
    {
        if(smallerDimVal(newPoints[i],pivotValue,dimension))
        {
            temp = newPoints[i];
            newPoints[i] = newPoints[lo];
            newPoints[lo] = temp;
            lo++;
        }
    }
    temp = newPoints[lo];
    newPoints[lo]=newPoints[high];
    newPoints[high]=temp;
    return lo;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    return findNN(query, 0, points.size()-1, 0);
}

template<int Dim>
Point<Dim> KDTree<Dim>::findNN(const Point<Dim> & query, int left, int right,  int dimension) const
{
    int mid = (left+right)/2;
    int curDim = dimension%Dim;

    Point<Dim> curBest;
    Point<Dim> potBest;

    int bestDistance =0;
    int curDistance =0;

    bool accessed = false; //check if we went into that subtree

    if(right<=left)
        return points[mid];
    else
        if(smallerDimVal(query,points[mid],curDim)){
            curBest = findNN(query, left, mid-1, dimension+1);
            accessed = true; 
        }
        else
            curBest = findNN(query, mid+1, right, dimension+1);

    if(shouldReplace(query, curBest, points[mid]))
    {
        curBest = points[mid];
    }

    for(int i =0;i<Dim;i++)
    {
        bestDistance += (curBest[i]-query[i])*(curBest[i]-query[i]);
    }

    curDistance = (query[curDim]-points[mid][curDim]) * (query[curDim] - points[mid][curDim]);

    if(curDistance<=bestDistance && accessed == false)
        potBest = findNN(query, left, mid-1, dimension+1);
    if(curDistance<=bestDistance && accessed == true)
        potBest = findNN(query, mid+1, right, dimension+1);

    if(shouldReplace(query, curBest, potBest))
            curBest = potBest;
    return curBest;
}


