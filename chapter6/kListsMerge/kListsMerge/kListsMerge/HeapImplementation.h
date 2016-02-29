template <typename T>
void Heap<T>::heapify(int i){
	int left = leftChild(i);
	int right = rightChild(i);
	int largest = i;
	if(left<_size && compareNode(_elem[i],_elem[left])==SMALLER)
		largest = left;
	if(right<_size && compareNode(_elem[largest],_elem[right])==SMALLER)
		largest = right;
	if(largest!=i){
		swap(_elem[i],_elem[largest]);
		heapify(largest);
	}
}
template <typename T>
Heap<T>::Heap(T *A,int lo,int hi,const T &maxNode):_maxNode(maxNode){
	_capacity = 2*(hi-lo);
	_elem = new int[_capacity];
	_size=0;
	while(lo<hi)
		_elem[_size++]=A[lo++];
}
template <typename T>
Heap<T>::Heap(const vector<T>& v,const T &maxNode):_maxNode(maxNode){
	_capacity = 2*v.size();
	_elem = new int[_capacity];
	_size = 0;
	for(auto t:v){
		_elem[_size++] = t;
	}
}
template <typename T>
void Heap<T>::expand(){
	if(_size<_capacity) return;
	if(_capacity<DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;
	auto *oldElem = _elem;
	_capacity *=2;
	_elem = new T[_capacity];
	for(int i=0;i<_size;i++){
		_elem[i]=oldElem[i];
	}
	delete[] oldElem;
}
template <typename T>
void Heap<T>::shrink(){
	if(_capacity<DEFAULT_CAPACITY) return;
	if(_size*4 > _capacity) return;
	auto *oldElem = _elem;
	_capacity /=2;
	_elem = new T[_capacity];
	for(int i=0;i<_size;i++){
		_elem[i]=oldElem[i];
	}
	delete[] oldElem;
}
template <typename T>
void Heap<T>::build(){
	for(int i=_capacity/2;i>=0;i--){
		heapify(i);
	}
}
template <typename T>
void Heap<T>::print()const{
	for(int i=0;i<_size;i++){
		cout << _elem[i] <<" ";
	}
	cout << endl;	
}
template <typename T>
T Heap<T>::extractMax(){
	T bak = _elem[0];
	swap(_elem[_size-1],_elem[0]);
	--_size;
	shrink();
	heapify(0);
	return bak;
}
template <typename T>
void Heap<T>::insert(const T &e){
	expand();
	_size++;
	_elem[_size-1] = _maxNode;
	increaseKey(_size-1,e);
}
template <typename T>
void Heap<T>::increaseKey(int i,const T &e){
	_elem[i] = e;
	while(i>0 && compareNode(_elem[i],_elem[parent(i)])==BIGGER){
		swap(_elem[i],_elem[parent(i)]);
		i = parent(i);
	}
}
template <typename T>
T Heap<T>::erase(int i){
	increaseKey(i,_maxNode);
	return extractMax();
}
template <typename T>
compareResult Heap<T>::compareNode(T &A,T &B){
	if(A==_maxNode && B==_maxNode)
		return EQUAL;
	if(A==_maxNode)
		return BIGGER;
	if(B==_maxNode)
		return SMALLER;
	if(A<B)
		return SMALLER;
	if(A>B)
		return BIGGER;
	return EQUAL;
}
template <typename T>
void heapSort(vector<T> &v,const T& maxNode){
	vector<T> u;
	Heap<T> H(v,maxNode);
	H.build();
	while(!H.empty()){
		u.push_back(H.extractMax());
	}
	v = u;
}