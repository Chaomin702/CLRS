#include <iostream>
#include "stack.h"
using namespace std;
int main(void){
	stack<int> S;
	S.push(1);
	S.push(2);
	S.push(3);
	cout << S.top() << endl;
	S.pop();
	cout << S.top() << endl;
	return 0;
}