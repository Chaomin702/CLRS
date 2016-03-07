#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const vector<int> price_table = {0,1,5,8,9,10,17,17,20,24,30};
int cut_rod(const vector<int> &price_table,int n);
int cut_rod_down_to_top(const vector<int> &price_table,int n);
int cut_rod_top_down_top(const vector<int> &price_table,int n);
int main(void){
	cout << cut_rod(price_table,1) <<endl;
	cout << cut_rod(price_table,9) <<endl;
	cout << cut_rod_down_to_top(price_table,9) <<endl;
	cout << cut_rod_top_down_top(price_table,9) <<endl;
	return 0;
}

int cut_rod(const vector<int> &price_table,
						int n){
	if(n==0) return price_table[n];
	int earnings = INT_MIN;
	for(int i=1;i<=n;i++){
//		cout <<"pt: "<< price_table[i] << endl;
		earnings = max(earnings,price_table[i]+cut_rod(price_table,n-i));
	}
	return earnings;
}

int cut_rod_down_to_top(const vector<int> &price_table,
												int n){
	int r[n+1] = {0};
	int earnings = INT_MIN;
	for(int i=1;i<=n;i++){
		earnings = INT_MIN;
		for(int j=1;j<=i;j++){
			earnings = max(earnings,price_table[j]+r[i-j]);
		}
		r[i] = earnings;
	}
	return r[n];
}
int cut_rod_top_down_top_aux(const vector<int> &price_table,int n,int *r){
	if(n==0) return 0;
	if(r[n]!=INT_MIN) return r[n];
	int earnings = INT_MIN;
	for(int i=1;i<=n;i++){
		earnings = max(earnings,price_table[i]+cut_rod_top_down_top_aux(price_table,n-i,r));
	}
	return earnings;
}
int cut_rod_top_down_top(const vector<int> &price_table,
												int n){
	int r[n+1];
	for(auto &i:r){
		i = INT_MIN;
	}
	r[0]= 0;
	return cut_rod_top_down_top_aux(price_table,n,r);
}
