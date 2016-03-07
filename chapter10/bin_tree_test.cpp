#include <iostream>
#include "bin_tree.h"

using namespace std;

int main(){
	node<int> m(0);
	m.insertAsLchild(1);
	m.insertAsRchild(2);
	m.lc->insertAsLchild(3);
	m.lc->insertAsRchild(4);
	m.rc->insertAsLchild(5);
	m.rc->insertAsRchild(6);
	pre_traverse(&m);
	pre_traverse_iter(&m);
	cout << "------------"<<endl;
	in_traverse(&m);
	in_traverse_iter(&m);
	cout << "------------"<<endl;
	
	return 0;
}