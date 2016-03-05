#include <iostream>
using namespace std;
void InsertSort(int *A, int size);
int main(){
	int A[] = {5,3,4,2,1};
	InsertSort(A,5);
	for(int i=0;i<5;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}

void InsertSort(int *A, int size){
	for(int j=1; j<size; j++){
		int key = A[j];
		int i=j-1;
		while(i>=0 && A[i]>key){
			A[i+1] = A[i];
			i--;
		}
		A[i+1]=key;
	}
}