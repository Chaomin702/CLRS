#include <iostream>
#include "chip.h"

using namespace std;
int main(){
	goodChip g;
	badChip b;
	cout << g.checkout(g) << endl;
	cout << b.checkout(g) << endl;
	vector<chip*> v;
	for(int i=0;i<10;i++){
		chip *p = new goodChip();
		v.push_back(p);
	}
	for(int i=0;i<9;i++){
		chip *p = new badChip();
		v.push_back(p);
	}
	print(v);
	randomize(v);
	print(v);
	chip *p = chip_test(v);
	cout << p->property()<<endl;
	return 0;
}