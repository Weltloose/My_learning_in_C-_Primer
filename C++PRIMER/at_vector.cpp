#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <list>
#include <exception>

using namespace std;

int main(){
	//cout << "hello " << endl;
	
	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
	 
	try{
		auto &i = v.at(11);
	} catch(out_of_range &ec){ cout << ec.what() << endl;}
	
	for(auto i : v) cout << i << ' ';
}