#include <iostream>
#include <vector>
#include "Exercise6-5-9.h"

using namespace std;

int main(){
	vector<vector<Node>> v;
	vector<Node> v1,v2,v3;
	for(int i=12;i>0;i-=3){
		v1.push_back(Node(i,0));
	}
	for(int i=11;i>0;i-=3){
		v2.push_back(Node(i,1));
	}
	for(int i=10;i>0;i-=3){
		v3.push_back(Node(i,2));
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	for(auto i:v){
		for(auto j:i){
		cout << j.value <<"->"<<j.list <<" ";
		}
		cout << endl;
	}
	cout << endl;
	vector<Node> e = kListsMerge(v);
	for(auto i:e)
		cout << i.value <<" ";
	cout <<endl;
	return 0;
}