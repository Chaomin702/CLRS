#pragma once
#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif
#define QUEUE_SIZE	5
template <typename T>
class queue{
public:
	queue():_size(0),_head(0),_tail(1){}
	void enqueue(const T &e){
		if(overflow()) return;
		_elem[_tail++] = e;
		++_size;
		if(_tail==QUEUE_SIZE)
			_tail = 0;
	}
	void dequeue(){
		if(underflow()) return;
		_head++;
		--_size;
		if(_head==QUEUE_SIZE)
			_head = 0;	
	}
	#ifdef DEBUG
	void print(){
		for(auto i:_elem)
			std::cout << i <<" ";
		std::cout << std::endl;
	}
	#endif
private:
	bool overflow(){
		return _size>=QUEUE_SIZE;
	}
	bool underflow(){
		return _size<0;
	}
	int _size;
	int _head;
	int _tail;
	T _elem[QUEUE_SIZE];
};