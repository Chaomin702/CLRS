#pragma once


struct node{
	int val;
	node *left;
	node *right;
	node(int v):val(v),left(nullptr),right(nullptr){}
};

class bin_tree{
public:
	bin_tree():root(nullptr){}
	bin_tree(node *n):root(n){}
	void insert(int v){ __insert(&node(v));}
	bool search(int v)const { return __search(v)!=nullptr;}
	void inorder_traver()const;
private:
	node *__insert(node *n);
	node *__search(int v)const;
	void __inorder(node *n)const;
	node *root;
};
