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
	Test &operator ++ ();  //prefix
	Test operator ++ (int); //postfix  The sole purpose of taking a parament is to distinguish a postfix function from the prefix version.
	void print(){cout << data << endl;}
};

Test &Test::operator ++ (){
	++data;
	return *this;	
}

Test Test::operator ++ (int){
	Test temp(*this);
	++*this;
	return temp;
}

int main(){
	Test t1(3);
	t1 ++ ;
	t1.print();
}