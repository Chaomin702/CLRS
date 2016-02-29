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
	_capacity *= 2;
	_elem = new int[_capacity];
	for(int i=0;i<_size;i++){
		_elem[i]=oldElem[i];
	}
	delete[] oldElem;

}
void Heap::shrink(){
	if(_capacity<DEFAULT_CAPACITY/2) return;
	if(_size*4 > _capacity) return;
	auto *oldElem = _elem;
	_capacity /= 2;
	_elem = new int[_capacity];
	for(size_t i=0;i<_size;i++)
		_elem[i]=oldElem[i];
	delete[] oldElem;
}
void Heap::build(){
	for(int i=_capacity/2;i>=0;i--)
		heapify(i);
}
void Heap::print()const{
	for(size_t i=0;i<_size;i++){
		cout << _elem[i] <<" ";
	}
	cout << endl;
}
int Heap::extractMax(){
	int bak = _elem[0];
	swap(_elem[_size-1],_elem[0]);
	--_size;
	shrink();
	heapify(0);
	return bak;
}
void heapSort(vector<int> &v){
	vector<int> u;
	Heap H(v);
	H.build();
	while(!H.empty()){
		u.push_back(H.extractMax());
	}
	v = u;
}
void Heap::insert(const int &e){
	_size++;
	expand();
	_elem[_size-1] = INT_MIN;
	increaseKey(_size-1,e);

}
void Heap::increaseKey(size_t i,const int &e){
	_elem[i] = e;
	while(i>0 && _elem[i]>_elem[parent(i)]){
		swap(_elem[i],_elem[parent(i)]);
		i = parent(i);
	}
}
int Heap::erase(size_t i){
	increaseKey(i,INT_MAX);
	return extractMax();
}