#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Test{
private:
	int d;
public:
	Test(int n = 0): d(n){}
	operator int(){return d;}
};

int main(){
	Test a(3);
	cout << a * 2 << endl;
}