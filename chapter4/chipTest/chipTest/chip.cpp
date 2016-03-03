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
	for(auto i=v.begin();i!=v.end();i=i+2){
		if((*i)->checkout(**(i+1))==true &&
			(*(i+1))->checkout(**i)==true){
			u.push_back(*i);
		}
	}
	if(p!=nullptr && u.size()%2==0)
		u.push_back(p);
	randomize(u);
	return chip_test(u);
}