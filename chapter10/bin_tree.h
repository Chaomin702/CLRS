#pragma once
#include <iostream>
#include <stack>
template <typename T>
struct node
{
	T key;
	node<T> *lc;
	node<T> *rc;
	node(const T& e):key(e),lc(nullptr),rc(nullptr){}
	void insertAsLchild(const T& e){
		lc = new node<T>(e);
	}
	void insertAsRchild(const T& e){
		rc = new node<T>(e);
	}
};
template <typename T>
void visit(node<T>* n);
template <typename T>
void traverse(node<T>* root);
template <typename T>
void traverse(node<T>* root){
	std::stack<node<T>*> S;
	node<T> *p = nullptr;
	S.push(root);
	while(!S.empty()){
		p = S.top();
		S.pop();
		visit(p);
		if(p->lc!=nullptr) S.push(p->lc);
		if(p->rc!=nullptr) S.push(p->rc);
	}
}
template <typename T>
void visit(node<T>* n){
	std::cout << n->key << std::endl;
};