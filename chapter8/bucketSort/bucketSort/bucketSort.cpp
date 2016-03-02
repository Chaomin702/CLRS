#include <iostream>
using namespace std;
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
			cout << p->data << "   ";
			p = p->succ;
		}
		cout << endl;
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

template <typename T>
void insertSort(listNode<T> &L);
void bucketSort(double *A, int lo, int hi);
int main(){
	list<double> n;
	n.insert(0.1).insert(0.7).insert(0.4).insert(0.6).insert(0.23);
	n.print();
	insertSort(n.getFirst());
	n.print();
	double A[] = { 0.2, 0.5, 0.12, 0.56, 0.98, 0.46, 0.33 };
	bucketSort(A, 0, 7);
	return 0;
}

void bucketSort(double *A, int lo, int hi){
	int n = hi - lo;
	list<double> *B = new list<double>[n];
	for (int i = lo; i<hi; i++){
		B[(int)(n*A[i - lo])].insert(A[i]);
	}
	for (int i = 0; i<n; i++){
		insertSort(B[i].getFirst());
	}
	list<double> M;
	listNode<double> *m = nullptr;
	for (int i = 0; i<n; i++){
		m = &B[i].getFirst();
		if (m == nullptr) break;
		while (m->succ != nullptr){
			M.insert(m->data);
			m = m->succ;
		}
	}
	M.print();
	delete[] B;
}
template <typename T>
void insertSort(listNode<T> &L){
	listNode<T> *j = L.succ;
	if (j == nullptr) return;
	listNode<T> *i = nullptr;
	while (j->succ != nullptr){
		T key = j->data;
		i = j->pre;
		while (i->pre != nullptr && i->data>key){
			i->succ->data = i->data;
			i = i->pre;
		}
		i->succ->data = key;
		j = j->succ;
	}
}

