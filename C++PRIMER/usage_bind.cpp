#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;
using namespace std::placeholders;

bool check(int n, int sz){return n > sz;};

bool isSmaller(int a, int b){return a < b;}

ostream &print(ostream &os, int n, char c){return os << n << c;}

int main(){
	vector<int> v{1, -1, 2, -2, 5, 6};
	int sz = 3;
	cout << *find_if(v.begin(), v.end(), bind(check, _1, sz)) << endl;
	sort(v.begin(), v.end(), bind(isSmaller, _2, _1));  //using bind to reorder the arguments
	for(auto i : v) cout << i << ' ';
	cout << endl;
	for_each(v.begin(), v.end(), bind(print, ref(cout), _1, '\t'));  //bind using reference. also cref representing const reference.
	
}