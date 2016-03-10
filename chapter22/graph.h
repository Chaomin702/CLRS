#pragma once

class Edge{
public:
	int start;
	int end;
	Edge *next;
	Edge(int s,int e):start(s),end(e),next(nullptr){}

};
class Vertex{
public:
	Edge *next;
	int indegree; 
	Vertex():next(nullptr),indegree(0){}
};

class Graph{
public:
	Graph(int n=0):numOfVertex(n){
		V = new Vertex* [numOfVertex];
		for(int i=0;i<numOfVertex;++i){
			V[i] = new Vertex();
		}
	}
	~Graph(){

	}
private:
	int numOfVertex;
	Vertex **V;
};