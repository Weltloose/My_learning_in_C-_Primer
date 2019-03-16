#include <iostream>
#include <vector>
#include <string>
#include <memory>   // library needed

using namespace std;

int main(){
	unique_ptr<string> p1(new string("hello"));
	//unique_ptr<string> p2(p1); //error. no copy of unique_ptr;
	//unique_ptr<string> p2 = p1; //error. no assign of unique_ptr;
	unique_ptr<string> p2(p1.release());
	unique_ptr<string> p3(new string("google"));
	p2.reset(p3.release());
	cout << *p2;
	auto p = p2.release();
	delete p;
}