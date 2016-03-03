#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;
template <typename T>
void randomize(vector<T>& e);
int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,0};
	randomize(v);
	for(auto i:v)
		cout<<i<<" ";
	cout << endl;
	return 0;
}

void random(int *A,int lo,int hi){
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(lo,hi-1);
	for(int i=lo;i<hi;i++){
		swap(A[i],A[i+distribution(generator)]);
	}
}
template <typename T>
void randomize(vector<T>& e){
	srand(time(NULL));
	for(auto i=e.begin();i!=e.end();++i){
		swap(*i,*(i+rand()%(e.end()-i)));
	}
}