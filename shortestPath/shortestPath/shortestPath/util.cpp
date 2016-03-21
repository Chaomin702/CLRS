#include "util.h"
/******************************************************************************************
* 从命令行（文件重定向）中导入图
******************************************************************************************/
void importGraph(GraphMatrix<char, int> & g) {
	int n; scanf_s("%d\n", &n); 
	for (int i = 0; i < n; i++) { //插入v个顶点
		char vertex; scanf_s("%c", &vertex);
		g.insert(vertex);
	}
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++) { //插入边
		int edge; scanf_s("%d", &edge);
		if (0 > edge) continue;
		g.insert(edge, edge, i, j);
	}
}
//将路径存入向量
void pathPush(const std::vector<std::vector<int>> &pi, int i, int j, std::vector<int> &v){
	if (i == j)
		//v.push_back(i);
		return;
	else if (pi[i][j] == NIL)
		std::cout << "no path from " << i << " to " << j << " !" << std::endl;
	else{
		v.push_back(j);
		pathPush(pi, i, pi[i][j], v);
	}

}
//向量唯一化
template <typename T>
void uniquify(std::vector<T> &v){

}