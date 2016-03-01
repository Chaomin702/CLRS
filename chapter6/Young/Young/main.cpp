#include <iostream>
#include "young.h"

using namespace std;

int main(void){
	Young Y(4, 4);
	vector<int> v = { 4, 5, 1, 2, 3, 6, 7, 9, 8, 10 };
	Y.insert(1);
	Y.insert(2);
	Y.insert(3);
	Y.insert(4);
	Y.insert(5);
	Y.insert(6);
	Y.insert(7);
	cout << Y.extractMin() << endl;
	cout << Y.find(5) << endl;
	cout << Y.find(12) << endl;
	vector<int> u = sort(v);
	for (auto i : u)
		cout << i << " ";
	cout << endl;
	return 0;
}