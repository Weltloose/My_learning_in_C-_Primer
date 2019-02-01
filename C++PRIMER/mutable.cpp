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
	int b = 2; 
	// error: auto f = [b](int a) -> int {b++; return a + b;};
	auto f = [b](int a) mutable -> int {b++; return a + b;};
	cout << f(1) << endl;
}