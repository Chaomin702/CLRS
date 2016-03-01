#include <iostream>
#include <vector>
using namespace std;
void countingSort(int *A,int lo,int hi,int k);
int main(void){
	int A[]={4,5,2,3,5,7,8,1,2,4,7,9,1};
	countingSort(A,0,13,9);
	for(auto i:A)
		cout << i << " ";
	cout << endl;
	return 0;
}

void countingSort(int *A,int lo,int hi,int k){
	int B[hi-lo] = {0};
	int C[k+1] = {0};
	for(int i=lo;i<hi;++i)
		++C[A[i]];
	for(int i=1;i<=k;++i)
		C[i] += C[i-1];
	for(int i=hi-1;i>=lo;--i){
		B[C[A[i]]-1] = A[i];
		--C[A[i]];
	}
	for(int i=lo;i<hi;i++)
		A[i]=B[i];

}
