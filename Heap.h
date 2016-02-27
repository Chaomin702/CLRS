#pragma once
#include <iostream>
#include <vector>
const int DEFAULT_CAPACITY = 4;
using std::swap;
using std::vector;
class Heap{
public:
	Heap():_elem(nullptr),_size(0),_capacity(0){}
	Heap(int *A,size_t lo,size_t hi);
	Heap(const vector<int> &v);
	~Heap(){delete[] _elem;}
    void heapify(size_t i);
    void build();
//    void insert();
    bool empty(){
    	if(_size) 
    		return false;
    	else
    		return true;
    }
    int extractMax();
    int maximum(){if(_size!=0) return _elem[0];}
    void expand();
    void print();
private:
    int *_elem;
    size_t _size;
    size_t _capacity;

};
inline size_t parent(size_t i){return (i-1)/2;}
inline size_t leftChild(size_t i){return 2*i+1;}
inline size_t rightChild(size_t i){return 2*i+2;}
void heapSort(vector<int> &v);