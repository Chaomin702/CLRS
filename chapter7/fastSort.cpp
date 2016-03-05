#include <iostream>
#include <algorithm>
#include <random>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
using namespace std;
void fastSort(int *A,int lo,int hi);
int partition(int *A,int lo,int hi);
vector<int>::iterator partition(vector<int>::iterator lo,vector<int>::iterator hi);
vector<int>::iterator partition_random(vector<int>::iterator lo,vector<int>::iterator hi);
void fastSort(vector<int>::iterator lo,vector<int>::iterator hi);
int main(){
	int A[]={3,5,2,6,1,8,4,9,7};
	vector<int> u = {3,5,2,6,1,8,4,9,7};
	fastSort(A,0,9);
	fastSort(u.begin(),u.end());
	for(auto i:A){
		cout << i <<" ";
	}
	cout << endl;
	for(auto i:u){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

void fastSort(int *A,int lo,int hi){
	if(hi-lo<2) return;
	int mi = partition(A,lo,hi);
	fastSort(A,lo,mi);
	fastSort(A,mi+1,hi);
}

int partition(int *A,int lo,int hi){
	int key = A[hi-1];
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
void fastSort(vector<int>::iterator lo,vector<int>::iterator hi){
	if(hi-lo<2) return;
	auto mi = partition_random(lo,hi);
	fastSort(lo,mi);
	fastSort(mi+1,hi);
}
vector<int>::iterator partition(vector<int>::iterator lo,vector<int>::iterator hi){
	auto key = hi-1;
	auto i = lo - 1, j = lo;
	while(j!=hi-1){
		if((*j)<(*key)){
			++i;
			swap(*i,*j);
		}
		++j;
	}
	swap(*(i+1),*key);
	return ++i;
}
vector<int>::iterator partition_random(vector<int>::iterator lo,vector<int>::iterator hi){
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,hi-lo-1);
	swap(*(lo+distribution(generator)),*(hi-1));
	auto key =hi-1;		
	auto i = lo - 1, j = lo;
	while(j!=hi-1){
		if((*j)<(*key)){
			++i;
			swap(*i,*j);
		}
		++j;
	}
	swap(*(i+1),*key);
	return ++i;
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
int random_partition_with_equal(T *A,int lo,int hi){
	srand(time(NULL));
	swap(A[lo],A[lo+rand()%(hi-lo)]);
	T key = A[lo];
	while(lo<hi){
		while(lo<hi){
			if(A[hi]>key)
				hi--;
			else{
				A[lo++] = A[hi];break;
			}
		}
		while(lo<hi){
			if(A[lo]<key)
				lo++;
			else{
				A[hi--]=A[lo];break;
			}
		}
	}
	A[lo]=key;
	return lo;
}