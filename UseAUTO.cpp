#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
	string str = "Hi, my name is C++.";
	decltype(str.size()) count = 0;
	for(auto c: str){
		if(ispunct(c))
			++count;
	}
	for(auto &c: str){
		c = toupper(c);
	}
	cout << count <<endl;
	cout << str <<endl;
	return 0;
}