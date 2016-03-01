#pragma once
#include <climits>
#include <algorithm>
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
	void Youngify(int i, int j);
	IndexYoung down(int i, int j){ return IndexYoung(i + 1, j); }
	IndexYoung up(int i, int j){ return IndexYoung(i - 1, j); }
	IndexYoung left(int i, int j){ return IndexYoung(i, j - 1); }
	IndexYoung right(int i, int j){ return IndexYoung(i, j + 1); }
	bool verify(const IndexYoung& e);
	int& get(const IndexYoung& e){ return  _elem[e.i][e.j]; }
	void insert(int i, int j, const int& e);
private:
	int _elem[YOUNG_SIZE + 1][YOUNG_SIZE + 1];
	int length;
	int width;
};