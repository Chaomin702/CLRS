#pragma once
typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus; //����״̬
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType; //���ڱ�����������������
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
