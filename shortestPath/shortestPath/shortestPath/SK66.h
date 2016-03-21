#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "GraphMartix.h"
//��ָ���㼯��S���ҳ�����ڵ�t����Ľڵ�s������ֵΪ�ڵ�s��S�е�����
int shortestPathCostInSpecificNodes(int &s, int t, int &cost, const std::vector<int> &S, const std::vector<std::vector<int>> &D){
	int n = S.size();
	int minCost = INT_MAX;
	int minIndex = 0;
	int j = 0;
	for (int i = 0; i < n; ++i){
		int v = S[i];
		if (minCost>D[v][t]){
			minCost = D[v][t];
			minIndex = v;
			j = i;
		}
	}
	s = minIndex;
	cost = minCost;
	return j;
}

//SK66����
template <typename Tv, typename Te>
void SK66(GraphMatrix<Tv, Te>&G, int s, int t, std::vector<int> S){
	//����������ͼ��V��V U s��V U t������V��ָ���ڵ㼯
	GraphMatrix<Tv, Te> V(G), Vs(G), Vt(G);
	V.setUnreachable(s);
	V.setUnreachable(t);
	Vs.setUnreachable(t);
	Vt.setUnreachable(s);
	//SK66��ʼ��
	std::vector<vector<int>> V_D, Vs_D, Vt_D, V_pi, Vs_pi, Vt_pi;
	V.floyd(V_D, V_pi);
	Vs.floyd(Vs_D, Vs_pi);
	Vt.floyd(Vt_D, Vt_pi);

	std::vector<int> costVec, preVec;	//����������ǰ������
	//cost: r->...->p
	int r = 0, p = t, cost = 0;
	int j = 0;
	j = shortestPathCostInSpecificNodes(r, p, cost, S, Vt_D);	//Ѱ�Ҿ���t�����ָ���ڵ�
	std::swap(S[j], S[S.size() - 1]);
	S.pop_back();
	costVec.push_back(cost);
	pathPush(Vt_pi, r, p, preVec);
	int z = S.size();
	for (int i = 1; i <= z; i++){
		p = r;
		j = shortestPathCostInSpecificNodes(r, p, cost, S, V_D);	//Ѱ�Ҿ���ǰ���������ָ���ڵ�
		std::swap(S[j], S[S.size() - 1]);
		S.pop_back();
		costVec.push_back(cost);
		pathPush(V_pi, r, p, preVec);
	}
	p = r;
	costVec.push_back(Vs_D[s][p]);	//�������
	pathPush(Vs_pi, s, p, preVec);
	preVec.push_back(s);
	//��ӡ���
	for (auto i = preVec.crbegin(); i != preVec.crend() - 1; ++i)
		std::cout << *i << "->";
	std::cout << preVec.front() << endl;
	int weightSum = 0;
	for (auto &i : costVec)
		weightSum += i;
	std::cout << "sum of weight: " << weightSum << endl;
}