#include "chip.h"
std::ostream& operator <<(std::ostream& os,const chip& c){
	os << c.property() <<" ";
	return os;
}
chip* chip_test(std::vector<chip*> &v){
	if(v.size()<2) return v[0];
	std::vector<chip*> u;
	chip *p = nullptr;
	if(v.size()%2!=0){
		p = *(v.end()-1);
		v.pop_back();
	}
	//when i says i+1 is good and i+1 say i is good,
	//insert i into u
	for(auto i=v.begin();i!=v.end();i=i+2){
		if((*i)->checkout(**(i+1))==true &&
			(*(i+1))->checkout(**i)==true){
			u.push_back(*i);
		}
	}
	//if both the size of v and u are odd,
	//insert v[end] into u 
	if(p!=nullptr && u.size()%2==0)
		u.push_back(p);
	randomize(u);
	return chip_test(u);
}