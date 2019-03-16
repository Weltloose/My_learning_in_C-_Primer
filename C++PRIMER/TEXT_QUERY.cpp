#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int main(){
	map<string, int> map_cnt;
	map<string, set<int>> map_set_line;
	vector<string> v_line;
	ifstream fin;
	fin.open("test.txt");
	string temp;
	int line = 0;
	while(getline(fin, temp)){
		line ++ ;
		v_line.push_back(temp);
		istringstream recode(temp);
		string str;
		while(recode >> str){
			map_set_line[str].insert(line);
			map_cnt[str] ++ ;
		}
	}
	fin.close();
	string str;
	while(cin >> str){
		cout << "The string occurs " << map_cnt[str] << " times\n";
		for(auto i : map_set_line[str]){
			cout << "line " << i << ": " << v_line[i] << '\n'; 
		}
	}
}