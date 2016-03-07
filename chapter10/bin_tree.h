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
void pre_traverse(node<T>* root);
template <typename T>
void pre_traverse_iter(node<T>* root);
template <typename T>
void in_traverse(node<T>* root);
template <typename T>
void in_traverse_iter(node<T>* root);
#include "bin_tree_implementation.h"