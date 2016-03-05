#include <iostream>
#include "single_list.h"

using namespace std;

int main(){
	list<int> L;
	L.insert(1);
	L.print();
	L.insert(2);
	L.insert(4);
	L.insert(6);
	L.print();
	L.reverse();
	L.print();
	return 0;
}