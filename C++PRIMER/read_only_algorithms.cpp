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
	vector<int> v{1, 2, 1, 2, 1, 3, 1, 1, 5};
	auto i = find(v.cbegin(), v.cend(), 6);
	cout << (i == v.cend() ? "Doesn't exist" : "Exist") << endl;
	cout << accumulate(v.cbegin(), v.cend(), 0) << endl;  //the third augument is to initial sum; 
	cout << count(v.cbegin(), v.cend(), 1) << endl;

	vector<string> s{"abc", "def", "ghi"};
	list<const char *> l{"abc", "def", "ghi"};
	cout << equal(s.cbegin(), s.cend(), l.cbegin()) << endl; // pretermit l's size >= s's size.
	
}