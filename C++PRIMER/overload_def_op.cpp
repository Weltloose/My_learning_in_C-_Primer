#include <iostream>
#include <string>

using namespace  std;

class Test{
private:
	int data;
public:
	Test() = default;
	Test(int a): data(a) {}
	Test(const Test &t): data(t.data){}
	int &operator *() ;
	int *operator -> () ;
	void print(){cout << data << endl;}
};

int &Test::operator *() {
	return data;
}

int *Test::operator -> () {
	return & this->operator *();
}

int main(){
	Test t1(3);
	int &a = *t1;
	a = 2;
	t1.print();
}