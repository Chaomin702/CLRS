#include <iostream>
#include <algorithm>
//#define DEBUG 0
using namespace std;

struct Array {
	int m;
	int n;
	int (*_elem)[5];
	int step;
};
int left_min(int *A,int lo,int hi);
void monge(Array array,int *mins);
int height(const Array &array);
int main(void){
//	int A[][4] = {
//		{37,23,24,32},
//		{21,6,7,10},
//		{53,34,30,31},
//		{32,13,9,6},
//		{43,21,15,8}
//	};
	int A[][5]={
		{10,17,13,28,23},
		{17,22,16,29,23},
		{24,28,22,34,24},
		{11,13,6,17,7},
		{45,44,32,37,23},
		{36,33,19,21,6},
		{75,66,51,53,34},
	};
	int B[7]={0};
	Array array;
	array.m = 7;
	array.n = 5;
	array._elem = A;
	array.step = 1;
	monge(array,B);
	cout << endl;
	for(auto i : B){
		cout << i <<" ";
	}
	cout << endl;
	return 0;
}
int height(const Array &array){
	return array.step/array.m;
}
int left_min(int *A,int lo,int hi){
#ifdef DEBUG
	cout << "left_min " << lo <<" "<< hi <<" "<<endl;
#endif
	int min = lo;
	for(int i = lo+1;i<hi;i++){
#ifdef DEBUG
		cout << A[i] << " ";
#endif
		if(A[min]>A[i])
			min = i;
	}
#ifdef DEBUG
	cout << endl;
#endif
	return min;
}
void monge(Array array,int *mins){
	if(height(array)==1){
		mins[0] = left_min(array._elem[0],0,array.n);
#ifdef DEBUG
		cout << "mins[0]: " << mins[0] << endl;
#endif
		return;
	}
	array.step *= 2;
	monge(array,mins);
	for(int i=array.step/2;i<array.m;i+=array.step){
		mins[i] = left_min(array._elem[i],mins[i-array.step/2],(i+array.step/2>array.n)?array.n:mins[i+array.step/2]+1);
#ifdef DEBUG
		cout <<"mins "<< i <<" "<<mins[i]<<" ;";
#endif
	}
#ifdef DEBUG
	cout << endl;
#endif
}