#include <iostream>
#include <algorithm>
using namespace std;
void fastSort(int *A,int lo,int hi);
int partition(int *A,int lo,int hi);
vector<int>::iterator partition(vector<int>::iterator lo,vector<int>::iterator hi);
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
	auto mi = partition(lo,hi);
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
	swap(*(i+1),*(hi-1));
	return ++i;
}