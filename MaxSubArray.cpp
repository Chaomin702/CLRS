#include <iostream>
#include <vector>
using namespace std;
using iter = vector<int>::const_iterator;
using maxArray = struct{
	iter left;
	iter right;
	int sum;
};
maxArray findMaxMidArray(const vector<int> &v, iter l, iter m, iter r);
maxArray findMaxArray(const vector<int> &v, iter l, iter r);
maxArray findMaxArrayLinear(const vector<int> &v,iter l,iter r);
int main(void){
	vector<int> v = { 1,2,-3,-4,5,6,-7,8 };
	auto M = findMaxArray(v, v.cbegin(), v.cend()-1);
	auto N = findMaxArrayLinear(v,v.cbegin(),v.cend());
	cout << M.sum << endl;
	cout << N.sum << endl;
	return 0;
}
maxArray findMaxArrayLinear(const vector<int> &v,iter l,iter r){
	maxArray S[r-l];
	S[0].left = l;
	S[0].right = l+1;
	S[0].sum = *l;
	for(auto i = l+1;i!=r;++i){
		if(S[i-l-1].sum>0){
			S[i-l].left = S[i-l-1].left;
			S[i-l].right = i+1;
			S[i-l].sum = S[i-l-1].sum + *i; 
		}else{
			S[i-l].left = i;
			S[i-l].right = i+1;
			S[i-l].sum = *i;
		}
	}
	auto *maxS = &S[0];
	for(decltype(r-l) i=1;i<r-l;++i){
		if(maxS->sum < S[i].sum){
			maxS = &S[i];
		}
	}
	return *maxS;
}
maxArray findMaxMidArray(const vector<int> &v, iter l, iter m, iter r){
	maxArray M;
	if (l == r){
		M.left = l;
		M.right = r;
		M.sum = *l;
		return M;
	}
	int lMax = 0, rMax = 0;
	int lSum = 0, rSum = 0;
//	for (auto i = m; i >= l; --i){
//		lSum += *l;
//		if (lSum>lMax){
//			lMax = lSum;
//			M.left = i;
//		}
//	}
	auto i = m;
	do{
		lSum += *i;
		if (lSum>lMax){
			lMax = lSum;
			M.left = i;
		}
		if (i != l)
			--i;
		else
			break;
	}while(1);
	i = m + 1;
	do{
		rSum += *i;
		if (rSum>rMax){
			rMax = rSum;
			M.right = i;
		}
		if (i != r)
			++i;
		else
			break;
	} while (1);
//	for (auto i = m + 1; i <= r; ++i){
//		rSum += *r;
//		if (rSum>rMax){
//			rMax = rSum;
//			M.right = i;
//		}
//	}
	M.sum = lMax + rMax;
	return M;
}

maxArray findMaxArray(const vector<int> &v, iter l, iter r){
	maxArray M;
	if (l == r){
		M.left = l;
		M.right = r;
		M.sum = *l;
		return M;
	}
	auto m = l + (r - l) / 2;
	auto M1 = findMaxArray(v, l, m);
	auto M2 = findMaxArray(v, m + 1, r);
	auto M3 = findMaxMidArray(v, l, m, r);
	maxArray *M4 = &M1;
	if (M4->sum < M2.sum)
		M4 = &M1;
	if (M4->sum < M3.sum)
		M4 = &M3;
	return *M4;
}