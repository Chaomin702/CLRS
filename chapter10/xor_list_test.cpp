#include <iostream>
#include "xor_list.h"

using namespace std;

int main(void){

	list<int> L;
	L.print();
	L.insert(1);
	L.insert(2);
	L.insert(3);
	L.insert(5);
	cout<<	L.search(3)<<endl;
	cout << L.search(6) << endl;
	L.print();
	L.del(2);
	L.print();
	L.del(1);
	L.print();
	L.del(6);
	L.print();
	return 0;
}