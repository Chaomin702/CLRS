#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int matrix_chain_order(const vector<int> &p);
int main(void){
	const vector<int> p = {1,2,3,4,5,6,7,8,9};
	cout << matrix_chain_order(p) << endl;
	return 0;
}

int matrix_chain_order(const vector<int> &p){
	int n = p.size()-1;
	int m[n+1][n+1];
	for(auto &i:m)
		for(auto &j:i)
			j = INT_MAX;
	for(int i=0;i<=n;i++)
		m[i][i]=0;
	int s[n+1][n+1];
	for(int l=2;l<=n;++l){
		for(int i=1,j=i+l-1;j<=n;i++,++j){
			for(int k=i;k<j;++k){
				cout <<"i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
				m[i][j] = min(m[i][j],(m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			cout << m[i][j] <<" ";
		cout << endl;
	}
	return m[1][n];
}