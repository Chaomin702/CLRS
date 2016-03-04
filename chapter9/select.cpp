#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
using namespace std;
template <typename T>
void min_and_max(const vector<T>& v,T &smallest,T &largest);
template<typename T>
T sub_min(T *A,int lo,int hi);
template <typename T>
int random_partition(T *A,int lo,int hi);
template <typename T>
T random_select(T *A,int lo, int hi, int i);
template <typename T>
void print(T *A,int lo,int hi);
int main(void){
	vector<int> v = {5,4,3,2,6,8,6,2,1};
	int s = 0, l = 0;
	min_and_max(v,s,l);
	cout << s << " " << l <<" "<<endl;
	int A[] = {1,2,3,4,5,6,7,8,9,10};
//	cout << sub_min(A,0,11) << endl;
	cout << random_select(A,0,10,5) << endl;
	return 0;
}
template <typename T>
void min_and_max(const vector<T>& v,T &smallest,T &largest){
	if(v.empty()) return;
	auto i = v.begin(),j = v.begin();
	if(v.size()%2==0){
		++j;
		if(*i>*j){
			++i;
			--j;
		}
	}
	decltype(i) min,max;
	for(auto k=std::max(i,j)+1;k!=v.end();k+=2){
		if(*k>*(k+1)){
			max = k;
			min = k+1;
		}else{
			min = k;
			max = k+1;
		}
		if(*min<*i)
			i = min;
		if(*max>*j)
			j = max;
	}
	smallest = *i;
	largest = *j;
}
template<typename T>
T sub_min(T *A,int lo,int hi){
	int n = hi-lo;
	if(n<2)
		throw runtime_error("sub_min do not exist!");
	if(n==2){
		return (A[lo]>A[hi])?A[hi]:A[lo];
	}
	int k = hi;
	if(n%2!=0)
		k = hi-1;
	for(int i=lo;i<k;i+=2){
		A[i/2] = (A[lo]>A[hi])?A[lo]:A[hi];
	}
	if(n%2!=0)
		A[k/2]=A[k];
	return sub_min(A,lo,(hi+1)/2);
}
template <typename T>
int random_partition(T *A,int lo,int hi){
	if(hi==lo) throw runtime_error("Partition: parameter invaild!");
	if(hi-lo<2) return A[lo];
	srand(time(NULL));
	swap(A[hi-1],A[lo+rand()%(hi-lo)]);
	T key = A[hi-1];
	int i = lo-1,j=lo;
	while(j<hi-1){
		if(A[j]<key){
			++i;
			swap(A[j],A[i]);
		}
		++j;
	}
	swap(A[++i],A[hi-1]);
	return i;
}

template <typename T>
T random_select(T *A,int lo, int hi, int i){
	if(hi-lo<2) 
		return A[lo];
	print(A,lo,hi);
	int t = random_partition(A,lo,hi);
	int k = t-lo+1;
	print(A,lo,hi);
	cout <<"A[t]"<<A[t]<<" "<<"k: "<< k << "  "<<"i: "<< i << endl;
	if(i==k)
		return A[t];
	else if(k<i)
		return random_select(A,t+1,hi,i-k);
	else
		return random_select(A,lo,t,i);
}
template <typename T>
void print(T *A,int lo,int hi){
	for(int i=lo;i<hi;i++){
		cout << A[i]<<"  ";
	}
	cout << endl;
}