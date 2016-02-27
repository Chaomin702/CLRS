#include "Heap.h"
using std::cout;
using std::endl;
void Heap::heapify(size_t i){
	size_t left = leftChild(i);
	size_t right = rightChild(i);
	int largest = i;
	if(left<_size && _elem[i]<_elem[left])
		largest = left;
	if(right<_size && _elem[largest]<_elem[right])
		largest = right;
	if(largest!=i){
		swap(_elem[i],_elem[largest]);
		heapify(largest);
	}
}
Heap::Heap(int *A,size_t lo,size_t hi){
	_capacity = 2*(hi-lo);
	_elem = new int[_capacity];
	_size = 0;
	while(lo<hi)
		_elem[_size++] = A[lo++];
}
Heap::Heap(const vector<int>& v){
	_capacity = 2*v.size();
	_elem = new int[_capacity];
	_size = 0;
	for(auto t:v){
		_elem[_size++] = t;
	}
}
void Heap::expand(){
	if(_size<_capacity)
		return;
	if(_capacity<DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;
	auto *oldElem = _elem;
	_elem = new int[_capacity*2];
	for(int i=0;i<_size;i++){
		_elem[i]=oldElem[i];
	}
	delete[] oldElem;

}
void Heap::build(){
	for(int i=_capacity/2;i>=0;i--)
		heapify(i);
}
void Heap::print(){
	for(size_t i=0;i<_size;i++){
		cout << _elem[i] <<" ";
	}
	cout << endl;
}
int Heap::extractMax(){
	swap(_elem[_size-1],_elem[0]);
	--_size;
	heapify(0);
	return _elem[_size];
}
void heapSort(vector<int> &v){
	vector<int> u;
	Heap H(v);
	H.build();
	while(!H.empty())
		u.push_back(H.extractMax());
	v = u;
}