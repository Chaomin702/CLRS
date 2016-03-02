#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

int main(){

	return 0;
}

void random(int *A,int lo,int hi){
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(lo,hi-1);
	for(int i=lo;i<hi;i++){
		swap(A[i],A[i+distribution(generator)])
	}
}