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
//void Young::Youngify(int i, int j){
//	if (i > width || j > length) return;
//	IndexYoung r = right(i, j), d = down(i, j);
//	IndexYoung largest = IndexYoung(i, j);
//	if (verify(r) && _elem[i][j] < _elem[r.i][r.j])
//		largest = r;
//	if (verify(d) && _elem[largest.i][largest.j] < _elem[d.i][d.j])
//		largest = d;
//	if (largest != _elem[i][j]){
//		std::swap(_elem[largest.i][largest.j], _elem[i][j]);
//		Youngify(largest.i, largest.j);
//	}
//}
void Young::Youngify(IndexYoung index){
	if (!verify(index)) return;
	IndexYoung r = right(index), d = down(index), smallest = index;
	while (true){
		if (verify(r) && get(r) < get(smallest))
			smallest = r;
		if (verify(d) && get(d) < get(smallest))
			smallest = d;
		if (smallest != index){
			std::swap(get(smallest), get(index));
			index = smallest;
			r = right(index);
			d = down(index);
		}
		else{
			break;
		}
	}
}
void Young::insert(const int& e){
	if (get(width, length) < INT_MAX) return; //overflow
	int i = width, j = length;
	IndexYoung l = left(i, j), u = up(i, j),c = IndexYoung(i,j);
	IndexYoung m = c;
	set(m, e);
	while (true){
		if (verify(l) && get(l) > get(m))
			m = l;
		if (verify(u) && get(u) > get(m))
			m = u;
		if (m != c){
			std::swap(get(m), get(c));
			c = m;
			l = left(c);
			u = up(c);
		}
		else{
			break;
		}
	}
}
int Young::extractMin(){
	int bak = get(1, 1);
	set(1, 1, INT_MAX);
	Youngify(1, 1);
	return bak;
}
bool Young::find(const int&e){
	IndexYoung c = IndexYoung(width, 1);
	IndexYoung u = up(c), r = right(c);
	while (true){
		if (get(c) < e && verify(r))
			c = r;
		else if (get(c) > e && verify(u))
			c = u;
		else
			break;
		u = up(c);
		r = right(c);
	}
	if (get(c) == e) return true;
	else return false;
}
std::vector<int> sort(const std::vector<int>& v){
	Young Y(4, 4);
	std::vector<int> u;
	for (auto i : v)
		Y.insert(i);
	int m = Y.extractMin();
	while (m != INT_MAX){
		u.push_back(m);
		m = Y.extractMin();
	}
	return u;
}