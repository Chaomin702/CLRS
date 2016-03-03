#include <iostream>
#include "chip.h"

using namespace std;

int main(){
	vector<chip*> v;
	//insert 10 good chips and 9 bad chips
	for(int i=0;i<10;i++){
		chip *p = new goodChip();
		v.push_back(p);
	}
	for(int i=0;i<9;i++){
		chip *p = new badChip();
		v.push_back(p);
	}
	print(v);
	//find a good chip if print 1
	chip *p = chip_test(v);
	cout << p->property()<<endl;
	return 0;
}