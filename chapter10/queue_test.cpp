#include <iostream>
#include "queue.h"

using namespace std;

int main(){
	queue<int> Q;
	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(4);
	Q.enqueue(5);
	Q.enqueue(6);
	Q.print();
	Q.dequeue();
	Q.print();
	return 0;
}