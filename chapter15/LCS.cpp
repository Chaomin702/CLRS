#include <iostream>
#include <vector>
using namespace std;
int LCS_length(const vector<char>&A,const vector<char>&B);
void print_LCS(const vector<vector<int>> &c,int m,int n);
int main(void){
	vector<char> A = {'A','B','C','B','D','A','B'};
	vector<char> B = {'B','D','C','A','B','A'};
	cout << LCS_length(A,B) <<endl;
	return 0;
}

int LCS_length(const vector<char>&A,const vector<char>&B){
	int m = A.size(),n = B.size();
	vector<vector<int>> c;
	c.resize(m+1);
	for(auto &i:c)
		i.resize(n+1);
	for(auto &i:c)
		for (auto &j:i)
			j = 0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(A[i-1]==B[j-1]){
				c[i][j] = c[i-1][j-1]+1;
			}else if(c[i-1][j]>c[i][j-1]){
				c[i][j] = c[i-1][j];
			}else{
				c[i][j] = c[i][j-1];
			}
			cout <<"i: "<<i<<" j: "<<j<<" "<< c[i][j] <<endl;
		}
	}
	print_LCS(c,m,n);
	return c[m][n];
}

void print_LCS(const vector<vector<int>> &c,int m,int n){
	if(m==0||n==0){
		cout << endl;
		return;
	}
	else if(c[m][n]==c[m-1][n]){
		print_LCS(c,m-1,n);
	}else if(c[m][n]==c[m][n-1]){
		print_LCS(c,m,n-1);
	}else{
		print_LCS(c,m-1,n-1);
		cout <<"m: "<<m<<" n: "<<n<<" "<< c[m][n] <<endl;
	}

}