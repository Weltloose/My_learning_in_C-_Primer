#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(){
	//cout << "hello " << endl;
	
	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
	auto i = v.begin();
	int n;
	while(cin >> n){
		i = v.insert(i, n);
	}
	for(auto i : v) cout << i << ' ';
	cout << endl;
}