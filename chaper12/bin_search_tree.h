#pragma once
#include <iostream>
#include <stack>

struct node{
	int val;
	node *parent;
	node *left;
	node *right;
	node(int v):val(v),left(nullptr),right(nullptr),parent(nullptr){}
};

class bin_tree{
public:
	bin_tree():root(nullptr){}
	bin_tree(node *n):root(n){}
	void insert(int v){ 
		node *n = new node(v);
		__insert(n);
	}
	bool search(int v)const { 
		node *p = __search(v);
		return !p && (p->val == v);
	}
	void erase(int v){
		node *p = __search(v);
		if(!p || p->val != v)
			return;
		__erase(p);
	}
	void inorder_traver()const;
	int min()const;
	int max()const;
private:
	node *__insert(node *n);
	node *__search(int v)const;
	void __erase(node *);
	void __inorder(node *n)const;
	void __inorder_nonrecursive(node *n)const;
	void __inorder_successor(node *n)const;
	void __along_left(node *n, std::stack<node*> &S)const;
	node *__min(node* )const;
	node *__max(node* )const;
	node *successor(node *)const;
	node *predecessor(node *)const;
	void transplant(node *,node *);

	node *root;
};
