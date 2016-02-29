#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
const int DEFAULT_CAPACITY = 4;
using std::swap;
using std::vector;
using std::cout;
using std::endl;
enum compareResult{
	EQUAL=0,
	SMALLER=1,
	BIGGER=2
};
template<typename T>
class Heap{
public:
	Heap(const T &maxNode):_elem(nullptr),_size(0),_capacity(0),_maxNode(maxNode){}
	Heap(T *A,int lo,int hi,const T &);
	Heap(const vector<T>&,const T &);
	~Heap(){delete[] _elem;}
	void heapify(int i);
	void build();
	void insert(const T&);
	T erase(int i);
	void increaseKey(int,const T&);
	bool empty()const{return (_size)?false:true;}
	T extractMax();
	T& maximum()const{return _elem[0];}
	void expand();
	void shrink();
	void print()const;
	compareResult compareNode(T &A,T &B);
private:
	T *_elem;
	int _size;
	int _capacity;
	T _maxNode;
};
inline int parent(int i){return (i-1)/2;}
inline int leftChild(int i){return 2*i+1;}
inline int rightChild(int i){return 2*i+2;}
template<typename T>
void heapSort(vector<T> &v,const T&);
#include "HeapImplementation.h"
