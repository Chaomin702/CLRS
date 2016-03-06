#pragma once
#include <iostream>
template <typename T>
struct node{
	node():np(nullptr){}
	node(const T &e):key(e),np(nullptr){}
	T key;
	node *np;
};

template <typename T>
class list{
public:
	list(){
		head = new node<T>();
		tail = new node<T>();
		head->np = tail;
		tail->np = head;
	}
	void insert(const T &e){
		node<T> *p = new node<T>(e);
		p->np = xor_address(head,head->np);
		head->np->np = xor_address(p,xor_address(head,head->np->np));
		head->np = p;
	}
	bool search(const T &e){
		node<T> *p = head;
		node<T> *r = head->np;
		node<T> *q = nullptr;
		while(r!=tail){
			if(r->key==e)
				return true;
			q = r;
			r = get_next(p,r);
			p = q;
		}
		return false;
	}
	void del(const T& e){
		node<T> *p = head;
		node<T> *r = head->np;
		node<T> *q = nullptr;
		while(r!=tail){
			if(r->key==e)
				break;
			q = r;
			r = get_next(p,r);
			p = q;
		}
		if(r!=tail){
			q = get_next(p,r);
			p->np = xor_address(get_next(r,p),q);
			q->np = xor_address(get_next(r,q),p);
			delete[] r;
		}
	}
	node<T>* get_next(node<T> *pre,node<T> *cur){
		return xor_address(cur->np,pre);
	}
	void print(){
		node<T> *p = head;
		node<T> *r = head->np;
		node<T> *q = nullptr;
		while(r!=tail){
			std::cout << r->key << " ";
			q = r;
			r = get_next(p,r);
			p = q;
		}
		std::cout << std::endl;
	}
private:
	node<T>* xor_address(const node<T>*pre,const node<T>*succ){
		return reinterpret_cast<node<T>*>(reinterpret_cast<unsigned>(pre)^reinterpret_cast<unsigned>(succ));
	}
	node<T> *head;
	node<T> *tail;
};