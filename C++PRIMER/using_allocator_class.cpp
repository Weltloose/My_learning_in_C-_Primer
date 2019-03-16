#include <iostream>
#include <cstring>
#include <memory>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Test{
private:
	int a, b;
public:
	Test():a(1), b(2){}
	Test(int n, int m): a(n), b(m){}
	Test(int n): a(n), b(n){}
	~Test(){}
	void print(){cout << a << b << endl;}
};

int main(){
	int n = 10;
	allocator<Test> a;
	auto const p = a.allocate(n);  //allocated memory for n strings.
	p->print();   //output: 00. Didn't use the default constructor.
	auto q = p;
	a.construct(q++, 3);
	a.construct(q++, 2, 3);
	for(auto i = p; i != q; i++)
		i->print();
	//after used, must destroy
	while(q != p)
		a.destroy(--q);  //We may destroy only elements that are actually constructed.
	//Once the elements have been destroyed, we can either reuse the memory 
	//to hold other strings or return the memory to the system.
	a.deallocate(p, n); //free the memory
	//algorithms for allocator class.
	vector<string> v{"a", "b", "c"};
	allocator<string> all;
	auto const pt = all.allocate(20);
	auto qt = uninitialized_copy(v.cbegin(), v.cend(), pt);
	for(auto i = pt; i != qt; i++)
		cout << *i << endl;
	/*
	qt = uninitialized_copy_n(v.cbegin(), 2, qt);
	for(auto i = pt; i != qt; i++)
		cout << *i << endl;
	*/
	qt = uninitialized_fill_n(qt, 3, "m");
	for(auto i = pt; i != qt; i++)
		cout << *i << endl;
}