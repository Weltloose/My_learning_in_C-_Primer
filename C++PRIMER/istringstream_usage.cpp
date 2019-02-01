#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct PersonInfo{
	string name;
	vector<string> phones;
};

int main(){
	vector<string> v;
	ifstream out;
	vector<PersonInfo> ps;
	out.open("1");
	if(out.is_open()){
		string str;
		
		while(getline(out, str)){
			PersonInfo temp;
			istringstream record(str);
			record >> temp.name;
			string word;
			while(record >> word){
				temp.phones.push_back(word);
			}
			ps.push_back(temp);
		}
	}
	for(auto i : ps){
		cout << i.name << ' ';
		for(auto j : i.phones) cout << j << ' ';
		cout << endl;
	}
}