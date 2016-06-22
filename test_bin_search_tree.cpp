#include <iostream>
#include <bin_search_tree.h>

int main(){
	bin_tree t;
	t.insert(4);
	t.insert(3);
	t.insert(1);
	t.insert(2);
	t.insert(6);
	t.insert(5);
	t.insert(7);
	t.inorder_traver();
	return 0;
}