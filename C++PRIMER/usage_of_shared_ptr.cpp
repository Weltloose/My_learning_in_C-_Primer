#include <iostream>
#include <vector>
#include <memory>   // library needed

using namespace std;

int main(){
	int a = 2, b = 1;
	shared_ptr<int> p1;
	p1 = make_shared<int>(a);
	//shared_ptr<int> pn(&a); //error.
	shared_ptr<int> pn(new int (10));
	auto p2 = make_shared<int>(b);
	auto p3 = p1;
	auto p4(p2);
	p1 = p2;
	swap(p3, p4);
	int *t = p1.get();   //returns the pointer of shared_ptr
	bool l = p4.unique();  //returns true iff use_count is 1
	int n = p2.use_count();
	//int n1 = p4.use_count();
	cout << *p1 << ' ' << *p2 << ' ' << *p3 << ' ' << *p4 << ' ' << *t << endl;  
	cout << l << ' ' << n << endl;

/*<-------------------------------------------------------->*/
	shared_ptr<int> p(new int(30));  //From int * to shared_ptr<int>
	p.reset();   //makes q null;
	//p = new int(1024); // error: cannot assign a pointer to a shared_ptr 
	p.reset(new int(1024)); // ok: p points to a new object

}