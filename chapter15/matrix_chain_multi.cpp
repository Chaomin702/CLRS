#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int matrix_chain_order_down_to_top(const vector<int> &p);
int matrix_chain_order_top_to_down(const vector<int> &p);
int main(void){
	const vector<int> p = {30,35,15,5,10,20,25};
	cout << matrix_chain_order_down_to_top(p) << endl;
	cout << matrix_chain_order_top_to_down(p) << endl;
	return 0;
}

int matrix_chain_order_down_to_top(const vector<int> &p){
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
				int q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			cout << m[i][j] <<" ";
		cout << endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			cout << s[i][j] <<" ";
		cout << endl;
	}
	return m[1][n];
}

int look_up_chain(const vector<int> &p,vector<vector<int>> &m,int i,int j){
	if(i==j) return 0;
	if(m[i][j]!=INT_MAX) return m[i][j];
	for(int k=i;k<j;k++){
		m[i][j] = min(m[i][j],(look_up_chain(p,m,i,k)+look_up_chain(p,m,k+1,j)+p[i-1]*p[k]*p[j]));
	}	
	return m[i][j];
}
int matrix_chain_order_top_to_down(const vector<int> &p){
	int n = p.size()-1;
	vector<vector<int>> m;
	m.resize(n+1);
	for(auto &i:m)
		i.resize(n+1);
	for(auto &i:m)
		for(auto &j:i)
			j = INT_MAX;
	for(int i=0;i<=n;i++)
		m[i][i]=0;
	return look_up_chain(p,m,1,n);
}
