#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Sales_data{
public:
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);
	// other members as before
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main(){
	std::vector<Sales_data> v;
	v.emplace_back("hello", 11, 3.14);
	v.push_back("hello", 11, 3.14);
}