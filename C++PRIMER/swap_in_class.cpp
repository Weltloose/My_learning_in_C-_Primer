#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <memory>
#include <algorithm>

using namespace std;

class Data{
private:
	string home;
	int num;
public:
	friend void swap(Data &a, Data &b);
	friend bool comp(const Data &, const Data &);
	void print(){cout << num << ' ' << home << endl;}
	Data(string str, int n): home(str), num(n){}
	Data() = default;
	Data(const Data &) = default;
	

};

inline void swap(Data &a, Data &b){
	using swap;
	swap(a.num, b.num);
	//swap(a.num, b.num);   //error
}

bool comp(const Data &a, const Data &b){
	return a.num > b.num;
}

int main(){
	Data d[10];
	for(int i = 0; i < 10; i++){
		string str(i + 1, 'c');
		d[i] = Data(str, i);
	}
	swap(d[0], d[9]);// it uses our own defined swap;	
	for(auto i : d)
		i.print();
}