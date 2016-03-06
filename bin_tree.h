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

void traverse(node<T>* root){
	std::stack<T> S;
	node<T> *p = nullptr;
	S.push(root);
	while(!S.empty()){
		p = S.pop();
		visit(p->key);
		if(p->lc!=nullptr) S.push(p->lc);
		if(p->rc!=nullptr) S.push(p->rc)
	}
}

void visit(node<T>* root){
	std::cout << root->key << std::endl;
}