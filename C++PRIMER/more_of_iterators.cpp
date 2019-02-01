#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <iterator>

using namespace std;
using namespace std::placeholders;

ostream &print(ostream &os, int n){
	return os << n << ' ';
}

class Sales_items{
public:

	friend ostream & operator << (ostream &os, const Sales_items &);
	friend istream & operator >> (istream &is, Sales_items &);
	Sales_items &operator += (const Sales_items &t);
private:
	int sales;
};

Sales_items & Sales_items::operator += (const Sales_items &t){
	sales += t.sales;
	return *this;
}

ostream & operator << (ostream &os, const Sales_items &t){
	return os << t.sales;
}
istream & operator >> (istream &is, Sales_items &t){
	return is >> t.sales;
}

int main(){
	vector<int> v{1, 0, -1, 2, -6, 5, 33, -10, 10};
	list<int> l;
	unique_copy(v.begin(), v.end(), back_inserter(l));
	// unique_copy(v.begin(), v.end(), inserter(l, l.end()));
	// unique_copy(v.begin(), v.end(), front_inserter(l));

	for_each(l.begin(), l.end(), bind(print, ref(cout), _1));
	cout << endl;

	/*
	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof_iter;
	// vector<int> vt;
	// while(in_iter != eof_iter){
	// 	vt.push_back(*in_iter++);
	// }
	vector<int> vt(in_iter, eof_iter);

	ostream_iterator<int> outer(cout, " ");
	// for(auto i : vt) *outer++ = i;
	// cout << endl;
	copy(vt.begin(), vt.end(), outer);
	cout << endl;
	*/

	istream_iterator<Sales_items> is(cin), eof;  //The class should overload the operator <<, >>
	ostream_iterator<Sales_items> os(cout, " ");  //The second argument must be string ,not character; 
	Sales_items sum = *is++;
	while(is != eof){
		sum += *is++;
	}
	os = sum;
	
}