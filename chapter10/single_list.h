#pragma once
#include <iostream>
template <typename T>
struct node{
	node():next(nullptr){}
	node(const T &e):data(e),next(nullptr){}
	T data;
	node *next;
};
template <typename T>
class list{
public:
	list(){
		head.next = &tail;
	}
	void insert(const T &e){
		node<T> *p = new node<T>(e);
		p->next = head.next;
		head.next = p;
	}
	void reverse(){
		node<T> *p = &head;
		node<T> *r = p->next;
		node<T> *q = nullptr;
		while(r->next!=nullptr){
			q = r->next;
			r->next = p;
			p = r;
			r = q;
		}
		head.next->next = &tail;
		head.next = p;

	}
	void print(){
		for(node<T> *p = head.next;
			p->next!=nullptr;p=p->next)
			std::cout << p->data << " ";
		std::cout << std::endl;

	}
private:
	node<T> head,tail;
};