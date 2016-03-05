#include <iostream>
#include "Heap.h"
using namespace std;

int main(){
	int A[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	vector<int> v = {6,3,7,2,0,5,1,4};
	Heap H(A,0,15);
	H.print();
	H.build();
	H.print();
	cout << H.extractMax() << endl;
	H.print();
	H.insert(16);
	H.print();
	H.insert(24);
	H.print();
	H.erase(2);
	H.print();
	heapSort(v);
	for(auto i:v){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}