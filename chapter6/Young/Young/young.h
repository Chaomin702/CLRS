#pragma once
#include <climits>
#include <algorithm>
#include <vector>
#define YOUNG_SIZE 100
struct IndexYoung{
	int i;
	int j;
	IndexYoung(int ii = 0, int jj = 0) :i(ii), j(jj){}
	bool operator ==(const IndexYoung& e){ return (i == e.i) && (j == e.j); }
	bool operator !=(const IndexYoung& e){ return !(*this == e); }
};
class Young{
public:
	Young(int l , int w );
	void Youngify(IndexYoung);
	void Youngify(int i, int j){ Youngify(IndexYoung(i, j)); }
	IndexYoung down(int i, int j){ return IndexYoung(i + 1, j); }
	IndexYoung down(const IndexYoung& index){ return IndexYoung(index.i + 1, index.j); }
	IndexYoung up(int i, int j){ return IndexYoung(i - 1, j); }
	IndexYoung up(const IndexYoung& index){ return IndexYoung(index.i - 1, index.j); }
	IndexYoung left(int i, int j){ return IndexYoung(i, j - 1); }
	IndexYoung left(const IndexYoung& index){ return IndexYoung(index.i, index.j - 1); }
	IndexYoung right(int i, int j){ return IndexYoung(i, j + 1); }
	IndexYoung right(const IndexYoung& index){ return IndexYoung(index.i, index.j + 1); }
	bool verify(const IndexYoung& e);
	int& get(const IndexYoung& e){ return  _elem[e.i][e.j]; }
	int& get(int i, int j){ return get(IndexYoung(i, j)); }
	void set(const IndexYoung& e, const int& data){ _elem[e.i][e.j] = data; }
	void set(int i, int j, const int& data){ set(IndexYoung(i, j), data); }
	void insert(const int& e);
	int extractMin();
	bool find(const int& e);
	
private:
	int _elem[YOUNG_SIZE + 1][YOUNG_SIZE + 1];
	int length;
	int width;
};
std::vector<int> sort(const std::vector<int>& v);