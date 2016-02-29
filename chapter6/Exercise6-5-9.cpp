#include "Exercise6-5-9.h"

using std::vector;
using std::cout;
using std::ostream;
void insertListHeadToHeap(vector<vector<Node>> &v,Heap<Node> &H,int listIndex);

vector<Node> kListsMerge(vector<vector<Node>> &v){
	Heap<Node> H(Node::maxValue());
	vector<Node> ret;
	for(decltype(v.size()) i=0;i<v.size();i++){
		insertListHeadToHeap(v,H,i);
	}
	H.print();
	Node top;
	while(!H.empty()){
		top = H.extractMax();
		ret.push_back(top);
		insertListHeadToHeap(v,H,top.list);
	}
	return ret;
}

void insertListHeadToHeap(vector<vector<Node>> &v,Heap<Node> &H,int listIndex){
	auto *list = &v[listIndex];
	if(!list->empty()){
		H.insert((*list)[0]);
		list->erase(list->begin());
	}
}
ostream& operator <<(ostream& os,const Node& node){
	os << node.value << "->"<< node.list<<" ";
	return os;
}