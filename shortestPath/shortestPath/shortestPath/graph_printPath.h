#pragma once
//µÝ¹éµÄ´òÓ¡Â·¾¶
template <typename Tv,typename Te>
void Graph<Tv,Te>::printPath(const std::vector<std::vector<int>> &pi, int i, int j){
	if (i == j)
		std::cout << j << " ";
	else if (pi[i][j] == NIL)
		std::cout << "no path from " << i << " to " << j << " !" << std::endl;
	else{
		printPath(pi, i, pi[i][j]);
		std::cout << j << " ";
	}
}