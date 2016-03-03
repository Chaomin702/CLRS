#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
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
void randomize(vector<T>& e);
ostream& operator <<(ostream& os,const chip& c);
template <typename T>
void print(const vector<T>& v);
chip* chip_test(vector<chip*> &v);
int main(){
	goodChip g;
	badChip b;
	cout << g.checkout(g) << endl;
	cout << b.checkout(g) << endl;
	vector<chip*> v;
	for(int i=0;i<10;i++){
		chip *p = new goodChip();
		v.push_back(p);
	}
	for(int i=0;i<9;i++){
		chip *p = new badChip();
		v.push_back(p);
	}
	print(v);
	randomize(v);
	print(v);
	chip *p = chip_test(v);
	cout << p->property()<<endl;
//	print(u);
//	v.push_back(badChip());
//	v.insert(v.end(),u.begin(),u.end());
	return 0;
}
