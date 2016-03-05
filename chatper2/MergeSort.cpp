#include <iostream>
#include <climits>
using namespace std;
void Merge(int *A, int p, int q, int r);
void MergeSort(int *A, int p, int r);
//int main(void){
//	int A[] = { 1, 2, 5, 4, 3, 0 ,43,-34,8,9,9};
//	MergeSort(A, 0, 10);
//	for (int i = 0; i<11; i++){
//		cout << A[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

void Merge(int *A, int p, int q, int r){
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
			A[k] = R[j++];
		}
	}
	delete[] L;
	delete[] R;
}
void MergeNoGuard(int *A, int p, int q, int r){
	int *L = new int[q - p + 1];
	int *R = new int[r - q];
	for (int i = 0; i<q - p + 1; i++){
		L[i] = A[p + i];
	}
	for (int i = 0; i<r - q; i++){
		R[i] = A[q + i + 1];
	}
	int i = 0, j = 0, k = p;
	i = 0;
	while (i<q - p + 1 && j<r - q){
		if (L[i]<R[j]){
			A[k++] = L[i++];
		}
		else{
			A[k++] = R[j++];
		}
	}
	int *B = NULL;
	int m = 0;
	if (i == q - p + 1){
		B = R;
		m = j;
	}
	else{
		B = L;
		m = i;
	}
	for (; k<r + 1; ++k){
		A[k] = B[m++];
	}
}
void MergeSort(int *A, int p, int r){
	if (p<r){
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}