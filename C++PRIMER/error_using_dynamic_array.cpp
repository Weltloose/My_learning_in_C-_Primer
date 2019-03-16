#include <iostream>

using namespace std;

int main(){
	int *p = new int [10];
	for(auto i : p) cout << i << ' ';
}