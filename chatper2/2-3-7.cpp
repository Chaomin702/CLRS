#include <iostream>
#include <vector>
#include "MergeSort.h"
#include "BinSearch.h"

using namespace std;
void SearchSum(int *A,int size,int v,vector<int> &B);
int main(void){
	int A[]={1,2,3,4,5,6,7,8,9,0,10,12,14};
	vector<int> B;
	SearchSum(A,13,9,B);
	for(vector<int>::const_iterator it=B.begin();
		it!=B.end();++it){
		cout << *it <<" ";
	}
	cout << endl;
	return 0;
}

void SearchSum(int *A,int size,int v,vector<int> &B){
	MergeSort(A,0,size-1);
	for(int i=0,j=0;i<size;i++){
		int m = v - A[i];
		if( (j=BinSearchIter(A,size,m))!=-1){
			B.push_back(i);
			B.push_back(j);
		}
	}
}
