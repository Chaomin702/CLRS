#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int longest_subsequence(const vector<char> &A);
int main(void){
	vector<char> A = {'1','5','2','6','3','7','8'};
	cout << longest_subsequence(A) <<endl;
	return 0;
}

int longest_subsequence(const vector<char> &A){
	int n = A.size();
	vector<int> c(n,0);
	c[0] = 1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(A[j]<A[i]){
				c[i]=max(c[i],c[j]+1);
			}else{
				c[i]=max(c[i],c[j]);
			}
		}
	}
	return c[n-1];
}