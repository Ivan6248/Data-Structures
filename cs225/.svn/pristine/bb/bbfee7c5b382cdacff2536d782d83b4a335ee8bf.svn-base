/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    /* Your code here! */
	vector<Vertex> verticies = graph.getVertices();

	for(size_t i = 0 ; i<verticies.size(); i++)
	{
		graph.setVertexLabel(verticies[i], "UNEXPLORED");
		vector<Vertex> connected = graph.getAdjacent(verticies[i]);
		for(size_t j = 0; j<connected.size(); j++)
			graph.setEdgeLabel(verticies[i],connected[j],"UNEXPLORED");
	}

    queue<Vertex> q;
    int minWeight = 99999;
    Vertex min1;
    Vertex min2;

    Vertex start = graph.getStartingVertex();
    q.push(start);

    while(!q.empty())
    {
	    Vertex temp = q.front();
	    q.pop(); //dequeue 
	    vector<Vertex> adjacent = graph.getAdjacent(temp); //load a vector with all the adjacent verticies
	    for(size_t i = 0; i<adjacent.size();i++) //go through each verticie
	    {
	    	if(graph.getVertexLabel(adjacent[i]) == "UNEXPLORED")
	    		q.push(adjacent[i]);
			
	    		if(graph.getEdgeWeight(adjacent[i],temp) < minWeight){
	    			minWeight = graph.getEdgeWeight(adjacent[i],temp); //check the weights
	    			min1 = adjacent[i];
	    			min2 = temp;
	    		}
	    		if(graph.getVertexLabel(adjacent[i]) == "UNEXPLORED"){
	    			graph.setEdgeLabel(adjacent[i],temp,"DISCOVERY");
	    			graph.setVertexLabel(adjacent[i], "VISITED");
	    		}
	    		else if(graph.getVertexLabel(adjacent[i]) == "VISITED" && graph.getEdgeLabel(adjacent[i],temp)!="DISCOVERY")
	    		{
	    			graph.setEdgeLabel(adjacent[i],temp,"CROSS");
	    		}
	    	
	    	graph.setVertexLabel(temp, "VISITED");

	    }
	}
	graph.setEdgeLabel(min1,min2,"MIN");
	return minWeight;
}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
    /* Your code here! */
    if(graph.getEdges().size()==0)
    	return 0;
    vector<Vertex> verticies = graph.getVertices();
    vector<Edge> edges = graph.getEdges();

	for(size_t i = 0 ; i<verticies.size(); i++)
	{
		graph.setVertexLabel(verticies[i], "UNEXPLORED");
		vector<Vertex> connected = graph.getAdjacent(verticies[i]);
		for(size_t j = 0; j<connected.size(); j++)
			graph.setEdgeLabel(verticies[i],connected[j],"UNEXPLORED");
	}

	queue<Vertex> q;
	q.push(start);
	graph.setVertexLabel(start,"VISITED");

	int count = 1;
	unordered_map<Vertex,Vertex> container;
	Vertex temp;

	bool atEnd = false;
	while(!q.empty() && !atEnd)
	{
		temp=q.front();
		q.pop();
		vector <Vertex> adjacent = graph.getAdjacent(temp);
		for(size_t i =0; i<adjacent.size();i++){
			if(adjacent[i]==end)
		    {
				atEnd = true;
			}
			if(graph.getVertexLabel(adjacent[i]) == "UNEXPLORED"){
		    	graph.setEdgeLabel(adjacent[i],temp,"DISCOVERY");
		    	graph.setVertexLabel(adjacent[i], "VISITED");
		    	q.push(adjacent[i]);
		    	container[adjacent[i]]=temp;
		    }
		    else if(graph.getVertexLabel(adjacent[i]) == "VISITED" && graph.getEdgeLabel(adjacent[i],temp)!="DISCOVERY")
		    {
		    	graph.setEdgeLabel(adjacent[i],temp,"CROSS");
		    }

		}
			
	}
		graph.setEdgeLabel(end,temp,"MINPATH");

	while(temp!=start)
	{
		Vertex next = container[temp];
		graph.setEdgeLabel(temp,next,"MINPATH");
		temp=next;
		count++;
	}
	return count;



}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort instead of creating a priority queue.
 */
void GraphTools::findMST(Graph& graph)
{
    /* Your code here! */
    
    DisjointSets sets;
    sets.addelements(graph.getVertices().size());

    vector<Edge> edges = graph.getEdges();
    sort(edges.begin(),edges.end());

    for(size_t i=0;i<edges.size();i++)
    {
    	int temp1=sets.find(edges[i].source);
    	int temp2=sets.find(edges[i].dest);

    	if(temp1!=temp2)
    	{
    		graph.setEdgeLabel(edges[i].source,edges[i].dest,"MST");
    		sets.setunion(temp1,temp2);
    	}

    }



}

