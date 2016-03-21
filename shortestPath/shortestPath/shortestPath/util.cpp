#include "util.h"
/******************************************************************************************
* �������У��ļ��ض����е���ͼ
******************************************************************************************/
void importGraph(GraphMatrix<char, int> & g) {
	int n; scanf_s("%d\n", &n); 
	for (int i = 0; i < n; i++) { //����v������
		char vertex; scanf_s("%c", &vertex);
		g.insert(vertex);
	}
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++) { //�����
		int edge; scanf_s("%d", &edge);
		if (0 > edge) continue;
		g.insert(edge, edge, i, j);
	}
}
//��·����������
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
//����Ψһ��
template <typename T>
void uniquify(std::vector<T> &v){

}