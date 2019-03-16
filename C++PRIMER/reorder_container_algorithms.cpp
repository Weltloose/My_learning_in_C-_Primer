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
	//vector<int> v{1, 2, 3, 4, 5};
	vector<int> vec; list<int> lst{1, 2, 7, 4, 5};
	vec.resize(10);
	copy(lst.cbegin(), lst.cend(), vec.begin());
	for(auto i : vec) cout << i << ' ';
	cout << endl;

	vector<int> v{1, 2, 7, 4, 5, 1, 7};
	sort(v.begin(), v.end());
	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
	for(auto i : v) cout << i << ' ';
	cout << endl;
}