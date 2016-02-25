#include <iostream>
#include <climits>
using namespace std;
int Merge(int *A, int p, int q, int r);
int MergeSort(int *A, int p, int r);
int main(void){
	int A[]={4,5,6,1,2,3};
	cout << MergeSort(A,0,5) << endl;
	return 0;
}
int Merge(int *A, int p, int q, int r){
	int numOfInversions = 0;
	int *L = new int[q - p + 2];
	int *R = new int[r - q + 1];
	for (int i = 0; i<q - p + 1; i++){
		L[i] = A[p + i];
	}
	for (int i = 0; i<r - q; i++){
		R[i] = A[q + i + 1];
	}
	L[q - p + 1] = INT_MAX;
	R[r - q] = INT_MAX;
	int i = 0, j = 0;
	for (int k = p; k<r + 1; k++){
		if (L[i]<R[j]){
			A[k] = L[i++];
		}
		else{
			numOfInversions += q+1-j-(k-p);
			A[k] = R[j++];

		}
	}
	delete[] L;
	delete[] R;
	return numOfInversions;
}
int MergeSort(int *A, int p, int r){
	int numOfInversions = 0;
	if (p<r){
		int q = (p + r) / 2;
		numOfInversions +=MergeSort(A, p, q);
		numOfInversions +=MergeSort(A, q + 1, r);
		numOfInversions +=Merge(A, p, q, r);
	}
	return numOfInversions;
}