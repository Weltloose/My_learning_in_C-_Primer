#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace  std;

class Test{
public:
	Test(ostream &o = cout, char ch = ' '): os(cout), c(ch){}
	void operator ()(const string &s){os << s << c;}
private:
	ostream &os;
	char c;
};

int main(){
	Test t;
	t("hello");
	vector<string> v{"a", "b", "c"};
	for_each(v.cbegin(), v.cend(), Test(cout, '*'));
}