#include <iostream>
#include <vector>
#include "Exercise6-5-9.h"
#include "gtest/gtest.h"  
#include <tchar.h>   //若不包含，main中参数会报错

using namespace std;
bool compare(const vector<Node> &A, const vector<Node> &B){
	if (A.size() != B.size()) return false;
	for (int i = 0; i < A.size(); i++){
		if (A[i].value != B[i].value)
			return false;
	}
	return true;
}
TEST(fun, case1)
{
	vector<vector<Node>> v;
	vector<Node> v1, v2, v3, v4;
	for (int i = 12; i>0; i -= 3){
		v1.push_back(Node(i, 0));
	}
	for (int i = 11; i>0; i -= 3){
		v2.push_back(Node(i, 1));
	}
	for (int i = 10; i>0; i -= 3){
		v3.push_back(Node(i, 2));
	}
	for (int i = 12; i > 0; --i){
		v4.push_back(Node(i, 3));
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	vector<Node> e = kListsMerge(v);
	EXPECT_TRUE(compare(v4,e));
}
int _tmain(int argc, _TCHAR* argv[]){
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("PAUSE");
	return 0;
}