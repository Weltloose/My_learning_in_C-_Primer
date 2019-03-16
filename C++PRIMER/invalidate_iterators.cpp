#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <list>
#include <exception>

using namespace std;

int main(){
	
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> v(ia, ia + 11);
	auto i = v.begin() + 2;
	v.resize(25);
	*i = 10;
	
	cout << "The remaining vector: ";
	for(auto i : v) cout << i << ' ';
}