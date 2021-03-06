#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
class chip{
public:
	virtual	bool property()const=0;
	virtual bool checkout(const chip&)const=0;
};
class goodChip: public chip{
public:
	bool property()const{
		return true;
	}
	bool checkout(const chip& e)const{
		return e.property();
	}
};
class badChip:public chip{
public:	
	bool property()const{
		return false;
	}
	bool checkout(const chip& e)const{
		srand(time(NULL));
		return (rand()%2)?true:false;
	}
};
template <typename T>
void randomize(std::vector<T>& e){
	srand(time(NULL));
	for (auto i = e.begin(); i != e.end(); ++i){
		std::swap(*i, *(i + rand() % (e.end() - i)));
	}
}
std::ostream& operator <<(std::ostream& os,const chip& c);
template <typename T>
void print(const std::vector<T>& v){
	for (auto i : v)
		std::cout << *i << " ";
	std::cout << std::endl;
}
chip* chip_test(std::vector<chip*> &v);