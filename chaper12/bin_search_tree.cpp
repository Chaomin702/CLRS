#include "bin_search_tree.h"

node* bin_tree::__insert(node *n){
	node *p = __search(n->val);
	if(p==nullptr)	//tree is empty
		root = n;
	else if(p->val==n->val) 	//node exist
		return nullptr;		
	else{
		n->parent = p;
		if(p->val > n->val)
			p->left = n;
		else
			p->right = n;
	}
	return p;
}

node* bin_tree::__search(int v)const{
	node *x = root;
	node *p = nullptr;
	while(x){
		p = x;
		if(x->val == v)
			return x;
		else if(x->val > v)
			x = x->left;
		else
			x = x->right;
	}
	return p;
}

void bin_tree::inorder_traver()const{
	__inorder(root);
	__inorder_nonrecursive(root);
	__inorder_successor(root);
}

void bin_tree::__inorder(node *n)const{
	if(!n) return;
	__inorder(n->left);
	std::cout << " "<< n->val << " ";
	__inorder(n->right);
}
void bin_tree::__inorder_nonrecursive(node *n)const{
	std::stack<node*> S;
	__along_left(root,S);
	while(!S.empty()){
		node *p = S.top();
		S.pop();
		std::cout << " " << p->val <<" ";
		__along_left(p->right,S);
	}
}
void bin_tree::__along_left(node *n, std::stack<node*> &S)const{
	while(n){
		S.push(n);
		n = n->left;
	}
}

void bin_tree::__inorder_successor(node *n)const{
	node *p = __min(root);
	while(p){
		std::cout << " " << p->val << " ";
		p = successor(p);
	}
}
int bin_tree::min()const{
	return __min(root)->val;
}
node* bin_tree::__min(node *n)const{
	if(!n) return nullptr;
	node *m = nullptr;
	while(n){
		m = n;
		n = n->left;
	}
	return m;
}
int bin_tree::max()const{
	return __max(root)->val;
}
node *bin_tree::__max(node *n)const{
	if(!n) return nullptr;
	node *m = nullptr;
	while(n){
		m = n;
		n = n->right;
	}
	return m;
}
node* bin_tree::successor(node *n)const{
	if(!n) return nullptr;
	if(n->right)
		return __min(n->right);
	node *p = n->parent;
	while(p && p->right==n){
		n = p;
		p = n->parent;
	}
	return p;
}

node* bin_tree::predecessor(node *n)const{
	if(!n) return nullptr;
	if(n->left)
		return __max(n->left);
	node *p = n->parent;
	while(p && p->left==n){
		n = p;
		p = n->parent;
	}
	return p;
}

void bin_tree::transplant(node *u, node *v){
	if(!u->parent)
		root = v;
	else if(u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;
	if(v)
		v->parent = u->parent;
}

void bin_tree::__erase(node *n){
	if(!n->left)
		transplant(n,n->right);
	else if(!n->right)
		transplant(n,n->left);
	else{
		node *y = successor(n);
		if(n->right != y){
			transplant(y,y->right);
			n->right->parent = y;
			y->right = n->right;
			transplant(n,y);
			y->left = n->left;
		}
		transplant(n,y);
		y->left = n->left;
		n->left->parent = y;
	}
	delete n;
}