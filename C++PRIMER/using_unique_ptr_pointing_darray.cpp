#include <iostream>
#include <memory>

using namespace std;

int main(){
	unique_ptr<int []> p(new int [10]);  //needn't provide out own delete. It would delete the new int [10] automatically.
	for(int i = 0; i < 10; i++)
		p[i] = i;
	for(int i = 0; i < 10; i++)
		cout << p[i];

}