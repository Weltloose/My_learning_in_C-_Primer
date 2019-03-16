#include <iostream>
#include <memory>

using namespace std;

int main(){
	shared_ptr<int []> p(new int [10], [](int *p){delete [] p;});  // provide out own delete. It would delete the new int [10] automatically.
	for(int i = 0; i < 10; i++)
		*(p.get() + i) = i;
	for(int i = 0; i < 10; i++)
		cout << *(p.get() + i);

}