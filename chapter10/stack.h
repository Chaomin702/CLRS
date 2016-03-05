#pragma once
#define STACK_SIZE	100
template <typename T>
class stack{
public:
	stack():_head(0){}
	void push(const T& e){
		if(overflow())
			return;
		_elem[_head++] = e;
	}
	void pop(){
		if(underflow())
			return;
		--_head;
	}
	T& top(){return _elem[_head-1];}
private:
	bool overflow(){return _head>=STACK_SIZE;}
	bool underflow(){return _head<=0;}
	T _elem[STACK_SIZE];
	int _head;
};