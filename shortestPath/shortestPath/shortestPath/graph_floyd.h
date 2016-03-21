#pragma once
template <typename Tv,typename Te>
void Graph<Tv, Te>::floyd(std::vector<std::vector<int>> &v,
	std::vector<std::vector<int>> &pi){
	using matrix = std::vector<std::vector<int>>;
	v.resize(n);
	for (auto &i : v)
		i.resize(n);
	adjMatrix(v);
	matrix u = v;

	pi.resize(n);
	for (auto &i : pi)
		i.resize(n);
	preMatrix(pi);
	matrix ppi = pi;
	for (int k = 0; k < n; k++){
		v = u;
		pi = ppi;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (v[i][j] <= v[i][k] + v[k][j]){
					u[i][j] = v[i][j];
					ppi[i][j] = pi[i][j];
				}
				else{
					u[i][j] = v[i][k] + v[k][j];
					ppi[i][j] = pi[k][j];
				}
			}
		}
	}
	v = u;
	pi = ppi;
}