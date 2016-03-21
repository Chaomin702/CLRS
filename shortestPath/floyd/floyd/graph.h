#pragma once
typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus; //顶点状态
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType; //边在遍历树中所属的类型
template <typename Tv>
class Vertex{
	Tv data;
	int inDegree, outDegree;
	VStatus status;
	int dTime, fTime;
	Vertex *parent;
	int priority;
	Vertex(Tv const &d = (Tv)0)
		:data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
		dTime(0), fTime(0), parent(nullptr), priority(0){}
};
