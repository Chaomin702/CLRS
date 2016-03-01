#include "young.h"
Young::Young(int l = 0, int w = 0) :length(l), width(w){
	for (int i = 1; i <= w; i++){
		for (int j = 1; j <= l; j++){
			_elem[i][j] = INT_MAX;
		}
	}
}
bool Young::verify(const IndexYoung& e){
	return e.i > 0 && e.j > 0 && e.i <= width && e.j <= length;
}
void Young::Youngify(int i, int j){
	if (i > width || j > length) return;
	IndexYoung r = right(i, j), d = down(i, j);
	IndexYoung largest = IndexYoung(i, j);
	if (verify(r) && _elem[i][j] < _elem[r.i][r.j])
		largest = r;
	if (verify(d) && _elem[largest.i][largest.j] < _elem[d.i][d.j])
		largest = d;
	if (largest != _elem[i][j]){
		std::swap(_elem[largest.i][largest.j], _elem[i][j]);
		Youngify(largest.i, largest.j);
	}
}
void Young::insert(int i, int j, const int& e){
	if (!verify(IndexYoung(i, j))) return;
	IndexYoung l = left(i, j), u = up(i, j),c = IndexYoung(i,j);
	_elem[i][j] = e;
	while ((verify(l) || verify(u)) && (get(l) > get(c) || get(u) > get(c))){
		while ((verify(l) && (get(l) > get(c)))){
			std::swap(get(l), get(c));
			c = l;
			l = left(l.i, l.j);
		}
		while ((verify(u) && (get(u) > get(c)))){
			std::swap(get(u), get(c));
			c = u;
			u = left(u.i, u.j);
		}
	}
}