#include <iostream>
#include <vector>
using namespace std;
int BinSearchIter(int *A,int size,int v);
int BinsearchRecursive(int *A,int l,int r,int v);
//int main(void){
//	int A[]={1,2,3,4,5,6,7,8};
//	cout << BinSearchIter(A,8,3) << endl;
//	cout << BinsearchRecursive(A,0,8,3) << endl;
//	return 0;
//}
int BinSearchIter(int *A,int size,int v){
	int l=0,r=size;
	while(r-l>0){
		int c = (r+l)/2;
		if(A[c]<v){
			l=c+1;
		}else if(A[c]>v){
			r=c;
		}else{
			return c;
		}
	}
	return -1;
}
int BinsearchRecursive(int *A,int l,int r,int v){
	if(r-l<=0) return -1;
	int c = (r+l)/2;
	if(A[c]<v)
		return BinsearchRecursive(A,c+1,r,v);
	else if(A[c]>v)
		return BinsearchRecursive(A,l,c,v);
	else
		return c;
}
