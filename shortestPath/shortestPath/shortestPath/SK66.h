#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "GraphMartix.h"
//从指定点集合S中找出距离节点t最近的节点s，返回值为节点s在S中的索引
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

//SK66方法
template <typename Tv, typename Te>
void SK66(GraphMatrix<Tv, Te>&G, int s, int t, std::vector<int> S){
	//建立三个子图，V、V U s、V U t，其中V是指定节点集
	GraphMatrix<Tv, Te> V(G), Vs(G), Vt(G);
	V.setUnreachable(s);
	V.setUnreachable(t);
	Vs.setUnreachable(t);
	Vt.setUnreachable(s);
	//SK66初始化
	std::vector<vector<int>> V_D, Vs_D, Vt_D, V_pi, Vs_pi, Vt_pi;
	V.floyd(V_D, V_pi);
	Vs.floyd(Vs_D, Vs_pi);
	Vt.floyd(Vt_D, Vt_pi);

	std::vector<int> costVec, preVec;	//代价向量，前驱向量
	//cost: r->...->p
	int r = 0, p = t, cost = 0;
	int j = 0;
	j = shortestPathCostInSpecificNodes(r, p, cost, S, Vt_D);	//寻找距离t最近的指定节点
	std::swap(S[j], S[S.size() - 1]);
	S.pop_back();
	costVec.push_back(cost);
	pathPush(Vt_pi, r, p, preVec);
	int z = S.size();
	for (int i = 1; i <= z; i++){
		p = r;
		j = shortestPathCostInSpecificNodes(r, p, cost, S, V_D);	//寻找距离前驱点最近的指定节点
		std::swap(S[j], S[S.size() - 1]);
		S.pop_back();
		costVec.push_back(cost);
		pathPush(V_pi, r, p, preVec);
	}
	p = r;
	costVec.push_back(Vs_D[s][p]);	//加入起点
	pathPush(Vs_pi, s, p, preVec);
	preVec.push_back(s);
	//打印结果
	for (auto i = preVec.crbegin(); i != preVec.crend() - 1; ++i)
		std::cout << *i << "->";
	std::cout << preVec.front() << endl;
	int weightSum = 0;
	for (auto &i : costVec)
		weightSum += i;
	std::cout << "sum of weight: " << weightSum << endl;
}