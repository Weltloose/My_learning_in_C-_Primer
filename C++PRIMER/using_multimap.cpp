#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(){
	multimap<string, string> authors;
	authors.insert({"a", "b"});
	authors.insert({"c", "d"});
	authors.insert({"a", "f"});
	cout << authors.count("a") << endl;
	// auto cnt = authors.count("a");
	// auto iter = authors.find("a");
	// cout << "Mr. a writes books ";
	// while(cnt--){
	// 	cout << iter->second << " ";
	// 	iter ++ ;
	// }
	// cout << endl;
//------------------------------------------------------------------
	// cout << "Mr. a writes books ";
	// for(auto i = authors.lower_bound("a"), j = authors.upper_bound("a"); i != j; i ++ )
	// 	cout << i->second << ' ';
	// cout << endl;
//-----------------------------------------------------------------
	cout << "Mr. a writes books ";
	for(auto i = authors.equal_range("a"); i.first != i.second; i.first ++ ){
		cout << i.first->second << ' ';
	}
	cout << endl;
	for(const auto &i : authors) cout << i.first << " writes book " << i.second << endl;
}