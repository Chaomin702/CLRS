#pragma once
#include "Heap.h"
#include <iostream>
#include <vector>
#include <climits>
#include <climits>
struct Node{
	friend std::ostream& operator <<(std::ostream& os,const Node& node);
	int value;
	int list;
	Node():value(0),list(0){}
	Node(int v,int l):value(v),list(l){}
	static Node maxValue(){return Node(INT_MAX,0);}
	bool operator <(const Node &e){return value < e.value;}
	bool operator >(const Node &e){return value > e.value;}
	bool operator ==(const Node &e){return value == e.value;}
};
std::vector<Node> kListsMerge(std::vector<std::vector<Node>> &v);
std::ostream& operator <<(std::ostream& os,const Node& node);