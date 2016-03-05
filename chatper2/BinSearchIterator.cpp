#include <iostream>
#include <vector>

using namespace std;
vector<int>::const_iterator BinSearch(const vector<int> &v,int t);
int main(void){
	vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	cout << *BinSearch(v,8) << endl;
	return 0;
}

vector<int>::const_iterator BinSearch(const vector<int> &v,int t){
	auto begin = v.begin(),end = v.end();
	auto mid = begin + (end-begin)/2;
	while(begin!=end && *mid!=t){
		cout << *begin <<" "<<*mid<<" "<<*end<<endl;
		if(*mid > t)
			end = mid;
		else
			begin = mid + 1;
		mid = begin + (end-begin)/2;
	}
	return mid;
}