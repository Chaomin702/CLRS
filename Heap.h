#pragma once
#include <iostream>
#include <vector>
#include <climits>
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
    void insert(const int&);
    int erase(size_t i);
    void increaseKey(size_t i,const int &e);
    bool empty()const{
    	if(_size) 
    		return false;
    	else
    		return true;
    }
    int extractMax();
    int maximum()const{if(_size!=0) return _elem[0];}
    void expand();
    void shrink();
    void print()const;
private:
    int *_elem;
    size_t _size;
    size_t _capacity;

};
inline size_t parent(size_t i){return (i-1)/2;}
inline size_t leftChild(size_t i){return 2*i+1;}
inline size_t rightChild(size_t i){return 2*i+2;}
void heapSort(vector<int> &v);