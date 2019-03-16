#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <memory>

using namespace std;

class Test{
private:
	string *str_ptr;
	int *use_count;
public:
	Test():str_ptr(NULL), use_count(NULL){}
	Test(const string &str): str_ptr(new string (str)), use_count(new int(1)){}
	Test(const Test &t): str_ptr(t.str_ptr), use_count(t.use_count){++*use_count;}
	Test& operator=(const Test&t){
		--*use_count;
		++*t.use_count;
		if(*use_count == 0){
			delete use_count;
			delete str_ptr;
		}
		use_count = t.use_count;
		str_ptr = t.str_ptr;
		return *this;
	}
	~Test(){
		if(--*use_count == 0){
			delete use_count;
			delete str_ptr;
		}
	}
	void change(const string &str){
		*str_ptr = str;
	}
	void print() const{
		if(str_ptr != NULL)
			cout << *str_ptr << *use_count << endl; 
	}
	
};

int main(){
	Test t1("hello");
	Test t2("areyouok");
	Test m1(t1), m2(t2);
	m1 = t2;
	m1.print();
	t1 = t2;
	t1.change("not");
	t1.print();
}