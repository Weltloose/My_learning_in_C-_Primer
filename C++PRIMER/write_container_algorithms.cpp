#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <list>
#include <exception>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;


int main(){
	vector<int> v(10, 0);
	fill(v.begin(), v.begin() + v.size() / 2, 1);
	for(auto i : v) cout << i << ' ';
	cout << endl;

	fill_n(v.begin() + 1, 3, 2);  //fill 3 elements starting from v.begin() + 1
	for(auto i : v) cout << i << ' ';
	cout << endl;

	auto i = back_inserter(v);  //returns an insert iterator
	*i = 10;  //When we assign through that iterator, the assignment calls push_back to add an element with the given value
	for(auto i : v) cout << i << ' ';
	cout << endl;

	vector<int> vt;
	fill_n(back_inserter(vt), 10, 10);
	for(auto i : vt) cout << i << ' ';
	cout << endl;

	int a1[] = {0,1,2,3,4,5,6,7,8,9};
	int a2[sizeof(a1) / sizeof(*a1)];
	copy(begin(a1), end(a1), a2);
	for(int i = 0; i < 10; i++) cout << a2[i] << ' ';
	cout << endl;

	replace(v.begin(), v.end(), 0, 3);
	for(auto i : v) cout << i << ' ';
	cout << endl;

	list<int> l;
	replace_copy(v.begin(), v.end(), back_inserter(l), 1, 0);   //didn't change v
	for(auto i : l) cout << i << ' ';
	cout << endl;
}