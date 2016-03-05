#pragma once
#include <iostream>
template <typename T>
struct listNode{
	T data;
	listNode *pre;
	listNode *succ;
	listNode() :data(0), pre(nullptr), succ(nullptr){}
	listNode(T e, listNode *p, listNode *s) :data(e), pre(p), succ(s){}
	listNode& insertAsPre(T e){
		listNode *n = new listNode(e, this->pre, this);
		pre->succ = n;
		pre = n;
		return *n;
	}
	listNode& insertAsSucc(T e){
		listNode *n = new listNode(e, this, this->succ);
		succ->pre = n;
		succ = n;
		return *n;
	}
};
template <typename T>
class list{
public:
	list(){
		head.succ = &tail;
		tail.pre = &head;
	}
	~list(){ 	delete_list(); }
	bool empty(){ return head.succ == &tail; }
	void print(){
		listNode<T> *p = head.succ;
		while (p->succ != nullptr){
			std::cout << p->data << "   ";
			p = p->succ;
		}
		std::cout << std::endl;
	}
	list& insert(const T& e){
		tail.insertAsPre(e);
		return *this;
	}
	listNode<T>& getFirst(){
		return *(head.succ);
	}
private:
	listNode<T> head, tail;
	void delete_list(){
		if (empty()) return;
		listNode<T> *p = &getFirst();
		while (p->succ != nullptr){
			p = p->succ;
			delete p->pre;
		}
	}
};
