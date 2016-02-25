#include <iostream>
using namespace std;
int LinearSearch(int *A,int size,int v);
int main(void){
	int A[]={5,2,1,4,3};
	cout << LinearSearch(A,5,6) << endl;
	return 0;
}

int LinearSearch(int *A,int size,int v){
	for(int i=0;i<size;i++){
		if(A[i]==v)
			return i;
	}
	return -1;
}