#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <list>

using namespace std;

int main(){
	tuple<string, vector<double>, int, list<int>, int> tup1("hello", {3.15, 2.8}, 3, {2, 3}, 5);  
	tuple<int, int, int> tup2{1, 2, 3};  //explict. error: tuple<int, int, int> tup2 = {1, 2, 3};
	auto tup3 = make_tuple("a", 2, 3.0);
	cout << get<1>(tup3) << endl; // return the second element of tup3	
	get<2>(tup3) *= 2;            // lvalue
	cout << get<2>(tup3) << endl;
	int sz = tuple_size<decltype(tup1)>::value;
	cout << sz <<  endl;
	tuple_element<2, decltype(tup1)>::type c = get<2>(tup1);   //define the type of c as the type of the third element of tup1  
	cout << c << endl;
}