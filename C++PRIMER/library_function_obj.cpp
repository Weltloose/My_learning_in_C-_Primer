#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace  std;
using namespace	 std::placeholders;

int main(){
	vector<int> v{1, 2, 3};
	transform(v.begin(), v.end(), v.begin(), bind(multiplies<int>(), _1, 2));
	for(auto i : v) cout << i << ' ';
	cout << endl;
}