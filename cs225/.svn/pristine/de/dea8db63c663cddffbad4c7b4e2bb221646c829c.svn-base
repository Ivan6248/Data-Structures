/* Your code here! */
#ifndef MAZE_H
#define MAZE_H
#include<vector>
#include "png.h"
#include"dsets.h"

class SquareMaze
{
public:
	SquareMaze();
	void makeMaze(int width, int height);
	bool canTravel(int x, int y, int dir) const;
	void setWall(int x, int y, int dir, bool exists);
	vector<int> solveMaze();
	PNG* drawMaze() const;
	PNG* drawMazeWithSolution();

private:
	int mazeHeight;
	int mazeWidth;
	int size;
	bool isMaze;
	vector<bool> downWalls;
	vector<bool> rightWalls;
	DisjointSets sets;


};
#endif