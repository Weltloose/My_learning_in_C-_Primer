#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class NoDerived final { /* */ }; // NoDerived can't be a base class

class Quote{
public:
	Quote() = default;
	Quote(const string &book, double sales_price): bookNo(book), price(sales_price){}
	Quote(const Quote &) = default;

	string isbn() const{return bookNo;}
	virtual double net_price(int n) const{return n * price;}
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote: public Quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double sales_price, double d, int l): Quote(book, sales_price), discount(d), lp(l){}
	double net_price(int n) const override{
		if(n < lp) return price * n;
		else return price * n * (1 - discount);
	}
	// double net_price(int) const = 0;   //can't create an object with pure virtual functions

private:
	double discount = 0.0;
	int lp = 0;
};

void print_total(const Quote &q, int n){
	cout << q.net_price(n) << endl;
}

int main(){
	Bulk_quote b("xiaoming", 30, 0.1, 10);
	Quote &a = b;
	Quote *c = &b;
	print_total(a, 30);
	print_total(*c, 30);
	Quote d(b);   //Can construct the base class according to the derived class. Assignment too.
	print_total(d, 20);
	cout << c->Quote::net_price(30) << endl;  //calls the Quote version of net_price regardless of the type of the object to which c actually points
}