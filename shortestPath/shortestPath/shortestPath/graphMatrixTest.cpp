#include <iostream>
#include <algorithm>
#include "GraphMartix.h"
#include "SK66.h"
#include "util.h"
#pragma warning(disable:4996) 
using namespace std;
int main(void){
	GraphMatrix<int, int> G;
	//����ڵ�
	G.insert(0);
	G.insert(1);
	G.insert(2);
	G.insert(3);
	//�����
	G.insert(0, 1, 0, 1);
	G.insert(2, 1, 0, 3);
	G.insert(1, 2, 0, 2);
	G.insert(3, 3, 2, 1);
	G.insert(4, 1, 3, 1);
	G.insert(5, 1, 2, 3);
	G.insert(6, 1, 3, 2);
	//ָ���ڵ㼯
	vector<int> S = { 2, 3 };
	SK66(G, 0, 1, S);
	cout << endl;

	
	GraphMatrix<char, int> g;
	freopen("input.txt", "r", stdin); //IO�ض���
	importGraph(g);		//���ļ��е���ͼ
	vector<int> T = { 4, 7, 9 };
	SK66(g, 0, 1, T);
	return 0;
}

