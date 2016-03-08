#include <iostream>
#include <vector>
using namespace std;
int LCS_length(const vector<char>&A,const vector<char>&B);
int main(void){
	vector<char> A = {'A','B','C','B','D','A','B'};
	vector<char> B = {'B','D','C','A','B','A'};
	cout << LCS_length(A,B) <<endl;
	return 0;
}

int LCS_length(const vector<char>&A,const vector<char>&B){
	int m = A.size(),n = B.size();
	int c[m+1][n+1];
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
		}
	}
	return c[m][n];
}