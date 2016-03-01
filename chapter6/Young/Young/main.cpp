#include <iostream>
#include "young.h"

using namespace std;

int main(void){
	Young Y(4, 4);
	Y.insert(4, 4, 1);
	Y.insert(4, 4, 2);
	Y.insert(4, 4, 3);
	Y.insert(4, 4, 4);
	return 0;
}