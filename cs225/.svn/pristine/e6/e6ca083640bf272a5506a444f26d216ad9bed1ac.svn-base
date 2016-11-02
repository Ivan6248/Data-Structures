/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
    /**
     * @todo Implement this function!
     */
    MosaicCanvas *mosaic = new MosaicCanvas(theSource.getRows(), theSource.getColumns());

    std::vector<Point<3>> tiles;
    map<Point<3>,TileImage> tileMap;

    for(size_t i =0; i<theTiles.size();i++)
    {
    	RGBAPixel avg = theTiles[i].getAverageColor();
    	Point<3> x(avg.red, avg.green, avg.blue);
    	tileMap[x]=theTiles[i];
    	tiles.push_back(x);
    }
    
    KDTree<3> tree(tiles);

    for(int i =0;i<theSource.getRows();i++)
    {
    	for(int j=0;j<theSource.getColumns();j++)
    	{
    		RGBAPixel temp = theSource.getRegionColor(i,j);
    		Point<3> regionAvg(temp.red, temp.green, temp.blue);
    		Point<3> curBest = tree.findNearestNeighbor(regionAvg);
    		
    		TileImage image = tileMap[curBest];
    		mosaic->setTile(i,j,image);
    	}
    }

    return mosaic;
}

