#include <iostream>
using namespace std;
void SelectSort(int *A, int size);
int main(void){
	int A[]={3,2,4,5,1};
	SelectSort(A,5);
	for(int i=0;i<5;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}

void SelectSort(int *A, int size){
	for(int i=0;i<size;i++){
		int temp=i;
		for(int j=i;j<size;j++){
			if(A[j]<A[temp])
				temp = j;
		}
		swap(A[temp],A[i]);
	}
}