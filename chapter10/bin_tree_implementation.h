#pragma once
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
template <typename T>
void pre_traverse(node<T>* root){
	if(root==nullptr) return;
	visit(root);	
	pre_traverse(root->lc);
	pre_traverse(root->rc);
}

template <typename T>
void visit_alone_left(node<T>* p,std::stack<node<T>*> &S){
	while(p!=nullptr){
		visit(p);
		if(p->rc!=nullptr)
			S.push(p->rc);
		p = p->lc;
	}
}
template <typename T>
void pre_traverse_iter(node<T>* root){
	std::stack<node<T>*> S;
	node<T>* p=nullptr;
	S.push(root);
	while(!S.empty()){
		p = S.top();
		S.pop();
		visit_alone_left(p,S);
	}
}
template <typename T>
void in_traverse(node<T>* root){
	if(root==nullptr)
		return;
	in_traverse(root->lc);
	visit(root);
	in_traverse(root->rc);
}
template <typename T>
void go_alone_left(node<T> *p,std::stack<node<T>*> &S){
	while(p!=nullptr){
		S.push(p);
		p = p->lc;
	}
}
template <typename T>
void in_traverse_iter(node<T>* root){
	std::stack<node<T>*> S;
	node<T> *p = root;
	while(true){
		go_alone_left(p,S);
		if(S.empty()) break;
		p = S.top();
		S.pop();
		visit(p);
		p = p->rc;
	}
}


